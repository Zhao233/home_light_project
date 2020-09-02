#include <Wire.h>

#include <LiquidCrystal_I2C.h> //引用I2C库

#define ADDR 0x27
#define WORDS 16
#define LINE 2

LiquidCrystal_I2C lcd(ADDR, WORDS, LINE);

int index_line_0 = 0;
int index_line_1 = 0;

void init_lcd() {
    lcd.init(); // 初始化LCD
    lcd.backlight(); //设置LCD背景等亮
}

// line:  lcd的行数( 1602: 0-1 )
// index: 字符的开始指针(1602: 0-15 )
// word:  显示的内容
void display(int line, int index, String content) {
    lcd.setCursor(index, line);
    lcd.print(content);
}

void display(int line, int index, float temp) {
    lcd.setCursor(index, line);
    lcd.print(temp);
}
