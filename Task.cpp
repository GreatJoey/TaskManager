#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void print(string user, int pid, double cpu, double mem, string timestamp, string duration, string command)
{
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "User: " << user << endl;
    cout << "Process ID: " << pid << endl;
    cout << "CPU usage: " << cpu << endl;
    cout << "Memory usage: " << mem << endl;
    cout << "Timestamp: " << timestamp << endl;
    cout << "Duration: " << duration << endl;
    cout << "Command run: " << command << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
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
    string timestamp;
    string duration;
    string command;

    string garb1;
    string garb2;
    string garb3;
    string garb4;

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

        // get the PID
        location = line.find(',');
        pid = stoi(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        // get the cpu usage
        location = line.find(',');
        cpu = stod(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        // get the memory usage
        location = line.find(',');
        mem = stod(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        // Garbage stuff we dont care about
        location = line.find(',');
        garb1 = line.substr(0, location);
        line = line.substr(location + 1, line.length());
        location = line.find(',');
        garb2 = line.substr(0, location);
        line = line.substr(location + 1, line.length());
        location = line.find(',');
        garb3 = line.substr(0, location);
        line = line.substr(location + 1, line.length());
        location = line.find(',');
        garb4 = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        // get the timestamp
        location = line.find(',');
        timestamp = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        // get the duration
        location = line.find(',');
        duration = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        //get the command run
        location = line.find(',');
        command = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        print(user, pid, cpu, mem, timestamp, duration, command);

        cout << endl;
    }
}

int main()
{
    string filepath = "newproc.txt";
    cout << "Starting task manager" << endl;
    cout << endl;

    open_file(filepath);

    // add something here to print current date and time

    return 0;
}