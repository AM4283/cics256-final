import processing.serial.*;
Serial port;
import ddf.minim.*;
Minim minim;
AudioOutput out;

final String serialName = "portname";

final int D=90;
void setup() {
  port = new Serial(this, serialName, 115200);
  size(400, 500);
  minim = new Minim(this);
  out = minim.getLineOut();
}

void makenoise(){
  if(port.available() > 0){
    int data = port.read(); //reading the data
    int note = data * 50
    out.playNote(note);
  }  
}
