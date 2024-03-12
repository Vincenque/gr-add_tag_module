#!/bin/sh
cd build
sudo make uninstall
cd ..
sudo rm -r build
mkdir build 
cd build 
cmake .. 
make -j4 
sudo make install 
sudo ldconfig
echo '
import os
try:
    from add_tag_module.add_tag_module_python import *
except ModuleNotFoundError:
    pass
' | sudo tee /usr/local/lib/python3.10/dist-packages/gnuradio/add_tag_module/__init__.py > /dev/null
gnuradio-companion ../examples/testTagModule.grc
