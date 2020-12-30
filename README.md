# Esphome-Wiegand-reader

I use Esphome to integrate many devices in my Homeassistant hub. Some time ago i was looking to an alternative to pn532-rc522 especially because they haven't a case. I discovered Wiegand readers: Wiegand is a specific protocol for this purpose (access control etc.) and there are a lot of cheap but very good readers on the market specifically made to be used even on the outside (IP68). Unfortunately there is no support for Wiegand in Esphome (there is an old support request on Github: https://github.com/esphome/feature-requests/issues/211). I'm an electronic engineer and i'm not an expert software programmer, so i have not enough skills to create an esphome custom component. Combining an Arduino nano, that read Wiegand code from the reader (using one of many Arduino Wiegand libraries) with a Wemos D1 with Esphome, i was able to easily integrate Wiegand reader in Homeassistant. In Home assistant i create automations to unlock my entrance door (and even to disable alarm) when a known tag is read.


Use this yaml code to create your ESPHome firmware [sonoff_pow_r2_w_machine.yaml](https://github.com/Gio-dot/Washing-Machine-Sonoff-Pow-R2-Esphome/blob/master/sonoff_pow_r2_w_machine.yaml)

## How it works

<img src="https://github.com/Gio-dot/Esphome-Wiegand-reader/blob/main/img/Wemos%20D1%20wiegand%20ingresso_bb_new.png" width="300">
This image show Home assitant card from Sonoff Pow. Washing phases are shown in sequence from bottom to top. At the end of the cycle all phases (except RUN) remains lighted. At next cycle start they are resetted.
Sonoff Pow blue Led is lighted when a cycle is running and turned off at the cycle end.


