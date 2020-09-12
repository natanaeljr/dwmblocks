//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "cat ~/.notes-oneline",	                        60,		0},
	{"BAT: ", "acpi | awk '{print $4 $5}' | tr ',' ' '",	30,		0},
	{"CPU: ", "awk -f ~/.local/bin/cpuawk",	              2,		0},
	{"MEM: ", "free -h | awk '/Mem/ { print $3 }'",	      5,		0},
	{"", "date +'%a %b %d %Y %T %p'",			                1,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
