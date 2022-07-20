# Animated Weather

animated weather is a Qt/Qml project for RaspberryPi that is Interacting to html/css/js with Qtwebengine and its show the current real-time weather statistics by Graphical animation and [weatherapi.com](https://weatherapi.com) API


## Essentials



```bash
Qt creator 6
Raspberry pi 3 or Above with Buster Os and QtWebengine module
```

## Usage
###  RPI:
```rpi
#this is optional but can be effective on project running
$ sudo nano /boot/config.txt
#change raspberry pi arm_freq to 1400 and core_freq to 500 but keep it cool please
arm_freq=1400
core_freq=500

# Enable DRM VC4 driver with add this line at the bottom
dtoverlay=vc4-fkms-v3d

#change raspberry pi gpu memory to 256 at least
gpu_mem=256
```
###  QT Creator:
```qt
#At the Qt Creator you must to add some system environment variable to run the project with maximum 
rendering color option (grayscale and color depth problem can resolve with this method)
1. open the project with Qt Qreator
2. click on 'projects' button from left tabview (or just press the CTL+5)
3. find 'environment ->> details' option under 'RUN' option
4. click on add and set like these :
          variable              |           value
   QTWEBENGINE_DISABLE_SANDBOX  |             1
   QT_QPA_EGLFS_FORCE888        |             1
   QT_QPA_EGLFS_DEBUG           |             0
note that the last variable is just for debug option and i turend off also
```
###  Explain qml variable Code:
```explain
#signUp in weatherapi.com and get yours API key from dashboard and replace your API key with this this
    weatherApiKey: "Replace the weatherapi.com API key here!"

#change city name (tehran is default)
   cityName: "tehran"

#weather statistics are update every x minutes
   delayUpdateLoop: 5 //minutes
#weather retrying timeout for update the weather statistics
   delayCheckingUpdate: 10 //Secounds

```
###  resize the widget:
./wtools/css/style.css
```resize
  width:627px;
  height: 408px;
```
###  change weather label:
./wtools/js/conditions.js
```weatherTxt
#you can define day/night text and which weather graphical page when weather API Sent
 the exact status Code

example:
{
 "code" : 1000,
 "day" : "آفتابی", //show this weather text when is day
 "night" : "مهتابی", //show this weather text when is night
 "icon" : 113,
 "w_index": 4 //clear sky page will load
},

**************** note: ****************
w_index    |   summary Weather
  0               snow page
  1               windy page
  2               light rain page
  3               heavy rain page
  4               clear sky page
  5               cloudy sky page
 
```
## Tested Devices
- Raspberry Pi 3 - Buster V10
- ubuntu 20.04 LTS

## Some Resources That Used
[main Graphical source](https://codepen.io/ste-vg/pen/GqaZbo) by ste-vg on codePen.

js [GSAP](https://greensock.com/gsap/) animation library 

[Interacting html with qml over QtWebChannel](https://decovar.dev/blog/2018/07/14/html-from-qml-over-webchannel-websockets/)

## Contact Us
[Email](mailto:miladloveboth2014@gmail.com)
