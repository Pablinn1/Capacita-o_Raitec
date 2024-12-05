
#define LED 4
#define ECHO 12    // Defino o nome de cada pino Digital que irei utilizar
#define TRIGGER 13

float distancia0;

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(ECHO, INPUT);    // Definir ECHO como entrada de dados
  pinMode(TRIGGER, OUTPUT); // Definir TRIGGER como saída de dados

  Serial.begin(9600); // Ativar o monitor serial

}

void loop() {

distancia0 = calcularDistancia(); //Chamo a função distancia para ser repetida no loop e guardo o seu valor na variavel distancia

Serial.println(distancia0); // Printo a distância no Monitor serial


}

float calcularDistancia() { // Função para calcular a distancia captada pelo Sensor

digitalWrite(TRIGGER, LOW); // Trigger começa desabilitado
delayMicroseconds(2);
digitalWrite(TRIGGER, HIGH); // Trigger ativado
delayMicroseconds(10); 
digitalWrite(TRIGGER,LOW); // Trigger volta a ser desativado


long duracao = pulseIn(ECHO, HIGH); //Mede o tempo que o pino Echo fica em estado HIGH, indicando o tempo que o pulso levou para atingir o objeto e retornar.


float distancia = (duracao * 0.0343) / 2; // Converto o tempo em distancia

return distancia; // Retorna o valor de distancia para a função

}