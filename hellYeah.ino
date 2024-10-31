#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ATAODIE";
const char* password = "odi020106";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
  delay(5000);
}

void handleRoot() {
  String html = "<html><body><h2>Bilangan Ganjil:</h2><ul>";
  
  for (int i = 1; i <= 100; i += 2) {  // Menampilkan bilangan ganjil dari 1 hingga 100
    html += "<li>" + String(i) + "</li>";
  }

  html += "</ul></body></html>";
  server.send(200, "text/html", html);
  delay(5000);
}
