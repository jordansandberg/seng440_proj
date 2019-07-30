#!/bin/bash

./$1 < testinput.txt > output.txt
diff output.txt expected.txt
