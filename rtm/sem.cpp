#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int semkey = 12391;


union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};

union semun arg;
int main(int argc, char *argv[]) {
    int semid = semget(12391, 1, 0666 | IPC_CREAT);
    if (argc < 2) {
        if (semctl(semid, 0, IPC_RMID) < 0)
            perror("semctl remove");
    } else {
        printf("id %d\n", semid);
        arg.val = atoi(argv[1]);
        if (semctl(semid, 0, SETVAL, arg) < 0)
            perror("semctl set");
    }
    return 0;
}
