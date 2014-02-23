<pre><code>

int buttonPin = 2;    
	// 버튼핀 buttonPin이라는 이름을 2번 핀에게 지정한다.
	
int ledPin =  9;   
	// ledPin 불빛이 나오는 LED가 연결된 핀은 아두이노의 9번째 핀에 연결한다.
	
int buttonState = 0;         
	// 버튼의 상태를 읽기 위한 값이 변할수 있는 변수를 사용한다.

void setup() {
  
  pinMode(ledPin, OUTPUT);   
    // ledPin은 아웃풋, 출력으로 지정한다.
  
  pinMode(buttonPin, INPUT_PULLUP);
    // buttonPin, 즉 푸시버튼의 핀을 인풋, 입력으로 사용하기 위해서 풀업-인풋으로 지정한다.  
    // INPUT_PULLUP이란 아두이노의 내부적으로 풀업을 실행하고 있도록 한다. 
    // 즉 푸시버튼과 저항으로 회로에서 pull up button을 만들었을때 처럼 작동해서 
    //버튼이 눌리지 않은 상태에서는 HIGH 신호를 읽는다.
}

void loop(){
   
   buttonState = digitalRead(buttonPin);  
   // 푸시버튼의 값을 읽자. 이 코드를 그대로 읽으면,
   // "푸시버튼의 상태는 버튼핀(위 코드에서 2번 핀으로 지정한 상수이다)을 디지털 신호로 읽어라."

  //아래 코드에서는 버튼이 눌러졌는지 확인하고, 그렇다면 위에서 설정한 푸시버튼의 값 buttonState을 HIGH 참으로 지정한다.  

  if (buttonState == LOW) 
  	// 만약에 버튼의 상태가 LOW라면, 즉 0볼트라면 다음과 같은 작동을 명령한다.
  
  {
    // LED 전구를 깜빡여라!
    digitalWrite(ledPin, HIGH); 
    	// ledPin을 High, 즉 5볼트의 시그널을 보낸다.
    delay(1000);
    	// 1초동안 대기하라// 즉 1초동안 불을 켜라.
    digitalWrite(ledPin, LOW);
    	// ledPin을 Low, 즉 0볼트 혹은 그라운드를 연결한다.
    delay(1000); 
    	//1초동안 불을 꺼라
  } 
  else { //그렇지 않으면
    digitalWrite(ledPin, LOW); 
    	// turn LED off: LED를 꺼라 (pull up resistor 때문에 버튼의 기본 상태가 ON이다)  
    
  } // 여기서 if(buttonState == LOW)의 컬리 브라캣 '{' 을 닫아준다.   
} // 여기서 루프를 닫아준다. 
</code></pre>
