#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
} point_t;

bool is_convex(unsigned int n, ...);

int main()
{
    printf("Laba 1 Task 2\nDrobotun Yulia M8o-210B-20\n\n\n");
    printf("Result:\n");
    bool result;
    point_t a, b, c, d, e;
    a.x = 0;
    a.y = 5;
    b.x = 10;
    b.y = 8;
    c.x = 10;
    c.y = 25;
    d.x = -15;
    d.y = 25;
    e.x = -15;
    e.y = 9;
    result = is_convex(5, a, b, c, d, e);
    if (result)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}


bool is_convex(unsigned int n, ...)
{
    point_t *polygon = (point_t*)malloc(n * sizeof(point_t));
    bool result = true;
    va_list factor;
    va_start(factor, n);
    for(unsigned int i = 0; i < n; i++)
    {
        polygon[i] = va_arg(factor, point_t);
    }
    va_end(factor);
    point_t prev, next;
    prev.x = polygon[n - 1].x - polygon[n - 2].x;
    prev.y = polygon[n - 1].y - polygon[n - 2].y;

    next.x = polygon[0].x - polygon[n - 1].x;
    next.y = polygon[0].y - polygon[n - 1].y;
    for (unsigned int  i = 1; i < n && result; i++)
    {
        prev = next;
        next.x = polygon[i].x - polygon[i - 1].x;
        next.y = polygon[i].y - polygon[i - 1].y;
        if ((prev.x * next.y - prev.y * next.x) >= 0)
            result = true;
        else
            result = false;
    }
    return result;
}
