#include <stdio.h>
//required functions converting temperature measurement scales
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}
//method to print the notes about the temperature to the user
//finds out which temperature scale the user is wanting to know and gives notes according to that measurement specifically
void categorize_temperature(float temp, int scale) {
    if (scale == 1) 
    { 
        if (temp < 0) 
        {
            printf("Freezing\nStay indoors\n");
        }
        else if (temp < 10)
        {
            printf("Cold\nWear a jacket\n");
        }
        else if (temp < 25) 
        {
            printf("Comfortable\nIt is comfortable outside\n");
        }
        else if (temp < 35) 
        { 
            printf("Hot\nStay hydrated\n");
        }
        else
        {
            printf("Extreme Heat\nStay indoors\n");
        }
    } 
    else if (scale == 2) 
    { 
        if (temp < 32) 
        {
            printf("Freezing\nStay indoors\n");
        }
        else if (temp < 50) 
        {
            printf("Cold\nWear a jacket\n");
        }
        else if (temp < 77) 
        {
        printf("Comfortable\nIt is comfortable outside\n");
        }
        else if (temp < 95) 
        {
            printf("Hot\nStay hydrated\n");
        }
        else  
        {
            printf("Extreme Heat\nStay indoors\n");
        }
    } 
    else if (scale == 3) 
    {
        if (temp < 273.15) 
        {
            printf("Freezing\nStay indoors\n");
        }
        else if (temp < 283.15) 
        {
            printf("Cold\nWear a jacket\n");
        }
        else if (temp < 298.15) 
        { 
            printf("Comfortable\nIt is comfortable outside\n");
        }
        else if (temp < 308.15) 
        {
            printf("Hot\nStay hydrated\n");
        }
        else 
        {
        printf("Extreme Heat\nStay indoors\n");
        }
    }
}
//function converting the temperature
void temperature_conversion() {
    //variables 
    float temperature;
    float converted_temp;
    int input_scale; 
    int target_scale;
    //asks for a temp from the user
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    //asks the user what scale the temperature they entered is on
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);//saves the scale value

    //asks the user what they want to convert to on the scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);//saves that value

    //the provided scale cant be the same as the target scale
    if (input_scale == target_scale) {
        printf("Error: Cannot convert to the same scale.\n");
        temperature_conversion();    
    } 
    //runs conversions for celsius input scale
    else if (input_scale == 1){
        if  (target_scale == 2)
        {
         converted_temp = celsius_to_fahrenheit(temperature);
        printf("Converted temperature: %.2f°F\n", converted_temp);  
        categorize_temperature(converted_temp, target_scale);
        }
        else if (target_scale == 3)
        {
        converted_temp = celsius_to_kelvin(temperature);
        printf("Converted temperature: %.2f°F\n", converted_temp);
        categorize_temperature(converted_temp, target_scale);
        }
    }
    //runs conversions for fahrenheit input scale
    else if (input_scale == 2){
        if (target_scale == 1)
        {
        converted_temp = fahrenheit_to_celsius(temperature);
        printf("Converted temperature: %.2f°C\n", converted_temp);
        categorize_temperature(converted_temp, target_scale);
        }
     
        else if (target_scale == 3) 
        {
            converted_temp = fahrenheit_to_kelvin(temperature);
            printf("Converted temperature: %.2fK\n", converted_temp);
            categorize_temperature(converted_temp, target_scale);
        }
    } 
    //runs conversions for kelvin input scalwe
    else if (input_scale == 3) {
           if (target_scale == 1) 
           {
                if (temperature >= 0) 
                { 
                    converted_temp = kelvin_to_celsius(temperature);
                    printf("Converted temperature: %.2f°C\n", converted_temp);
                    categorize_temperature(converted_temp, target_scale);
                } 
                else 
                {
                    //kelvin has no negative values so raises an error
                    printf("Error: Kelvin cannot be negative.\n");
                    temperature_conversion();
                }
           }
    
            else if (target_scale == 2) 
    
                if (temperature >= 0) 
                { 
                    converted_temp = kelvin_to_fahrenheit(temperature);
                    printf("Converted temperature: %.2f°F\n", converted_temp);
                    categorize_temperature(converted_temp, target_scale);
                } 
                else 
                {
                    printf("Error: Kelvin cannot be negative.\n");
                    temperature_conversion();
                }
    } 
}
int main() 
{
    temperature_conversion();
    return 0;
}