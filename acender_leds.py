#!/usr/bin/python3

from time import sleep

path_amarelo = "/sys/class/gpio/gpio16/"  # variavel que contem o caminho para a porta do led amarelo
path_vermelho = "/sys/class/gpio/gpio20/"  # variavel que contem o caminho para a porta do led vermelho
path_verde = "/sys/class/gpio/gpio21/"  # variavel que contem o caminho para a porta do led verde
SYSFS_DIR = "/sys/class/gpio/" # variavel que contem o caminho para o sistema de portas
num_amarelo = "16"  # variavel que contem o valor da porta do led amarelo
num_vermelho = "20"  # variavel que contem o valor da porta do led vermelho
num_verde = "21"  # variavel que contem o valor da porta do led verde

def led(filename,valor,path):  # funcao que permite a alteracao que um arquivo do sistema com o valor que foi fornecido
    f_o = open(path+filename, "w")
    f_o.write(valor)
    f_o.close()
    return

def vermelho():  # funcao para acender e apagar o led vermelho
    #acendendo o led
    led("value","1",path_vermelho)
    sleep(2.0)
    #apagando o led
    led("value","0",path_vermelho)
    sleep(0.1)
    return
    
def verde():  # funcao para acender e apagar o led verde
    #acendendo o led
    led("value","1",path_verde)
    sleep(1.0)
    #apagando o led
    led("value","0",path_verde)
    sleep(0.1)
    return

def amarelo():  # funcao para acender e apagar o led amarelo
    #acendendo o led
    led("value","1",path_amarelo)
    sleep(1.0)
    #apagando o led
    led("value","0",path_amarelo)
    sleep(0.1)
    return

def main():  #definindo funcao principal
    #habilitando porta 16 (led amarelo)
    led("export",num_amarelo,SYSFS_DIR)
    sleep(0.1)
    led("direction","out",path_amarelo)
    #habilitando porta 20 (led vermelho)
    led("export",num_vermelho,SYSFS_DIR)
    sleep(0.1)
    led("direction","out",path_vermelho)
    #habilitando porta 21 (led verde)
    led("export",num_verde,SYSFS_DIR)
    sleep(0.1)
    led("direction","out",path_verde)
    c = 0  # variavel que atua como contador para o laco 
    while c<5:  #recorrencia que ira repetir 5 vezes o que esta dentro do laco
        vermelho()
        verde()
        amarelo()
        c=c+1  # acrescenta 1 a variavel que serve como contador
    #desabilitando as portas dos leds vermelho, verde e amarelo, respectivamente 
    led("unexport",num_vermelho,SYSFS_DIR)
    led("unexport",num_verde,SYSFS_DIR)
    led("unexport",num_amarelo,SYSFS_DIR)
    return
        

main()  #chamando a funcao principal
