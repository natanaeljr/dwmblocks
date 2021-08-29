//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
/*Icon*/  /*Command*/  /*Update Interval*/  /*Update Signal*/
{"📻",R"(SIGNAL=8 spotify-bar)", 60, 8},
{"💵ﴑ", R"(curl -s https://www.mercadobitcoin.net/api/BTC/ticker/ | jq '.ticker.last' | LC_NUMERIC=pt_BR.UTF-8 xargs printf "R$%'.2fn")", 60, 7},
{"🤖", R"(nvidia-smi --query-gpu="utilization.gpu,temperature.gpu,fan.speed" --format=csv,noheader | tr -d ',' | awk '{printf "%02d %02d糖 %02dn",$1,$3,$5,$6}')", 2, 6},
{"🧬", R"((cpu-percent; cpu-speed; sensors-cached | awk '/CPU_FAN/{print $2} /CPU_TEMP/{print $2}' | tr -d '+°C') | xargs | awk '{printf "%02d %.1fGHz %02d糖 %dn",$1,$2,$4,$3}')", 2, 5},
{"🧭", R"(sensors-cached | awk '/SYS_FAN/ {print $2}' | xargs printf "%d %dn")", 3, 4},
{"🔥",R"(sensors-cached | awk '/_TEMP/ {print $2}' | tr -d '+°C' | xargs | awk '{printf "%d %d %d %d糖n",$1,$2,$5,$6}')", 3, 3},
{"📟", R"(free -m | awk '/Mem:/ {free_pc=$4*100/$2; used=$2-$7; used_pc=used*100/$2; unit="MiB"; if(used>=1000) {used/=1024; unit="GiB"}; printf("%02.f " (unit=="GiB"?"%.1f":"%d") "%s %02.fn",used_pc,used,unit,free_pc)}')", 3, 2},
{"", R"(
  function yad_calendar() {
    GTK_THEME="Adwaita:dark" yad --calendar --title="Calendar [dwmblocks]" --fixed --mouse --skip-taskbar --no-buttons --sticky --on-top "$@" > /dev/null 2>&1 &
  }
  if [ -n "$BUTTON" ]; then
    case $BUTTON in
      1) xdotool search --name "Calendar \[dwmblocks\]" > /dev/null 2>&1 || yad_calendar --close-on-unfocus ;;
      *) yad_calendar
    esac
  fi
  TZ="Asia/Kolkata" date +'%R' | xargs printf "IST %s 📅 "
  date +'%b %d %a %T %p'
)", 1, 1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = '|';
