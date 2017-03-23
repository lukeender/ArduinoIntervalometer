# ArduinoInvervalometer

This is code for a very simple Arduino Nano based Canon DSLR Intervalometer I made. The hardware is based off of [this](http://www.trevorshp.com/creations/intervalometer.htm) design by Trevor Shannon utilizing a 2N222 transistor to pull the shutter pin of the camera to ground; see the schematic at Trevor's site. However, I opted for using a standard parallel 16x1 LCD instead of 8 segment displays and shift registers.

## Operation

The device has four buttons on the front of the device which server as its sole inputs. When switched on, the display shows an hrs:mins:secs display on the left half of the screen, indicating the amount of time be wait between shutters, and the number of shots to take on the right, which take on their defaults of 0:0:0 and the max value of an unsigned short int (i.e. "unlimited"). Two of the buttons are used to increment the selected value either up or down respectively, one used to toggle between which number to increment, and one used to start the time lapse.

Once the time lapse mode has been activated, the device counts down the number of seconds until the next photo is taken and displays the number of completed shots/the number to be taken. The toggle button can be used to toggle the screen and backlight on and off to save battery during operation.

## Part List

* Generic Hitachi HD44780-compatible LCD (ubiquitous on eBay, aliexpress, etc
* Arduino Nano
* 4x push-buttons with pull-down resistors
* Potentiometer (to set display contrast)
* Old Li-on cellphone battery
* Power switch
* 5V regulator (eg: [here](http://www.electrodragon.com/product/tiny-dc-step-boost-module-3v-5v-1a/))
* Li-on battery charging circuit (eg: [here](http://www.electrodragon.com/product/tp4056-lithium-battery-charging-board-1a/))
* 2.5mm jack cable (for interfacing with camera)
