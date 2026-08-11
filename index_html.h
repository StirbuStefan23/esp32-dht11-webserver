#ifndef INDEX_HTML_H
#define INDEX_HTML_H

#include <pgmspace.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Dashboard</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; background: #f2f2f2; padding-top: 50px; }
    .card { background: white; padding: 20px; max-width: 300px; margin: 0 auto; border-radius: 10px; box-shadow: 0 4px 8px rgba(0,0,0,0.1); }
    h1 { color: #333; margin-bottom: 20px; }
    p { font-size: 1.2em; color: #555; }
    .val { font-weight: bold; color: #007bff; }
  </style>
</head>
<body>

  <div class="card">
    <h1>Data from sensor</h1>
    <p>Temperatura: <span id="temp" class="val">--</span> °C</p>
    <p>Humidity: <span id="hum" class="val">--</span> %</p>
  </div>

  <script>
    function updateData() {
      // Caută datele de la ruta /data creată în ESP32
      fetch('/data')
        .then(response => response.json())
        .then(data => {
          if (!data.error) {
            document.getElementById('temp').innerText = data.temp;
            document.getElementById('hum').innerText = data.hum;
          }
        })
        .catch(err => console.error("Eroare la preluarea datelor:", err));
    }

    // Apelează funcția imediat la încărcarea paginii
    updateData();

    // Reîmprospătează datele automat la fiecare 2000 ms (2 secunde)
    setInterval(updateData, 2000);
  </script>

</body>
</html>
)rawliteral";

#endif