#!/bin/bash

rm proc.txt
rm newproc.txt

echo "Running ps aux"

ps aux > proc.txt

tr -s ' ' ',' < proc.txt > newproc.txt

echo "proc.txt created"

g++ Task.cpp -o Task

./Task