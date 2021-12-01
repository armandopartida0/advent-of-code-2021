/**
 * @file main.cpp Day 1 Solution
 * @author Armando Partida-Sanabia
 * @brief Sonar Sweep
 * @date 2021-12-01
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * @brief Calculates number of measurements that are larger
 * than the previous measurement
 * 
 * @param data Measurements to analyze
 * @return int Number of increases
 */
int numOfIncreases(vector<int> &data)
{
    // Find number of increases
    int numIncreases = 0;
    int oldMeasure = data.at(0);
    for(int i = 1; i < data.size(); ++i)
    {
        if(oldMeasure < data.at(i))
        {
            numIncreases++;
        }
        
        oldMeasure = data.at(i);
    }

    return numIncreases;
}

/**
 * @brief Calculates number of increases based on sums of
 * three-measurement sliding window
 * 
 * @param data Measurements to analyze
 * @return int Number of increases
 */
int partTwo(vector<int> &data)
{
    // Find number of increases
    int numIncreases = 0;
    int oldWindow = data.at(0) + data.at(1) + data.at(2);
    for(int i = 1; (i < data.size()) && ((i + 2) < data.size()); i++)
    {
        int window = data.at(i) + data.at(i+1) + data.at(i+2);
        if(oldWindow < window)
        {
            numIncreases++;
        }
        
        oldWindow = window;
    }

    return numIncreases;
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "usage: main <input-file-name>\n";
        exit(1);
    }

    // Get input data
    vector<int> inputData{};
    string line{};
    ifstream infile(argv[1]);

    if(infile.is_open())
    {
        while(getline(infile, line))
        {
            inputData.push_back(stoi(line));
        }

        infile.close();
    }

    int result1 = numOfIncreases(inputData);
    int result2 = partTwo(inputData);

    // Print result
    cout << "Number of increases (Part 1): " << result1 << '\n';
    cout << "Number of increases (Part 2): " << result2 << '\n';

    return 0;
}