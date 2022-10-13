< iostream >;
< fstream >;
< string >;
< unistd . >;
using namespace std ;

GPIO_amarelo_num = "16";
GPIO_amarelo_path = "/sys/ class / gpio / gpio16 /";
GPIO_vermelho_num = "20";
GPIO_vermelho_path = "/sys/ class / gpio / gpio20 /";
GPIO_verde_num = "21";
GPIO_verde_path = "/sys/ class / gpio / gpio21 /";
GPIO_SYSFS = "/ sys / class / gpio /";

void alterar_led ( string path , string filename , string value ){
	fstream fs;
	fs.open ((path + filename). c_str () , fstream :: out );
	fs << value ;
	fs . close () ;
}


void acender (GPIO_path){
	alterar_led ( string ( GPIO_path ) , " value ", "1");
}

void desligar (GPIO_path){
	alterar_led ( string ( GPIO_path ) , " value ", "0");
}

void habilitar (GPIO_num, GPIO_path){
	alterar_led ( string ( GPIO_SYSFS ) , " export ", GPIO_num );
	usleep (100000) ;
	alterar_led ( string ( GPIO_path ) , " direction ", " out ");
}

void desabilitar (GPIO_num){
	writeGPIO ( string ( GPIO_SYSFS ) , " unexport ", GPIO_num );
}

void loop (){
	c = 0;
	habilitar (GPIO_vermelho_num, GPIO_vermelho_path);
	habilitar (GPIO_amarelo_num, GPIO_amarelo_path);
	habilitar (GPIO_verde_num, GPIO_verde_path);
	while c<5;
		acender (GPIO_vermelho_path);
		usleep(200000);
		desligar (GPIO_vermelho_path);
		usleep(1000);
		acender (GPIO_verde_path);
		usleep(200000);
		desligar (GPIO_verde_path);
		usleep(1000);
		acender (GPIO_amarelo_path);
		usleep(200000);
		desligar (GPIO_amarelo_path);
		usleep(1000);
	desabilitar (GPIO_vermelho_num);
	desabilitar (GPIO_amarelo_num);
	desabilitar (GPIO_verde_num);
}	
