int pin_2_switchstate = 0;
int pin_3_switchstate = 0;
int pin_4_switchstate = 0;
int pin_5_switchstate = 0;


int pin_2_prevState = 0;
int pin_3_prevState = 0;
int pin_4_prevState = 0;
int pin_5_prevState = 0;






int notes[] = {262, 294, 330, 349};

int light_sequence[100];
int user_input[100];
int sequence_length = 1;
int button_pressed = 0;
boolean generate_random_pattern =true;
boolean show_light_sequence = false;
boolean listen_for_sequence = false;
boolean check_results = false;
boolean not_pressed_3 = true;
boolean not_pressed_4 = true;
boolean not_pressed_5 = true;
boolean not_pressed_6 = true;

boolean start_game = false;


String inputString = "";      
boolean stringComplete = false;


void setup() {
    //start serial communication
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  
  
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT);
 
  inputString.reserve(200);
 
 pinMode(6, INPUT); 
  
  
}

void loop() {
    if (stringComplete) {
      Serial.println(inputString.length());
    if(inputString == "start\n"){
        sequence_length = 1;
        
         start_game = true;
         Serial.println("I am supposed to start the game");
         generate_random_pattern =true;
         show_light_sequence = false;
         listen_for_sequence = false;
         check_results = false;
         delay(2000);
          
          Serial.println("generate game is: "+generate_random_pattern);
         
    }
    Serial.println("the input string was: "+inputString); 
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
  
  // create a local variable to hold the input on pin A0
  pin_2_switchstate = digitalRead(2);
  pin_3_switchstate = digitalRead(3);
  pin_4_switchstate = digitalRead(4);
  pin_5_switchstate = digitalRead(5);
  // send the value from A0 to the Serial Monitor
//  Serial.println(keyVal);

//  Serial.println(pin_4_switchstate);
if(start_game == true){
  
        if(generate_random_pattern == true){
                      digitalWrite(8, HIGH);
                      digitalWrite(9, HIGH);
                      digitalWrite(10, HIGH);
                      digitalWrite(11, HIGH);
                      
      //                Serial.println("i GOT HERE");
                      
                      delay(1000);
              
                      digitalWrite(8, LOW);
                      digitalWrite(9, LOW);
                      digitalWrite(10, LOW);
                      digitalWrite(11, LOW);
                      
                      delay(100);
                   
                      Serial.println("here we are bitches");
                      int val_1;
                      
                     val_1 = random(8,11);
                     light_sequence[sequence_length-1] = val_1;
                     show_light_sequence = true;
                     generate_random_pattern = false;
          
        }
        
        else if(show_light_sequence == true){
          
      //      Serial.println("We begin the light show!!");
            
            
            delay(300);
            for (int thisPin = 0; thisPin < sequence_length; thisPin++) { 
                Serial.println(sequence_length);
                  // turn the pin on:
                  digitalWrite(light_sequence[thisPin], HIGH);   
      //            Serial.println("The LED light is:  "+light_sequence[thisPin]);
                  
                  delay(700);                  
                  // turn the pin off:
                  digitalWrite(light_sequence[thisPin], LOW); 
                 delay(300);   
              }
              show_light_sequence = false;
              button_pressed = 0;
              listen_for_sequence =true;
            
        }
        
        // play the note corresponding to each value on A0
        
        else if(listen_for_sequence ==true){
          
               if(button_pressed<sequence_length){
                 
                         if(pin_2_switchstate == HIGH){
                                if(pin_2_prevState == LOW){
                                          pin_2_prevState = HIGH;
                                    }
                                digitalWrite(8,HIGH);
                            }
                        else if(pin_2_switchstate == LOW){
                                digitalWrite(8,LOW);
                               if(pin_2_prevState == HIGH){
                                          button_pressed++;
                                          user_input[button_pressed-1] = 8;
                                          pin_2_prevState = LOW;
                                }  
                            }
       
       
                          if(pin_3_switchstate == HIGH){
                                if(pin_3_prevState == LOW){
                                          
                                          pin_3_prevState = HIGH;
                                    }
                                digitalWrite(9,HIGH);
                            }
                        else if(pin_3_switchstate == LOW){
                               digitalWrite(9,LOW);
                               if(pin_3_prevState == HIGH){
                                          button_pressed++;
                                          user_input[button_pressed-1] = 9;
                                          pin_3_prevState = LOW;
                                }  
                            }
                            
                            
                          if(pin_4_switchstate == HIGH){
                                if(pin_4_prevState == LOW){
                                          
                                          pin_4_prevState = HIGH;
                                    }
                                digitalWrite(10,HIGH);
                            }
                        else if(pin_4_switchstate == LOW){
                               digitalWrite(10,LOW);
                               if(pin_4_prevState == HIGH){
                                          button_pressed++;
                                          user_input[button_pressed-1] = 10;
                                          pin_4_prevState = LOW;
                                }  
                            }
                          if(pin_5_switchstate == HIGH){
                                if(pin_5_prevState == LOW){
                                          
                                          pin_5_prevState = HIGH;
                                    }
                                digitalWrite(11,HIGH);
                            }
                        else if(pin_5_switchstate == LOW){
                                digitalWrite(11,LOW);
                               if(pin_5_prevState == HIGH){
                                         button_pressed++;
                                         user_input[button_pressed-1] = 11;
                                          pin_5_prevState = LOW;
                                }  
                            }
                            
       
       
       
       
       
                 
                 
      //              if(keyVal == 1023){
      //                if(not_pressed_3 == true){
      //                  user_input[button_pressed] = 3;
      //                  button_pressed++;
      //                  not_pressed_3 = false;
      //                  not_pressed_4 = true;
      //                  not_pressed_5 = true;
      //                  not_pressed_6 = true;
      //                  digitalWrite(3, HIGH);  
      //                }
      //                // play the first frequency in the array on pin 8
      //                tone(8, notes[0]);
      //                digitalWrite(3, HIGH);
      //              }
      
      
      
      
      
      
      
      
      
      
      
                    else{
                      digitalWrite(8, LOW);
                      digitalWrite(9, LOW);
                      digitalWrite(10, LOW);
                      digitalWrite(11, LOW);
                    }
                    
               }
              else if(button_pressed==sequence_length){
                      check_results = true;
              
              
              }
      
          }
       if(check_results == true){
                     boolean user_correct;
                     Serial.println("I am in check results");
                    for (int thisPos = 0; thisPos < sequence_length; thisPos++) { 
      //                          Serial.println(sequence_length);
                                if(light_sequence[thisPos]!=user_input[thisPos]){
                                  Serial.println("end game");
                                  start_game = false;
                                  Serial.println("User Got it wrong, resetting values");
                                  sequence_length = 1;
                                  generate_random_pattern =true;
                                  listen_for_sequence = false;
                                  check_results = false;
                                  user_correct = false;
                                }
                               else{
                               user_correct = true;
                             }
                        }
                     if(user_correct == true){
                      sequence_length++;
                      generate_random_pattern =true;
                      listen_for_sequence = false;
                      check_results = false;
                    }
          
                }
        }
      }







void serialEvent() {
  while (Serial.available()>0) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
