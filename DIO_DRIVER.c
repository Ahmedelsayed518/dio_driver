#include "DIO_DRIVER.h"

void DIO_SetPinValue(Uint8 PortIDCopy, Uint8 PinIDCopy, Uint8 PinValueCopy)
{
	if ((PinIDCopy <= DIO_PIN7 && PinIDCopy >= DIO_PIN0) && (PortIDCopy <= DIO_PORTD && PortIDCopy >= DIO_PORTA))
	{
		if (PinValueCopy == HIGH)
		{
			switch(PortIDCopy)
			{
				case DIO_PORTA:
					SET_BIT(PORTA, PinIDCopy);
					break;
				case DIO_PORTB:
					SET_BIT(PORTB, PinIDCopy);
					break;
				case DIO_PORTC:
					SET_BIT(PORTC, PinIDCopy);
					break;
				case DIO_PORTD:
					SET_BIT(PORTD, PinIDCopy);
					break;
			}
		}
		else if (PinValueCopy == LOW)
		{
			switch(PortIDCopy)
			{
				case DIO_PORTA:
					CLR_BIT(PORTA, PinIDCopy);
					break;
				case DIO_PORTB:
					CLR_BIT(PORTB, PinIDCopy);
					break;
				case DIO_PORTC:
					CLR_BIT(PORTC, PinIDCopy);
					break;
				case DIO_PORTD:
					CLR_BIT(PORTD, PinIDCopy);
					break;
			}
		}
		else
		{
			/* do nothing */
		}
		
	}
	else
	{
		/* do nothing */
	}	
}


Uint8 DIO_GetPinValue(Uint8 PortIDCopy, Uint8 PinIDCopy)
{
	Uint8 result;
	if ((PinIDCopy <= DIO_PIN7 && PinIDCopy >= DIO_PIN0) && (PortIDCopy <= DIO_PORTD && PortIDCopy >= DIO_PORTA))
	{
		switch(PortIDCopy)
			{
				case DIO_PORTA:
					result = GET_BIT(PINA, PinIDCopy);
					break;
				case DIO_PORTB:
					result = GET_BIT(PINB, PinIDCopy);
					break;
				case DIO_PORTC:
					result = GET_BIT(PINC, PinIDCopy);
					break;
				case DIO_PORTD:
					result = GET_BIT(PIND, PinIDCopy);
					break;
			}
	}
	else
	{
		/* nothing */
	}
	return result;
}

void DIO_SetPinDirection(Uint8 PortIDCopy, Uint8 PinIDCopy, Uint8 PinDirCopy)
{
	if ((PinIDCopy <= DIO_PIN7 && PinIDCopy >= DIO_PIN0) && (PortIDCopy <= DIO_PORTD && PortIDCopy >= DIO_PORTA))
	{
		if (PinDirCopy == OUTPUT)
		{
			switch(PortIDCopy)
			{
				case DIO_PORTA:
					SET_BIT(DDRA, PinIDCopy);
					break;
				case DIO_PORTB:
					SET_BIT(DDRB, PinIDCopy);
					break;
				case DIO_PORTC:
					SET_BIT(DDRC, PinIDCopy);
					break;
				case DIO_PORTD:
					SET_BIT(DDRD, PinIDCopy);
					break;
			}
		}
		else if (PinDirCopy == INPUT)
		{
			switch(PortIDCopy)
			{
				case DIO_PORTA:
					CLR_BIT(DDRA, PinIDCopy);
					break;
				case DIO_PORTB:
					CLR_BIT(DDRB, PinIDCopy);
					break;
				case DIO_PORTC:
					CLR_BIT(DDRC, PinIDCopy);
					break;
				case DIO_PORTD:
					CLR_BIT(DDRD, PinIDCopy);
					break;
			}
		}
		else
		{
			/* DO NOTHING */
		}
		
	}
	else
	{
		/* DO NOTHING */
	}
}

void DIO_SetPortDirection(Uint8 PortID, Uint8 PortDir)
{
	if ((PortID <= DIO_PORTD) && (PortID >= PORTA))
	{
		if (PortDir == OUTPUT)
		{
			switch (PortID)
			{
				case DIO_PORTA:
					DDRA = 0xFF;
					break;
				case DIO_PORTB:
					DDRB = 0xFF;
					break;
				case DIO_PORTC:
					DDRC = 0xFF;
					break;
				case DIO_PORTD:
					DDRD = 0xFF;
					break;
			}
		}
		else if (PortDir == INPUT)
		{
			switch (PortID)
			{
				case DIO_PORTA:
					DDRA = 0;
					break;
				case DIO_PORTB:
					DDRB = 0;
					break;
				case DIO_PORTC:
					DDRC = 0;
					break;
				case DIO_PORTD:
					DDRD = 0;
					break;
			}
		}
		else
		{
			/* do nothing */
		}
	}
	else
	{
		/* do nothing */
	}
}


void DIO_SetPortValue(Uint8 PortID, Uint8 PortVal)
{
	if ((PortID <= DIO_PORTD) && (PortID >= PORTA))
	{
		switch (PortID)
			{
				case DIO_PORTA:
					PORTA = PortVal;
					break;
				case DIO_PORTB:
					PORTB = PortVal;
					break;
				case DIO_PORTC:
					PORTC = PortVal;
					break;
				case DIO_PORTD:
					PORTD = PortVal;
					break;
			}
	}
	else
	{
		/* do nothing */
	}
}

void DIO_Nibble(Uint8 PortIDCopy, Uint8 Section, Uint8 data)
{
	if ((PortIDCopy <= DIO_PORTD) && (PortIDCopy >= PORTA))
	{
		if(Section==FIRST)
		{
			switch(PortIDCopy)
			{
				case DIO_PORTA:
					PORTA = (PORTA & 0xF0) | (data & 0xF);
					break;
				case DIO_PORTB:
					PORTB = (PORTB & 0xF0) | (data & 0xF);
					break;
				case DIO_PORTC:
					PORTC = (PORTC & 0xF0) | (data & 0xF);
					break;
				case DIO_PORTD:
					PORTD = (PORTD & 0xF0) | (data & 0xF); 
					break;		
			}
		}
		else if (Section == SECOND)
		{
			switch(PortIDCopy)
			{
				case DIO_PORTA:
					PORTA = (PORTA & 0x0F) | ((data & 0xF) << 4);
					break;
				case DIO_PORTB:
					PORTB = (PORTB & 0x0F) | ((data & 0xF) << 4);
					break;
				case DIO_PORTC:
					PORTC = (PORTC & 0x0F) | ((data & 0xF) << 4);
					break;
				case DIO_PORTD:
					PORTD = (PORTD & 0x0F) | ((data & 0xF) << 4);
					break;		
			}
		}
	}
	
}