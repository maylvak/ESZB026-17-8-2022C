#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {
   int ciclos, dc;                            // este programa deve ser rodado com 'sudo'
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // Ajustando a frequencia do PWM em 261,6 Hz com 1005 passos de duty cycle
   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 261,6 = 19200000 / (divisor * 1005) => divisor = 73
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(1005);                    // passos do duty cycle (max=4096)
   pwmSetClock(73);                     // fornece uma frequencia de 261,1 Hz (max=4096)
   for(ciclos = 0; ciclos < 1; ciclos++){    //repete duas vezes
        for(ciclos = 0; ciclos < 3; ciclos++){  // variando o duty cycle 
             pwmWrite(pino_PWM0, 502);
             usleep(1000000);
             pwmWrite(pino_PWM0, 0);
             usleep(500000);
         }
         usleep(1000000);
         for(ciclos = 0; ciclos < 1; ciclos++){
             pwmWrite(pino_PWM0, 502);
             usleep(1000000);
             pwmWrite(pino_PWM0, 0);
             usleep(500000);      

   }
}
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
