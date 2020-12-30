# Esphome-Wiegand-reader

I use Esphome to integrate many devices in my Homeassistant hub. Some time ago i was looking to an alternative to pn532-rc522 especially because they haven't a case. I discovered Wiegand readers: Wiegand is a specific protocol for this purpose (access control etc.) and there are a lot of cheap but very good readers on the market specifically made to be used even on the outside (IP68). Unfortunately there is no support for Wiegand in Esphome (there is an old support request on Github: https://github.com/esphome/feature-requests/issues/211). I'm an electronic engineer and i'm not an expert software programmer, so i have not enough skills to create an esphome custom component. Combining an Arduino nano, that read Wiegand code from the reader (using one of many Arduino Wiegand libraries) with a Wemos D1 with Esphome, i was able to easily integrate Wiegand reader in Homeassistant. In Home assistant i create automations to unlock my entrance door (and even to disable alarm) when a known tag is read.


Use this yaml code to create your ESPHome firmware: [wemos_d1_wiegand_ingresso.yaml](https://github.com/Gio-dot/Esphome-Wiegand-reader/blob/main/wemos_d1_wiegand_ingresso.yaml). 

Remember to put this file in your esphome folder:  [UartReadLineStateComponent.h](https://github.com/Gio-dot/Esphome-Wiegand-reader/blob/main/UartReadLineStateComponent.h).

Resultant integration in Homeassistant:

<img src="https://github.com/Gio-dot/Esphome-Wiegand-reader/blob/main/img/2020-12-30%2018_58_18-Panoramica%20-%20Home%20Assistant.png" width="350">

Homeassistant basic configuration: [home_assistant_wiegand](https://github.com/Gio-dot/Esphome-Wiegand-reader/blob/main/home_assistant_wiegand.yaml)

## How it works

<img src="https://github.com/Gio-dot/Esphome-Wiegand-reader/blob/main/img/Wemos%20D1%20wiegand%20ingresso_bb.png" width="900">
When tag is read, Arduino device sent it through serial to Esphome device (only TX is needed because communication is unidirectional). In Esphome i used uart text sensor component to read the code and send it to Homeassistant. In Home assistant i create binary sensors (one for each tag code that i'm using); then i use this binary sensors to fire various automations (door, alarm, external light, Wiegand reader led, Wiegand reader beep etc.)

