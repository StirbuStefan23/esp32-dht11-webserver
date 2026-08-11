# 🌡️ ESP32 DHT11 Web Server & Dashboard

Proiect IoT bazat pe **ESP32** și senzorul **DHT11**, ce afișează în timp real datele de temperatură și umiditate pe un dashboard web accesibil din rețeaua locală Wi-Fi.

---

## 🚀 Caracteristici

* **Server Web Asincron:** Renders un dashboard web minimal direct din memoria ESP32 (`PROGMEM`).
* **Actualizare Dinamică (AJAX/Fetch API):** Datele se reîmprospătează automat la fiecare 2 secunde fără reîncărcarea paginii.
* **Format Date Standard:** Preluarea datelor de către frontend se face în format JSON prin endpoint-ul `/data`.

---

## 🛠️ Cerințe Hardware & Conexiuni

* Placă de dezvoltare **ESP32**
* Senzor de temperatură și umiditate **DHT11**

### Schema de conectare:

| Pin Senzor DHT11 | Pin ESP32 |
| :--- | :--- |
| **VCC** | `3.3V` (sau `5V`) |
| **DATA** | **`GPIO 4`** |
| **GND** | `GND` |

---

## 📁 Structura Fișierelor

* `main.ino` – Codul principal ESP32 (conexiune Wi-Fi, endpoint-uri `/` și `/data`).
* `index_html.h` – Interfața Web (HTML, CSS și JavaScript).
* `config.h` – Credențialele rețelei Wi-Fi (`WIFI_SSID` și `WIFI_PASSWORD`).

---

## 📚 Biblioteci Necesare (Arduino IDE)

Instalează următoarele biblioteci din *Library Manager*:

1. **DHT sensor library** (by Adafruit)
2. **Adafruit Unified Sensor**
