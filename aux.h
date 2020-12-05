#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int QuickSort(int *lista, int izda, int dcha)
{
    int pivot = izda, aux;

    if (izda < dcha)
    {
        for (int i = izda + 1; i <= dcha; i++)
        {
            if (lista[i] < lista[izda])
            {
                pivot += 1;
                swap(&lista[i], &lista[pivot]);
            }
        }

        swap(&lista[izda], &lista[pivot]);

        QuickSort(lista, izda, pivot - 1);
        QuickSort(lista, pivot + 1, dcha);
    }
}