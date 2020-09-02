#include "Sensor.h"
#include "lcd.h"
#include "lightMode.h"

float* sensor_value;

int index_temperature = 6;
int index_humidity = 10;
int index_light_mode = 15;

String tem = "temp:";
String hum = "humidity:";

void display_temp(float temp){
  display(0, index_temperature, temp);
}

void display_humd(float humd){
  display(1, index_humidity, humd);
}

void setup(){
    Serial.begin(9600);
    
    init_lcd();
    init_sensor();
    init_light_mode();

    display(0, 0, tem);
    display(1, 0, hum);
    display(0, index_light_mode, current_light_mode);
}

void loop(){
    read_sensor_value();

    display_temp(sensor.temperature-3);
    display_humd(sensor.humidity);
    
    display( 0, index_light_mode, watch_light_mode() );

    delay(100);
}
