#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void run_command(const char *cmd, char *const argv[], int in_fd, int out_fd) {
    if (fork() == 0) { 
        if (in_fd != STDIN_FILENO) {
            dup2(in_fd, STDIN_FILENO); 
            close(in_fd);
        }
        if (out_fd != STDOUT_FILENO) {
            dup2(out_fd, STDOUT_FILENO); 
            close(out_fd);
        }
        execvp(cmd, argv);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {

    if(argc != 2){
        fprintf(stderr, "Usage: %s name\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipe1[2], pipe2[2], pipe3[2];

    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    char *grep_args[] = {"grep", argv[1], "PhoneBook.txt", NULL};
    run_command("grep", grep_args, STDIN_FILENO, pipe1[1]);
    close(pipe1[1]);

    char *sed1_args[] = {"sed", "s/ /#/g", NULL};
    run_command("sed", sed1_args, pipe1[0], pipe2[1]);
    close(pipe1[0]);
    close(pipe2[1]);

    char *sed2_args[] = {"sed", "s/,/ /", NULL};
    run_command("sed", sed2_args, pipe2[0], pipe3[1]);
    close(pipe2[0]);
    close(pipe3[1]);

    char *awk_args[] = {"awk", "{print $2}", NULL};
    run_command("awk", awk_args, pipe3[0], STDOUT_FILENO);
    close(pipe3[0]);

    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}
