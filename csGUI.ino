#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "abudhathoki";
const char* pass = "cics2560";
WebServer server(80);

void on_home() {
  String html = "<style>";
  html += "body {";
  html += "display: flex;";
  html += "flex-direction: column;";
  html += "justify-content: center;";
  html += "align-items: center;";
  html += "height: 100vh;";
  html += "}";

  html += "h1 {";
  html += "text-align: center;";
  html += "margin-bottom: 30px;";
  html += "}";

  html += "button {";
  html += "display: block;";
  html += "width: 200px;";
  html += "height: 60px;";
  html += "margin: 10px auto;";
  html += "border: none;";
  html += "border-radius: 5px;";
  html += "color: #fff;";
  html += "font-size: 18px;";
  html += "font-weight: bold;";
  html += "text-align: center;";
  html += "text-decoration: none;";
  html += "transition: background-color 0.3s, transform 0.3s;";
  html += "}";

  html += "button:hover {";
  html += "background-color: #555;";
  html += "transform: scale(1.05);";
  html += "}";

  html += "button:active {";
  html += "background-color: #333;";
  html += "transform: scale(0.95);";
  html += "}";

  html += "#mode1 { background-color: #228B22; }";
  html += "#mode2 { background-color: #FFD700; }";
  html += "#mode3 { background-color: red; }";
  html += "#instructions { background-color: #444; }";

  html += "</style>";
  html += "<h1>SIMON GAME</h1>";
  html += "<h1>Select a game mode:</h1>";
  html += "<button id='mode1' onclick=\"window.location.href='/mode1'\">Game Mode 1</button>";
  html += "<button id='mode2' onclick=\"window.location.href='/mode2'\">Game Mode 2</button>";
  html += "<button id='mode3' onclick=\"window.location.href='/mode3'\">Game Mode 3</button>";
  html += "<button id='instructions' onclick=\"window.location.href='/instructions'\">Instructions</button>";

  server.send(200, "text/html", html);
}

void on_mode1() {
  String html = "<style>";

  html += "button {";
  html += "display: block;";
  html += "width: 200px;";
  html += "height: 60px;";
  html += "margin: 10px;";
  html += "border: none;";
  html += "border-radius: 5px;";
  html += "color: #fff;";
  html += "font-size: 18px;";
  html += "font-weight: bold;";
  html += "text-align: center;";
  html += "text-decoration: none;";
  html += "transition: background-color 0.3s, transform 0.3s;";
  html += "}";

  html += "button:hover {";
  html += "background-color: #555;";
  html += "transform: scale(1.05);";
  html += "}";

  html += "button:active {";
  html += "background-color: #333;";
  html += "transform: scale(0.95);";
  html += "}";
  
  html += "#button-container {";
  html += "display: flex;";
  html += "justify-content: center;";
  html += "}";

  html += "#easy { background-color: #228B22; }";
  html += "#medium { background-color: #FFD700; }";
  html += "#hard { background-color: red; }";

  html += "</style>";
  
  html += "<h1>Game Mode 1</h1>";
  html += "<h2>Select Difficulty Level:</h2>";
  html += "<div id='button-container'>";
  html += "<button id='easy' onclick=\"window.location.href='/mode1/easy'\">Easy</button>";
  html += "<button id='medium' onclick=\"window.location.href='/mode1/medium'\">Medium</button>";
  html += "<button id='hard' onclick=\"window.location.href='/mode1/hard'\">Hard</button>";
  html += "</div>";

  server.send(200, "text/html", html);
}

void on_mode2() {
  String html = "<style>";

  html += "button {";
  html += "display: block;";
  html += "width: 200px;";
  html += "height: 60px;";
  html += "margin: 10px;";
  html += "border: none;";
  html += "border-radius: 5px;";
  html += "color: #fff;";
  html += "font-size: 18px;";
  html += "font-weight: bold;";
  html += "text-align: center;";
  html += "text-decoration: none;";
  html += "transition: background-color 0.3s, transform 0.3s;";
  html += "}";

  html += "button:hover {";
  html += "background-color: #555;";
  html += "transform: scale(1.05);";
  html += "}";

  html += "button:active {";
  html += "background-color: #333;";
  html += "transform: scale(0.95);";
  html += "}";
  
  html += "#button-container {";
  html += "display: flex;";
  html += "justify-content: center;";
  html += "}";

  html += "#easy { background-color: #228B22; }";
  html += "#medium { background-color: #FFD700; }";
  html += "#hard { background-color: red; }";

  html += "</style>";
  
  html += "<h1>Game Mode 1</h1>";
  html += "<h2>Select Difficulty Level:</h2>";
  html += "<div id='button-container'>";
  html += "<button id='easy' onclick=\"window.location.href='/mode1/easy'\">Easy</button>";
  html += "<button id='medium' onclick=\"window.location.href='/mode1/medium'\">Medium</button>";
  html += "<button id='hard' onclick=\"window.location.href='/mode1/hard'\">Hard</button>";
  html += "</div>";

  server.send(200, "text/html", html);
}

void on_mode3() {
  String html = "<style>";

  html += "button {";
  html += "display: block;";
  html += "width: 200px;";
  html += "height: 60px;";
  html += "margin: 10px;";
  html += "border: none;";
  html += "border-radius: 5px;";
  html += "color: #fff;";
  html += "font-size: 18px;";
  html += "font-weight: bold;";
  html += "text-align: center;";
  html += "text-decoration: none;";
  html += "transition: background-color 0.3s, transform 0.3s;";
  html += "}";

  html += "button:hover {";
  html += "background-color: #555;";
  html += "transform: scale(1.05);";
  html += "}";

  html += "button:active {";
  html += "background-color: #333;";
  html += "transform: scale(0.95);";
  html += "}";
  
  html += "#button-container {";
  html += "display: flex;";
  html += "justify-content: center;";
  html += "}";

  html += "#easy { background-color: #228B22; }";
  html += "#medium { background-color: #FFD700; }";
  html += "#hard { background-color: red; }";

  html += "</style>";
  
  html += "<h1>Game Mode 1</h1>";
  html += "<h2>Select Difficulty Level:</h2>";
  html += "<div id='button-container'>";
  html += "<button id='easy' onclick=\"window.location.href='/mode1/easy'\">Easy</button>";
  html += "<button id='medium' onclick=\"window.location.href='/mode1/medium'\">Medium</button>";
  html += "<button id='hard' onclick=\"window.location.href='/mode1/hard'\">Hard</button>";
  html += "</div>";

  server.send(200, "text/html", html);
}

void on_instructions() {
  String html = "<style>";
  // space to add css to the text
  html += "</style>";
  
  html += "<h1>Instructions</h1>";
  html += "<p>The player must repeat the sequence of lights or sounds in the correct order. The game starts off with a simple sequence, but it gets more and more difficult as the game progresses. The player loses if they make a mistake.</p>";
  html += "<h2>Game Mode 1</h2>";
  html += "<p>In Game Mode 1, the player's visual memory will be tested. On the board, a sequence of lights will light up, and as you get it right, the sequence gets longer. There are three difficulty levels: easy, medium, and hard.</p>";
  html += "<ul>";
  html += "<li>Easy: The game is limited to a 2x2 square.</li>";
  html += "<li>Medium: The game is limited to a 3x3 board.</li>";
  html += "<li>Hard: The game uses the full 4x4 board.</li>";
  html += "</ul>";
  html += "<h2>Game Mode 2</h2>";
  html += "<p>In Game Mode 2, your auditory skills are being tested. Instead of lights, a sequence of noises will play. This mode also has three different difficulty settings.</p>";
  html += "<li>Easy: The game is limited to a 2x2 square.</li>";
  html += "<li>Medium: The game is limited to a 3x3 board.</li>";
  html += "<li>Hard: The game uses the full 4x4 board.</li>";
  html += "<h2>Game Mode 3</h2>";
  html += "<p>The last mode combines both light and audio elements.</p>";
  html += "<li>Easy: The game is limited to a 2x2 square.</li>";
  html += "<li>Medium: The game is limited to a 3x3 board.</li>";
  html += "<li>Hard: The game uses the full 4x4 board.</li>";
  html += "<p>Have fun!</p>";

  server.send(200, "text/html", html);
}

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, pass);
  server.on("/", on_home);
  server.on("/mode1", on_mode1);
  server.on("/mode2", on_mode2);
  server.on("/mode3", on_mode3);
  server.on("/instructions", on_instructions);
  server.begin();
}

void loop() {
  server.handleClient();
}







