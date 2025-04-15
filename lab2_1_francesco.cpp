#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

 

// Fill in a function prototype named openFileIn
bool openFileIn(ifstream &fileInput, string name);

// Fill in a function prototype named openFileOut
bool openFileOut(ofstream &fileOutput, string name);
 

// Fill in a function prototype named copyFile
// Return type is boolean
// Parameters: ifstream and ofstream
bool copyFile(ifstream &fileInput, ofstream &fileOutput);

 

int main() {

    

    string fileNameI, fileNameO;

    ifstream inFile;

    ofstream outFile;

    

    cout << "Enter an input file name: ";

    cin >> fileNameI;

    cout << "Enter an output file name: ";

    cin >> fileNameO;

    

    // Fill  in code that calls openFileIn with appropriate parameters  (input file steam object and input file name. Include error validation statement
    if(!openFileIn(inFile, fileNameI))
    {
        cout << "Error opening input file" << endl;
        return 1;
    }
    // Fill  in code that calls openFileOut with appropriate parameters  (output file steam object and output file name. Include error validation statement
    if(!openFileOut(outFile, fileNameO))
    {
        cout << "Error opening output file" << endl;
        return 2;
    }
    // Fill in code that calls copyFile with appropriate parameters (input file stream object and output file stream object). Include error validation statement.
    if(!copyFile(inFile, outFile))
    {
        cout << "Error copying files" << endl;
        return 3;
    }

    return 0;

}

 

// Fill in function definition here for openFileIn.

// This function opens the input file and returns true or false when opening the file
bool openFileIn(ifstream &fileInput, string name)
{
    fileInput.open(name);
    return fileInput.is_open();
}

// Fill in function definition here for openFileOut.

// This function opens the output file and returns true or false when opening the file
bool openFileOut(ofstream &fileOutput, string name)
{
    fileOutput.open(name);
    return fileOutput.is_open();
}

 

// Fill in function definition here for copyFile.
// This function opens reads a character from input file and changes it to upper case and then writes to the output file until the end of input file.
// This function closes opened input file stream object and output file stream object. Include error validation statement.
bool copyFile(ifstream &fileInput, ofstream &fileOutput)
{
    // checks if the file is empty
    if(fileInput.peek() == EOF)
    {
        cout << "The input file is empty\n";
        return false;
    }

    char ch;
    while(fileInput.get(ch))
    {
        // converts the ch in uppercase
        fileOutput.put(toupper(ch));
        // checks if there is any issue with the output file
        if(fileOutput.fail())
        {
            fileInput.close();
            fileOutput.close();
            return false;
        }
    }
    // checks if there was a problem that interrupted the copy process not due to the end of the file
    if(fileInput.fail() && !fileInput.eof())
    {
        fileInput.close();
        fileOutput.close();
        return false;
    }
    // if everything went ok, will close the files and returns true
    fileInput.close();
    fileOutput.close();
    return true;
}
 

// Reference programs: 12-5 and 12-12