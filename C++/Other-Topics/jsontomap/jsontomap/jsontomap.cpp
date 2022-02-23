// jsontomap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

int main()
{
    std::string myText;
    std::string array;
    std::map<std::string, std::string> mapOfElement;
    std::vector<std::map<std::string, std::string>> vector;

    // Read from the text file
    std::ifstream MyReadFile("C:\\Programming\\table.json");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        array += myText;
    }

    
    // Close the file
    MyReadFile.close();
    array.erase(remove(array.begin(), array.end(), '['), array.end());
    array.erase(remove(array.begin(), array.end(), ']'), array.end());
    array.erase(remove(array.begin(), array.end(), ' '), array.end());
    array.erase(remove(array.begin(), array.end(), ','), array.end());
    int rowCount = std::count(array.begin(), array.end(), '{');
    int elementCount = std::count(array.begin(), array.end(), ':');
    array.erase(remove(array.begin(), array.end(), '{'), array.end());
    array.erase(remove(array.begin(), array.end(), '}'), array.end());
    array.erase(remove(array.begin(), array.end(), ':'), array.end());
    std::cout << array<< std::endl;
    array.erase(0, 1);
    int counter = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < elementCount/rowCount; j++) {   
            auto end = array.find('"');
            std::string key = array.substr(0, end);
            array.erase(0, end+1);
            //std::cout << array;
            end = array.find("\"\"");
            std::string value = array.substr(1, end-1);
            array.erase(0, end+2);
            if (i == rowCount - 1 && j == elementCount / rowCount - 1) {
                value.erase(remove(value.begin(), value.end(), '\"'), value.end());
            }
            mapOfElement.insert(std::pair<std::string, std::string>(key, value));
        }
        /*std::map<std::string, std::string>::iterator itr;
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = mapOfElement.begin(); itr != mapOfElement.end(); ++itr) {
            std::cout << '\t' << itr->first << '\t' << itr->second
                << '\n';
        }
        std::cout << std::endl;*/
        vector.push_back(mapOfElement);
        mapOfElement.clear();
   }
    for (int i = 0; i < vector.size(); i++) {
        std::map<std::string, std::string>::iterator itr;
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = vector.at(i).begin(); itr != vector.at(i).end(); ++itr) {
            std::cout << '\t' << itr->first << '\t' << itr->second
                << '\n';
        }
        std::cout << std::endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
