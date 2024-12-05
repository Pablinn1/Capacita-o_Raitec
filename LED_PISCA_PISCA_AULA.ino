
// PISCA PISCA LED

#define LED 4 // Definindo o LED como a porta 4

void setup() {

pinMode(LED, OUTPUT);  // Selecionando o LED/Porta digital 4 como OUTPUT (saída de dados)

}
void loop() {

  digitalWrite(LED, HIGH); // Envio um sinal alto para o LED/PINO DIGITAL 4
  delay(500);  // Crio um delay de 500ms/0,5s
  digitalWrite(LED, LOW);  // Envio um sinal alto para o LED/PINO DIGITAL 4
  delay(500);

// Por está alocado no void loop, o código vai se repetir infinitas vezes, permitindo o efeito de liga e desliga do LED.

}
