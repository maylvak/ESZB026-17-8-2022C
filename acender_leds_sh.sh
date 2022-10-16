#!/bin/bash

# Script para acender tres leds consecutivamente 5 vezes, sendo que a ordem é vermelho por 2 segundos, verde e amarelo por 1 segundo

GPIO_amarelo_num = 16  # define o numero da porta associada ao led amarelo como uma variavel
GPIO_vermelho_num = 20  # define o numero da porta associada ao led vermelho como uma variavel
GPIO_verde_num = 21  # define o numero da porta associada ao led verde como uma variavel

definir_led (numero, GPIO_num)  {   # a variavel numero é passada para a funcao
	echo $numero >> "/sys/class/gpio/gpio$GPIO_num/value"  
}

habilitar (GPIO_num) {  # funcao para habilitar a porta 
	echo $GPIO_num >> "/sys/class/gpio/export"  # a variavel é informada para a funcao
	sleep 1                       
	echo "out" >> "/sys/class/gpio/gpio$GPIO_num/direction"
}

desabilitar (GPIO_num) { # funcao para desabilitar a porta 
	echo $GPIO_num >> "/sys/class/gpio/unexport"
}


function main() {  # funcao principal, responsavel por habilitar e desabilitar as portas, assim como acender e apagar os leds na ordem definida
	habilitar (GPIO_amarelo_num)  # habilita a porta do led amarelo
	habilitar (GPIO_vermelho_num)  # habilita a porta do led vermelho
	habilitar (GPIO_verde_num)  # habilita a porta do led verde
	c = 0   # define uma variavel que servira como um contador   
	while [$c -lt 5]  # cria um looping, que para apos 5 repeticoes
	do
		definir_led(1, GPIO_vermelho_num)  # acende o led vermelho por 2 seg
		sleep 2
		definir_led(0, GPIO_vermelho_num)  # desliga o led vermelho
		sleep 0.1
		definir_led(1, GPIO_verde_num)  # acende o led verde por 1 seg
		sleep 1
		definir_led(0, GPIO_verde_num)  # desliga o led verde
		sleep 0.1
		definir_led(1, GPIO_amarelo_num)  # acende o led amarelo por 1 seg
		sleep 1
		definir_led(0, GPIO_amarelo_num)  # desliga o led amarelo
		sleep 0.1
		c=c+1
	done
	desabilitar (GPIO_amarelo_num)  # desabilita a porta do led amarelo
	desabilitar (GPIO_vermelho_num)  # desabilita a porta do led vermelho
	desabilitar (GPIO_verde_num)  # desabilita a porta do led verde
}
main()  # chama e executa a funcao principal
