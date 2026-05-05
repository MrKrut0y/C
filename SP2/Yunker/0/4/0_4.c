#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Russian");

    int base_damage, armor_class, is_critical;
    float defender_health, damage;

    printf("Введите обычный урон, целое число, от 1 до 300 включительно\n");
    scanf("%d", &base_damage);

    if (base_damage < 1 || base_damage > 300) {
        printf("введите целое число от 1 до 300 включительно\n");
        return 1;
    }

    printf("Введите текущий уровень жизни защитника, вещественное число от 1 до 1000 включительно\n");
    scanf("%f", &defender_health);

    if (defender_health < 1.0 || defender_health > 1000.0) {
        printf("введите вещественное число от 1 до 1000 включительно\n");
        return 1;
    }

    printf("Введите класс брони защитника, целое число от 0 до 8 включительно\n");
    scanf("%d", &armor_class);

    if (armor_class < 0 || armor_class > 8) {
        printf("введите целое число от 0 до 8 включительно\n");
        return 1;
    }

    printf("Введите флаг критического удара (0 или 1)\n");
    scanf("%d", &is_critical);

    if (is_critical != 0 && is_critical != 1) {
        printf("введите 0 или 1\n");
        return 1;
    }

    damage = base_damage;

    if (is_critical == 1) {
        damage *= 2;
        printf("Урон увеличен в 2 раза!\n");
    }

    if (armor_class > 0) {  
        float y = armor_class / 10.0f;
        damage = damage * (1.0f - y);
    }

    float hp = defender_health - damage;
    if (hp < 0) {
        hp = 0.0f;
    }

    printf("Нанесенный урон %.2f\nОставшееся здоровье %.2f\n", damage,hp);
    
    if (defender_health <= damage) {
        printf("\nYou win!\n");
    }

    return 0;
}