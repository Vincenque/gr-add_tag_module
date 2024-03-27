# gr-add_tag_module
It is a simple module to add a tag (to a 'Tagged File Sink' which will record) when button is pressed to a stream in C++ to make it sure it works as fast as possible.

If you want to make sure that data going to multiple 'Tagged File Sink's is being saved synchronically use only one 'Add Tag' and change number of ports. Every OutputSignal[n] = InputSignal[n] for n = {1, number of ports}.

Best to use with 'Modified Tagged Filk Sink' (https://github.com/Vincenque/gr-modified_tagged_file_sink/blob/main/lib/modified_tagged_file_sink_impl.cc), so you can change file name.

If 'number_of_samples_to_record' is equal to 0 file will be recorded until you hold button. If value is more than 0 you should just push button and then file will be recorded automatically.

Tested on GNU Radio Companion 3.10.7.0 (Python 3.10.12).
To build and run test in terminal:
```
sh rebuild.sh
```
or also in terminal:
```
mkdir build 
cd build 
cmake .. 
make -j4 
sudo make install 
sudo ldconfig
gnuradio-companion ../examples/testTagModule.grc ../examples/testTagModuleWithModifiedTaggedFileSink.grc
```

To rebuild and run test:
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


