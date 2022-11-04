#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // biblioteca para comunicacao serial

int habilitar(){
   int file, count;
   if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("UART: Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;             // cria estruturas para configurar a comunicacao
   tcgetattr(file, &options);          // ajusta os parametros do arquivo

   // Configura a comunicacao
   // 115200 baud, 8-bit, enable receiver, no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;   // ignora erros de paridade
   tcflush(file, TCIFLUSH);            // descarta informacao no arquivo
   tcsetattr(file, TCSANOW, &options); // aplica alteracoes imediatamente
   unsigned char transmit[23] = "Testando a comunicacao\0";  // cria uma frase (\0 indica o final da mensagem)
   if ((count = write(file, &transmit, 23))<0){             // transmite a frase
      perror("Falha ao escrever na saida\n");
      return -1;
   }
   usleep(100000);                     // Espera 100ms pela resposta do Arduino
   unsigned char receive[100];         // cria um buffer para receber os dados
   if ((count = read(file, (void*)receive, 100))<0){        // recebe os dados
      perror("Falha ao ler da entrada\n");
      return -1;
   }
   if (count==0) printf("Nao houve resposta!\n");
   else printf("Foram lidos [%d] caracteres: %s\n",count,receive);
   close(file);
   int resposta;
   sscanf(receive, "%d", &resposta);
   return resposta;
}

int main(){
	int pino_PWM = 23;                         // pwm por software na GPIO23
	int brilho;
	int c= 0;
	int range = 100;                           // periodo do PWM = 100us*range
	wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
	brilho = habilitar();
	pinMode(pino_PWM,OUTPUT);	           // configura GPIO23 como saida
	softPwmCreate(pino_PWM, 1, range);         // inicializa PWM por software
	while (c<=4){
		softPwmWrite (pino_PWM, brilho); // altera o duty cycle do PWM	
		delay (10);                     // aguarda 10ms
		c=+1;
	}
	return 0;
		
}
