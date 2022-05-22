# dio_driver
dio driver in C language for atmega32
this drive contains the below features:
1. setting any pin in any port you want and that's with the below function:
```C
DIO_SetPinValue(Uint8 PortIDCopy, Uint8 PinIDCopy, Uint8 PinValueCopy)
```
for example:
```C
DIO_SetPinValue(DIO_PORTA, DIO_PIN0, HIGH);
```

2. getting the pin value in any port you want and that's with the below function:
```C
DIO_GetPinValue(Uint8 PortIDCopy, Uint8 PinIDCopy)
```
for example:
```C
DIO_GetPinValue(DIO_PORTA, DIO_PIN0);
```

3. setting the pin direction in any port you want and that's with the below function:
```C
DIO_SetPinDirection(Uint8 PortIDCopy, Uint8 PinIDCopy, Uint8 PinDirCopy)
```
for example:
```C
DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, INPUT);
```

4. setting the value of a nibble in port and that's with the below function:
```C
DIO_Nibble(Uint8 PortIDCopy, Uint8 Section, Uint8 data)
```
for example:
```C
DIO_Nibble(DIO_PORTA, FIRST, 0b00001111);
```
5. setting the port direction and that's with the below function:
```C
DIO_SetPortDirection(Uint8 PortID, Uint8 PortDir)
```
for example:
```C
DIO_SetPinDirection(DIO_PORTA, INPUT);
```
6. setting the port direction and that's with the below function:
```C
DIO_SetPortValue(Uint8 PortID, Uint8 PortVal)
```
for example:
```C
DIO_SetPortValue(DIO_PORTA, 0b11111111);
```
