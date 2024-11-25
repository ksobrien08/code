#include <iostream>
#include "nlohmann/json.hpp"

// Define a struct to hold the value and isSet properties
struct SetValue {
    int value;
    bool isSet;
};

// Function to get the array
SetValue* getArray() {
    // Assuming you have a function to read JSON and return the array
    // For simplicity, let's assume it's a hardcoded array for now
    static SetValue array[300] = {};
    return array;
}

// Function to set the array
void setArray(SetValue* array, nlohmann::json json) {
    // Assuming you have a function to read JSON and set the array
    // For simplicity, let's assume it's a simple loop for now
    for (int i = 0; i < 300; i++) {
        array[i].value = json["set_values"][i];
        array[i].isSet = false; // Initialize isSet to false
    }
}

int main() {
    // Create a JSON object with set_values
    nlohmann::json json = {
        {"set_values", nlohmann::json::array()}
    };

    // Initialize the set_values array with some values
    for (int i = 0; i < 300; i++) {
        json["set_values"].push_back(i);
    }

    // Get the array
    SetValue* array = getArray();

    // Set the array using the JSON object
    setArray(array, json);

    // Print the array
    for (int i = 0; i < 300; i++) {
        std::cout << "Value: " << array[i].value << ", IsSet: " << array[i].isSet << std::endl;
    }

    return 0;
}
