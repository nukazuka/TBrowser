# TBrowser

[日本語版はこちら](README.ja.md)

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

	./tb --dir=./data --height=600 --width=800

### Canvas Style

A default style was introduced.
This style is based on "Modern" style and I changed

#### Pad

Gray grids (kGray)  are drawn.
Ticks are drawn in all axis.
A result of fitting is displayed.

#### HISTGRAM

A line color is changed into kBlack.
A line width is bolder.
A y axis begins from 0(I did not check it).

#### GRAPH

A style of marker is changed from 1(dot, for scatter plot) into 6(begger than 1 but still small)
A sytle 1 is too small for graph which has few points.
But with styles except 1, it may take longer time to draw scatter plot.
If you don't like this option, please edit by yourself.

#### DATE DISPLAY

A date is printed on the left and bottom of a canvas.
Its color is gray(kGray+1).

## Recomendation

I recommend to add following statement into .bashrc or .bash_profile.

	function tb { ~/bin/tb $@  & }

So you don't need to type "&" to run this app in background!
Note that "~/bin/" must be same as INSTALL_DIR in makefile.
