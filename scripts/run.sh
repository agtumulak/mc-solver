#!/bin/bash

PROJECT_DIR='/Users/atumulak/Developer/mc-solver'

cd $PROJECT_DIR
make
bin/mc-solver > $1
python scripts/process.py $1