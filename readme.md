# double_farlomp

![double_farlomp](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [FrancoAccifonte](https://github.com/yourusername)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make double_farlomp:default

Flashing example for this keyboard:

    make double_farlomp:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

# Compile
```
qmk compile -kb double_farlomp -km alpha_farlomp
```

# Misc
https://deskthority.net/wiki/Arduino_Pro_Micro#Pinout
