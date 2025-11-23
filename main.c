
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

extern void asmfunc(int n, float* matrix, int* result);

void checkcorrectness(int n, float* matrix, int* asmresult) {
    int errors = 0;
    int i, expected;
    float vi, vf, t, computed;
    for (i = 0; i < n; i++) {
        vi = matrix[i * 3];
        vf = matrix[i * 3 + 1];
        t = matrix[i * 3 + 2];
        computed = ((vf - vi) * 1000.0f / 3600.0f) / t;
        expected = (int)rintf(computed);

        if (asmresult[i] != expected) {
            errors++;
            if (errors < 5) {
                printf("incorrect value\n");
            }
        }
    }
    if (errors == 0) {
        printf("Correctness Check: PASS (values are correct)\n");
    }
    else {
        printf("correctness check: fail (%d errors)\n", errors);
    }
}


int main() {
    int nmanual, numsizes = 4, runs = 30;
    int sizes[] = { 10,100,1000,10000 };
    int s, i, r;
    float* matrix, matrixmanual;
    int* result;
    double totaltime, avgtime, interval;
    LARGE_INTEGER frequency, start, end;
    srand((unsigned int)time(NULL));
    printf("manual input test\n");
    printf("enter number of cars: ");

    if (scanf_s("%d", &nmanual) == 1 && nmanual > 0) {
        float* matrixmanual = (float*)malloc(nmanual * 3 * sizeof(float));
        int* resultmanual = (int*)malloc(nmanual * sizeof(int));
        if (matrixmanual && resultmanual) {
            printf("enter matrix values (vi vf t) for each car:\n");
            for (i = 0; i < nmanual; i++) {
                printf("car %d: ", i + 1);
                scanf_s("%f %f %f", &matrixmanual[i * 3], &matrixmanual[i * 3 + 1], &matrixmanual[i * 3 + 2]);
            }

            asmfunc(nmanual, matrixmanual, resultmanual);

            printf("\nmanual output results:\n");
            for (i = 0; i < nmanual; i++) {
                printf("car %d acceleration: %d\n", i + 1, resultmanual[i]);
            }
            printf("\n");
            free(matrixmanual);
            free(resultmanual);
        }
    }
    else {
        printf("skipping manual test\n");
    }


    QueryPerformanceFrequency(&frequency);
    printf("calculation benchmark\n");


    for (s = 0; s < numsizes; s++) {
        int n = sizes[s];
        printf("\ntesting input size: %d\n", n);
        matrix = (float*)malloc(n * 3 * sizeof(float));
        result = (int*)malloc(n * sizeof(int));

        if (!matrix || !result)
            return 1;

        for (i = 0; i < n * 3; i++) {
            matrix[i] = (float)(rand() % 200) + ((rand() % 10) / 10.0f);
            if ((i + 1) % 3 == 0) {
                matrix[i] = (float)((rand() % 20) + 1);
            }
        }

        asmfunc(n, matrix, result);
        checkcorrectness(n, matrix, result);

        totaltime = 0.0;
        for (r = 0; r < runs; r++) {
            QueryPerformanceCounter(&start);
            asmfunc(n, matrix, result);
            QueryPerformanceCounter(&end);
            interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            totaltime += interval;
        }

        avgtime = totaltime / runs;
        printf("average time over 30 runs: %.6f seconds\n", avgtime);

        free(matrix);
        free(result);
    }

    printf("\npress enter to exit...");
    int ch;
    ch = getchar(); ch = getchar();
    return 0;
}