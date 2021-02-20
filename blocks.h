//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
/*Icon*/  /*Command*/  /*Update Interval*/  /*Update Signal*/
{"PLAY:",R"(
  case $BUTTON in
    1) timeout 8 playerctl --player=spotifyd previous & ;;
    2) timeout 8 playerctl --player=spotifyd play-pause & ;;
    3) timeout 8 playerctl --player=spotifyd next & ;;
  esac
  # TODO spawn cmd on the fly to get the playing title
  # - save it to a cache file
  # - launch it on background and send a signal to update the block when finished
  # - compute the duration to end the music and launch a timer on background to update
  #   when the music is ending, so the title is synced
  # - launch bg process each time a button is clicked or it ticks
  # ( timeout 10 playerctl --player=spotifyd metadata --format "{{ title }}" )
  echo [spotify]
)", 60, 8},

{"BTC:", R"(curl -s https://www.mercadobitcoin.net/api/BTC/ticker/ | jq '.ticker.last' | LC_NUMERIC=pt_BR.UTF-8 xargs printf "[R$%'.2f]\n")", 60, 7},
{"GPU:", R"(nvidia-smi --query-gpu="utilization.gpu,temperature.gpu,memory.used,fan.speed" --format=csv,noheader | tr -d ',' | awk '{printf "[%02d%% %02d°C %d%s %02d%%]\n",$1,$3,$4,$5,$6}')", 2, 6},
{"CPU:", R"((cpu-percent; sensors-cached | awk '/CPU_FAN/{print $2} /CPU_TEMP/{print $2}' | tr -d '+°C') | xargs | awk '{printf "[%02d%% %02.0f°C %drmp]\n",$1,$3,$2}')", 2, 5},
{"FAN:", R"(sensors-cached | awk '/SYS_FAN/ {print $2}' | xargs printf "[%d %drpm]\n")", 3, 4},
{"TEMP:",R"(sensors-cached | awk '/_TEMP/ {print $2}' | tr -d '+°C' | xargs | awk '{printf "[%d %d %d %d°C]\n",$1,$2,$5,$6}')", 3, 3},
{"MEM:", R"(free -m | awk '/Mem:/ {free_pc=$4*100/$2; used=$2-$7; used_pc=used*100/$2; unit="MiB"; if(used>=1000) {used/=1024; unit="GiB"}; printf("[%02.f%% %.1f%s %02.f%%]\n",used_pc,used,unit,free_pc)}')", 3, 2},
{"", R"(
  function yad_calendar() {
    yad --calendar --title="Calendar [dwmblocks]" --fixed --mouse --skip-taskbar --no-buttons --sticky --on-top "$@" > /dev/null 2>&1 &
  }
  if [ -n "$BUTTON" ]; then
    case $BUTTON in
      1) xdotool search --name "Calendar \[dwmblocks\]" > /dev/null 2>&1 || yad_calendar --close-on-unfocus ;;
      *) yad_calendar
    esac
  fi
  date +'(%a) %b %d %Y %T %p'
)", 1, 1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
