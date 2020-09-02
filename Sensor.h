

#include <dht11.h>     //引用dht11库文件，使得下面可以调用相关参数
#define DHT11PIN 8     //定义温湿度针脚号为8号引脚

dht11 DHT11;

struct Sensor {
  float temperature;
  float humidity;  
} sensor;

void init_sensor(){         //初始化设置
  pinMode(DHT11PIN,OUTPUT);
}

void read_sensor_value(){
  DHT11.read(DHT11PIN);

  sensor.humidity = (float)DHT11.humidity;
  sensor.temperature = (float)DHT11.temperature;
}
