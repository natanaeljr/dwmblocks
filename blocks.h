//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
/*Icon*/  /*Command*/  /*Update Interval*/  /*Update Signal*/
{"BTC:", R"(curl -s https://www.mercadobitcoin.net/api/BTC/ticker/ | jq '.ticker.last' | LC_NUMERIC=pt_BR.UTF-8 xargs printf "[R$%'.2f]\n")", 60, 7},
{"GPU:", R"(nvidia-smi --query-gpu="utilization.gpu,temperature.gpu,memory.used,fan.speed" --format=csv,noheader | tr -d ',' | awk '{printf "[%02d%% %02d°C %d%s %02d%%]\n",$1,$3,$4,$5,$6}')", 2, 6},
{"CPU:", R"((cpu-percent; sensors-cached | awk '/CPU_FAN/{print $2} /CPU_TEMP/{print $2}' | tr -d '+°C') | xargs | awk '{printf "[%02d%% %02.0f°C %drmp]\n",$1,$3,$2}')", 2, 5},
{"FAN:", R"(sensors-cached | awk '/SYS_FAN/ {print $2}' | xargs printf "[%d %drpm]\n")", 3, 4},
{"TEMP:",R"(sensors-cached | awk '/_TEMP/ {print $2}' | tr -d '+°C' | xargs | awk '{printf "[%d %d %d %d°C]\n",$1,$2,$5,$6}')", 3, 3},
{"MEM:", R"(free -m | awk '/Mem:/ {used=$2-$7; perc=used*100/$2; unit="MiB"; if(used>=1000) {used/=1024; unit="GiB"}; printf("[%02.f%% %.1f%s]\n",perc,used,unit)}')", 3, 2},
{"", R"(
  if [ -n "$BUTTON" ]; then
    # Uncomment to allow only one instance of the calender
    # xdotool search --name "Calendar \[dwmblocks\]" > /dev/null 2>&1 || \
      ( yad --calendar --title="Calendar [dwmblocks]" --fixed --mouse --skip-taskbar --no-buttons --sticky --on-top > /dev/null 2>&1 & )
  fi
  date +'(%a) %b %d %Y %T %p'
)", 1, 1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
