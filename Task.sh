#!/bin/bash

echo "Running ps aux"

ps aux > proc.txt

tr -s ' ' ',' < proc.txt > newproc.txt

echo "proc.txt created"