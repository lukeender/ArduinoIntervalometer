# ArduinoInvervalometer

This is code for a very simple Arduino Nano based Canon DSLR intervalometer I made. The hardware is based off of [this](http://www.trevorshp.com/creations/intervalometer.htm) design by Trevor Shannon utilizing a 2N222 transistor to pull the shutter pin of the camera to ground; see the schematic at Trevor's site. However, I opted for using a standard parallel 16x1 LCD instead of 8 segment displays and shift registers, as well as an old lithium-ion battery I had laying around instead of a 9-volt battery.

## Operation

The device has four buttons on the front which serve as its sole inputs. When switched on, the display shows an hrs:mins:secs display on the left half of the screen, indicating the amount of time be wait between shutters, and on the left side of the display it shows the number of shots to be taken, which take on their defaults of 0:0:0 and the max value of an unsigned short int (i.e. "unlimited"), respectively. The two leftmost buttons are used to increment the selected value up and down, the second button from the right used to toggle between which number to increment, and the far right button used start the time lapse loop after configured.

Once the time lapse mode has been activated, the device counts down the number of seconds until the next photo is taken and displays the number of completed shots vs the number to be taken. The select button can be used to toggle the screen and backlight on and off to save battery during operation.

## Gallery
![a](https://i.imgur.com/K2o8Chx.jpg)
A snapshot of the device set to take an "unlimited" number of photos with an interval of 10 seconds
![b](https://i.imgur.com/zEgj2Hh.jpg)
Here it is counting down on the left side and showing the taken/remaining photos on the right

Here is an example of a timelapse I took out my window one afternoon:
https://gfycat.com/DemandingDrearyBluebottle

## Part List

* Generic Hitachi HD44780-compatible LCD (ubiquitous on eBay, aliexpress, etc)
* Arduino Nano
* 4x push-buttons with pull-down resistors
* Potentiometer (to set display contrast)
* Old Li-on cellphone battery
* Power switch
* 5V regulator for battery (eg: [here](http://www.electrodragon.com/product/tiny-dc-step-boost-module-3v-5v-1a/))
* Li-on battery charging circuit (eg: [here](http://www.electrodragon.com/product/tp4056-lithium-battery-charging-board-1a/))
* 2.5mm jack cable (for interfacing with camera)
