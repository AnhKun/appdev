# Application Development

This application offers a possibility to turn a Raspberry Pi as a sound 
device. The application comes with 2 function: a sound collector and a test tone generation.

List of content:
1. Configuration Instructions
2. Installation Instructions
3. Operating Instructions
4. List of files
5. Copyright / Copyleft
6. Contact info.
7. Credits and Acknowledgements

## Configuration Installations: 
- This project uses Raspberry Pi, soundcard USB and microphone
- Raspberry Pi:
	* First of all, you need to set up your Raspberry Pi to send ip address by email. More information you can click here: https://portal.vamk.fi/mod/resource/view.php?id=388584
- Soundcard USB:
	* Use `lsusb` command to check if your USB sound card is mounted.
	* Use `sudo nano /etc/asound.conf` command and put following content to the file:

```bash
pcm.!default {
  type plug
  slave {
    pcm "hw:1,0"
  }
}
ctl.!default {
    type hw
    card 1
}
```

	*  Go to your home directory. Use `nano .asoundrc` command and put the same content to the file.
	* Run “alsamixer” you should be able to see that USB sound card is the default audio device 
- NOTE: the way you can fix the bug of the arecord:
	* Use `sudo nano /etc/apt/sources.list` command and add the last line:

```
deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
# Uncomment line below then 'apt-get update' to enable 'apt-get source'
#deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi
deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi
```

	* Run `sudo apt-get update`
	* Run `sudo aptitude versions alsa-utils` to check if version 1.0.25 of alsa-util is available
	* If yours is higher, run “sudo apt-get install alsa-utils=1.0.25-4” to downgrade. 
	* Run `arecord -r44100 -c1 -f S16_LE -d5 test.wav` to test that your microphone is working. You should see a “test.wav” file in the current folder.
	* Put earphone on the USB sound card. Run “aplay test.wav” to check that your recording is okay

## Installation Instructions
- Install the libcurl: 
	* First use command `ls /usr/include/curl` or `ls /usr/include/arm-linux-gnueabihf/curl` to identify that libcurl library is installed.
	* Run `sudo apt-get install libcurl3` to install the libcurl3.
	* Run `sudo apt-get install libcurl4-openssl-dev` to install the development API of libcurl4.
- Clone the repository `git clone https://github.com/AnhKun/appdev`

## Operating Instructions
- Run `make` to compile the project. 
- Run `./sound.out` to display your voice in barchart and count the number of peaks. Press `Ctrl+C` to stop. 
- If you want to test your ears which frequency of the voice you can hear, run "./sound.out arg"
Then run "aplay testTone.wav" to hear.

## List of files:
- main.c 
- comm.c 
- comm.h 
- makefile 
- screen.c 
- screen.h 
- sound.c 
- sound.h 
- sound.php 
- testcurl.c

## Copyleft: 
First thing, i am gratefull for receiving a lot of helps from DR.Gao Chao to complete 
this project. This source code is free so you can use or distribute. I will be very happy when i know 
this project can help you.

## Contact info.
- Name: Nguyen Hoang Anh
- Email: nganhh014@gmail.com

## Credits 
Nguyen Hoang Anh  
