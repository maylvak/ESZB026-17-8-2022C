#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define GPIO_amarelo_num "16"
#define GPIO_amarelo_path "/sys/class/gpio/gpio16/"
#define GPIO_vermelho_num "20"
#define GPIO_vermelho_path "/sys/class/gpio/gpio20/"
#define GPIO_verde_num "21"
#define GPIO_verde_path "/sys/class/gpio/gpio21/"
#define GPIO_SYSFS "/sys/class/gpio/"

void alterar_GPIO(char filename[], char value[]){
   FILE* fp;                           
   fp = fopen(filename, "w+");       
   fprintf(fp, "%s", value);           
   fclose(fp);                         
}

void acender(char GPIO_path){
	alterar_led(GPIO_path "value", "1");        
}

void desligar(char GPIO_path){
	alterar_led(GPIO_path "value", "0");
}

void habilitar(char GPIO_num, char GPIO_path){      
	alterar_led(GPIO_SYSFS "export", GPIO_num );
	usleep(1000);
	alterar_led(GPIO_path "direction","out");        
}

void desabilitar (char GPIO_num){
	alterar_led ( GPIO_SYSFS "unexport", GPIO_num );
}

int main (){
        int c = 0;
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
