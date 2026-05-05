#include <stdio.h>
#include <locale.h>
#include <string.h>

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

int write_file( struct Employee emp[5], int count, const char *filename) {

    FILE *out = fopen(filename, "wt");
    if (out == NULL) {
        printf("Ошибка");
        return 0;
    }
    for (int i = 0; i < count; i++) {
        fprintf(out, "Фамилия: %s ", emp[i].surname);
        fprintf(out, "Имя: %s ", emp[i].name);
        fprintf(out, "Отчество: %s ", emp[i].middle_name);
        fprintf(out, "Должность: %s ", emp[i].position);
        fprintf(out, "Пол: %s ", emp[i].gender == 'M' ? "Мужской" : "Женский"); 
        fprintf(out, "Дата приема: %02d.%02d.%04d", 
            emp[i].hire_day, emp[i].hire_month, emp[i].hire_year);
        fprintf(out, "\n");
    }

    fclose(out);
    return 1;
}

int main() {

    setlocale(LC_ALL, "Russian");

   
    int count = 5;
    int day, month, year;

    struct Employee temp[5] = {
            {"Иванов", "Иван", "Иванович", "Инженер", 'M', 15, 3, 2010},
            {"Сидоров", "Петр", "Алексеевич", "Менеджер", 'M', 5, 1, 2012},
            {"Козлова", "Елена", "Дмитриевна", "Аналитик", 'F', 20, 11, 2020},
            {"Смирнов", "Михаил", "Андреевич", "Директор", 'M', 1, 9, 2005},
            {"Васильева", "Ольга", "Петровна", "Экономист", 'F', 5, 6, 2015}
        };

    write_file(temp, count, "employees.txt");

    return 0;
}
