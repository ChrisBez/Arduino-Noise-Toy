# Arduino-Noise-Chirper
Arduino project for a musical instrument that uses piezo buzzers to make a chiptune style sound that can be adjusted using two tuners.

The basis of the toy is that there are two piezo buzzers that play a noise at the same time, each controlled by a different potentiometer that change the frequency for each buzzer.

As the code only takes a sample at a set frequency (once every 10 ms), the tone of the sound will always be slightly different, creating a random arpeggio style tune.

The higher the pitch the more LEDs that light up.

Here is a basic diagram for the project:

![Alt text](/Noise-Toy-Diagram.png?raw=true "Diagram")
