// Définition des pins
int digitalInputs[] = {7, 8, 12, 13}; //ENTRES DIGITALES 4 ENTREE
int analogInputs[] = {A0, A1, A6, A7}; //ENTRES ANALOG 4 ENTREE
int relayOutputs[] = {2, 3, 4, 5, A2, A3}; // Q1 à Q6
int analogOutputs[] = {6, 9, 10, 11};  //SORTIES ANALOG 4
void setup() 
{     
  Serial.begin(9600);
  //Configurer entrée digitales   
  for (int i = 0; i < 4; i++)  {
  pinMode(digitalInputs[i], INPUT);                         
  }                                                   
  
  //Configurer relais sortie
  for (int i = 0; i < 6; i++)  {
  pinMode(relayOutputs[i], OUTPUT);
  digitalWrite(relayOutputs[i], LOW);
  } 
}
void loop()    
   {
   // Lecture des entrées et activation des relais correspondants (logique inversée)
  digitalWrite(2, digitalRead(7) == LOW ? LOW : HIGH);
  digitalWrite(3, digitalRead(8) == LOW ? LOW : HIGH);


  int potValue = analogRead(14); // 0 à 1023
if (potValue < 475) {
    // TROTTLE DOWN
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    int speed = analogRead(14);
    int pwmVal = map(speed, 0, 496, 52, 0); 
    analogWrite(6, pwmVal);

   } else if (potValue > 545) {
    // TROTTLE UP
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    int speed = analogRead(14);
    int pwmVal = map(speed, 526, 1023, 0, 128);
    analogWrite(6, pwmVal);
    }
    else if (potValue > 476) {
    // NEUTRE
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    int speed = analogRead(14);
    int pwmVal = map(speed, 501, 525, 0, 0); // plus c'est à droite, plus c'est rapide
    analogWrite(6, pwmVal);
    }

    delay(100); // Petite pause pour éviter de trop surcharger
  
  }
