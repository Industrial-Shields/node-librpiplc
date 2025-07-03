#!/bin/bash



if ! dpkg -l | grep -q librpiplc && [ ! -f /usr/lib/librpiplc.so ] && [ ! -f /usr/local/lib/librpiplc.so ]; then
    echo "Error: The librpiplc package is either not installed or librpiplc.so is not present in either /usr/lib or /usr/local/lib."
    echo "Please install the package using 'sudo apt install librpiplc' and ensure the library is correctly installed."
    exit 1
fi
