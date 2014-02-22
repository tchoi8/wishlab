wishlab
=======
This tutorial and sample codes for working with Arduino during *Wishlab* with Kobakant in Making Lab.
4회 안양공공예술프로젝트 만들자연구실에 초청한 코바칸트의 '소원 연구실' 워크숍을 위한 아두위노 정보 모음입니다.  




아두위노 소프트웨어 설치 방법 
---
윈도우스 설치 방법 

매킨토시 설치 방법  

* 붓로더? Bootloader? 
* 컴파일? Compile? 
* 업로드? Upload?  
* 시리얼 통신? Serial communication? 
* 핀? Pin? 


아두위노 마이크로 Arduino Micro
---
![](https://dlnmh9ip6v2uc.cloudfront.net/r/600-600/assets/9/c/3/c/4/523a1765757b7f5c6e8b4567.png)



아두위노는 작은 컴퓨터이자 디지털 신호의 입출력을 제어할수 있는 마이크로 컨트롤러(Microcontroller)이다. 아두위노의 핀은 인풋이자 아웃풋으로 사용될수 있으며 그것은 소프트웨어에서 지정해 준다. 위의 그림을 보면 하나의 핀에 여러가지 활용 가능성이 채크된 것을 확인할수 있다. 


아두위노는 USB 케이블을 통해서 *시리얼 통신*으로 컴퓨터와 소통한다. 
TX: 시리얼 통신 송신 (트랜시버 Tranciever의 약자) 

RX: 시리얼 통신 수신 (리시버 Reciever의 약자) 

GND: 그라운드. 전원에서 보내진 전기가 흐르는 곳. 전원의 마이너스, 즉 0V (0 볼트) 

RAW: 아두위노의 전원을 공급하는 곳. USB 케이블로 연결해도 마찬가지. 5볼트 기준이지만 12볼트까지 가능.

VCC: 아두위노가 제공하는 5볼트 전원. 브래드보드에 연결해서 다양한 센서나 스위치 사용에 활용이 가능하다.

Analog: Analog to Digital Converter 아날로그 신호를 디지털 신호로 변환할수 있는 핀이다. 즉 빛 센서 등의 값을 아두위노가 읽을수 있도록 연결한다. 
 
PWM: Pulse width modulation 디지털 핀으로 아날로그 값을 재현할수 있다. 
analogWrite([pin], [value])을 사용한다. 

SCLK, MISO, MOSI: [SPI](http://arduino.cc/en/Reference/SPI)

**초보자가 가장 범하기 쉬운 실수: GND와 VCC가 직접 연결이 되면 혼선이 되서 아두위노가 쇼트된다. 그러면 아두위노의 전원을 제공하고 프로그램을 업로드 하던 컴퓨터의 USB 드라이브로 역전류가 흘러서 하드웨어의 손상을 줄 가능성이 있다. 브레드보드 작업시 유의하면 안전하게 프로토타입 구현이 가능하다. **  
 

만들자연구실에서 준비한 아두위노는 Pro Micro이고 자세한 정보는 [이곳에](https://www.sparkfun.com/products/12640) 있다.
 
Digital signal 디지털 신호와 프로그래밍   
---
 
**Input/ Output**
 
인풋은 현실세계의 물리적인 값이 들어오는 핀이다. 

아웃풋은 디지털 신호가 전기로 출력되는 핀이다 .

아두위노에서 인풋핀은 아웃풋핀으로 지정이 가능하다. 

**Binary logic** 

True or False (참과 거짓)

True는 1 혹은 0이 아닌 모든 수, 혹은 5v 볼트  

False는 0, 혹은 0 v볼트  
  
Q: 그러면, 전기 신호가 언제나 0 혹은 5일수는 없으니 아두위노는 언제 신호가 참인지 거짓인지 판단하나?
A: 인풋일 경우에는 3볼트 이상이면 True, 그보다 낮으면 False로 판단한다. 아웃풋은 언제나 5볼트로 출력한다.  

* 전기와 프로그래밍은 같은 원리로 작동하기 때문에 때로는 High와 Low로 True and False를 사용하기도 한다. 

<pre><code>

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
  delay(1000);                  // 1초를 대기해라, 즉 1초간 켜있어라. 1000 밀리세컨트는 1초.  
  digitalWrite(LEDPin, LOW);    // LED 핀을 LOW로 지정해라. 
  delay(1000);                  // 1초간 대기해라.
}
</code></pre>
 
 
이 코드가 작동한다면 해볼것! 
 Serial println으로 시리얼 창에 보여주기 
 
프로그래밍 언어에 자주 사용되는 표현 
---

프로그래밍에서 사용하는 기본적인 개념과 표현이 있다. 기초 수학을 기억해 보면 이해하기가 쉽다. 

**Integer: 정수**
 
수학에서 "음(陰)의 정수(…,－3,－2,－1), 0, 양(陽)의 정수(1,2,3,…)를 합한 것, 즉 자연수 전체에 그 역원과 0을 합한 것이다."으로 정의한다.  

프로그래밍에서 정수는 수의 값을 기억하기 위한 데이터의 종류이다. 아두위노에서 정수는 글자의 앞자리를 따서 int로 쓴다. 16비트의 정보를 담을수 있어서 -32768 부터 32767 까지의 값을 표현할수 있다. 
  
<pre><code> int var = val; </code></pre>

이 코드에서는 세가지의 표현이 사용된다. 코드를 인간의 언어로 풀어쓰면 *"정수의 값(int)은 var(variable)라는 이름의 변수이고 그 값은 val (value, 값의 약자)이다"*.   

 

**Function: 함수**

수학에서 "변수 x와 y 사이에 x의 값이 정해지면 따라서 y값이 정해진다는 관계가 있을 때, y는 x의 함수라고 한다"로 정의 한다. 

**Variable: 변수**

조건에 따라서 값이 변하는 수, 혹은 여러 수를 담을수 있는 자리. 

 
 <pre><code> 

void setup(){
  Serial.begin(9600);
//이것은 프로그램이 시리얼 통신으로 작동하도록 정의한다}

void loop 
{
	//이곳에서 프로그램의 루프가 돌아간다. 컬리 브래킷 { 안이 루프된다.  
int a = 5;
	// 정수 a의 값은 5이다. 
int p = 8;
	// 정수 p의 값은 8이다. 
int k;
	// 정수 k는... 
k = multiply(i, j); // 
	// k는 i와  j를 곱한 값이다.
Serial.print(k);
	// k의 값을 시리얼로 출력한다. 
}
	// 컬리 브래킷을 닫아서 이곳에 루프가 끝난다. 

//그러면 이제 multiply 곱하기 함수를 정의하자.  
int multiply(int x, int y){
	// multiply라는 함수는 x와 y라는 매게변수(parameter)를 필요로 하는 정수이다. 
int result;
	// result 결과값이라는 정수를 또 정의한다. 
result = x * y;
	// result란 x 와 y의 곲이다. ;를 빼먹으면 안된다. 
return result;
	// result의 결과를 함수의 결과로 리턴한다.  
}

</code></pre>

프로그래밍 언어에서 함수는 다양한 방법으로 사용된다. 예를들어 C 언어에서 함수의 사용. 
 
![](http://arduino.cc/en/uploads/Reference/FuncAnatomy.png)
 

**Constant: 항수** 

* 어떤 관계를 통하여 일정 불변의 값을 가진수와 양.  





고급반
=== 
 
[Blink without delay](http://arduino.cc/en/Tutorial/BlinkWithoutDelay#.UwcXPUKSyTE)

[Delay를 피하는 방법](http://playground.arduino.cc/Code/AvoidDelay)