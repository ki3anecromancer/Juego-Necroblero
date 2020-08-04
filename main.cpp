#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main() {

    int dado, casillero_uno(0), casillero_dos(0), contador_rondas(0);

    // Instrucciones del juego
    cout << "\tJueguito de necro uwu" << endl;
    cout << "\nInstrucciones:" << endl;
    cout << "1. Toque una tecla para tirar el dado" <<endl;
    cout << "2. No escribas otra cosa o crashea todo y te explota la pc" << endl;
    cout << "======================================" << endl;
    cout << "Empiezas en el casillero 0, debes llegar al 50" << endl;
    cout << "El dado sale al azar del 1 al 6" << endl;
    cout << "Los casilleros multiplos de 10 te devuelven 2 casillas atras" << endl;
    cout << "Los casilleros multiplo de 7 te hacen avanzar 1 casillero" << endl;
    cout << "Si te pasas del 50, retrocedes las casillas sobrantes\n\n\tCOMENZAR PARTIDA\n";


    do {
        contador_rondas++;
        cout << "\n==================================================================\n";
        //==================================================================
        //Jugador 1 tira los dados y avanza las casillas
        cout << "\n\t== TURNO DEL JUGADOR ==" << endl;
        cout << "Presione una tecla para tirar el dado: ";
        getch();
        srand(time(NULL));
        dado = 1+rand()%6;
        cout << "\nEl dado salio en: " << dado << endl;
        casillero_uno += dado;
        cout << "El jugador avanza al casillero: " << casillero_uno << "\n\n";

        //Si cae en un multiplo de 10 menor quee 50
        if ((casillero_uno%10 == 0) && (casillero_uno < 50)) {
            cout << "[Multiplo de 10] Retrocede dos casilleros";
            casillero_uno -= 2;
            cout << "\nEl jugador retrocede al casillero: " << casillero_uno << "\n\n";
        }

        //Si cae en un multiplo de 7 menor que 56
        if ((casillero_uno%7 == 0) && (casillero_uno < 56)) {
            cout << "[Multiplo de 7] Avanza un casillero";
            casillero_uno += 1;
            cout << "\nEl jugador avanza al casillero: " << casillero_uno << "\n\n";
        }

        //Si cae en una casilla mayor que 50
        if (casillero_uno > 50) {
            cout << "Oops! te pasaste " << casillero_uno - 50 << " casillas..." << endl;
            casillero_uno = 50 - (casillero_uno - 50);
            cout << "Retrocede al casillero: " << casillero_uno << "\n\n";
        }

        //Si cae en la casilla 50
        if (casillero_uno == 50) {
            cout << "== FELICITACIONES: GANASTE LA PARTIDA!! ==" << "\n\n";
            break;
        }
        //==================================================================
        //Se repite lo mismo que el jugador 1
        //Juador Maquina tira los dados y avanza las casillas

        cout << "\n\n\t== TURNO DE LA MAQUINA ==" << endl;
        dado = 1+rand()%6;
        cout << "El dado salio en: " << dado << endl;
        casillero_dos += dado;
        cout << "El jugador avanza al casillero: " << casillero_dos << "\n\n";

        //Si cae en un multiplo de 10 menor quee 50
        if ((casillero_dos%10 == 0) && (casillero_dos < 50)) {
            cout << "[Multiplo de 10] Retrocede dos casilleros";
            casillero_dos -= 2;
            cout << "\nEl jugador retrocede al casillero: " << casillero_dos << "\n\n";
        }

        //Si cae en un multiplo de 7 menor que 56
        if ((casillero_dos%7 == 0) && (casillero_dos < 56)) {
            cout << "[Multiplo de 7] Avanza un casillero";
            casillero_dos += 1;
            cout << "\nEl jugador avanza al casillero: " << casillero_dos << "\n\n";
        }

        //Si cae en una casilla mayor que 50
        if (casillero_dos > 50) {
            cout << "Oops! te pasaste " << casillero_dos - 50 << " casillas..." << endl;
            casillero_dos = 50 - (casillero_dos - 50);
            cout << "Retrocede al casillero: " << casillero_dos << "\n\n";
        }

        //Si cae en la casilla 50
        if (casillero_dos == 50) {
            cout << "== GANADORA: LA MAQUINA ==" << "\n\n";
            break;
        }

    } while ((casillero_uno != 50) || (casillero_dos != 50));

    cout << "\nRondas totales jugadas: " << contador_rondas << endl;

    getch();
    return 0;
}
