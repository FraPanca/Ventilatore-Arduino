# Ventilatore-Arduino

## Italiano

Un ventilatore con velocità regolabile tramite potenziometro, con indicatore su display a 7 segmenti.

**Stack:** C/C++ (Arduino)

### Descrizione

Realizzazione di un ventilatore con una scheda Arduino UNO R3: la velocità del motore è regolata in tempo reale tramite un potenziometro, mentre un pulsante ne consente l'accensione/spegnimento. Il livello di velocità corrente (da 0 a 9) viene mostrato su un display a 7 segmenti, pilotato pin per pin con una decodifica decimale-segmenti implementata via software.

### Componenti necessari

- UNO R3 Controller Board
- Fan Blade
- 3-6V Motor CC
- Button
- 1 Digit 7-Segment Display
- Potenziometro 10k
- NPN Transistor PN2222
- Diode Rectifier
- 3 resistori 220 Ohm
- Breadboard
- Breadboard jumpers

### Come si esegue

1. Apri `Ventilatore.ino` nell'IDE Arduino, seleziona la scheda "Arduino UNO" e la porta seriale corretta.
2. Collega i componenti secondo lo schema elettrico incluso (`Ventilatore-Tinkercad.png` / `Ventilatore.pdf`).
3. Carica lo sketch sulla scheda. Ruota il potenziometro per impostare la velocità, premi il bottone per accendere/spegnere il ventilatore.

### Funzionalità principali

- Regolazione continua della velocità del motore tramite potenziometro, con conversione della lettura analogica in un valore PWM (0-255) e in un livello 0-9 per il display
- Accensione/spegnimento del ventilatore tramite pulsante, con attesa del rilascio del tasto per evitare letture multiple accidentali (debounce software)
- Visualizzazione del livello di velocità corrente (0-9) su un display a 7 segmenti, pilotato direttamente pin per pin (nessun decoder BCD dedicato: la decodifica cifra → segmenti è realizzata via switch-case nel firmware)
- Motore fermo (PWM a 0) e display a "0" quando il ventilatore è spento, indipendentemente dalla posizione del potenziometro

### Struttura del progetto

```
Ventilatore-Arduino/
├── Ventilatore.ino            # Sketch principale: lettura potenziometro, PWM motore, decodifica e pilotaggio display
├── Ventilatore-Tinkercad.png  # Schema elettrico del circuito
└── Ventilatore.pdf            # Schema elettrico (esportazione Tinkercad)
```

### Note

Progetto personale con Arduino UNO R3. Il debounce del pulsante è realizzato tramite un ciclo bloccante (`while`) che attende il rilascio del tasto.

### Licenza

MIT

---

## English

A fan with speed adjustable via a potentiometer, with the current level shown on a 7-segment display.

**Stack:** C/C++ (Arduino)

### Description

Implementation of a fan using an Arduino UNO R3 board: motor speed is adjusted in real time via a potentiometer, while a button turns it on and off. The current speed level (0 to 9) is shown on a 7-segment display, driven pin by pin with a decimal-to-segments decoding implemented in software.

### Required components

- UNO R3 Controller Board
- Fan Blade
- 3-6V Motor CC
- Button
- 1 Digit 7-Segment Display
- 10k Potentiometer
- NPN Transistor PN2222
- Diode Rectifier
- 3 resistors 220 Ohm
- Breadboard
- Breadboard jumpers

### How to run

1. Open `Ventilatore.ino` in the Arduino IDE, select the "Arduino UNO" board and the correct serial port.
2. Wire the components according to the included circuit diagram (`Ventilatore-Tinkercad.png` / `Ventilatore.pdf`).
3. Upload the sketch to the board. Turn the potentiometer to set the speed, press the button to turn the fan on/off.

### Key features

- Continuous motor speed adjustment via a potentiometer, converting the analog reading into a PWM value (0-255) and into a 0-9 level for the display
- Fan on/off toggling via a button, waiting for the key release to avoid accidental multiple reads (software debounce)
- Display of the current speed level (0-9) on a 7-segment display, driven directly pin by pin (no dedicated BCD decoder: digit-to-segments decoding is implemented via a switch-case in firmware)
- Motor stopped (PWM at 0) and display showing "0" when the fan is off, regardless of the potentiometer position

### Project structure

```
Ventilatore-Arduino/
├── Ventilatore.ino            # Main sketch: potentiometer reading, motor PWM, display decoding and driving
├── Ventilatore-Tinkercad.png  # Circuit diagram
└── Ventilatore.pdf            # Circuit diagram (Tinkercad export)
```

### Notes

Personal project with an Arduino UNO R3. Button debouncing is implemented with a blocking `while` loop that waits for the key release.

### License

MIT
