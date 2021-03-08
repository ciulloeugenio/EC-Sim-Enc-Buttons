/*
┏━━━┓╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┏━━━┓╋╋╋┏┓┏┓
┃┏━━┛╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋╋┃┏━┓┃╋╋╋┃┃┃┃
┃┗━━┳┓┏┳━━┳━━┳━┓┏┳━━┓┃┃╋┗╋┳┓┏┫┃┃┃┏━━┓
┃┏━━┫┃┃┃┏┓┃┃━┫┏┓╋┫┏┓┃┃┃╋┏╋┫┃┃┃┃┃┃┃┏┓┃
┃┗━━┫┗┛┃┗┛┃┃━┫┃┃┃┃┗┛┃┃┗━┛┃┃┗┛┃┗┫┗┫┗┛┃
┗━━━┻━━┻━┓┣━━┻┛┗┻┻━━┛┗━━━┻┻━━┻━┻━┻━━┛
╋╋╋╋╋╋╋┏━┛┃
╋╋╋╋╋╋╋┗━━┛




███████╗░█████╗░  ░██████╗██╗███╗░░░███╗
██╔════╝██╔══██╗  ██╔════╝██║████╗░████║
█████╗░░██║░░╚═╝  ╚█████╗░██║██╔████╔██║
██╔══╝░░██║░░██╗  ░╚═══██╗██║██║╚██╔╝██║
███████╗╚█████╔╝  ██████╔╝██║██║░╚═╝░██║
╚══════╝░╚════╝░  ╚═════╝░╚═╝╚═╝░░░░░╚═╝

███████╗███╗░░██╗░█████╗░  ░█████╗░███╗░░██╗██████╗░  ██████╗░██╗░░░██╗████████╗████████╗░█████╗░███╗░░██╗░██████╗
██╔════╝████╗░██║██╔══██╗  ██╔══██╗████╗░██║██╔══██╗  ██╔══██╗██║░░░██║╚══██╔══╝╚══██╔══╝██╔══██╗████╗░██║██╔════╝
█████╗░░██╔██╗██║██║░░╚═╝  ███████║██╔██╗██║██║░░██║  ██████╦╝██║░░░██║░░░██║░░░░░░██║░░░██║░░██║██╔██╗██║╚█████╗░
██╔══╝░░██║╚████║██║░░██╗  ██╔══██║██║╚████║██║░░██║  ██╔══██╗██║░░░██║░░░██║░░░░░░██║░░░██║░░██║██║╚████║░╚═══██╗
███████╗██║░╚███║╚█████╔╝  ██║░░██║██║░╚███║██████╔╝  ██████╦╝╚██████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██║░╚███║██████╔╝
╚══════╝╚═╝░░╚══╝░╚════╝░  ╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░  ╚═════╝░░╚═════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═╝░░╚══╝╚═════╝░



░█████╗░████████╗░██████╗██████╗░░█████╗░░█████╗░
██╔══██╗╚══██╔══╝██╔════╝╚════██╗██╔══██╗██╔══██╗
██║░░╚═╝░░░██║░░░╚█████╗░░░███╔═╝╚█████╔╝╚█████╔╝
██║░░██╗░░░██║░░░░╚═══██╗██╔══╝░░██╔══██╗██╔══██╗
╚█████╔╝░░░██║░░░██████╔╝███████╗╚█████╔╝╚█████╔╝
░╚════╝░░░░╚═╝░░░╚═════╝░╚══════╝░╚════╝░░╚════╝░


Copyright (c) 2020 Eugenio Ciullo


Gli sketch in questo repository sono stati creati da Eugenio Ciullo.
Verrà creato un Controller HID disposto di 2 Assi 18 Pulsanti e 3 Encoder.

Per poter compilare questo sketch è necessario installare le librerie ufficiali Keypad di Mark Stanley attraverso la gestione libreria, inoltre installare la libreria Encoder di Paul Stoffregen nella gestione libreria

Bisogna installare inoltre nella Documents/Arduino directory la libreria ArduinoJoystickLibrary creata da MHeironimus reperibile al seguente link:
https://github.com/MHeironimus/ArduinoJoystickLibrary



Matrice Assi X e Y

A3 - RIGHT --- LEFT -- DOWN -- UP
      |         |       |      |
15____|         |       |      |
14______________|       |      |
16______________________|      |
10_____________________________|



Matrice Pulsanti
PIN - PULSANTI

A2 - 1 -- 2 -- 3 -- 4
     |    |    |    |
A1 - 5 -- 6 -- 7 -- 8
     |    |    |    |
A0 - 9 - 10 - 11 - 12
     |    |    |    |
15___|    |    |    |
          |    |    |
14________|    |    |
               |    |
16_____________|    |
                    |
10__________________|


PIN   EncoderPIN
1 ---> ENCA1

0 ---> ENCB1

2 ---> ENCA2

3 ---> ENCB2

4 ---> ENCA3

5 ---> ENCB3


Pin riservati per usi futuri:

6, 7, 8, 9

Buon Divertimento


*/

#include <Joystick.h>
#include <Keypad.h>
#include <Encoder.h>

Encoder myEnc1(1, 0);
Encoder myEnc2(2, 3);
Encoder myEnc3(4, 5);

#define NumPulsanti 18
#define NumColonnepulsanti 4
#define NumRighepulsanti 3
#define NumColonne_assi 4
#define NumRighe_assi 1

long oldPosition1  = 0;
long oldPosition2  = 0;
long oldPosition3  = 0;

byte Pinrighe_assi[NumRighe_assi] = {A3};
byte PinRighepulsanti[NumRighepulsanti] = {A2,A1,A0};
byte PinColonnepulsanti[NumColonnepulsanti] = {15,14,16,10};

byte matricepulsanti[NumRighepulsanti][NumColonnepulsanti] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11}
};

byte matrice_assi[NumRighe_assi][NumColonne_assi] = {
    {12,13,14,15}
};

Keypad pulsanti = Keypad( makeKeymap(matricepulsanti), PinRighepulsanti, PinColonnepulsanti, NumRighepulsanti, NumColonnepulsanti );
Keypad assi = Keypad( makeKeymap(matrice_assi), Pinrighe_assi, PinColonnepulsanti, NumRighe_assi, NumColonne_assi );


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  NumPulsanti, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering


void setup()
{
  tutti_i_pin_a_pullup();
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
} 

void loop()
{
  istruzioni_encoder();
  istruzioni_matrice_pulsanti();
  istruzioni_matrice_assi();
  delay(2);
}


void istruzioni_encoder(){
  // ENCODER 1
  long newPosition1 = myEnc1.read();
  if (newPosition1 != oldPosition1) {
    if (oldPosition1 > newPosition1){
      Joystick.pressButton(12);
      delay(75);
      Joystick.releaseButton(12);
    }else
     {
      Joystick.pressButton(13);
      delay(75);
      Joystick.releaseButton(13); 
      }
   }
  oldPosition1 = newPosition1;

  // ENCODER 2
  long newPosition2 = myEnc2.read();
  if (newPosition2 != oldPosition2) {
    if (oldPosition2 > newPosition2){
      Joystick.pressButton(14);
      delay(75);
      Joystick.releaseButton(14);
    }else
     {
      Joystick.pressButton(15);
      delay(75);
      Joystick.releaseButton(15); 
      }
   }
  oldPosition2 = newPosition2;

  // ENCODER 3
  long newPosition3 = myEnc3.read();
  if (newPosition3 != oldPosition3) {
    if (oldPosition3 > newPosition3){
      Joystick.pressButton(16);
      delay(75);
      Joystick.releaseButton(16);
    }else
     {
      Joystick.pressButton(17);
      delay(75);
      Joystick.releaseButton(17); 
      }
   }
  oldPosition3 = newPosition3;
}


void tutti_i_pin_a_pullup()
{
  pinMode(1, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
}

void istruzioni_matrice_pulsanti(){
      if (pulsanti.getKeys())
    {
       for (int B=0; B<LIST_MAX; B++)   
        {
           if ( pulsanti.key[B].stateChanged )   
            {
            switch (pulsanti.key[B].kstate) {  
                    case PRESSED:
                    case HOLD:
                              Joystick.setButton(pulsanti.key[B].kchar, 1);
                              break;
                    case RELEASED:
                              Joystick.setButton(pulsanti.key[B].kchar, 0);
                              break;
            }
           }   
         }
     }
 }

void istruzioni_matrice_assi(){
      if (assi.getKeys())
    {
       for (int D=0; D<LIST_MAX; D++)   
        {
           if ( assi.key[D].stateChanged )   
            {
            switch (assi.key[D].kstate) {
              
                case PRESSED:
                    case HOLD:
                    
                    if (assi.key[D].kchar == 12){
                      Joystick.setXAxis(1);
                    }
                    if (assi.key[D].kchar == 13){
                      Joystick.setXAxis(-1);
                    }
                    if (assi.key[D].kchar == 14){
                      Joystick.setYAxis(1);
                    }
                    if (assi.key[D].kchar == 15){
                      Joystick.setYAxis(-1);
                    }
                    break;

                   case RELEASED:
                       Joystick.setXAxis(0);
                       Joystick.setYAxis(0);
                       break;}
            }
        }
    }
}
