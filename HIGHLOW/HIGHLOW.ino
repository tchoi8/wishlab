
int LEDPin = 13;                
	// LED 전구를 13번 핀에 연결한다. 브래드보드를 사용할 경우에는 LED의 긴 다리를 핀에 연결하고 짧은 다리를 저항을 통해 그라운드에 연결한다. 

void setup()
{
  pinMode(LEDPin, OUTPUT);      
  	// 셋업에서 pinMode로 LEDPin은 아웃풋이라고 정의한다.   
}

void loop()
{
  digitalWrite(LEDPin, HIGH);   // LED핀을 HIGH로 지정해라. 
  delay(1000);                  // 1초를 대기해라, 즉 1초간 켜있어라. 
  digitalWrite(LEDPin, LOW);    // LED 핀을 LOW로 지정해라. 
  delay(1000);                  // 1초간 대기해라.
}
