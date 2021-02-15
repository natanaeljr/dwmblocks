//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
/*Icon*/  /*Command*/  /*Update Interval*/  /*Update Signal*/
{"", R"(cat ~/.notes-oneline)",	60, 0},
{"BTC:", R"(curl -s https://www.mercadobitcoin.net/api/BTC/ticker/ | jq '.ticker.last' | LC_NUMERIC=pt_BR.UTF-8 xargs printf "[R$%'.2f]\n")", 30, 0},
{"FAN:", R"(\
  sensors-cached | \
  awk '/FAN/ {print $2}' | \
  xargs printf "[%d %d %d rpm]\n")",
  3, 0},
{"GPU:", R"(nvidia-smi --query-gpu="utilization.gpu,temperature.gpu,memory.used,fan.speed" --format=csv,noheader | tr -d ',' | awk '{printf "[%02d%% %02d°C %d%s %02d%%]\n", $1, $3, $4, $5, $6}')", 2, 0},
{"CPU:", R"((cpu-percent; sensors-cached | awk '/CPU:/ {printf $2}' | tr -d '+°C') | xargs printf "[%02d%% %02.0f°C]\n")", 2, 0},
{"MEM:", R"(free -m | awk '/Mem:/ {used=$2-$7; unit="MiB"; if(used>=1000) {used/=1024; unit="GiB"}; printf("[%.1f%s]\n",used,unit)}')", 3, 0},
{"", R"(date +'%a %b %d %Y %T %p')", 1, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
