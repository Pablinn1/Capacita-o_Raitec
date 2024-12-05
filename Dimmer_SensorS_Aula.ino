#define LED 3
#define ultrasomEcho 12
#define ultrasomTrigger 13

float distancia;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(ultrasomEcho, INPUT);
    pinMode(ultrasomTrigger, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // Calcular a distância
    distancia = calcularDistancia();

    // Mapeio a Luminosidade para uma faixa de valores de 0 á 255
    int brilho = map(distancia, 0, 200, 255, 0); // Menor distância = maior brilho //map(valor, entrada_min, entrada_max, saida_min, saida_max)

    // Limitar o brilho para evitar valores fora do intervalo
    brilho = constrain(brilho, 0, 255); // constrain(valor, minimo, maximo)

    // Ajustar a luminosidade do LED
    analogWrite(LED, brilho);

    // Mostrar a distância e o brilho no monitor serial
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.print(" cm | Brilho: ");
    Serial.println(brilho);

    delay(100); // Pequeno atraso para estabilizar
}

float calcularDistancia() {
    digitalWrite(ultrasomTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(ultrasomTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasomTrigger, LOW);

    long duracao = pulseIn(ultrasomEcho, HIGH); 
    float distancia = (duracao * 0.0343) / 2; // Converter o tempo em distância
    return distancia; // Retorna o valor de distancia para a função
}
