#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[])
{
    int fd;
    struct book record;

    if (argc < 2) {
        fprintf(stderr, "How to use: %s file\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0640)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("%-9s %-9s %-9s %-9s %-9s %-9s", "Book_Unique_Number", "Book_Name", "wrier_name", "Year_of_publication", "Number_of_loans", "Loan_availability");
    while (scanf("%d %s %s %d %d %s", &record.Book_Unique_Number, &record.Book_Name, &record.writer_name, &record.Year_of_publication, &record.Number_of_loans, &record.Loan_availability) == 6) {
        lseek(fd, (record.Book_Unique_Number - START_ID) * sizeof(record), SEEK_SET); 
        write(fd, (char *) &record, sizeof(record));               
    }

    close(fd); 
    exit(0);
}
