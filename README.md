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

Some options are available:

dir
:   You can specify a directory which you want to see.

height
:   You can set a hight of a window in px.

width
:   You can set a width of a window in px.

option
:   You can check all options.


### Example

	./tb --dir="./data" --height="600" --width="800"

