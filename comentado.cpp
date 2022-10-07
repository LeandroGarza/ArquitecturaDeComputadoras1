#include<iostream>
#include "string.h"
#include "conio.h"
#include <vector>
#include <Windows.h>
#include<stdlib.h>

using namespace std;

void retardo(unsigned long int);  //da tiempo entre las luces
void mostrar (unsigned char);

void auto_fantastico(unsigned long int);
void carrera(unsigned long int);
void choque(unsigned long int);
void bateriaDescargandose(unsigned long int);
void chocaLos5(unsigned long int);
//el proceso para dibujar es siempre el mismo!! lo unico que necesito hacer es decir que dibujar
//esto seria ver como cambiar de lugar los 1 = *
int main(){

	char contrasenia[] = {'a' , 'b' , 'c' , '1' , '0'};
	char contra[20];
	string pw;
	int v = 0;
	int contador = 0 , intentos = 3;

	while(intentos != 0){
        cout<<"Ingrese su contraseña: ";
        for(int i = 0 ; i < 5 ; i++){
            v = getch();
            pw.push_back(v);
            cout<<"*";
        }

        if(pw != "abc10"){
            contador++;
            intentos--;
            system("cls");
            cout<<"Contrasenia incorrecta, le quedan "<<intentos<<" intentos"<<endl;
        }
        else{
            intentos = 0;
        }
	}

	if(contador == 0){
        system("cls");
		cout<<"Bienvenido al sistema"<<endl;
	}
	else{
		cout<<"\nPassword no valida"<<endl;
	}

    int opcion = 0;
    unsigned long int velocidadAux = 151000000;
    unsigned long int velocidad = velocidadAux;

	do{
        if(contador == 0){

            cout<<"\n(1) Autos fantastico"<<endl;
            cout<<"(2) La carrera"<<endl;
            cout<<"(3) El choque"<<endl;
            cout<<"(4) Bateria Descargandose"<<endl;
            cout<<"(5) Choca los 5"<<endl;
            cout<<"(6) Salir"<<endl;


            cout<<"\nIngrese la opcion que desee visualizar: ";cin>>opcion;
            while(opcion < 1 || opcion > 6){
                cout<<"Valor erroneo, ingrese nuevamente: ";cin>>opcion;
            }

            switch(opcion){
                case 1:
                    system("cls");
                    cout<<"Autos fantastico";break;
                case 2:
                    system("cls");
                    carrera(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 3:
                    system("cls");
                    choque(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 4:
                    system("cls");
                    bateriaDescargandose(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 5:
                    system("cls");
                    chocaLos5(velocidad);
                    opcion = 0;
                    velocidad = velocidadAux;
                    break;
                case 6:
                    system("cls");
                    cout<<"Apagando sistema";break;
                default:
                    system("cls");
                    cout<<"No existe secuencia para ese numero"<<endl;
                    opcion = 0;
            }
        }
	}while(opcion != 6);
}

void retardo (unsigned long int a){
    while (a) a--;
}

void mostrar (unsigned char dato){  //mascara>>=1 desplaza a la derecha osea 0x80 ahora es 0x40
    for(unsigned char mascara = 128; mascara > 0; mascara>>=1){ //128(decimal) = 10.000.000 (binario) = 0x80 (hexa) , acaba cuando > 0 osea 00.000.001 = 0x01
        if (dato&mascara){  //compara bit a bit dato y mascara, si coinciden (ya sea con 1 o 0) muestra * = 1 = prendido
            cout<<"*";      //dato es siempre 128 pero mascara primero 128 , luego 64 , 32 , 16 , 8 , 4 , 2, 1 osea *______
        }
        else{
            cout<<"_";
        }
    }
}
//asi como & es una especie de and bit a bit
// ^ or exclusivo bit a bit
// | or inclusivo bit a bit
// && y logico bit a bit
// || o logico bit a bit

void carrera (unsigned long int velocidad){ //uint8_t es de numero entero de 1 byte = 8 bits sin signo
    uint8_t tabla[] = {     //dibujamos la tabla con 80 = 10.000.000, 40 = 01.000.000, 20 = 00.100.000 , 10 = 00.010.000
        0x80, 0x80, 0x40, 0x40, 0x20, 0x20,     // 0x es el prefijo de un numero hexadecimal!
        0x10, 0x10, 0x88, 0x48, 0x24, 0x14,     //88 = 10.001.000 , 0x48 = 01.001.000 , 24 = 00.100.100 , 14 = 00.010.100
        0xA, 0x6, 0x3,0x1                       //A = 1010 , 6 = 0110 , 3 = 0011 , 1 = 0001
        };


    while(1){   //crea un bucle infinito, q lo rompemos luego con vk_escape!
        for (int i = 0; i < 16; ++i) {  //16 ya que son la cantidad de numeros que pusimos arriba osea recorre todo
            cout<< "Presione ESC para regresar al menu principal"<<endl;
            cout<<"Delay: "<<velocidad<<endl;   //velocidad es lo que le mandamos como parametro para todos los juegos la misma
            mostrar(tabla[i]);  //le vamos pasando elemento a elemento de la tabla
            retardo(velocidad);
            system("cls");

            if((velocidad - 5000000) > 1000000){ //tanto el 5000 como el 1000 son a prueba y error
                if(GetAsyncKeyState(VK_UP) & 0x0001){velocidad -= 5000000;} //funcion sacada de internet  q capta la tecla q apretas
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){velocidad += 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }
}

void choque(unsigned long int velocidad){
    uint8_t tabla[] = {
        0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42  //81 = 10.000.001, 42 = 01.000.010, 24 = 00.100.100 , 18 = 00.011.000
        };                                        //|| = 81

    while(1){
        for (int i = 0; i < 8; ++i) {
            cout<< "Presione ESC para regresar al menu principal"<<endl;
            cout<<"Delay: "<<velocidad<<endl;
            mostrar(tabla[i]);
            retardo(velocidad);
            system("cls");

            if((velocidad - 5000000) > 1000000){
                if(GetAsyncKeyState(VK_UP) & 0x0001){velocidad -= 5000000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){velocidad += 5000000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
        }
    }
}

void chocaLos5(unsigned long int velocidad){
    unsigned char tabla []={                     //decimal = 129            195               231               255
        0x0,0x81, 0xC3, 0xE7, 0xFF, 0xE7, 0xC3, 0x81    //81 = 10.000.001 , C3 = 11.000.011 , E7 = 11.100.111 , FF = 11.111.111
        };                                             //hexa = binario
        while (1) {
            for (int i = 0; i < 8; i++) {
                cout<< "Presione ESC para regresar al menu principal"<<endl;
                cout<<"Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla"<<endl;
                cout<<"Demora: "<<velocidad<<endl;
                mostrar(tabla[i]);
                retardo(velocidad);
                system("cls");

                if ((velocidad - 4800000) > 9600000){
                if(GetAsyncKeyState(VK_UP) & 0x0001){velocidad -= 4800000;}
                }
                if(GetAsyncKeyState(VK_DOWN) & 0x0001){velocidad += 4800000;}
                if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}
            }
        }
}

void bateriaDescargandose(unsigned long int velocidad){
    unsigned int dato = 0xFF;   //11.111.111
    while(1){
        for (int i = 0; i < 9; ++i) {
            cout<< "Presione ESC para regresar al menu principal"<<endl;
            cout<<"Pulse la flecha para arriba para incrementar la velocidad, o para abajo para disminuirla"<<endl;
            cout<<"Demora: "<<velocidad<<endl;
            mostrar(dato);
            dato <<= 1; //desplaza a la izquiera osea que 11.111.111 seria 11.111.110 luego 11.111.101
            retardo(velocidad);
            system("cls");

            if ((velocidad - 4800000) > 9600000){
                if(GetAsyncKeyState(VK_UP) & 0x0001){velocidad -= 4800000;}
            }
            if(GetAsyncKeyState(VK_DOWN) & 0x0001){velocidad += 4800000;}
            if(GetAsyncKeyState(VK_ESCAPE) & 0x0001){return;}

        }
        dato = 0xFF;
    }
}

//resumen de la cantidad de ciclos (for) de cada uno
//auto fantastico =
//carrera = 16
//choque = 7
//bateriaDescargandose = 9
//chocaLos5 = 8

//binario a hexa y viceversa solo reemplazas en ambos, recordar 0123456789ABCDEF

//decimal a binario lo vas dividiendo por dos y lo que queda en el resto de abajo para arriba

//binario a decimal los que tengan un 1, elevar el 2 a su posicion y sumarlos con los otros (de otras posiciones)

//decimal a hexa al numero en decimal lo dividis por 16 y redondeas para abajo. Este numero lo multiplicas por 16 y te
//va a dar un sobrante, el cual lo convertis en hexa con la tabla. Si el multiplicando es >= 16 lo tenes q seguir dividiendo
// Y asi con todos los numeros q tenga el decimal
//una vez convertido todos, el numero empieza del ultimo q convertiste al primero
