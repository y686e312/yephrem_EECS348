#include <stdio.h>
#include <stdlib.h>


const char* months[] = {"January", "February", "March", "April", "May", "June", 
                        "July", "August", "September", "October", "November", "December"}; // array for the months

float read_text_file(const char* filename, float sales[], int size) //float to read the file. takes in the filename, the array, and its size
{
    FILE* file = fopen(filename, "r"); //sets the file equal to file 
    for (int i = 0; i < size; i++) 
    {
        fscanf(file, "%f", &sales[i]);
    }
    fclose(file); //closes the file
}


float monthly_sales(float sales[], int size) 
{
    printf("Monthly Sales Report for 2024\n"); 
    printf("Month            Sales\n");
    for (int i = 0; i < size; i++) //i initialized to 0, until i is not less than size, it is incremented on iteration
    {
        printf("%-16s %.2f\n", months[i], sales[i]);
    }
}

float sales_summary(float sales[], int size) 
{
    float min = sales[0], max = sales[0], sum = 0; //sets the min/max/sum to 0 to initialize
    for (int i = 0; i < size; i++) // same loop as last
    {
        if (sales[i] < min) min = sales[i]; // if the current index is less than the min it becomes the new min
        if (sales[i] > max) max = sales[i]; // if the current index is less than the max it becomes the new max
        sum += sales[i]; //adds every sale num
    }
    float avg = sum / size; 
    printf("\nSales Summary Report : \n");
    printf("Minimum Sales: %.2f\n", min);
    printf("Maximum Sales: %.2f\n", max);
    printf("Average Sales: %.2f\n", avg);
}

float six_month_avg(float sales[], int size) 
{
    printf("\nSix-Month Moving Average Report : \n");
    for (int i = 0; i <= 6; i++) // initialized to 0, until i is greater than the 6, and increments per iteration
    {
        float sum = 0; 
        for (int j = i; j < i + 6; j++) //initialized j to i, until j is >= i + 6, incremented on iteration
        {
            sum += sales[j]; 
        }
        printf("%s-%s: %.2f\n", months[i], months[i + 5], sum / 6); //after the 6 month loop you print the information and restart for the next...
    }
}

float hi_lo_sales(float sales[], int size) {
    float ordered_sales[size];
    const char* ordered_months[size];
    for (int i = 0; i < size; i++) 
    {
        ordered_sales[i] = sales[i]; //creates a copy of the sales to be ordered
        ordered_months[i] = months[i]; //creates a copy of the months to be ordered
    }

    for (int i = 0; i < size - 1; i++) // i initialized to 0, until i is not less than the size-1, and incremented per iteration
    {
        for (int j = 0; j < size - i - 1; j++) //does the same loop but for the next month to compare them
        {
            if (ordered_sales[j] < ordered_sales[j + 1]) //if the sales num in i < j+1 then...
            {
                float temp_sales = ordered_sales[j]; //save j to a temp var
                ordered_sales[j] = ordered_sales[j + 1]; //the j+1 takes js place
                ordered_sales[j + 1] = temp_sales; //j+1 becomes the lower temp var (j)
                const char* temp_month = ordered_months[j]; //repeat the same thing for their respective months
                ordered_months[j] = ordered_months[j + 1];
                ordered_months[j + 1] = temp_month;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest)\n");
    printf("Month            Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-16s %.2f\n", ordered_months[i], ordered_sales[i]);
    }
}

int main() //calls the functions
{
    float sales[12];
    read_text_file("lab_5_text.txt", sales, 12);
    monthly_sales(sales, 12);
    sales_summary(sales, 12);
    six_month_avg(sales, 12);
    hi_lo_sales(sales, 12);
    return 0;
}
