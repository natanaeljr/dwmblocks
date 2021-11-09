//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
/*Icon*/  /*Command*/  /*Update Interval*/  /*Update Signal*/
{"",R"(SIGNAL=8 spotify-bar)", 60, 8},
{"ﴑ", R"(curl -s https://www.mercadobitcoin.net/api/BTC/ticker/ | jq '.ticker.last' | LC_NUMERIC=pt_BR.UTF-8 xargs printf "R$%'.2f\n")", 60, 7},
//{"", R"(nvidia-smi --query-gpu="utilization.gpu,temperature.gpu,fan.speed" --format=csv,noheader | tr -d ',' | awk '{printf "^b#98c379^^c#1e222a^%02d%%^d^ ^c#98c379^%02d糖^d^\n",$1,$3}')", 3, 6},
{"", R"((cpu-percent; cpu-speed; sensors-cached | awk '/CPU_FAN/{print $2} /CPU_TEMP/{print $2}' | tr -d '+°C') | xargs | awk '{printf "^c#e06c75^%02d%% ^b#e06c75^^c#1e222a^%.1fGHz^d^^c#e06c75^ %02d糖 %d ^d^\n",$1,$2,$4,$3}')", 2, 5},
//{"", R"(sensors-cached | awk '/SYS_FAN/ {print $2}' | xargs printf "%d %dn")", 3, 4},
//{"",R"(sensors-cached | awk '/_TEMP/ {print $2}' | tr -d '+°C' | xargs | awk '{printf "%d %d %d %d糖\n",$1,$2,$5,$6}')", 3, 3},
{"", R"(free -m | awk '/Mem:/ {free_pc=$4*100/$2; used=$2-$7; used_pc=used*100/$2; unit="M"; if(used>=1000) {used/=1024; unit="G"}; printf("^b#61afef^^c#1e222a^%02.f%%^d^ ^c#61afef^" (unit=="G"?"%.1f":"%d") "%s %02.f%%^d^\n",used_pc,used,unit,free_pc)}')", 3, 2},
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
  TZ="Asia/Kolkata" date +'%R' | xargs printf "IST %s "
  date +'^c#abb2bf^%b %d %a ^b#abb2bf^^c#1e222a^%T^d^ ^c#abb2bf^%p^d^ '
)", 1, 1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
