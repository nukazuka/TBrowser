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

	./tb --dir=./data --height=600 --width=800

### Canvas Style

A default style was introduced.
This style is based on "Modern" style and I changed

**DATE DISPLAY**

SetOptDate(kTRUE)
: prints date.

GetAttDate()->SetTextColor(kGray+1)
: changes text color of the date into kGray+1.

SetDateX(0.005),SetDateY(0.005)
: change a position of date lefter and lower.

**Pad**

SetOptFit(kTRUE)
: prints a result of fitting(maybe).

SetPadGridX(kTRUE),SetPadGridY(kTRUE)
: print girds.

SetGridColor(kGray)
: changes color of grid into kGray.

SetPadTickX(kTRUE), SetPadTickY(kTRUE)
: print ticks.

**HISTGRAM**
SetHistLineColor(kBlack)
: changes line color of histogram into kBlack.

SetHistLineWidth(2)
: changes line width of histogram into bolder.

SetHistMinimumZero(kTRUE)
: make yaxis begin from 0( I don't check it.).

**GRAPH**

SetMarkerStyle(6)
: changes marker from 1(dot, for scatter plot) into 6(begger than 1 but still small)
  A sytle 1 is too small for graph which has few points.
  But with styles except 1, it may take longer time to draw scatter plot.
  If you don't like this option, please edit by yourself.


## Recomendation

I recommend to add following statement into .bashrc or .bash_profile.
	function tb { ~/bin/tb $@  & }

So you don't need to type "&" to run this app in background!
Note that "~/bin/" must be same as INSTALL_DIR in makefile.
