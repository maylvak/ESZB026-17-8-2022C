from time import sleep
path_amarelo = "/sys / class / gpio / gpio16 / "
path_vermelho = "/sys / class / gpio / gpio20 / "
path_verde = "/sys / class / gpio / gpio21 / " 
SYSFS_DIR = "/ sys / class / gpio / "
num_amarelo = "16"
num_vermelho = "20"
num_verde = "21"

def led(filename,valor,path):
    f_o = open(path+filename, "w")
    f_o.write(valor)
    f_o.close()
    return

def vermelho():
    #acendendo o led
    led("value","1",path_vermelho)
    sleep(2.0)
    #apagando o led
    led("value","0",path_vermelho)
    sleep(0.1)
    return
    
def verde():
    #acendendo o led
    led("value","1",path_verde)
    sleep(1.0)
    #apagando o led
    led("value","0",path_verde)
    sleep(0.1)
    return

def amarelo():
    #acendendo o led
    led("value","1",path_amarelo)
    sleep(1.0)
    #apagando o led
    led("value","0",path_amarelo)
    sleep(0.1)
    return

def main():
    #habilitando porta 16
    led("export",num_amarelo,SYSFS_DIR)
    sleep(0.1)
    led("direction","out",path_amarelo)
    #habilitando porta 20
    led("export",num_vermelho,SYSFS_DIR)
    sleep(0.1)
    led("direction","out",path_vermelho)
    #habilitando porta 21
    led("export",num_verde,SYSFS_DIR)
    sleep(0.1)
    led("direction","out",path_verde)
    c = 0
    while c<5:
        vermelho()
        verde()
        amarelo()
        c=c+1
    #desabilitando
    led("unexport",num_vermelho,SYSFS_DIR)
    led("unexport",num_verde,SYSFS_DIR)
    led("unexport",num_amarelo,SYSFS_DIR)
    return
        

main()
