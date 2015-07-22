# TBrowser

Just start TBrowser.

ROOT (data analysis framework made by CERN) is needed.


## Compling

Go to "src" directory and

	make


You can install this application with following:

	make install

If you want to specify installed directory, edit Makefile:

	INSTALL_DIR = path/to/somewhere


## Option

Following options are available:

 option      | detail 
 ----------- | ------------------------------------------------- 
 option or o | You can check all options. 
 file        | You can open onyl 1 file.
 dir         | You can specify a directory which you want to see.
 height      | You can set a hight of a window in px. 
 width       | You can set a width of a window in px. 

*A file option has priority to a dir option.*

### Example

	./tb --dir="./data" --height="600" --width="800"

