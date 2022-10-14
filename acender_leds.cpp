#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

#define GPIO_amarelo_num "16"
#define GPIO_amarelo_path "/sys/class/gpio/gpio16/"
#define GPIO_vermelho_num "20"
#define GPIO_vermelho_path "/sys/class/gpio/gpio20/"
#define GPIO_verde_num "21"
#define GPIO_verde_path "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS "/sys/class/gpio/"

void alterar_led(string path,string filename , string value){
	fstream fs;
	fs.open((path + filename).c_str() , fstream::out );
	fs << value;
	fs.close();
 
}


void acender(string GPIO_path){
       
	alterar_led( GPIO_path , "value", "1");
        
}

void desligar(string GPIO_path){
	alterar_led( GPIO_path , "value", "0");
}

void habilitar(string GPIO_num, string GPIO_path){
       
	alterar_led( GPIO_SYSFS , "export", GPIO_num );
	usleep(1000000) ;
	alterar_led( GPIO_path ,"direction","out");
        
}

void desabilitar (string GPIO_num){
	alterar_led ( GPIO_SYSFS , "unexport", GPIO_num );
}

int main (){
        int c = 0;
        cout << "Iniciando..." << endl;
	habilitar (GPIO_vermelho_num, GPIO_vermelho_path);
	habilitar (GPIO_amarelo_num, GPIO_amarelo_path);
	habilitar (GPIO_verde_num, GPIO_verde_path);
	while(c<5){;
		acender (GPIO_vermelho_path);
		usleep(2000000);
		desligar (GPIO_vermelho_path);
		usleep(10000);
		acender (GPIO_verde_path);
		usleep(1000000);
		desligar (GPIO_verde_path);
		usleep(10000);
		acender (GPIO_amarelo_path);
		usleep(1000000);
		desligar (GPIO_amarelo_path);
		usleep(10000);
                c++;
	}
	desabilitar (GPIO_vermelho_num);
	desabilitar (GPIO_amarelo_num);
	desabilitar (GPIO_verde_num);
        return 0;

}	
