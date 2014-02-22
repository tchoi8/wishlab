<pre><code>

const int buttonPin = 2;    
<<<<<<< HEAD
	// 컨스턴트(Constant)는 바뀌지 않는 상수이다. 이곳에서는 핀의 번호를 지정하기 위해 사용된다.
	// "상수를 정의하는데 그것은 정수이며 이름은 buttonPin 이다." 
=======
	// 컨스턴트(Constant)는 바뀌지 않는 값, 즉 상수이다. 여기서는 핀의 번호를 지정하기 위해 사용된다.
	// "상수를 정의한다. 그것은 정수이며 이름은 buttonPin 이다." 
>>>>>>> 7dbd83e3c4dda2cfe070b3610a51feb1a6feb85e
	// 즉 버튼핀 buttonPin이라는 이름을 2번 핀에게 지정하는 것이다.
	// [achim] 정수인 변수 buttonPin에 2라는 상수값을 부여한다.
	// [achim] do we need introduce read-only variable for wishlab? confusing, also might as well be "int buttonPin = 2;" for our use
const int ledPin =  9;   
	// ledPin 불빛이 나오는 LED가 연결된 핀은 아두이노의 9번째 핀에 연결한다.
int buttonState = 0;         
	// 버튼의 상태를 읽기 위한 수가 필요하다. 그러면 값이 변할수 있는 변수를 사용한다.

void setup() {
  
  pinMode(ledPin, OUTPUT);   
    // ledPin은 아웃풋, 출력으로 지정한다.
  
  pinMode(buttonPin, INPUT_PULLUP);
    // buttonPin, 즉 푸시버튼의 핀을 인풋, 입력으로 사용하기 위해서 풀업-인풋으로 지정한다.  
    // INPUT_PULLUP이란 아두이노의 내부적으로 풀업을 실행하고 있도록 한다. 
    // 즉 푸시버튼과 저항으로 pull up button을 만들었을때 처럼 작동하게 된다.
}

void loop(){
   
   buttonState = digitalRead(buttonPin);  
   // 푸시버튼의 값을 읽자. 이 코드를 그대로 읽으면,
   // "푸시버튼의 상태는 버튼핀(위 코드에서 2번 핀으로 지정한 상수이다)을 디지털 신호로 읽어라."

  //아래 코드에서는 버튼이 눌러졌는지 확인하고, 그렇다면 buttonState을 HIGH 참으로 지정한다. 그 코드가 만들어진 방법을 유심히 살펴보자.

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
    // turn LED off: LED를 꺼라, 즉 버튼이 ON이면 -- 이것은 pull up resistor 때문에
    digitalWrite(ledPin, LOW); 
  }
}
</code></pre>
