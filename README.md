# Esphome-Wiegand-reader

I use Esphome to integrate many devices in my Homeassistant hub. Some time ago i was looking to an alternative to pn532-rc522 especially because they haven't a case. I discovered Wiegand readers: Wiegand is a specific protocol for this purpose (access control etc.) and there are a lot of cheap but very good readers on the market specifically made to be used even on the outside (IP68). Unfortunately there is no support for Wiegand in Esphome (there is an old support request on Github: https://github.com/esphome/feature-requests/issues/211). I'm an electronic engineer and i'm not an expert software programmer, so i have not enough skills to create an esphome custom component. Combining an Arduino nano, that read Wiegand code from the reader (using one of many Arduino Wiegand libraries) with a Wemos D1 with Esphome, i was able to easily integrate Wiegand reader in Homeassistant. In Home assistant i create automations to unlock my entrance door when a known tag is read.

RUN or END sensors can be easily used in Home assistant automations to send messages to Telegram or Google home etc. to  warn that the cycle has ended. See Home assistant example: [home_assistant_w_machine.yaml](https://github.com/Gio-dot/Washing-Machine-Sonoff-Pow-R2-Esphome/blob/master/home_assistant_w_machine.yaml)

For instructions about ESPHome installation see: https://esphome.io/index.html

### New Esphome and Home assistant code 10/06/2020
Changelog:
1. Optimized washing phases detection.
2. Removed "washing" phase.
3. Optimized Home assistant yaml.

Use this yaml code to create your ESPHome firmware [sonoff_pow_r2_w_machine.yaml](https://github.com/Gio-dot/Washing-Machine-Sonoff-Pow-R2-Esphome/blob/master/sonoff_pow_r2_w_machine.yaml)

## How it works

<img src="https://github.com/Gio-dot/Washing-Machine-Sonoff-Pow-R2-Esphome/blob/master/img/end.jpg" width="300">
This image show Home assitant card from Sonoff Pow. Washing phases are shown in sequence from bottom to top. At the end of the cycle all phases (except RUN) remains lighted. At next cycle start they are resetted.
Sonoff Pow blue Led is lighted when a cycle is running and turned off at the cycle end.

## ESPHome firmware notes

Line 5: `esp8266_restore_from_flash: true` to restore previous relay state after a Sonoff POW R2 power cycle.

Lines 48-167: washing phases; phases detection can be optimized changing power thresholds and delay filters. 

ESPHome `total_daily_energy` isn't retained through Sonoff power cycles. For this reason and also to store washing machine consumption hystorical data, i used an utility meter in Home assistant Configuration feeding it with `total_daily_energy` sensor from Sonoff POW.
