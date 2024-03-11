# gr-add_tag_module
It is a simple module to add a tag (to a 'Tagged File Sink' which will record) when button is pressed to a stream in C++ to make it sure it works as fast as possible.
Tested on GNU Radio Companion 3.10.7.0 (Python 3.10.12).
To build:
```
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
gnuradio-companion
```


To rebuild (in build folder):
```
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
gnuradio-companion
```
