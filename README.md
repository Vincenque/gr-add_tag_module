# gr-add_tag_module
It is a simple module to add a tag (to a 'Tagged File Sink' which will record) when button is pressed to a stream in C++ to make it sure it works as fast as possible.

If you want to make sure that data going to multiple 'Tagged File Sink's is being saved synchronically use only one 'Add Tag' and change number of ports. Every OutputSignal[n] = InputSignal[n] for n = {1, number of ports}.

Best to use with 'Modified Tagged Filk Sink', so you can change file name.

Tested on GNU Radio Companion 3.10.7.0 (Python 3.10.12).
To build and run test:
```
mkdir build 
cd build 
cmake .. 
make -j4 
sudo make install 
sudo ldconfig
gnuradio-companion ../examples/testTagModule.grc ../examples/testTagModuleWithModifiedTaggedFileSink.grc
```


To rebuild (in build folder) and run test:
```
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
gnuradio-companion ../examples/testTagModule.grc ../examples/testTagModuleWithModifiedTaggedFileSink.grc
```


