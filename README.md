Blinkytape_multilamp
====================

A simple multipurpose flashlight/area light/beacon made with Blinkinlabs Blinktape.

Dependencies:
FastLED library
Button library

Purpose:
Simple lighting code to make a Blinkytape work like a flashlight (wrap it around your head,) or a red pulsing beacon for being seen by others and not getting run over, or an area light in two brightness levels.

Use the button on the control board to switch modes, though the red beacon will complete one cycle before exiting to the next mode.

Brightness levels are reduced from full to prevent overloading the power source.  I presume the source can provide a minimum of 500mA/5v.  Feel free to play with the setBrightness value if your power source can do better, but be advised that if the device crashes during code upload that you may need to use the "two needles trick" to reset the bootloader.

Remember that the flexible tape can break so don't wrap it too tightly around anything.

wwward@pobox.com
