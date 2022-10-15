#!/bin/bash

GPIO_amarelo_num = 16
GPIO_vermelho_num = 20
GPIO_verde_num = 21

definir_led (GPIO_num, value)
{
	echo $1 >> "/sys/class/gpio/gpio$GPIO_num/value"
}

habilitar (GPIO_num)
{
	echo $GPIO_num >> "/sys/class/gpio/export"
	sleep 1                       
	echo "out" >> "/sys/class/gpio/gpio$GPIO_num/direction"
}

desabilitar (GPIO_num)
{
	echo $GPIO_num >> "/sys/class/gpio/unexport"
}


function main()
{
	habilitar (GPIO_amarelo_num)
	habilitar (GPIO_vermelho_num)
	habilitar (GPIO_verde_num)
	c=0
	while [$c -lt 5]
	do
		definir_led(GPIO_vermelho_num, 1)
		sleep 2
		definir_led(GPIO_vermelho_num, 0)
		sleep 0.1
		definir_led(GPIO_verde_num, 1)
		sleep 2
		definir_led(GPIO_amarelo_num, 0)
		sleep 0.1
		c=c+1
	done
	desabilitar (GPIO_amarelo_num)
	desabilitar (GPIO_vermelho_num)
	desabilitar (GPIO_verde_num)
}
