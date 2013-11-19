Goldberg-machine
================

Wireless multi-node machine inspired by "Rube Goldberg Machine" 
Project for ITP Class Understanding Networks by Tom Igoe

In this repository, there is code for both sides of the machine, physical and wireless receiver/senders.

On the Wireless receiver, an Arduino + XBee radio is listening for a specific serial message. Once received, it triggers a toy car with a hacked pushbutton switch (connected through a NPN transistor). The toy car starts it's ride, and then crashes into a wooden wall, that houses a hidden switch. 

On that other side, another Arduino is listening for that event, and then triggers another serial message that is sento through the second Xbee radio to the next device in the chain.
  
Game Instructions on http://itp.nyu.edu/physcomp/Labs/XBeeTelephoneGame
  
Project by Sergio Majluf and Donna Miller
Understanding Networks, by Tom Igoe
November 2013
