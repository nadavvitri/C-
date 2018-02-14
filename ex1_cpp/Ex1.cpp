#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include "ArenstorfPoint.h"
#include "Arenstorf.h"

#define BAD_ARG "Error: Bad argument format!\n"
#define TOO_MANY_ARG "Error: Too many argument!\n"
#define OPEN_FAILED "Error: Failed to open files!\n"
#define CLOSE_FAILED "Error: Failed to close files!\n"
const int ARG_INDEX_ONE = 1;
const int ARG_INDEX_TWO = 2;
const int FIRST_LINE = 1;
const int SECOND_LINE = 2;
const int LINE_MAX_SIZE = 400;
const int ARG_ERROR = 1;
const int IO_ERROR = 2;
const int BAD_GIVEN_PARAMS = 3;
const int SUCCESS = 0;

/**
 * Read the input file and gets the parameters to compute Arenstorf Orbit
 * @param inputFile  file with the information.
 * @param outputFile output file to write the result.
 * @return 0 if the function success, else non-zero number that represent the problem
 */
int inputFromFile(FILE *inputFile, std::ofstream& outputFile)
{
    long double x = 0, y = 0, vx = 0, vy = 0, t = 0;
    unsigned int n = 0, m = 0;
    char comma1 = '\0', comma2 = '\0', comma3 = '\0', breakLine = '\0';
    char line[LINE_MAX_SIZE];
    int numberOfLines = 0;  // counter for number of lines in the file
    bool validFile = true;
    while (feof(inputFile) == 0)
    {
        fgets(line, LINE_MAX_SIZE, inputFile);
        std::stringstream ss(line);
        numberOfLines++;  // update number of lines counter
        if (numberOfLines == FIRST_LINE)  // we in the first line
        {
            ss >> x >> comma1 >> y >> comma2 >> vx >> comma3 >> vy >> breakLine;
            if (comma1 != ',' or comma2 != ',' or comma3 != ',' or breakLine != '\0')
            {
                validFile = false;
                break;
            }
            ss.clear();
        }
        else if (numberOfLines == SECOND_LINE)  // we in the second line
        {
            ss >> t >> comma1 >> n >> comma2 >> m >> breakLine;
            if (comma1 != ',' or comma2 != ',' or breakLine != '\0')
            {
                validFile = false;
                break;
            }
            ss.clear();
        }
        if (numberOfLines == 3 or !validFile) // if there is more then 2 lines or bad parameters
        {
            validFile = false;
            break;
        }
    }
    if (!validFile)  // if there is problem with the format of the input file exit
    {
        std::cerr << BAD_ARG;
        return BAD_GIVEN_PARAMS;
    }
    ArenstorfPoint point(x, y, vx, vy);  // init Arenstorf point
    long double dt = (double)t / n;
    return Arenstorf::computeArenstorf(point, n, m, dt, outputFile);
}

/**
 * Check if the input is long double type
 * @param temp input from user
 */
void checkInput(std::string &temp, bool &flag)
{
    std::regex regex_pattern("-?[0-9]+(\\.[0-9]+)?");
    std::smatch match;
    if (!std::regex_match(temp, match, regex_pattern))
    {
        flag = false;
        return;
    }
    flag = true;
}

/**
 * Check if the input from user is type of unsgined int
 * @param temp input from user
 */
void checkSteps(std::string &temp, bool &flag)
{
    std::regex regex_pattern("^\\d+$");
    std::smatch match;
    if (!std::regex_match(temp, match, regex_pattern))
    {
        flag = false;
        return;
    }
    flag = true;
}


/**
 * gets the parameters to compute Arenstorf Orbit from user.
 * @param outputFile output file to write the result.
 * @return 0 if the function success, else non-zero number that represent the problem
 */
int inputFromUser(std::ofstream& outputFile)
{
    int flag = SUCCESS;
    bool flag1, flag2, flag3, flag4, flag5, flag6, flag7; // flags for every input from user
    std::string temp;
    long double x = 0, y = 0, vx = 0, vy = 0, t = 0;
    unsigned int n = 0, m = 0;
    std::cout << "Enter initial pos x:\n";
    getline(std::cin, temp);
    checkInput(temp, flag1);
    if (flag1)
    {
        std::stringstream(temp) >> x;
    }
    std::cout << "Enter initial pos y:\n";
    getline(std::cin, temp);
    checkInput(temp, flag2);
    if (flag2)
    {
        std::stringstream(temp) >> y;
    }
    std::cout << "Enter initial vel x:\n";
    getline(std::cin, temp);
    checkInput(temp, flag3);
    if (flag3)
    {
        std::stringstream(temp) >> vx;
    }
    std::cout << "Enter initial vel y:\n";
    getline(std::cin, temp);
    checkInput(temp, flag4);
    if (flag4)
    {
        std::stringstream(temp) >> vy;
    }
    std::cout << "Enter total time T:\n";
    getline(std::cin, temp);
    checkInput(temp, flag5);
    if (flag5)
    {
        std::stringstream(temp) >> t;
    }
    std::cout << "Enter num of steps:\n";
    getline(std::cin, temp);
    checkSteps(temp, flag6);
    if (flag6)
    {
        std::stringstream(temp) >> n;
    }
    std::cout << "Enter num of steps to save:\n";
    getline(std::cin, temp);
    checkSteps(temp, flag7);
    if (flag7)
    {
        std::stringstream(temp) >> m;
    }
    if (n < m or t < 0 or !flag1 or !flag2 or !flag3 or !flag4 or !flag5 or !flag6 or !flag7)
    {
        std::cerr << BAD_ARG;
        flag = ARG_ERROR;
    }
    else
    {
        ArenstorfPoint point(x, y, vx, vy);  // init Arenstorf point
        long double dt = (double)t / n;
        return Arenstorf::computeArenstorf(point, n, m, dt, outputFile);
    }
    return flag;
}


/**
 * This function check if closing input file has succeed
 * @param inputFile include practice examples and data to tag
 * @return non-zero number if failed
 */
int fileCheckClosing(FILE *inputFile)
{
    if (fclose(inputFile) == EOF)
    {
        std::cerr << CLOSE_FAILED;
        return IO_ERROR;
    }
    return SUCCESS;
}

/**
 * This function check if opened input file has succeed
 * @param inputFile include practice examples and data to tag
 * @return non-zero number if failed
 */
int fileCheckOpening(FILE *inputFile)
{
    if (inputFile == nullptr)
    {
        std::cerr << OPEN_FAILED;
        return IO_ERROR;
    }
    return SUCCESS;
}

/**
 * This function check if opened output file as stream has succeed
 * @param outputFile include practice examples and data to tag
 * @return non-zero number if failed
 */
int checkOutputFileOpen(std::ofstream& outputFile)
{
    if (!outputFile.is_open())
    {
        std::cerr << OPEN_FAILED;
        return IO_ERROR;
    }
    return SUCCESS;
}


/**
 * this is the main function that run the program. there is 2 different ways to get the
 * parameters to calculate the Arenstorf orbit:
 * 1. Get the parameters from the user keyboard   2. get the parameters from file.
 * @param argc - number of the program argument.
 * @param argv - if we got the parameters from the user keyboard the first argument is the output
 * file for the results. if we got the parameters from file so the first argument is the file with
 * the parameters and the second argument for the result.
 * @return 0 if the function success, else non-zero number that represent the problem
 */
int main(int argc, char* argv[])
{
    int flag = SUCCESS;
    if (argc == 2)   // we getting the parameters from the user
    {
        std::ofstream outputFile (argv[ARG_INDEX_ONE]);
        flag = checkOutputFileOpen(outputFile); // check output file opening
        if (flag == SUCCESS)
        {
            flag = inputFromUser(outputFile);
        }
        // close the file
        outputFile.close();
    }
    else if (argc == 3)  // we getting the parameters from file
    {
        FILE* inputFile = fopen(argv[ARG_INDEX_ONE], "r");
        flag = fileCheckOpening(inputFile);  // check input file file opening
        if (flag != SUCCESS)
        {
            return flag;
        }
        std::ofstream outputFile (argv[ARG_INDEX_TWO]);
        flag = checkOutputFileOpen(outputFile);  // check output file opening
        if (flag == SUCCESS)
        {
            flag = inputFromFile(inputFile, outputFile);
        }
        // close the files
        outputFile.close();
        flag = fileCheckClosing(inputFile);

    }
    else  // too many arguments
    {
        std::cerr << TOO_MANY_ARG;
        return ARG_ERROR;
    }
    return flag;
}