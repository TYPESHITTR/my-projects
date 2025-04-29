#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert the input to lowercase
void to_lowercase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to get the value of a color band
int get_band_value(char color[]) {
    to_lowercase(color); // convert input to lower case
    if (strcmp(color, "black") == 0) return 0;
    if (strcmp(color, "brown") == 0) return 1;
    if (strcmp(color, "red") == 0) return 2;
    if (strcmp(color, "orange") == 0) return 3;
    if (strcmp(color, "yellow") == 0) return 4;
    if (strcmp(color, "green") == 0) return 5;
    if (strcmp(color, "blue") == 0) return 6;
    if (strcmp(color, "violet") == 0) return 7;
    if (strcmp(color, "gray") == 0) return 8;
    if (strcmp(color, "white") == 0) return 9;
    return -1;
}

// Function to get multiplier value
int get_multiplier(char color[]) {
    to_lowercase(color); // convert input to lower case
    if (strcmp(color, "black") == 0) return 1;
    if (strcmp(color, "brown") == 0) return 10;
    if (strcmp(color, "red") == 0) return 100;
    if (strcmp(color, "orange") == 0) return 1000;
    if (strcmp(color, "yellow") == 0) return 10000;
    if (strcmp(color, "green") == 0) return 100000;
    if (strcmp(color, "blue") == 0) return 1000000;
    if (strcmp(color, "violet") == 0) return 10000000;
    if (strcmp(color, "gray") == 0) return 100000000;
    if (strcmp(color, "white") == 0) return 1000000000;
    return -1;
}

// Function to get tolerance value
float get_tolerance(char color[]) {
    to_lowercase(color); // convert input to lower case
    if (strcmp(color, "violet") == 0) return 0.1;
    if (strcmp(color, "gray") == 0) return 0.05;
    if (strcmp(color, "gold") == 0) return 5.0;
    if (strcmp(color, "silver") == 0) return 10.0;
    return -1;
}

// Function to validate input using a while loop
  int prompt_for_band(char band_name[], char band_color[]) {
    int value;
    while (1) {
        printf("Enter %s band color: ", band_name);
        scanf("%s", band_color);
        value = get_band_value(band_color);
        if (value != -1) break; // Exit loop if valid color is entered
        printf("Invalid color entered. Please try again.\n");
    }
    return value;
}


int main() {
    char band1[10], band2[10], multiplier_band[10], tolerance_band[10];
    int value1, value2, multiplier;
    float tolerance;

    // Prompt for valid colors using the while loop
    value1 = prompt_for_band("first", band1);
    value2 = prompt_for_band("second", band2);

    // Multiplier band
    while (1) {
        printf("Enter multiplier band color: ");
        scanf("%s", multiplier_band);
        multiplier = get_multiplier(multiplier_band);
        if (multiplier != -1) break; // Valid color check
        printf("Invalid multiplier entered. Re-enter color.");
    }
    // Tolerance band
while (1) {
    printf("Enter tolerance band color: ");
    scanf("%s", tolerance_band);
    tolerance = get_tolerance(tolerance_band);
    if (tolerance != -1) break; // Valid color check
    printf("Invalid tolerance entered. Please try again.\n");
}

    // Calculate resistance
    int resistance = (value1 * 10 + value2) * multiplier;

    printf("Resistance: %d ohms ± %.2f%%\n", resistance, tolerance);
    return 0;
}
