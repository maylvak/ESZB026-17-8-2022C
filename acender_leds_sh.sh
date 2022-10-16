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
	habilitar (GPIO_amarelo_num)
	habilitar (GPIO_vermelho_num)
	habilitar (GPIO_verde_num)
	c = 0   # define uma variavel que servira como um contador   
	while [$c -lt 5]  # cria um looping, que para apos 5 repeticoes
	do
		definir_led(1, GPIO_vermelho_num)
		sleep 2
		definir_led(0, GPIO_vermelho_num)
		sleep 0.1
		definir_led(1, GPIO_verde_num)
		sleep 1
		definir_led(0, GPIO_verde_num)
		sleep 0.1
		definir_led(1, GPIO_amarelo_num)
		sleep 1
		definir_led(0, GPIO_amarelo_num)
		sleep 0.1
		c=c+1
	done
	desabilitar (GPIO_amarelo_num)
	desabilitar (GPIO_vermelho_num)
	desabilitar (GPIO_verde_num)
}
main()  # chama e executa a funcao principal
