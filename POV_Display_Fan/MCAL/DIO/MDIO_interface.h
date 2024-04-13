//Groups
#define A		1
#define B		2
#define C		3
#define D		4

//PINS
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7

//Values
#define 	HIGH		1
#define 	LOW			0

//Directions
#define     OUTPUT          1
#define     INPUT           0
#define     INPUT_PULLUP    2


// APIs
void MDIO_voidSetPinDirection (u8 port, u8 pin, u8 dir);
void MDIO_voidSetPinValue (u8 port, u8 pin, u8 val);
u8   MDIO_u8GetPinValue   (u8 port, u8 pin);

void MDIO_voidSetPortDirection (u8 port, u8 dir);
void MDIO_voidSetPortValue (u8 port, u8 val);
u8   MDIO_u8GetPortValue   (u8 port);