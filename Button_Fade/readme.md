<pre><code>


	// 핀의 번호(위치)를 지정한다:
int buttonPin = 2;     // 푸시버튼의 이름은 buttonPin이고 핀의 위치는 2번 
int ledPin =  9;      // LED 전구의 이름은 ledPin이고 핀의 위치는 9번 

	// 변수: 
int buttonState = 0;         // 푸시버튼의 상태를 읽기위한 변수 

	// 아래의 코드를 바꾸면 LED가 페이딩하는 속도가 바뀐다. 
int delayAmount=30;     // 페이딩 단계 간 딜레이의 양  
int fadeAmount=5;       // 페이딩 단계의 크기 

void setup() {
   pinMode(ledPin, OUTPUT);	 //  LED 전구를 출력으로 지정한다.        
   pinMode(buttonPin, INPUT_PULLUP);	// 푸시버튼을 입력으로 사용하고 풀업 인풋으로 지정한다.      
}

void loop(){

  buttonState = digitalRead(buttonPin); // 푸시버튼의 상태를 읽는다. 

  // 버튼이 눌려졌나 확인하고, 그렇다면 buttonState은 LOW 이다. 
  
  if (buttonState == LOW) {     
  
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=fadeAmount) 
  	// 그러면 페이딩의 값 fadeValue는 0에서 255까지 fadeAmount에서 지정한 단계로 증가한다. 
  	// 이 코드에는 5로 지정되어 있어서 0에서 5, 그 다음에 10, 15로 커진다. 
  	// 그 단계의 크기는 int fadeAmount의 수를 바꿈으로 조정할수 있다. 
  	// for statement를 처음 경험하는 사람이라면 위의 코드를 "이런 조건이 충족되는 동안 (fadeValue라는 정수는 0이고 ; fadeVlaue가 255이 되기 전까지는; fadeValue 에 fadeAmount를 한번 더하라" 라고 이해하면 된다. 
  
  { 
	  analogWrite(ledPin, fadeValue);         
    // 0에서 255 사이에서 증가하고 있는 수 중에서 현재의 값을 지정하고, analogWrite으로 ledPin에 출력한다. 
    // analogWrite은 PWM (pulse width modulation)을 사용해서 디지털 값으로 아날로그적인 출력을 흉내낸다. 
    // 즉 아주 빨리 꺼졌다 켜졌다 하면서 페이딩 효과를 보여준다. 
    
       delay(delayAmount);                            
 	 // 딜레이의 양만큼 기다려서 빛의 밝기가 서서히 변하도록 한다.  

 
  } 

  // fade out from max to min in increments of fadeAmount:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=fadeAmount) 
  
  // fadeValue가 255가 되면 반대로 최대치에서 최소치로 페이드 아웃한다. 
  // fadeValue -= fadeAmount를 주목하자. 
  // 증가했을때와 마찬가지의 값인 fadeAmount 만큼씩 줄어든다.  
  { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for delayAmount milliseconds to see the dimming effect    
    delay(delayAmount);                            
 	// 이곳의 코드는 위의 증가하는 코드와 동일하다. 
 
  }
  }
  
  
 	//여기에서 if(buttonState == LOW) 외의 모든 조건(else)에 대해 정의하면  
  else {

    analogWrite(ledPin, 0); 
	//ledPin에 0의 값, 즉 전구를 라. 
  }
}
</code>
</pre> 