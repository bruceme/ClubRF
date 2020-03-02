# ClubRF &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [![Have questions? Join the chat](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/ClubRF/community?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

*Sailplane club oriented DIY proximity awareness system.*

## Features:
* Community based open-source. Pull requests friendly
* 2-way raw data bridge between 868/915 MHz radio band and Bluetooth / Wi-Fi 
* All focus is on a standalone, battery powered, compatible proximity awareness device for club-environments

## Protocol Supported

* Open Glider Network, P3I & FANET+  - Fully supported 
* FLARM Air v6 (LegacY) - Minimal on-board capability, requires additional software on the Android
* ADS-B 1099ES & 978 UAV - Requires additional hardware
* GDL90, 

## Software supported

* XCSoar - All versions, but special pull request required for FLARM support.
* LK8000 - All version, no additional FLARM support 
* PilotAware
* Skytraxx

## Build it yourself
It's really not hard.  And some board supplier have already installed a firmware version of SoftRF that can be upgraded to ClubRF

### The BOM
1. [TTGO T-Beam ESP32 board](https://www.amazon.com/s/ref=nb_sb_noss?url=search-alias%3Daps&field-keywords=TTGO+T-Beam+ESP32) (must be appropriate for your region 433/868/915mhz)
2. [Larger/better Antenna](https://www.amazon.com/s/ref=nb_sb_ss_c_1_7?url=search-alias%3Daps&field-keywords=868+mhz+antenna)
3. An 18650 LiPo Battery *source locally is best*

### The Build
4. [Simple Case](https://www.thingiverse.com/thing:3425494) *least material* 
5. [Build/Install the firmware](wiki/Firmware-update)

You can order it fully built and delivered here...

### Upgrade to "stand-alone"
Adds the ability to use the device without having to connect to software.

*To the above add;*

6. [8-bit WS2812 LED rings](https://www.ebay.com/sch/i.html?_from=R40&_trksid=m570.l1313&_nkw=8-bit+ws2812+led+ring+&_sacat=0&LH_TitleDesc=0&_osacat=0&_odkw=8-bit+led+ring)
7. [3x WS2812 LED array](https://www.ebay.com/sch/i.html?_from=R40&_trksid=m570.l1313&_nkw=ws2812+10x10+5050&_sacat=0&LH_TitleDesc=0&_osacat=0&_odkw=ws2812+10x10+led&LH_TitleDesc=0)
8. [Wire/solder per these instructions](wiki/build-stand-alone)

## Community sourced

This is based on another populare DIY proximity awareness project.  There's tons more great information on that reprository.  This project is focussed on Soaring Club solutions and commited to staying community sourced. 

## Documentation

* [Pilot Guide](wiki/Pilots-Guide)
* [Settings](wiki/Settings) 
* [Update](wiki/Firmware-update-(Web-method)) (Web method)
* [OGNTP](wiki/OGNTP-compatibility)
* [P3I Open (PilotAware)](wiki/PilotAware-compatibility)
* [FANET (Skytraxx)](wiki/FANET-compatibility)
* [Garmin GDL90 datalink](wiki/Garmin-GDL90-compatibility)
     * [SkyDemon](wiki/Garmin-GDL90-compatibility#skydemon)
     * [Avare](wiki/Garmin-GDL90-compatibility#avare)
     * [ForeFlight](wiki/Garmin-GDL90-compatibility#foreflight)
* [Integration with airborne (Stratux, PilotAware,...) and groundstation (FlightRadar24, FlightAware,...) ADS-B receivers](wiki/Integration-with-RTL%E2%80%90SDR-based-ADS%E2%80%90B-receivers)