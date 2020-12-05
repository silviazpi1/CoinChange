#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"
#include <stdbool.h>

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int QuickSort(float *list, int left, int right)
{
    int pivot = left, aux;

    if (left < right)
    {
        for (int i = left + 1; i <= right; i++)
        {
            if (list[i] < list[left])
            {
                pivot += 1;
                swap(&list[i], &list[pivot]);
            }
        }

        swap(&list[left], &list[pivot]);

        QuickSort(list, left, pivot - 1);
        QuickSort(list, pivot + 1, right);
    }
}