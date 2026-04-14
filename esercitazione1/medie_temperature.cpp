#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, const char *argv[])
{
	string filename;

	if (argc != 2) {
		cerr << "Errore!! Numero di parametri errato!";
		return 1;
	}

	filename = argv[1];

	cout << filename << "\n";


	ifstream ifs(filename);
	if ( ifs.is_open() ){ // controllo se apre file
		while( !ifs.eof() ) {
		       string location;
		       float tmp;
		       const int n_temp = 4;
		       const int n_citta = 3;
		       float media;
		       for (int j = 0; j < n_citta ; j++) {

			        media = 0;

		       		if (!( ifs >> location)) {
			       		cerr << "Errore nella lettura della citta";
		      		}
		       		for (int i = 0; i < n_temp; i++) {
			      		if ( !(ifs >> tmp)){
				       		cerr << "Errore nella lettura delle temperature";
			       		}
			       		media += tmp;
		       		}
		       		media = media / n_temp;
		       		cout << location << "\t" << media << "\n";
		
		       }

		       break;
		}
	} else {
		cerr << "File non trovato!";
	}

	return 0;
}


