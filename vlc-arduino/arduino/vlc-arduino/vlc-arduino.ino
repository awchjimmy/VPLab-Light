void setup() {
  Serial.begin(115200);
}

void loop() {
  // 原本 cmd 底下空格的部份，改成冒號:，好讓我的python不會因為路徑有空白的緣故有bug
  video("vlc:--no-video-title-show:/path/to/video.mp4");
  
  delay(10000);
}

void video(char* cmd) {
  Serial.println(cmd);  
}
