/*
 * Задание 25. Описать запись студента с помощью struct, enum и union.
 * Ввод: имя; затем оценка 0..100 и тип контакта (1 — телефон, 2 — email);
 * затем контакт отдельной строкой.
 * Вывод: имя, результат PASS/FAIL и выбранный контакт.
 * Пример: Anna / 78 2 / anna@example.org -> Anna / PASS / anna@example.org.
 */
#include <stdio.h>
#include <string.h>

enum { TEXT_SIZE = 128 };

typedef enum {
    CONTACT_PHONE = 1,
    CONTACT_EMAIL = 2
} ContactType;

typedef union {
    long long phone;
    char email[TEXT_SIZE];
} Contact;

typedef struct {
    char name[TEXT_SIZE];
    int grade;
    ContactType contact_type;
    Contact contact;
} Student;

static int read_line(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) return 0;
    size_t end = strcspn(buffer, "\r\n");
    if (buffer[end] == '\0' && end == size - 1) return 0;
    buffer[end] = '\0';
    return buffer[0] != '\0';
}

int main(void) {
    Student student;
    int type;
    if (!read_line(student.name, sizeof(student.name)) ||
        scanf("%d %d", &student.grade, &type) != 2 ||
        student.grade < 0 || student.grade > 100 ||
        (type != CONTACT_PHONE && type != CONTACT_EMAIL)) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    student.contact_type = (ContactType)type;
    if (student.contact_type == CONTACT_PHONE) {
        if (scanf("%lld", &student.contact.phone) != 1 ||
            student.contact.phone <= 0) {
            fprintf(stderr, "Error\n");
            return 1;
        }
    } else {
        if (!read_line(student.contact.email, sizeof(student.contact.email))) {
            fprintf(stderr, "Error\n");
            return 1;
        }
    }

    printf("Name: %s\n", student.name);
    printf("Result: %s\n", student.grade >= 60 ? "PASS" : "FAIL");
    if (student.contact_type == CONTACT_PHONE) {
        printf("Contact: %lld\n", student.contact.phone);
    } else {
        printf("Contact: %s\n", student.contact.email);
    }
    return 0;
}
