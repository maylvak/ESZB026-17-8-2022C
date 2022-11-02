int ledPin = 11;
const int analogInPin = AO;

void setup() {
  Serial.begin(115200, SERIAL_8N1);
  pinMode(analogInPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valor = analogRead(analogInPin);
  if(valor>=0 && valor<=255){           // verifica se eh um numero valido
            analogWrite(ledPin, level);        // escreve no PWM o valor desejado
            sprintf(buffer, "Brilho do LED ajustado para %d\n", valor);
         }
         else{                                 // nao eh um numero valido
            sprintf(buffer, "%d esta fora da faixa valida.\n", valor);
         } 
  delay(30);
}
