int tempoatual;
int tempoanterior;
int firsttime;
bool estado;

int Botao;
int FimDeCurso;

void setup() {

  //Iniciando a comunicação com o computador
  Serial.begin(9600); 

  //Defininindo pinos de saida e entrada
  pinMode(26, OUTPUT);
  pinMode(13, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  Botao = digitalRead(4);
  if(Botao == 1){
    while(Botao == 1){
      delay(10);
      Botao = digitalRead(4);
    }
    Serial.println();
    Serial.print("Ativando");
    Serial.println();
    digitalWrite(26, LOW);
    delay(300);
    Serial.print("Desativando");
    digitalWrite(26, HIGH);
    tempoanterior = micros();
    firsttime = 0;
  }
  FimDeCurso = digitalRead(2);
  if((FimDeCurso == 1) && (firsttime == 0)){
    firsttime = 1;
    Serial.println();
    Serial.println();
    Serial.print("Tempo decorrido: ");
    Serial.print(micros() - tempoanterior);
    Serial.print(" microsegundos");
  }
}
