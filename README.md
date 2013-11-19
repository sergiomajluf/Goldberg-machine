Goldberg-machine
================

Wireless multi-node machine inspired by "Rube Goldberg Machine" 
Project for ITP Class Understanding Networks by Tom Igoe

In this repository, there is code for both sides of the machine, physical and wireless receiver/senders.

On the Wireless receiver, an Arduino + XBee radio is listening for a specific serial message. Once received, it triggers a toy car with a hacked pushbutton switch (connected through a NPN transistor). The toy car starts it's ride, and then crashes into a wooden wall, that houses a hidden switch. 

On that other side, another Arduino is listening for that event, and then triggers another serial message that is sento through the second Xbee radio to the next device in the chain.

Check out my [ITP blog post](http://itp.nyu.edu/~sam926/a-wireless-rube-goldberg-machine/) about this, some pictures, and soon, the results.

Also, this [Google Spreadhseet](https://docs.google.com/a/nyu.edu/spreadsheet/ccc?key=0AmAbQ-nKpWHidDVCdTREd1hzUDhQQzRWbWNxbHJPTEE&usp=drive_web#gid=0) might come in handy to understand how everybody's radio were setup
  
Game Instructions on the [ITP Physcomp Wiki](http://itp.nyu.edu/physcomp/Labs/XBeeTelephoneGame)
  
Project by Sergio Majluf and Donna Miller
Understanding Networks, by Tom Igoe
November 2013
