#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
 * my_system - synchronously spawns and waits for the command
 * "/bin/sh -c <cmd>"
 * 
 * return -1 on error of any sort, or the exit code from the launched process.
 * Dose not block the ignore and signals
*/
int my_system(const char *command)
{
	pid_t pid;

	pid = fork();
	if (pid == -1) {
		return -1;
	}

	if (!pid) {
		int ret;
		ret = execl("/bin/sh", "sh", "-c", command, NULL);
		if (ret == -1) {
			return -1;
		}
	} else {
		pid_t npid;
		int status;
		npid = waitpid(pid, &status, WUNTRACED);
		if (npid == -1) {
			return -1;
		} else if (WIFEXITED(status)) {
			return WEXITSTATUS(status);
		}
		return -1;
	}
}

int main()
{
	int status;
	status = my_system("vim test.txt");

	if (status == -1) {
		perror("my_system");
	}
}