//pin declartaion
//pin mode declaration
//pin data declaration

int trigPin = 10;
int echoPin = 9;
float duration, cm, inch, foot, m, hcm;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = (duration / 2) / 29.1;

    hcm = 213.36 - cm;
    foot = hcm * 0.0328;
    inch = hcm * 0.397;
    m = hcm * 0.01;

    Serial.print("please stand below the sensor");
    Serial.println();
    Serial.print("YOUR HEIGHT:");
    Serial.println();
    Serial.print("in cm:");
    Serial.print(hcm);
    Serial.println();
    Serial.print("in m:");
    Serial.print(m);
    Serial.println();
    Serial.print("in foot:");
    Serial.print(foot);
    Serial.println();
    Serial.print("in inch:");
    Serial.print(inch);
    Serial.println();
}