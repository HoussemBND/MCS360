#include <iostream>  
#include <sstream>  
#include <fstream>  

using namespace std;


/*array_search function, loops through the arrays
 * to find the matching value of the user*/
int array_search(int stopid[], int lower, int upper, int stopid_search) {
    if (lower > upper)
        return -1;
    int mid = (lower + upper) / 2;
    if (stopid[mid] == stopid_search)
        return mid;
    else if (stopid_search > stopid[mid])  // search in the upper half of the array
        return array_search(stopid, mid + 1, upper, stopid_search);
    else
        return array_search(stopid, lower, mid - 1, stopid_search); // search in the lower half of the array
}


int main() {
// The main function opens the text file and counts the number of lines inside the file
    ifstream myfile;
    myfile.open("stops.txt");



    int linecount = 0;
    string line;           // This string holds the line while reading it


    std::getline(myfile, line); // This line reads the first line, and since it's a heading we skip it

    std::getline(myfile, line);

    while (myfile) {//This while loop iterates through the file to read all the lines
        ++linecount; //linecount increases after reading each line
        std::getline(myfile, line);
    }
    cout<< "Opening stops.txt..."<< "Counted " <<linecount<< " stops " << endl;
    // Go to the beginning of file
    myfile.clear();                   // clearing the offset
    myfile.seekg(0, ios::beg);       // moving file stream back to the beginning




    int *stopid = new int[linecount];// This array stores stop id numbers

    string *stop_name = new string[linecount];// This array stores stop names

    std::getline(myfile, line);

    std::getline(myfile, line);
    int indx = 0;
    while (myfile) {

        istringstream iss(line);  // istringstream is used to parse the comma separated values

        string arr1, arr2, arr3;

        std::getline(iss, arr1, ',');  // arr1 stores values before the first comma
        std::getline(iss, arr2, ',');  // arr2 stores values between first and second comma
        std::getline(iss, arr3, ',');  // arr2 stores values between second and third comma

        stopid[indx] = std::stoi(arr1);  // convert int to str using stoi
        stop_name[indx] = arr3;

        indx++;
        std::getline(myfile, line);
    }

    // The following while loop interacts with the user
    int idnum;
    cout << "Enter a stop id (0 to stop) : ";
    cin >> idnum;


    while (idnum != 0) {
        // validity check

        int arr_index = array_search(stopid, 0, linecount - 1, idnum);
        if (arr_index == -1) {
            cout << "There is no stop with id " << idnum << endl;
        }
        else {
            cout << "Stop " <<idnum << " has name \"" << stop_name[arr_index] << endl;
        }

        cout << "Give a stop id (0 to stop): ";
        cin >>idnum;

    }

    myfile.close();

    delete [] stopid;
    delete [] stop_name;
    return 0;
}