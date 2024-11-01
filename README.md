<h1 align="center">UniPG - Tutoraggio: esercizio equazioni di 2° grado</h1>

<p align="center" style="font-family: monospace">Made by <a href="https://github.com/matbagnoletti">@matbagnoletti</a></p>
<p align="center" style="font-family: monospace">Corso di Programmazione Procedurale I° anno a.a. 2024/2025, <a href="https://www.dmi.unipg.it/didattica/corsi-di-studio-in-informatica/informatica-triennale">UniPG - DMI</a></p>
<p align="center">
    <img src="https://img.shields.io/github/last-commit/matbagnoletti/UniPGTutoraggioEq2Grado?style=for-the-badge" alt="Ultimo commit">
    <img src="https://img.shields.io/github/languages/top/matbagnoletti/UniPGTutoraggioEq2Grado?style=for-the-badge" alt="Linguaggio">
</p>

## Descrizione
Esercizio di tutoraggio svolto durante il corso di Programmazione Procedurale del primo anno di Informatica presso l'Università degli Studi di Perugia.

## Requisiti
- [gcc](https://www.gcc.gnu.org/) (v13.2.0)

È possibile visualizzare la versione già presente sul proprio dispositivo mediante i seguenti comandi:
```bash
gcc -v
```

## Richiesta dell'esercizio
Si realizzi un programma in linguaggio C per risolvere equazioni di secondo grado. 
In particolare, data una generica equazione di secondo grado nella forma <code>ax^2 + bx + c = 0</code>,
dove a, b, c sono coefficienti reali noti (valori di tipo double passati da tastiera con scanf()) e x
rappresenta l’incognita, il programma determini le due radici <code>x1</code> ed <code>x2</code> dell’equazione data, ove esse esistano. 

Si identifichino tutti i casi particolari, come:
<ul>
    <li><code>a == 0</code></li>
    <li><code>∆ == 0</code></li>
    <li><code>∆ < 0</code></li>
    <li><code>∆ > 0</code></li>
</ul>
stampando opportuni messaggi informativi.

Tramite la soluzione proposta si verifichi che il programma sia in grado di risolvere correttamente i seguenti scenari:
<ul>
    <li>Se <code>a == 0</code>, l'equazione è di primo grado. Se, inoltre,<code>b == 0</code>, allora l’equazione ammette infinite soluzioni.</li>
    <li>Se <code>b! = 0</code>, allora l’unica soluzione vale <code>−c ÷ b</code></li>
    <li>Se <code>∆ == 0</code>, l'equazione ha due soluzioni coincidenti.</li>
    <li>Se <code>∆ < 0</code>, l'equazione non ha soluzioni reali.</li>
    <li>Se <code>∆ > 0</code>, l'equazione ha due soluzioni reali distinte.</li>
</ul>

Il file eseguibile della soluzione proposta dovrà presentarsi nel formato `<nomeCognome>`.

## Soluzione proposta
Il programma richiede all'utente di inserire i coefficienti <code>a</code>, <code>b</code> e <code>c</code> dell'equazione di secondo grado.
Successivamente, il programma calcola il discriminante <code>∆</code> e, in base al suo valore, determina le soluzioni dell'equazione.
Apposite funzioni, come `stampaEqSanificata()` ed `eliminaZeri()`, sono state create per stampare l'equazione in un formato naturale e per eliminare eventuali zeri superflui.


## Installazione e utilizzo
Per poter utilizzare il programma, è necessario seguire i seguenti passaggi:
1. Effettua il clone della repository con il comando:
   ```bash
   git clone https://www.github.com/matbagnoletti/UniPGTutoraggioEq2Grado.git
   ```
   In alternativa, effettua il download del file compresso del progetto ed estrailo in una cartella locale del tuo computer.
2. Nel terminale, spostati nella cartella del progetto:
   ```bash
   cd UniPGTutoraggioEq2Grado
   ```
3. Compila il codice sorgente:
   ```bash
    gcc main.c -o [eseguibile] -lm
    ```
4. Esegui il programma:
    ```bash
    ./[eseguibile]
    ```
