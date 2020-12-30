/*
	060420 MODIFIED BY https://github.com/Gio-dot
	ADDED WIEGAND PROTOCOL READING ON SERIAL PINS 2 (D0) AND PIN 3 (D1)
	READING OUT CODE ON UART RX/TX PINS
*/

#include <Wiegand.h>	// GIO WIEGAND
WIEGAND wg;	// GIO WIEGAND

#define DEBUG // remove debug so pin 0 and 1 can be used for IO

unsigned long durata_codice= 0;	// durata codice Wiegand (passato un certo tempo invio codice vuoto sulla seriale)
int flag_durata_codice= 0;      // flag per cancellare wiegand una volta sola

void setup()
{
#ifdef DEBUG
  Serial.begin(115200);
  Serial.println(F("Init "));
#endif
	
	// default Wiegand Pin 2 and Pin 3 see image on README.md
	// for non UNO board, use wg.begin(pinD0, pinD1) where pinD0 and pinD1 
	// are the pins connected to D0 and D1 of wiegand reader respectively.
	wg.begin();	// WIEGAND

#ifdef DEBUG
  Serial.println(F("Wire ok"));
#endif
}

void loop()
{
  if(wg.available())
		{
			// Serial.print("Wiegand HEX = ");
			// Serial.print(wg.getCode(),HEX);
			// Serial.print(", DECIMAL = ");
			Serial.println(wg.getCode());	// WIEGAND
			// Serial.print(", Type W");
			// Serial.println(wg.getWiegandType()); 
			durata_codice= millis();  // azzero il tempo per invio caodice vuoto Wiegand
			flag_durata_codice= 1; // flag per wiegand vuoto 1 volta sola		
		}
	
	if ( ( (millis()-durata_codice)>=2000)&&(flag_durata_codice== 1) )
		{
				Serial.println("ready...");	 // dopo 2 secondi dalla lettura invio codice wiegand vuoto per essere pronto a letture successive
				flag_durata_codice= 0;
		}		

}


