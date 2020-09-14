# T3-Head-Lighting-V1
Version 1 of the T3-M4 Lighting System.

<h1>Current Abilities</h1>
<u>14/09/202</u>
System went through a rewrite with thanks to Craig Pay. Taking inspriation from his BT-1 Main Eye the code now features the ability to have a more "feathery" type of fade if wanted or just a standard fade in and fade out.

<u>24/09/2019:</u>
The T3 Head Lighting System is in it's most basic form. whilst I am still very new to coding Arduino the system works and gives a nice simply output.

<b>Main Eye</b>
The main eye, as well as the whole system is pretty straight forward and simple. Using a 24 LED RGBW Neo-Pixel, we alternate the colours of the pixels to give the illusion of "thinking" and also with the random delay changing the colours at random times only adds to the illusion. Currently the LED's are set individually varying between Blue and White and every other pixel is one of the colours IE LED 0=BLUE, LED 1=WHITE, LED2=BLUE etc.
https://shop.pimoroni.com/products/neopixel-ring-24-x-5050-rgbw-leds-w-integrated-drivers?variant=17450439303

<b>Large Eye</b>
Using a 16 LED RGBW Neo-Pixel we have a nice pulsing/ fading type of function going on. I tried my best to keep to as close to KOTOR 2's version of T3 as I could. Currently it pulses between Orange and Red. This pulses at the same time as the small eye and again with a slight random timing to it.
https://shop.pimoroni.com/products/neopixel-ring-16-x-5050-rgbw-leds-w-integrated-drivers?variant=17439635079

<b>Small Eye</b>
This part of the system uses a 7 LED RGBW Jewel Pixel which actually is slightly too big for the small eye but we can make this work. Again this does the same thing as the Large Eye at the same time so there's not much to say other than it's smaller.
https://shop.pimoroni.com/products/neopixel-jewel-7-x-5050-rgbw-led-w-integrated-drivers?variant=17449306567

<h2>Connections</h2>
I have set this up to use the Arduino UNO, it is untested with any other board type but feel free to try and let me know how it goes! Since I bought the Large Eye Pixel first, that is the default first in the chain but by giving each pixel it's own Data In instead of daisy chaining them, technically any of the pixels can be first in the chain.
<br><br>
<b>NOTICE:</b>
The 7 LED Jewel that we are going to use for the Small Eye is unable to go first or second and I would advise putting it last in the chain. The reason for this is that is doesn't have a second POWER and GND so you cannot daisy chain the power and gnd connections like we need to.
<br><br>
To start with, grab your Arduino UNO and make sure you have the Digital Output pins 5,6,9 that have the ~ next to it, for those of you that are new to this, this means that it allows PWM (Pulse Width Modulation) which is needed for anything fading/ pulsing etc. If you don't have these then you probably have incorrect board.

If you have that then great, I started with the first Pixel, the 16 LED one. You'll notice there are 2 PWR and 2 GND. As far as I'm aware there is no specific INPUT or OUTPUT. You want to solder in a red and black wire into each of the PWR and GND holes. I would suggest that you make the cables nice and long because they do have to make a couple of turns which takes up cable length.

I would also suggest that you add some connectors to the OUTPUT PWR and GND and you will understand why later. 

You will also have DATA IN and DATA OUT. We are only going to be using the DATA In. For these you can use any colour wires you want really just as long as you know what they are. Solder one end into the DATA IN hole and the on for the Large Eye will connect into Pin 6 of the Arduino (I'll post a connection table below). Now you need to do this for all the Pixels but reffer to the table below for PINs.

I said you may want to connect them to some connectors earlier and here is why. due to these still being in beta testing I am not 100% sure on the components yet. They seem fine but they haven't had a great deal of testing so everything is like a placeholder right now. Adding connectors between each PWR and GND connection will allow you to easily disconnect that particular Pixel to either swap or alter.

<b>Connections Table</b><br>
<table>
  <thead>
    <tr>
      <td><u>Arduino</u></td>
      <td><u>Large Eye</u></td>
      <td><u>Main Eye</u></td>         
      <td><u>Small Eye</u></td>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>5V > PWR(LE)</td>
      <td>PWR(LE) > PWR(ME)</td>
      <td>PWR(ME) > PWR(SE)</td>
      <td>PWR</td>
      </tr>
    <tr>
      <td>GND(A) > GND(LE)</td>
      <td>GND(LE) > GND(ME)</td>
      <td>GND(ME) > GND(SE)</td>
      <td>GND</td>
    </tr>
    <tr>
      <td>Pins 5,6,9</td>
      <td>Pin 6 > DATA IN</td>
      <td>PIN 5 > DATA IN</td>
      <td>PIN 9 > DATA IN</td>
    </tr>
  </tbody>
  </table>
  
  Hopefully the above table is easy to follow but if you have any questions then drop me a line.
  Download the sketch and upload it to your Arduino and it should all work out. If not drop me a line. <br><br>
  
  <h2>Future Improvements</h2>
  This code will constantly be developed making it more functional and easier to use as well as edit. I intend to add various animations to the code to give each droid unique lights and animations.
  
  Users will also be able to customise what colours they would like for their droid
  
  I will be looking into merging this system with the Padawan360 original created by Dan Kraus who has kindly given his permission to adapt the system for T3.
  
  Users are welcome to make changes to the code and if needed create a pull request and I'll take a look. Any features/ updates will be posted here.
