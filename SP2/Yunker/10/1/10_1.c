#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#define SIZE 5
#define FNAME "employees.txt"

typedef struct Employee {
    char surname[50];
    char name[50];        
    char middle_name[50];    
    char position[50];     
    char gender;        
    int hire_day;    
    int hire_month;
    int hire_year;            
} employee_t;

void fill_array(employee_t *employees, int size) {
    FILE *in = fopen(FNAME, "r");
    if (in == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    for (int i=0;i<size;i++) {
        if (fscanf(in, "%s %s %s %s %c %d %d %d\n", 
            employees[i].surname,
            employees[i].name,
            employees[i].middle_name,
            employees[i].position,
            &employees[i].gender,
            &employees[i].hire_day,
            &employees[i].hire_month,
            &employees[i].hire_year) != 8) {
            break;
        }
    }

    fclose(in);
}

void print_array(employee_t *employees, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nСотрудник %d\n", i + 1);
        printf("Фамилия: %s\n", employees[i].surname);
        printf("Имя: %s\n", employees[i].name);
        printf("Отчество: %s\n", employees[i].middle_name);
        printf("Должность: %s\n", employees[i].position);
        printf("Пол: %s\n", employees[i].gender == 'M' ? "Мужской" : "Женский"); 
        printf("Дата приема: %02d.%02d.%04d\n", 
               employees[i].hire_day, employees[i].hire_month, employees[i].hire_year);
    }
    printf("\n");
}   

void print_employee(employee_t emp, int num) {
    printf("\nСотрудник %d\n", num);
    printf("Фамилия: %s\n", emp.surname);
    printf("Имя: %s\n", emp.name);
    printf("Отчество: %s\n", emp.middle_name);
    printf("Должность: %s\n", emp.position);
    printf("Пол: %s\n", emp.gender == 'M' ? "Мужской" : "Женский"); 
    printf("Дата приема: %02d.%02d.%04d\n", 
           emp.hire_day, emp.hire_month, emp.hire_year);
    printf("\n");
} 

void edit_employee(employee_t *employees, int size) {
    int num;
    printf("Введите номер сотрудника для изменения (1-%d): ", size);
    scanf("%d", &num);

    while (getchar() != '\n');

    if (num < 1 || num > size) {
        printf("Ошибка: неверный номер сотрудника\n");
        return;
    }

    int index = num - 1;

    printf("\nТекущие данные сотрудника %d:\n", num);
    print_employee(employees[index], num);

    printf("Введите новые данные (или оставьте пустым для сохранения текущего значения):\n");
    
    char buffer[100];

    printf("Фамилия [%s]: ", employees[index].surname);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) {
        strcpy(employees[index].surname, buffer);
    }

    printf("Имя [%s]: ", employees[index].name);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) {
        strcpy(employees[index].name, buffer);
    }

    printf("Отчество [%s]: ", employees[index].middle_name);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) {
        strcpy(employees[index].middle_name, buffer);
    }

    printf("Должность [%s]: ", employees[index].position);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) {
        strcpy(employees[index].position, buffer);
    }

    printf("Пол [%c] (M/F): ", employees[index].gender);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) {
        char gender = buffer[0];
        if (gender == 'M' || gender == 'F') {
            employees[index].gender = gender;
        }
    }

    printf("Дата приема [%02d.%02d.%04d] (день месяц год): ", 
           employees[index].hire_day, employees[index].hire_month, employees[index].hire_year);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    
    if (strlen(buffer) > 0) {
        int day, month, year;
        if (sscanf(buffer, "%d %d %d", &day, &month, &year) == 3) {
            employees[index].hire_day = day;
            employees[index].hire_month = month;
            employees[index].hire_year = year;
        }
    }
    
    printf("\nДанные сотрудника %d успешно обновлены!\n", num);
    print_employee(employees[index], num);
}

void search_employees(employee_t *employees, int size) {
    if (employees[0].surname[0] == '\0') {
        printf("Сначала загрузите данные (пункт 1)\n");
        return;
    }

    int choice;
    printf("\nВыберите поле для поиска:\n");
    printf("1 - Фамилия\n");
    printf("2 - Имя\n");
    printf("3 - Отчество\n");
    printf("4 - Должность\n");
    printf("5 - Пол\n");
    printf("6 - Год приема\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);

    while (getchar() != '\n');

    char search_str[100];
    char gender_search;
    int year_search;
    int found = 0;

    switch (choice) {
        case 1:
            printf("Введите фамилию сотрудника для поиска: ");
            fgets(search_str, sizeof(search_str), stdin);
            search_str[strcspn(search_str, "\n")] = 0;

            printf("\nРезультаты поиска по фамилии \"%s\":\n", search_str);
            for (int i=0;i<size;i++) {
                if (strcmp(employees[i].surname, search_str) == 0) {
                    print_employee(employees[i], i+1);
                    found=1;
                }
            }
            break;

        case 2:
            printf("Введите имя сотрудника для поиска: ");
            fgets(search_str, sizeof(search_str), stdin);
            search_str[strcspn(search_str, "\n")] = 0;

            printf("\nРезультаты поиска по имени \"%s\":\n", search_str);
            for (int i=0;i<size;i++) {
                if (strcmp(employees[i].name, search_str) == 0) {
                    print_employee(employees[i], i+1);
                    found=1;
                }
            }
            break;

        case 3:
            printf("Введите отчество сотрудника для поиска: ");
            fgets(search_str, sizeof(search_str), stdin);
            search_str[strcspn(search_str, "\n")] = 0;

            printf("\nРезультаты поиска по отчеству \"%s\":\n", search_str);
            for (int i=0;i<size;i++) {
                if (strcmp(employees[i].middle_name, search_str) == 0) {
                    print_employee(employees[i], i+1);
                    found=1;
                }
            }
            break;

        case 4:
            printf("Введите должность сотрудника для поиска: ");
            fgets(search_str, sizeof(search_str), stdin);
            search_str[strcspn(search_str, "\n")] = 0;

            printf("\nРезультаты поиска по должности \"%s\":\n", search_str);
            for (int i=0;i<size;i++) {
                if (strcmp(employees[i].position, search_str) == 0) {
                    print_employee(employees[i], i+1);
                    found=1;
                }
            }
            break;

        case 5:
            printf("Введите пол для поиска (M, F): ");
            scanf(" %c", &gender_search);
            
            printf("\nРезультаты поиска по полу '%c':\n", gender_search);
            for (int i = 0; i < size; i++) {
                if (employees[i].gender == gender_search) {
                    print_employee(employees[i], i + 1);
                    found = 1;
                }
            }
            break;

        case 6:
            printf("Введите год приема для поиска: ");
            scanf("%d", &year_search);
            
            printf("\nРезультаты поиска по году %d:\n", year_search);
            for (int i = 0; i < size; i++) {
                if (employees[i].hire_year == year_search) {
                    print_employee(employees[i], i + 1);
                    found = 1;
                }
            }
            break;
    
        default:
            printf("Неверный выбор поля для поиска\n");
            break;
    }

    if (!found) {
        printf("Сотрудники не найдены.\n");
    }
}

void save_new_file(employee_t *employees, int size) {
    if (employees[0].surname[0] == '\0') {
        printf("Массив пуст. Сначала загрузите данные (пункт 1)\n");
        return;
    }

    char fname[50];
    printf("Введите название файла: ");
    scanf("%s", fname);

    FILE *out;
    if ((out = fopen(fname, "wt")) == NULL) {
        printf("Ошибка открытия файла для записи\n");
        return;
    }

    for (int i=0;i<size;i++) {
        fprintf(out, "%s %s %s %s %c %d %d %d\n", 
            employees[i].surname,
            employees[i].name,
            employees[i].middle_name,
            employees[i].position,
            employees[i].gender,
            employees[i].hire_day,
            employees[i].hire_month,
            employees[i].hire_year);
    }

    fclose(out);
    printf("Данные успешно сохранены в файл %s\n", fname);
}

int compare_by_surname(const void *a, const void *b) {
    employee_t *ea = (employee_t*)a;
    employee_t *eb = (employee_t*)b;
    return strcmp(ea->surname, eb->surname);
}

int compare_by_name(const void *a, const void *b) {
    employee_t *ea = (employee_t*)a;
    employee_t *eb = (employee_t*)b;
    return strcmp(ea->name, eb->name);
}

int compare_by_middle_name(const void *a, const void *b) {
    employee_t *ea = (employee_t*)a;
    employee_t *eb = (employee_t*)b;
    return strcmp(ea->middle_name, eb->middle_name);
}

int compare_by_position(const void *a, const void *b) {
    employee_t *ea = (employee_t*)a;
    employee_t *eb = (employee_t*)b;
    return strcmp(ea->position, eb->position);
}

int compare_by_gender(const void *a, const void *b) {
    employee_t *ea = (employee_t*)a;
    employee_t *eb = (employee_t*)b;
    return (ea->gender - eb->gender);
}

int compare_by_year(const void *a, const void *b) {
    employee_t *ea = (employee_t*)a;
    employee_t *eb = (employee_t*)b;
    return (ea->hire_year - eb->hire_year);
}

void sort_employees(employee_t *employees, int size) {
    if (employees[0].surname[0] == '\0') {
        printf("Сначала загрузите данные (пункт 1)\n");
        return;
    }

    int choice;
    printf("\n--Сортировка--\n");
    printf("1 - по фамилии\n2 - по имени\n3 - по отчеству\n");
    printf("4 - по должности\n5 - по полу\n6 - по году\n");
    printf("\nВыбор: ");
    scanf("%d", &choice);

    int (*compare_func)(const void*, const void*) = NULL;

    switch (choice) {
        case 1: compare_func = compare_by_surname; break;
        case 2: compare_func = compare_by_name; break;
        case 3: compare_func = compare_by_middle_name; break;
        case 4: compare_func = compare_by_position; break;
        case 5: compare_func = compare_by_gender; break;
        case 6: compare_func = compare_by_year; break;
        default:
            printf("Неверный выбор\n");
            return;
    }

    qsort(employees, size, sizeof(employee_t), compare_func);
    
    printf("Сортировка выполнена\n");
}

int main() {

    SetConsoleCP(1251);        // Устанавливаем кодировку ввода
    SetConsoleOutputCP(1251);  // Устанавливаем кодировку вывода

    setlocale(LC_ALL, "Russian");               // 23

    int n;

    employee_t employees[SIZE];

    while (1) {
        printf("\n--Выберите действие--\n");
        printf("1) загрузку данных и файла(заполнение массива)\n"
        "2) изменение выбранной записи\n"
        "3) поиск записи в массиве по одному полю, значение которого задал пользователь\n"
        "4) сортировка массива  по выбранному полю\n"
        "5) сохранение измененного массива записей в новый файл.\n\n"
        "6) вывод всего массива\n"
        "7) вывод одного сотрудника\n"
        "8) выход\n"
        "-> ");
        scanf("%d", &n);

        if (n==1) {
            fill_array(employees, SIZE);
            printf("\nМассив заполнен\n");
        } else if (n==2) {
            edit_employee(employees, SIZE);
        } else if (n==3) {
            search_employees(employees, SIZE);
        } else if (n==4) {
            sort_employees(employees, SIZE);
        } else if (n==5) {
            save_new_file(employees, SIZE);
        } else if (n==6) {
            print_array(employees, SIZE);
        } else if (n==7) {
            int num;
            printf("Введите номер сотрудника (1-%d): ", SIZE);
            scanf("%d", &num);
            if (num < 1 || num > SIZE) {
                printf("Ошибка: неверный номер сотрудника\n");
            } else {
                print_employee(employees[num-1], num);
            }
        } else if (n==8) {
            break;
        }
        else {
            printf("Неверный выбор\n");
        }
    }

    return 0;
}

/*Вариант 23. Запись «Сотрудник»:
Фамилия
Имя
Отчество
Должность
Пол
Дата приема на работу
Вывести все сведения о сотрудниках, стаж которых превышает
10 лет.
*/
