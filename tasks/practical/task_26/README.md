### Задание 26. Односвязный список в C

**Условие.** Построить односвязный список, развернуть его без создания второго списка, вывести элементы и освободить все узлы.

#### Формат входных данных

N (0..100000), затем N целых чисел.

#### Формат выходных данных

элементы списка после разворота; для пустого списка — Empty. Если входные данные нарушают указанный формат или ограничения, программа выводит `Error` в стандартный поток ошибок и завершается с ненулевым кодом.

#### Разбор решения

Каждый узел хранит значение и адрес следующего узла. Три указателя позволяют развернуть связи за линейное время без второго списка; отдельная функция освобождает каждый узел.

#### Алгоритм

1. построить список, сохраняя указатель на хвост.
2. развернуть ссылки `next`.
3. вывести новый список.
4. освободить все узлы.

#### Исходный код

[main.c](main.c)

```c
/*
 * Задание 26. Построить односвязный список, развернуть его без создания
 * второго списка, вывести элементы и освободить все узлы.
 * Ввод: N (0..100000), затем N целых чисел.
 * Вывод: элементы списка после разворота; для пустого списка — Empty.
 * Пример: 4 / 1 2 3 4 -> 4 3 2 1.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

static void destroy(Node *head) {
    while (head != NULL) {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0 || n > 100000) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    Node *head = NULL;
    Node **tail = &head;
    for (int i = 0; i < n; ++i) {
        Node *node = malloc(sizeof(*node));
        if (node == NULL) {
            destroy(head);
            fprintf(stderr, "Error\n");
            return 1;
        }
        if (scanf("%d", &node->value) != 1) {
            free(node);
            destroy(head);
            fprintf(stderr, "Error\n");
            return 1;
        }
        node->next = NULL;
        *tail = node;
        tail = &node->next;
    }

    Node *reversed = NULL;
    while (head != NULL) {
        Node *next = head->next;
        head->next = reversed;
        reversed = head;
        head = next;
    }

    if (reversed == NULL) {
        puts("Empty");
    } else {
        for (Node *node = reversed; node != NULL; node = node->next) {
            printf("%d%c", node->value, node->next == NULL ? '\n' : ' ');
        }
    }
    destroy(reversed);
    return 0;
}

```

#### Пример работы

Ввод:

```text
4
1 2 3 4
```

Вывод:

```text
4 3 2 1
```

#### Граничные случаи

Для `N = 0` выводится `Empty`; уже развёрнутый одноэлементный список не меняется.

#### Компиляция и запуск

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic main.c -o program
./program
```
