void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int a = 5;
  int p = 8;
  int k;
  
  k = multiply(a,p);
  Serial.print(k);
  delay(100);
}

int multiply(int x, int y){
int result;
result = x * y;
return result;
}
