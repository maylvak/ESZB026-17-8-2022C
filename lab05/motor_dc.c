#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {
   int duty,divisor;                            // este programa deve ser rodado com 'sudo'
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware
   pwmSetRange(1000);
   pwmSetClock(38);
   // Ajustando a frequencia do PWM em 261,6 Hz com 1005 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // f = 19200000 / (divisor * range) => divisor = 73
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   for (duty = 1; duty < 1000; duty++){  
        printf("Testando motor. ");
        printf("Range = %d \n",duty);
        pwmWrite(pino_PWM0, duty);
	usleep(10000);
    }
   pwmWrite(pino_PWM0, 0);
   
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
