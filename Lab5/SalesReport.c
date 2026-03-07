#include <stdio.h>
#define MONTHS 12

const char *monthNames[MONTHS] = {
    "January","February","March","April","May","June","July","August","September","October","November","December"

};

void monthlyReport(float sales[]) {
    printf("Monthly Sales Report for 2026\n");
    printf("\nMonth      Sales\n\n");

    for(int i = 0; i < MONTHS; i++) {
        printf("%-10s %.2f\n", monthNames[i], sales[i]);
    }
}

void summaryReport(float sales[]) {
    float min = sales[0];
    float max = sales[0];
    float sum = 0;
    int minMonth = 0, maxMonth = 0;

    for(int i = 0; i < MONTHS; i++) {
        if(sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if(sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        sum += sales[i];
    }

    printf("\nSales Summary Report\n");
    printf("\nMinimum Sales: %.2f (%s)\n", min, monthNames[minMonth]);
    printf("Maximum Sales: %.2f (%s)\n", max, monthNames[maxMonth]);
    printf("Average Sales: %.2f\n", sum / MONTHS);
}

void movingAverage(float sales[]) {
    printf("\nSix-Month Moving Average Report\n\n");

    for(int i = 0; i <= 6; i++) {
        float sum = 0;

        for(int j = i; j < i + 6; j++) {
            sum += sales[j];
        }

        printf("%s - %s:   %.2f\n",
            monthNames[i],
            monthNames[i + 5],
            sum / 6);
    }
}

void sortReport(float sales[]) {
    float sorted[MONTHS];

    for(int i = 0; i < MONTHS; i++)
        sorted[i] = sales[i];

    for(int i = 0; i < MONTHS-1; i++) {
        for(int j = i+1; j <MONTHS; j++) {
            if(sorted[i] < sorted[j]) {
                float temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest)\n\n");

    for(int i = 0; i < MONTHS; i++) {
        for(int j = 0; j < MONTHS; j++) {
            if(sorted[i] == sales[j]) {
                printf("%-10s %.2f\n", monthNames[j], sorted[i]);
                break;
            }
        }
    }
}

int main() {

    FILE *file = fopen("sales.txt", "r");
    float sales[MONTHS];

    if(file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for(int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);
    }

    fclose(file);

    monthlyReport(sales);
    summaryReport(sales);
    movingAverage(sales);
    sortReport(sales);

    return 0;
}