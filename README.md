# TaskManager
A task manager written in C++ and some bash

***How to run***

1. Clone the repo (duh)


2. Run the bash script (Won't work in Powershell)

 ```./Task.sh```

You should see something like this (Likely way more proccesses)

```
$ ./Task.sh
Running ps aux
proc.txt created
Starting task manager

File found.

--------------------------------------------------------------------------------
User:
Process ID: 579
CPU usage: 568
Memory usage: 579
Timestamp: /usr/bin/bash
Duration: /usr/bin/bash
Command run: /usr/bin/bash
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
User:
Process ID: 568
CPU usage: 1
Memory usage: 568
Timestamp: /usr/bin/bash
Duration: /usr/bin/bash
Command run: /usr/bin/bash
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
User:
Process ID: 582
CPU usage: 579
Memory usage: 579
Timestamp: /usr/bin/ps
Duration: /usr/bin/ps
Command run: /usr/bin/ps
--------------------------------------------------------------------------------

Current time: Fri Apr 10 16:02:10 2026
```
