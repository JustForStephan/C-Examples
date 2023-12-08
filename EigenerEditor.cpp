// In diesem Programm kann Text, der in der Konsole inform von Parametern geschrieben wird, Text in einer Datei abspeichern und wieder in der Konsole auflisten
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>


using namespace std;


int main(int argc, char* argv[]){ // argc steht für die Anzahl der nachfolgenden Parameter in der Konsole, und argv ist ein string Feld in dem alle Parameter gespeichert werden.
    string s1="r";
    bool RKiller=false;
    // Mit einer Fallunterscheidung kann zwischen, in das momory hineinschreiben oder das memory Auslesen unterschieden werden
    // Für den Fall dass man das memory auslesen will
    if (s1.compare(argv[1])==0) { // Wenn Buchstabe "r"== Parameter 1 des Feldes argv ist, dann...
        RKiller=true;
        ifstream myfile; //Die Klasse Ifstream dient zum einlesen von Datein und besitzt das Objekt myfile in dem der Text der Datei gespeichert wird.
        myfile.open("backupmemory.txt", ios::in); // Der Festplatte wird gesagt dass sie die Datei "backupmemory.txt" zum Bearbeiten Freigegeben werden soll
        string s; // Myfile kann nicht diereckt in die Konsole kopiert werden, deshalb wird einen string angelegt wo die Zeichenketten zwischengeschpeichert werden.
        cout <<"Exist memorys:" <<endl;
        while ( getline (myfile, s) ) { // der Text wird aus dem Objekt myfile in den string s geschrieben 
            cout << s << endl;
        }
        myfile.close(); // Der Festplatte wird gesagt dass sie die Datei für das Bearbeiten sperren soll
    }   
  
  if(RKiller==false){
    ofstream myfile;
    myfile.open ("backupmemory.txt", ios::app); 
    for (int i=1; i<argc; i++) {
        myfile << argv[i] << " ";  // myfile schreibt in das Programm "backupmemory.txt"herein
  
    }
    myfile <<  endl;
    myfile.close();
  }
  return 0;
}
