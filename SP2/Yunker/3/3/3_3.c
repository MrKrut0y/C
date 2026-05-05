#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

struct Employee {
    char surname[50];
    char name[50];
    char middle_name[50];
    char position[50];
    char gender;
    int hire_day;
    int hire_month;
    int hire_year;
};

int calculate_experience(int hire_day, int hire_month, int hire_year,
                         int day, int month, int year) {
    int experience = year - hire_year;

    if (month < hire_month || 
        (month == hire_month && day < hire_day)) {
        experience--;
    }
    
    return experience;
}

void print_employee(struct Employee emp) {
    printf("Фамилия: %s\n", emp.surname);
    printf("Имя: %s\n", emp.name);
    printf("Отчество: %s\n", emp.middle_name);
    printf("Должность: %s\n", emp.position);
    printf("Пол: %s\n", emp.gender == 'M' ? "Мужской" : "Женский"); 
    printf("Дата приема: %02d.%02d.%04d\n", 
           emp.hire_day, emp.hire_month, emp.hire_year);
}

void input_employee(struct Employee *emp) {
    printf("\nВвод данных сотрудника\n");
    
    printf("Фамилия: ");
    scanf("%s", emp->surname);
    
    printf("Имя: ");
    scanf("%s", emp->name);
    
    printf("Отчество: ");
    scanf("%s", emp->middle_name);
    
    printf("Должность: ");
    scanf("%s", emp->position);
    
    printf("Пол (M - мужской, F - женский): ");
    scanf(" %c", &emp->gender);
    
    printf("Дата приема (день месяц год): ");
    scanf("%d %d %d", &emp->hire_day, &emp->hire_month, &emp->hire_year);
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    struct Employee employees[5]; 
    int count = 5;
    int day, month, year;
    int choice;
    
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    day = tm_info->tm_mday;
    month = tm_info->tm_mon + 1;
    year = tm_info->tm_year + 1900;
    
    printf("Выберите способ ввода данных:\n");
    printf("1 - Ввести сотрудников вручную\n");
    printf("2 - Использовать готовых сотрудников\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        for (int i = 0; i < count; i++) {
            printf("\nСотрудник %d", i + 1);
            input_employee(&employees[i]);
        }
    } else {
        struct Employee temp[5] = {
            {"Иванов", "Иван", "Иванович", "Инженер", 'M', 15, 3, 2010},
            {"Сидоров", "Петр", "Алексеевич", "Менеджер", 'M', 5, 1, 2012},
            {"Козлова", "Елена", "Дмитриевна", "Аналитик", 'F', 20, 11, 2020},
            {"Смирнов", "Михаил", "Андреевич", "Директор", 'M', 1, 9, 2005},
            {"Васильева", "Ольга", "Петровна", "Экономист", 'F', 5, 6, 2015}
        };
        
        for (int i = 0; i < count; i++) {
            employees[i] = temp[i];
        }
    }

    printf("\n\nВсе сотрудники: \n");
    for (int i = 0; i < count; i++) {
        printf("\nСотрудник %d:\n", i + 1);
        print_employee(employees[i]);
        
        int experience = calculate_experience(
            employees[i].hire_day,
            employees[i].hire_month,
            employees[i].hire_year,
            day, month, year
        );
        printf("Стаж: %d лет\n\n", experience);

    }
    
    printf("\n\n-Сотрудники со стажем более 10 лет- \n\n\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        int experience = calculate_experience(
            employees[i].hire_day,
            employees[i].hire_month,
            employees[i].hire_year,
            day, month, year
        );
        
        if (experience > 10) {
            print_employee(employees[i]);
            printf("Стаж: %d лет\n\n", experience);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Нет сотрудников со стажем более 10 лет.\n");
    }

    return 0;
}