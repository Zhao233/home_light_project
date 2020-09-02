#define LIGHT_WIRE_OUT 7

#define MODE_1 1
#define MODE_2 3
#define MODE_3 5
#define MODE_4 7

int light_mode_[4] = { MODE_1, MODE_2, MODE_3, MODE_4};

int index_light_mode_;

int current_light_mode;

bool buttonState;

void init_light_mode(){
  pinMode(LIGHT_WIRE_OUT, INPUT);
  current_light_mode = MODE_2;
}

int watch_light_mode(){
  if(digitalRead(LIGHT_WIRE_OUT) == HIGH) {
    //buttonState = !buttonState;
    index_light_mode_++;
    
    if( index_light_mode_ > 3 ){
      index_light_mode_ = 0;
    }
    
    while (digitalRead(LIGHT_WIRE_OUT) == HIGH);

    current_light_mode = light_mode_[index_light_mode_];
    return current_light_mode;
  }

}
  
