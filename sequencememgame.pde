import controlP5.*; //impot library
import processing.serial.*;
final String serialName = "/dev/ttyUSB0"; // change this
ControlP5 cp5; //create gui obj
Serial port;
PFont font;
int paused = 0;
void setup() {
  size(500,500); //win size 500x500
  cp5 = new ControlP5(this);
  font = createFont("verdana", 20); //custom font for button
  port = new Serial(this, serialName, 9600);
  //cp5.addButton("Pause") //name of button
  //  .setPosition(100, 50) //pos of button (upper left coord)
  //  .setSize(100, 80) //width*height
  //  .setFont(font)
  //;
  cp5.addButton("instructions").setPosition(100,50).setSize(100,25).setFont(createFont("verdana",8));
}
String score = "Score: ";
String scoreNum = "0";
int instruction = 0;

void draw() {
  background(255, 255, 255); //bg color of window
  fill(0, 0, 0); //text color
  textFont(font);
  text("Sequence Memory Game", 100, 30); //text, x, y
  if(port.available() > 0) {
    int data = port.read();
    //score.concat(String.valueOf(data[0]));
    scoreNum = Integer.toString(data);
    //text(score.concat(String.valueOf(data[0])), 100, 80);
    //String currentLevel = "Current: ";
    //text(currentLevel.concat(String.valueOf(data[1])), 100, 110);
    //if (data[2] == 1) {
    //  text("Wrong!", 100, 130);
    //  text("Try again?", 100, 160);
    //  paused = 1;
    //  port.write(paused);
    //}
  }
  text(score.concat(scoreNum), 200, 150);
  if (instruction == 1) {
    textFont(createFont("Verdana", 8));
    text("How to Play:\n Press the LEDs in the same sequence they lit up on the board. After each round, another LED is added to the sequence.\nThe sequence restarts if you press the incorrect LED", 150, 400);
  }
    
}
void pause() {
  paused = paused == 1 ? 0 : 1;
  port.write(paused);
}
void instructions() {
  instruction = instruction == 1 ? 0 : 1;
}
