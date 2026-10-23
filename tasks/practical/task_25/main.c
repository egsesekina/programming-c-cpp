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
    char phone[TEXT_SIZE];
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
    char contact_text[TEXT_SIZE];

    if (!read_line(student.name, sizeof(student.name)) ||
        scanf("%d %d", &student.grade, &type) != 2 ||
        student.grade < 0 || student.grade > 100 ||
        (type != CONTACT_PHONE && type != CONTACT_EMAIL)) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    if (!read_line(contact_text, sizeof(contact_text))) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    student.contact_type = (ContactType)type;
    if (student.contact_type == CONTACT_PHONE) {
        strcpy(student.contact.phone, contact_text);
    } else {
        strcpy(student.contact.email, contact_text);
    }

    printf("Name: %s\n", student.name);
    printf("Result: %s\n", student.grade >= 60 ? "PASS" : "FAIL");
    printf("Contact: %s\n", student.contact_type == CONTACT_PHONE
                               ? student.contact.phone
                               : student.contact.email);
    return 0;
}
