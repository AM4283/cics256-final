import controlP5.*; //impot library
import processing.serial.*;
final String serialName = "/dev/ttyUSB0"; // change this
ControlP5 cp5; //create gui obj
Serial port;
PFont font;
int paused = 0;
void setup() {
  size(300,400); //win size 500x500
  cp5 = new ControlP5(this);
  font = createFont("verdana", 20); //custom font for button
  port = new Serial(this, serialName, 9600);
  cp5.addButton("Pause") //name of button
    .setPosition(100, 50) //pos of button (upper left coord)
    .setSize(100, 80) //width*height
    .setFont(font)
  ;
}
void draw() {
  background(150, 0, 150); //bg color of window
  fill(0, 255, 0); //text color
  textFont(font);
  text("Sequence Memory Game", 100, 30); //text, x, y
  if(port.available() > 0) {
    byte data[] = port.readBytes();
    String score = "Score: ";
    //score.concat(String.valueOf(data[0]));
    text(score.concat(String.valueOf(data[0])), 100, 80);
    String currentLevel = "Current: ";
    text(currentLevel.concat(String.valueOf(data[1])), 100, 110);
    if (data[2] == 1) {
      text("Wrong!", 100, 130);
      text("Try again?", 100, 160);
      paused = 1;
      port.write(paused);
    }
  }
    
}
void pause() {
  paused = paused == 1 ? 0 : 1;
  port.write(paused);
}
