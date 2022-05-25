#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_
#include "REG.h"
#include "BIT_MATH.h"

/* port define */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/* pin define */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/* pin directions */
#define INPUT 0
#define OUTPUT 1

/* PIN value options */
#define HIGH 1
#define LOW 0


#define FIRST 0
#define SECOND 1

/* io pins */
void DIO_SetPinValue(Uint8 PortIDCopy, Uint8 PinIDCopy, Uint8 PinValueCopy);

Uint8 DIO_GetPinValue(Uint8 PortIDCopy, Uint8 PinIDCopy);

void DIO_SetPinDirection(Uint8 PortIDCopy, Uint8 PinIDCopy, Uint8 PinDirCopy);

void DIO_Nibble(Uint8 PortIDCopy, Uint8 Section, Uint8 data);

/* io ports */
void DIO_SetPortDirection(Uint8 PortID, Uint8 PortDir);

void DIO_SetPortValue(Uint8 PortID, Uint8 PortVal);
#endif
