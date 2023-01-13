//Llamamos a la libreria que contiene este MCU
//Importante recordar que no se debe usar gcc puesto que este MCU no lo soporta
//En su lugar utilizar sdcc para crear el bistream pasable a la configuracion del dispositivo
#include <pic14/pic12f675.h>

typedef unsigned int word;
//Defines para mejor manejo de los numeros mostrados en los dados
#define one     0b00000001
#define two     0b00010000
#define three   0b00010001
#define four    0b00010100
#define five    0b00010101
#define six     0b00010111
//jugamos con el registro config a traves de los macros
//Apago el wdt y uso la salida MCLR como salida
word __at 0x2007 __CONFIG =(_WDT_OFF & _MCLRE_OFF & _INTRC_OSC_NOCLKOUT);

//declaramos la funcion delay y dentro de ella la funcion tiempo
void delay(unsigned int tiempo);
//Ddeclaramos la funcion principal que va a llamar a delay y todo esto de un while(true) para 
//se siga ejecutando.
void main(void)
{
    //Configuracion de los registros pertinentes (GPIO-TRISIO y ANSEL)
    //Ponemos todos en bajo:
    GPIO = 0x00;
    //TRISIO4 = ~TRISIO1;//Solo el pin 5  como entrada.
    TRISIO = 0b00100000;
    //Y como dijimos que para este lab todo es meramente digital, con ANSEL se lo indicamos:
    ANSEL = 0;
    //Indicamos la magnitud del tiempo para pasarselo como argumento a delay()
    unsigned int time = 100;
    /*
    El profesor dijo que no se puede usar rand()
    aux_cont para incrememntar y hacer una secuencia de rangos
    */
   unsigned int aux_cont = 0;//Inicializado en 0;
   //Loop forever
   while (1)
   {
    //Number selector 
    if(aux_cont < 37)
        {
            aux_cont++;
        }else{
            //reiniciamos la variable auxiliar
            aux_cont = 0;
        }
        //Anidar todo bajo el boton de encendido dado el pin 5 que declaramos como entrada
        if (GP5 == 0)
        {
            while (GP5 == 0)
            {
                int cont = aux_cont;
                //Empezamos con la logica de intervalos
				if (0<=cont & cont<5) 
				{
					GPIO = one;
					delay(time);
					GPIO = 0x00; 
				}
				if (6<=cont & cont<12)
				{
					GPIO = two;
					delay(time);
					GPIO = 0x00;
				}
				if (13<=cont & cont<18)
				{
					GPIO = three;
					delay(time);
					GPIO = 0x00;
				}
				if (19<=cont & cont<24)
				{
					GPIO = four;
					delay(time);
					GPIO = 0x00;
				}
				if (25<=cont & cont<30)
				{
					GPIO = five;
					delay(time);
					GPIO = 0x00; 
				if (31<=cont & cont<37)
				{
					GPIO = six;
					delay(time);
					GPIO = 0x00;
				}                
            }
        } 
   }
   
    }
}




//Fuente del profesor.
//Logica de la funcion delay que consiste en la iteracion y se le asigna a tiempo
//Como no retorna nada la hacemos como void
void delay(unsigned int tiempo)
{
    unsigned int i,j;
    
    {
        for (i = 0; i < tiempo; i++)
            for(j = 0; j<1275;j++);
    }
    
}
