/*
 * Ver. 0.3
 * oBeacon.setManufacturerId(0x004c); --> oBeacon.setManufacturerId(0x4c00);
 */

#include <M5StickC.h>

// function
#define GLOW_OFF 0
#define GLOW_ON 1
#define GROUP_ID_START 2
#define GROUP_ID_END 3
#define DEVICE_ID_START 4
#define DEVICE_ID_END 5

const uint32_t TargetGroup = 1; //グループIDを書き込む場合のグループIDを指定します
const uint32_t TargetID    = 1; //デバイスIDを書き込む場合のデバイスIDを指定します
const uint32_t CommandRed  = 0x2064;
const uint32_t CommandOff  = 0x0;

void setup()
{ 
  M5.begin();
  M5.Lcd.setRotation(0);
  M5.Lcd.setCursor(0, 40);
  Serial.begin(115200);
  init_BLE("GlowSDK");
  delay(100);
}

void loop()
{
  uint32_t group;
  uint32_t id;

  for (int i=1;i<=5;i++){
    group=1;
    id=i;
    displayOut(GLOW_ON,group,id,CommandRed);
    sendGlowData(GLOW_ON,group,id,CommandRed);
    delay(100);
    
    group=1;
    id=i;
    displayOut(GLOW_OFF,group,id,CommandOff);
    sendGlowData(GLOW_OFF,group,id,CommandOff);
    delay(100);

    if (M5.BtnA.wasPressed())DeviceIDwrite();    // Aボタンを押すとデバイスIDの書き込み
    if (M5.BtnB.wasPressed())GroupIDwrite();     // Bボタンを押すとグループIDの書き込み
    M5.update();
  }
}

// GLOWの電源を切った状態からM5StickCのAボタンを押し
// 赤文字でGrp:XXが表示されている間に書き込み対象GLOWの電源スイッチを入れます

void GroupIDwrite(){  
  sendGlowData(GROUP_ID_START,TargetGroup,0,0);
  displayOutGroupID(TargetGroup);
  delay(5000);
  sendGlowData(GROUP_ID_END,TargetGroup,0,0);
  displayOutEnd(); 
  delay(3000);
}

// GLOWの電源を切った状態からM5StickCのBボタンを押し
// 赤文字でID:XXが表示されている間に書き込み対象GLOWの電源スイッチを入れます

void DeviceIDwrite(){
  sendGlowData(DEVICE_ID_START,0,TargetID,0);
  displayOutDeviceID(TargetID);
  delay(5000);
  sendGlowData(DEVICE_ID_END,0,TargetID,0);
  displayOutEnd();  
  delay(3000);
}

/***************
 * Diplay out
 */

void displayOutGroupID(int group){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 35);
  M5.Lcd.printf("Grp:");
  M5.Lcd.setCursor(10, 55);
  M5.Lcd.printf("%d", group);
}

void displayOutDeviceID(int id){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 35);
  M5.Lcd.printf("ID:");
  M5.Lcd.setCursor(10, 55);
  M5.Lcd.printf("%d", id);
}

void displayOutEnd(){
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 90);
  M5.Lcd.printf("End");
}

void displayOut(uint32_t func, uint32_t group, uint32_t id, uint32_t command){
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(GREEN);
  M5.Lcd.setTextSize(2);

  M5.Lcd.setCursor(10, 10); // Function
  M5.Lcd.printf("F:");
  M5.Lcd.setCursor(35, 10);
  M5.Lcd.printf("%d", func);

  M5.Lcd.setCursor(10, 35); // Group
  M5.Lcd.printf("G:");
  M5.Lcd.setCursor(35, 35);
  M5.Lcd.printf("%d", group);

  M5.Lcd.setCursor(10, 60); // ID
  M5.Lcd.printf("ID:");
  M5.Lcd.setCursor(10, 80);
  M5.Lcd.printf("%d", id);

  M5.Lcd.setCursor(10, 105);  // Command
  M5.Lcd.printf("Cmd:");
  M5.Lcd.setCursor(10, 125);
  M5.Lcd.printf("%x", command);
}
