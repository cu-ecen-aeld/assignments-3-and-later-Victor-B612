#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //Setup syslog 
    openlog("my_app", 0, LOG_USER);
    //Check arguments input
    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <file_path> <string_to_write>", argv[0]);
        return EXIT_FAILURE;
    }

    char *file_path = argv[1];
    char *text_to_write = argv[2];

    int fd = open(file_path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | // owner: read/write
                                                           S_IRGRP | S_IWGRP | // group: read/write
                                                           S_IROTH | S_IWOTH); // others: read/write);
    if (fd == -1) {
        syslog(LOG_ERR, "File does not exist");
        return EXIT_FAILURE;
    }
    syslog(LOG_DEBUG, "Writing %s to %s", text_to_write,file_path);
    ssize_t num_bytes = write(fd, text_to_write, strlen(text_to_write));
    if(num_bytes == strlen(text_to_write)) {
        return EXIT_SUCCESS;
    } else {
        syslog(LOG_ERR, "FAILED TO WRITE IN THE FILE");
        return EXIT_FAILURE;
    }
}