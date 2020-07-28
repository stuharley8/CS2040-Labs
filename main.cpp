#include <iostream>

using namespace std;

void get_input_values(int nums[], int min, int max);
int calculate_axis_width(int num[], int size);
void draw_horizontal_axis(int axisWidth);
void label_horizontal_axis(int axisWidth);
void draw_count(int num, int value);

int main() {
    cout << "Enter #'s separates by spaces." << endl;
    cout << "The first number is the min." << endl;
    cout << "The second number is the max." << endl;
    cout << "The following numbers are the values." << endl;
    int min;
    cin >> min;
    int max;
    cin >> max;
    if(min > max) {
        cout << "Error: Min cannot be greater than max." << endl;
        return 0;
    }
    int size = max - min + 1;
    int nums[size] = { 0 };
    get_input_values(nums, min, max);
    for(int i=size-1; i>=0; i--) {
        draw_count(i+min, nums[i]);
    }
    int axisWidth = calculate_axis_width(nums, size);
    draw_horizontal_axis(axisWidth);
    label_horizontal_axis(axisWidth);
    return 0;
}

/**
 * @brief Takes the input values and puts them in the array
 * @param nums the array
 * @param min the minimum value of the array
 * @param max the maximum value of the array
 */
void get_input_values(int nums[], int min, int max) {
    int num;
    cin >> num;
    while ( cin ) {
        if(num < min || num > max) {
            cout << "Error: value " << num << " is out of range" << endl;
        }
        else {
            nums[num-min]++;
        }
        cin >> num;
    }
}

/**
 * @brief Calculates the width of the horizontal axis for the histogram
 * @param nums the array
 * @param size the size of the array
 * @return the width of the horizontal axis
 */
int calculate_axis_width(int nums[], int size) {
    int maxFreq = 0;
    for(int i=0; i<size; i++) {
        if(nums[i] > maxFreq) {
            maxFreq = nums[i];
        }
    }
    int axisWidth = (maxFreq+10)-(maxFreq%10);
    if(axisWidth%10==0) {
        axisWidth -= 10;
    }
    if(axisWidth < 10) {
        axisWidth = 10;
    }
    return axisWidth;
}

/**
 * @brief Draws the horizontal axis
 * @param axisWidth the width of the horizontal axis
 */
void draw_horizontal_axis(int axisWidth) {
    cout << "   " << flush; // aligns the first + with the vertical axis
    for(int i=0; i<axisWidth/10; i++) {
        cout << "+----+----" << flush;
    }
    cout << "+" << endl;
}

/**
 * @brief Labels the horizontal axis
 * @param axisWidth the width of the horizontal axis
 */
void label_horizontal_axis(int axisWidth) {
    cout << "   " << flush; // aligns the first label with the first +
    cout << "0    5    10" << flush;
    for(int i=1; i<axisWidth/10; i++) {
        cout << "   " << i*10+5 << "   " << (i+1)*10 << flush;
    }
    cout << "\n" << endl;
}

/**
 * @brief Draws a line of the histogram for a specified number and value
 * @param num the specified number
 * @param value the specified value
 */
void draw_count(int num, int value) {
    if(num < 10) {
        cout << " " << flush;
    }
    cout << num << " |" << flush;
    for(int i=0; i<value; i++) {
        cout << "#" << flush;
    }
    cout << endl;
}