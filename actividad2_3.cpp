// El siguiente programa lee datos del archivo txt "bitacora.txt" y realiza una variedad de ordenamientos, busqueda y conteo de IPs por fecha; regresando los resultados en un archivo nuevo.
// Este programa fue realizado por Regina Cavazos Valdés, Miguel Ángel Sánchez López y Ana Karina Aramoni Ruíz en del16 al 19 de octubre del 2023.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Log.h"
#include "DoublyLinkedList.h"
#include <map> 

using namespace std;

int main() {
    // Se crean 3 listas distintas que cada una corresponde a una opcion del menu
    DoublyLinkedList<Log> logList1;
    DoublyLinkedList<string> logList2;
    DoublyLinkedList<string> logList3;

    // Se declaran las variables que seran utilizadas para leer
    string year, month, day, time, ip, message;
    string line, word;
    ifstream fileIn("bitacora.txt");


    // Se muestra el menu
    cout << "-------------------------- MENU --------------------------" << endl;
    cout << "1. Ordenar por IP, fecha y hora" << endl;
    cout << "2. Buscar por rango de IPs" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Por favor selecciona una opcion: " << endl;
    int opcion;
    cin >> opcion;

    // Se lee el archivo y se guardan los datos en la lista correspondiente a la opcion seleccionada
    switch (opcion) {

        // Se ordenan los datos por IP, fecha y hora
        case 1:
            {cout << "Haz seleccionado ordenar los datos por IP, fecha y hora. " << endl;
            
            // Se lee la informacion que viene en el archivo, hasta que ya no se encuenten mas lineas que leer
            while (getline(fileIn, line)) {
                    stringstream vAux(line);
                    // Se extraen los datos individuales
                    vAux >> month >> day >> year >> time >> ip >> message;
                    while (vAux >> word) {
                        message = message + " " + word;
                    }
                    
                    // Se crea una instancia con los datos extraidos
                    Log log_a(year, month, day, time, ip, message);
                    // Se reemplazan los puntos en la dirección IP con ceros
                    log_a.replaceIpDotsWithZero();
                    // Se agregan los IP, mes, dia, anio, hora y mensaje
                    logList2.addFirst("Log: " + log_a.getIpKey() + " " + log_a.getMonth() + " " + log_a.getDay() + " " + log_a.getYear() + " " + log_a.getTime() +  " " + log_a.getMessage());
            }

                // Se ordenan los datos
                logList2.sort();
                
                // Se almacenan los resultados en un nuevo archivo
                ofstream outFile("resultados_bitacora_ip_fecha_hora.out");
                for (int j = 0; j < logList2.getSize(); j++) {
                    outFile << logList2[j] << endl;
                }
                outFile.close();

                cout << "Los datos han sido ordenados por IP, fecha y hora. Los puedes encontrar en el archivo 'resultados_bitacora_ip_fecha_hora.out'." << endl;
                break;
            }
             // Se buscan los datos por un rango de IPs
        case 2:
            cout << "Haz seleccionado busar por un rango de IPs. Estas seran despliegadas en orden ascendente. " << endl;

            // Se declaran variables para determinar el rango que es insertado por el usuario
            string startIp;
            string endIp;

            // Se piden los valore y el orden al usuario
            cout << "Por favor inserta la primera IP en el rango a buscar: ";
            cin >> startIp;
            cout << "Por favor inserta la ultima IP en el rango a buscar: ";
            cin >> endIp;
        
           // Se lee la informacion que viene en el archivo, hasta que ya no se encuenten mas lineas que leer
            while (getline(fileIn, line)) {
                stringstream vAux(line);
                vAux >> month >> day >> year >> time >> ip >> message;
                while (vAux >> word) {
                    message = message + " " + word;
                }

                // Se crea una instancia con los datos extraidos
                Log log_a(year, month, day, time, ip, message);
                // Se verifica si la IP se encuentra en el rango deseado
                if (log_a.getIpKey() >= startIp && log_a.getIpKey() <= endIp) {
                    logList3.addFirst("Log: " + log_a.getIpKey() + " " + log_a.getMonth()+ " " + log_a.getDay() + " " + log_a.getYear() +" "+log_a.getTime()+  " " + log_a.getMessage());
                }
            }

            // Se ordenan los datos
            logList3.sort();

            // Se almacenan los resultados en un nuevo archivo
            ofstream outFile("resultados_bitacora_ip_ascendente.out");
            for (int j = 0; j < logList3.getSize(); j++) {
                outFile << logList3[j] << endl;
            }
            outFile.close();

            cout << "Los datos han sido ordenados en orden ascendente dentro del rango determinado. Los puedes encontrar en el archivo 'resultados_bitacora_ip_ascendente.out'." << endl;
            break;

           }
    return 0;
}