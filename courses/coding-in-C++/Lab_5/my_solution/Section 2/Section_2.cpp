#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

// Template avoids code duplication.
// One function works for many data types instead of writing
// separate swap functions for int, double and std::string.
template <typename T>
void swapValues(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T, std::size_t N>
void printArray(const T (&arr)[N])
{
    std::cout << "[";

    for (std::size_t index = 0; index < N; ++index)
    {
        std::cout << arr[index];
        if (index < N - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

template <typename T, std::size_t N>
T weakestMeassurement(const T(&arr)[N])
{
    T weakest_temp = arr[0];

    for (int index = 1; index < N; ++index)
    {
        if (arr[index] < weakest_temp)
        {
            weakest_temp = arr[index];
        }
    }

    return weakest_temp;
}

template <typename Type1, typename Type2>
void printDroneData(const std::string& label1, const std::string& label2, 
                    const Type1& data1, const Type2& data2)
{
    std::cout << label1 << ": " << data1 
              << " | " 
              << label2 << ": " << data2 
              << std::endl;
}

void printVector(std::vector<int>& data)
{
    for (int value : data)
    {
        std::cout << value << " ";
    }

    std::cout << std::endl;
}

int main()
{
    // =====================================================
    // Task 1: Generic Swap Function
    // =====================================================

    int int_a = 3;
    int int_b = 4;
    std::cout << "a: " << int_a << " b: " << int_b << std::endl;
    swapValues(int_a, int_b);
    std::cout << "a: " << int_a << " b: " << int_b << std::endl;

    double double_a = 3.0;
    double double_b = 4.0;
    std::cout << "\na: " << double_a << " b: " << double_b << std::endl;
    swapValues(double_a, double_b);
    std::cout << "a: " << double_a << " b: " << double_b << std::endl;

    std::string string_a = "Hello";
    std::string string_b = "Daniel";
    std::cout << "\na: " << string_a << " b: " << string_b << std::endl;
    swapValues(string_a, string_b);
    std::cout << "a: " << string_a << " b: " << string_b << std::endl;


    // =====================================================
    // Task 2: Generic Array Printer
    // =====================================================

    int numbers[4] = {6, 2, 8, 1};
    double doubles[6] = {6.1, 4.2, 2.3, 9.0, 12.9, 1.9};
    char chars[4] = {'A', 'B', 'C', 'D'};

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "\n";

    printArray(numbers);
    printArray(doubles);
    printArray(chars);


    // =====================================================
    // Task 3: Weakest Signal Detector
    // =====================================================

    std::cout << "\nweakest number in numbers: "
              << weakestMeassurement(numbers)
              << std::endl;

    std::cout << "weakest double in doubles: "
              << weakestMeassurement(doubles)
              << std::endl;


    // =====================================================
    // Task 4: Telemetry Tag Composer
    // =====================================================

    printDroneData("Channel",
                   "Priority",
                   std::string("motor_temp"),
                   2);


    // =====================================================
    // Task 6: Sort and Inspect Recorded Samples
    // =====================================================

    std::vector<int> recordedData =
    {
        42, 17, 42, 5, 99, 17, 63, 12
    };

    // Print original data
    printVector(recordedData);

    // Sort data
    std::sort(recordedData.begin(), recordedData.end());

    // Print sorted data
    printVector(recordedData);

    // Search for value 63
    auto it = std::find(recordedData.begin(),
                        recordedData.end(),
                        63);

    if (it != recordedData.end())
    {
        auto position = it - recordedData.begin();

        std::cout << "Number Found at Position: "
                  << position << std::endl;

        std::cout << "Number: "
                  << recordedData[position]
                  << std::endl;
    }
    else
    {
        std::cout << "Number not found..." 
                  << std::endl;
    }

// =====================================================
// Task 7: Noise Cleanup Pipeline
// =====================================================
    std::vector<int> sensorData = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    std::cout << "\nOriginal sensor data: ";
    printVector(sensorData);
    
    std::replace(sensorData.begin(), sensorData.end(), -1, 0);
    std::cout << "\nCorrected sensor data: ";
    printVector(sensorData);

    int occourence = std::count(sensorData.begin(), sensorData.end(), 8);
    std::cout << "\nValue 8 occures " << occourence << " times in the dataset.";

    std::reverse(sensorData.begin(), sensorData.end());
    std::cout << "\nReversed sensor data: ";
    printVector(sensorData);

    std::cout << std::endl;

// =====================================================
// Task 8: Manual Iterator Walk
// =====================================================

    for (auto it = sensorData.begin();
        it != sensorData.end();
        ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
        
    return 0;
}