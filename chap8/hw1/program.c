#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void print_usage() {
    printf("Usage: ./program [-e ENV_VAR] [-u] [-g] [-i] [-p]\n");
}

int main(int argc, char *argv[]) {
    int opt;

    if (argc < 2) {
        print_usage();
        return 1;
    }

    while ((opt = getopt(argc, argv, "e:ugip")) != -1) {
        switch (opt) {
            case 'e': {
                char *env_value = getenv(optarg);
                if (env_value) {
                    printf("%s=%s\n", optarg, env_value);
                } else {
                    printf("Environment variable %s not found.\n", optarg);
                }
                break;
            }
            case 'u': {
                uid_t real_uid = getuid();
                uid_t effective_uid = geteuid();
                printf("Real User ID: %d, Effective User ID: %d\n", real_uid, effective_uid);
                break;
            }
            case 'g': {
                gid_t real_gid = getgid();
                gid_t effective_gid = getegid();
                printf("Real Group ID: %d, Effective Group ID: %d\n", real_gid, effective_gid);
                break;
            }
            case 'i': {
                pid_t pid = getpid();
                printf("Process ID: %d\n", pid);
                break;
            }
            case 'p': {
                pid_t ppid = getppid();
                printf("Parent Process ID: %d\n", ppid);
                break;
            }
            default: {
                print_usage();
                return 1;
            }
        }
    }

    return 0;
}

