#include <stdio.h>
#include <locale.h>
#include <math.h>

struct point
{
    char* name;
    float x;
    float y;
};

void put_point(struct point z){
    printf("point %s (%.1f, %.1f)\n", z.name, z.x, z.y);
  }

float dist (struct point z, struct point w) {
    float l = sqrt((w.x - z.x) * (w.x - z.x) + (w.y - z.y) * (w.y - z.y));
    return l;
}

int main() {

    setlocale(LC_ALL, "Russian");

    struct point z = {"z", 2.0, 3.1};
    struct point w = {"w", 5.2, 2.5};

    put_point(z);
    put_point(w);

    float distance = dist(z, w);
    printf("\nРасстояние: %.2lf\n", distance);

    return 0;
}
