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





Copyright (c) 2020 Eugenio Ciullo


Gli sketch in questo repository sono stati creati da Eugenio Ciullo.
Verrà creato un Controller HID disposto di 2 Assi 22 Pulsanti e 5 Encoder.

Per poter compilare questo sketch è necessario installare le librerie ufficiali Keypad di Mark Stanley attraverso la gestione libreria, inoltre installare la libreria Rotary Enc https://github.com/mathertel/RotaryEncoder nella Documents/Arduino directory.

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
1 ---> ENCB1

0 ---> ENCA1

2 ---> ENCA2

3 ---> ENCB2

4 ---> ENCA3

5 ---> ENCB3

6 ---> ENCA4

7 ---> ENCB4

8 ---> ENCA5

9 ---> ENCB5


Buon Divertimento

*/



#include <Joystick.h>
#include <Keypad.h>
#include <RotaryEncoder.h>

/*___ DEFINIZIONI ___*/
#define NumPulsanti 22
#define NumColonnepulsanti 4
#define NumRighepulsanti 3
#define NumColonne_assi 4
#define NumRighe_assi 1


/* PINOUT ENCODER */
RotaryEncoder encoder1(1, 0);
RotaryEncoder encoder2(2, 3);
RotaryEncoder encoder3(4, 5);
RotaryEncoder encoder4(6, 7);
RotaryEncoder encoder5(8, 9);

/* DEFINIZIONE ARRAY PINOUT RIGHE E COLONNE */
byte Pinrighe_assi[NumRighe_assi] = {A3};
byte PinRighepulsanti[NumRighepulsanti] = {A2,A1,A0};
byte PinColonnepulsanti[NumColonnepulsanti] = {15,14,16,10};


/* MATRICE PULSANTI */

byte matricepulsanti[NumRighepulsanti][NumColonnepulsanti] = {
  {0,1,2,3},
  {4,5,6,7},
  {8,9,10,11}
};

/* MATRICE ASSI */
byte matrice_assi[NumRighe_assi][NumColonne_assi] = {
    {12,13,14,15}
};

/* DEFINIZIONI CLASSI KEYPAD */
Keypad pulsanti = Keypad( makeKeymap(matricepulsanti), PinRighepulsanti, PinColonnepulsanti, NumRighepulsanti, NumColonnepulsanti );
Keypad assi = Keypad( makeKeymap(matrice_assi), Pinrighe_assi, PinColonnepulsanti, NumRighe_assi, NumColonne_assi );



/*______________________DEFINIZIONE JOYSTICK______________________________________________________________*/
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  NumPulsanti, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering
/*________________________________________________________________________________________________________*/

void setup()
{
  tutti_i_pin_a_pullup();
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
  Serial.begin(9600);
} 

void loop()
{
  istruzioni_encoder();
  istruzioni_matrice_pulsanti();
  istruzioni_matrice_assi();
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


                              


void istruzioni_encoder(){
  // ENCODER 1
   static int pos1 = 0;
   encoder1.tick();
   int newPos1 = encoder1.getPosition();
   if (pos1 != newPos1) {
    if (pos1 > newPos1){
      Joystick.pressButton(13);
      delay(75);
      Joystick.releaseButton(13);
    }else
     {
      Joystick.pressButton(12);
      delay(75);
      Joystick.releaseButton(12); 
      }
   }
  pos1 = newPos1;
  
  //ENCODER 2
   static int pos2 = 0;
   encoder2.tick();
   int newPos2 = encoder2.getPosition();
   if (pos2 != newPos2) {
    if (pos2 > newPos2){
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
  pos2 = newPos2;

  
  //ENCODER 3
   static int pos3 = 0;
   encoder3.tick();
   int newPos3 = encoder3.getPosition();
   if (pos3 != newPos3) {
    if (pos3 > newPos3){
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
  pos3 = newPos3;

    
  //ENCODER 4
   static int pos4 = 0;
   encoder4.tick();
   int newPos4 = encoder4.getPosition();
   if (pos4 != newPos4) {
    if (pos4 > newPos4){
      Joystick.pressButton(18);
      delay(75);
      Joystick.releaseButton(18);
    }else
     {
      Joystick.pressButton(19);
      delay(75);
      Joystick.releaseButton(19); 
      }
   }
  pos4 = newPos4;

  
  //ENCODER 5
   static int pos5 = 0;
   encoder5.tick();
   int newPos5 = encoder5.getPosition();
   if (pos5 != newPos5) {
    if (pos5 > newPos5){
      Joystick.pressButton(20);
      delay(75);
      Joystick.releaseButton(20);
    }else
     {
      Joystick.pressButton(21);
      delay(75);
      Joystick.releaseButton(21); 
      }
   }
  pos5 = newPos5;
}

}
