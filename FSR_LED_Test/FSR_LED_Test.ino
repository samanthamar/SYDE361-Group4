int pressurePin = A1;
int force;

const int NoteA=1;
const int NoteB=2;
const int NoteC=3;
const int NoteD=4;
const int NoteE=5;

void setup() {
  Serial.begin(9600);
}

void loop() {

  force = analogRead(pressurePin);
  Serial.println(force);

  if(force > 50)
    {
      randNote();
  } else {

  }

  delay(100);

}

void randNote() {
  int note = random(60,90); // Need to find out the appropriate values
  usbMIDI.sendNoteOn(note, 50, NoteA); // Turn a note on!
  delay(200); // Duration of the note
  usbMIDI.sendNoteOff(note, 0, NoteA); // Make sure to turn it off!
  delay(100); // Duration between notes
}

