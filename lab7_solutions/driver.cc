#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;

		ofstream Q3data;
		Q3data.open("Q3data.csv");
		Q3data << "Type, Insertions, load, probeRate\n";

		int maxSize = 1000;
		Hashtable H(maxSize);

		// Linear
		for(int i = 1; i < maxSize; i+=10) {
			for(int j = 0; j < i; ++j) {
				H.linsert(rand() + 1);
			}
			cout << "Linear " << i << " insertions: " << endl;
			H.printStats();
			Q3data << "l, " << i << ", " << i/float(maxSize) << ", " << H.probeRate() << "\n";
			H.clear();
		}

		// Quadratic
		for(int i = 1; i < maxSize; i+=10) {
			for(int j = 0; j < i; ++j) {
				H.qinsert(rand() + 1);
			}
			cout << "Quadratic " << i << " insertions: " << endl;
			H.printStats();
			Q3data << "q, " << i << ", " << i/float(maxSize) << ", " << H.probeRate() << "\n";
			H.clear();
		}

		// Double hash 1
		for(int i = 1; i < maxSize; i+=10) {
			for(int j = 0; j < i; ++j) {
				H.dinsert(rand() + 1, 1);
			}
			cout << "Double hash 1" << i << " insertions: " << endl;
			H.printStats();
			Q3data << "d1, " << i << ", " << i/float(maxSize) << ", " << H.probeRate() << "\n";
			H.clear();
		}

		// Double hash 2
		for(int i = 1; i < maxSize; i+=10) {
			for(int j = 0; j < i; ++j) {
				H.dinsert(rand() + 1, 2);
			}
			cout << "Double hash 1" << i << " insertions: " << endl;
			H.printStats();
			Q3data << "d2, " << i << ", " << i/float(maxSize) << ", " << H.probeRate() << "\n";
			H.clear();
		}

		// Double hash 3
		for(int i = 1; i < maxSize; i+=10) {
			for(int j = 0; j < i; ++j) {
				H.dinsert(rand() + 1, 3);
			}
			cout << "Double hash 1" << i << " insertions: " << endl;
			H.printStats();
			Q3data << "d3, " << i << ", " << i/float(maxSize) << ", " << H.probeRate() << "\n";
			H.clear();
		}

		Q3data.close();

		return 0;
	}

	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);

	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1, 1);
		}
		//    H.print();
		cout << "Double Hashing: ";
		H.printStats();
		break;
	default:
		usage(argv);
	}
}

