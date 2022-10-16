#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

#define GPIO_amarelo_num "16"   // define o valor da porta para o led amarelo
#define GPIO_amarelo_path "/sys/class/gpio/gpio16/"  // define o caminho para a porta do led amarelo
#define GPIO_vermelho_num "20"   // define o valor da porta para o led vermelho
#define GPIO_vermelho_path "/sys/class/gpio/gpio20/"  // define o caminho para a porta do led vermelho
#define GPIO_verde_num "21"   // define o valor da porta para o led verde
#define GPIO_verde_path "/sys/class/gpio/gpio21/"  // define o caminho para a porta do led verde
#define GPIO_SYSFS "/sys/class/gpio/"  // define o caminho para o sistema de portas

void alterar_led(string path,string filename , string value){  // funcao que permite alterar os arquivos de acordo com o que for fornecido 
	fstream fs;
	fs.open((path + filename).c_str() , fstream::out );
	fs << value;
	fs.close();
 
}


void acender(string GPIO_path){  // funcao para acender o led
       
	alterar_led( GPIO_path , "value", "1");  // fornece o valor 1 para a porta informada ao chamar a funcao
        
}

void desligar(string GPIO_path){  // funcao para apagar o led
	alterar_led( GPIO_path , "value", "0");  // fornece o valor 0 para o caminho da porta do led desejado
}

void habilitar(string GPIO_num, string GPIO_path){  //funcao para habilitar a porta
       
	alterar_led( GPIO_SYSFS , "export", GPIO_num );
	usleep(1000000) ;
	alterar_led( GPIO_path ,"direction","out");
        
}

void desabilitar (string GPIO_num){  //funcao para desabilitar 
	alterar_led ( GPIO_SYSFS , "unexport", GPIO_num );
}

int main (){  // funcao principal que retorna um inteiro 0
        int c = 0;  // define uma variavel c que servira de contador para o laco
        cout << "Iniciando..." << endl;
	habilitar (GPIO_vermelho_num, GPIO_vermelho_path); // chama a funcao para habilitar a porta do led vermelho
	habilitar (GPIO_amarelo_num, GPIO_amarelo_path); // chama a funcao para habilitar a porta do led amarelo
	habilitar (GPIO_verde_num, GPIO_verde_path); // chama a funcao para habilitar a porta do led verde
	while(c<5){;   //laco de recorrencia que ira repetir 5 vezes o que esta dentro dele 
		acender (GPIO_vermelho_path);  // acende o led vermelho por 2 seg
		usleep(2000000);
		desligar (GPIO_vermelho_path); // apaga o led vermelho
		usleep(10000);
		acender (GPIO_verde_path);  // acende o led verde por 1 seg
		usleep(1000000);
		desligar (GPIO_verde_path); // apaga o led verde
		usleep(10000);
		acender (GPIO_amarelo_path);  // acende o led amarelo por 1 seg
		usleep(1000000);
		desligar (GPIO_amarelo_path); // apaga o led amarelo
		usleep(10000);
                c++; // soma 1 a variavel que serve como contador
	}
	desabilitar (GPIO_vermelho_num); // chama a funcao para desabilitar a porta do led vermelho
	desabilitar (GPIO_amarelo_num); // chama a funcao para desabilitar a porta do led amarelo
	desabilitar (GPIO_verde_num); // chama a funcao para desabilitar a porta do led verde
        return 0;

}	
