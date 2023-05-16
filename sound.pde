import processing.serial.*;
Serial port;
import ddf.minim.*;
Minim minim;
AudioOutput out;

final String serialName = "COM3";

void setup() {
  port = new Serial(this, serialName, 9600);
  size(400, 500);
  minim = new Minim(this);
  out = minim.getLineOut();
}
void draw(){
  if(port.available() > 0){
    int data = port.read(); //reading the data
    println(data);
    //println("HELP");
    int note = 0;
    if (data < 16 && data >= 0) {
       note = data * 100+100;
    }
    out.playNote(note);
  }  
}
