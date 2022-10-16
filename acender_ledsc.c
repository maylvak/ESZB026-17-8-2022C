// Script para acender tres leds consecutivamente 5 vezes, sendo que a ordem é vermelho por 2 segundos, verde e amarelo por 1 segundo

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define GPIO_amarelo_num "16"     // define a porta associada ao led amarelo
#define GPIO_amarelo_path "/sys/class/gpio/gpio16/"    // define o caminho para acessar a porta do led
#define GPIO_vermelho_num "20"     // define a porta associada ao led vermelho
#define GPIO_vermelho_path "/sys/class/gpio/gpio20/"    // define o caminho para acessar a porta do led
#define GPIO_verde_num "21"     // define a porta associada ao led verde
#define GPIO_verde_path "/sys/class/gpio/gpio21/"   // define o caminho para acessar a porta do led
#define GPIO_SYSFS "/sys/class/gpio/"  // define o caminho para o sistema

void alterar_GPIO(char filename[], char value[]){    // funcao para escrever o valor fornecido no arquivo que se deseja, serve tanto para acender e desligar o led quanto para habilitar ou desabilitar uma porta
   FILE* fp;                           
   fp = fopen(filename, "w+");       
   fprintf(fp, "%s", value);           
   fclose(fp);                         
}

void habilitar(char GPIO_num, char GPIO_path){      // funcao para habilitar a porta associada ao led
	alterar_led(GPIO_SYSFS "export", GPIO_num );
	usleep(1000);
	alterar_led(GPIO_path "direction","out");        
}

void desabilitar (char GPIO_num){      // funcao para desabilitar a porta associada ao led
	alterar_led ( GPIO_SYSFS "unexport", GPIO_num );
}

int main (){   //funcao principal que retorna um inteiro 0
        int c = 0;  // define uma variavel que serve como contador para o laco while
	habilitar (GPIO_vermelho_num, GPIO_vermelho_path);  // habilita a porta do led vermelho
	habilitar (GPIO_amarelo_num, GPIO_amarelo_path);  // habilita a porta do led amarelo
	habilitar (GPIO_verde_num, GPIO_verde_path);   // habilita a porta do led verde
	while(c<5){;   //laco de recorrencia que irá repetir 5 vezes o que esta contido nele
		alterar_led(GPIO_vermelho_path "value", "1");   // acende o led vermelho por 2 seg
		usleep(2000000);
		alterar_led(GPIO_vermelho_path "value", "0");  // apaga o led vermelho
		usleep(10000);
		alterar_led(GPIO_verde_path "value", "1");   // acende o led verde por 1 seg
		usleep(1000000);
		alterar_led(GPIO_verde_path "value", "0");  // apaga o led verde
		usleep(10000);
		alterar_led(GPIO_amarelo_path "value", "1");   // acende o led amarelo por 1 seg
		usleep(1000000);
		alterar_led(GPIO_amarelo_path "value", "0");  // apaga o led amarelo
		usleep(10000);
                c++; // acrescenta 1 ao contador 
	}
	alterar_led ( GPIO_SYSFS "unexport", GPIO_vermelho_num);  //desabilita a porta do led vermelho
	alterar_led ( GPIO_SYSFS "unexport", GPIO_amarelo_num);  //desabilita a porta do led verde
	alterar_led ( GPIO_SYSFS "unexport", GPIO_verde_num);  //desabilita a porta do led amarelo
        return 0;

}	
