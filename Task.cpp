#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int loc(int location, string line)
{
    int i = 0;
    for (i=0; i<100; i++){
        if(line.substr(i) != " "){
            location = stoi(line.substr(i));
            break;
        }
    }

    return location;
}

double locd(int location, string line)
{
    int i = 0;
    for(i=0; i<10; i++){
        if(line.substr(i) == "1" || line.substr(i) == "2" || line.substr(i) == "3" || line.substr(i) == "4"){
            for(int j=0; j<10; j++){
                if(line.substr(j) == " "){
                    location = stod(line.substr(j));
                }
            }
        }
    }
    return location;
}

int setloc(int location, string line) /* The issue is its only skipping over one space */
{
    int i = 0;
    for(i=0; i<5;i++){
        if(line.substr(i) != " "){
            location = i;
            cout << i << endl;
            break;
        }
    }
    return location;
}

void open_file(string filepath)
{
    ifstream myfile;
    string line = "";
    int location = 0;
    string user;
    int pid;
    double cpu;
    double mem;

    myfile.open(filepath);
    if(myfile.is_open()){
        cout << "File found." << endl;
    } else {
        cout << "Couldn't find file. " << endl;
    }
    cout << endl;
    getline(myfile,line); // skips over the first line


    while (getline(myfile, line)){
        // get the user
        location = line.find(',');
        user = line.substr(0, location);
        line = line.substr(location + 1, line.length());
        cout << "User: " << user << endl;

        // get the PID
        location = line.find(',');
        pid = stoi(line.substr(0, location));
        line = line.substr(location + 1, line.length());
        cout << "PID: " << pid << endl;

        // get the cpu usage
        location = line.find(',');
        cpu = stod(line.substr(0, location));
        line = line.substr(location + 1, line.length());
        cout << "CPU Usage: " << cpu << endl;

        // get the memory usage
        location = line.find(',');
        mem = stod(line.substr(0, location));
        line = line.substr(location + 1, line.length());
        cout << "Memory Usage: " << mem << endl; 


        cout << endl;
    }
}

int main()
{
    string filepath = "newproc.txt";
    cout << "Starting task manager" << endl;
    cout << endl;

    open_file(filepath);

    return 0;
}