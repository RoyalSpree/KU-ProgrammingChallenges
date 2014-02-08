/**
@file MatrixRoads.c++
@author Kaleb Goering */

#include "MatrixRoads.h"

MatrixRoads::MatrixRoads() {
	repaired = false;

	cout << "How big is the city length? " << endl;
	cin >> cityLength;
	
	potholes = new int*[cityLength];
	potChar = new char*[cityLength];
	for(int i = 0; i < cityLength; i++) {
		potholes[i] = new int[cityLength];
		potChar[i] = new char[cityLength];
	}

	cout << "Please input city info row by row" << endl;
	for(int i = 0; i < cityLength; i++) {
		for(int j = 0; j < cityLength; j++) {
			cin >> potholes[i][j];
			potChar[i][j] = '0' + potholes[i][j];
		}
	}
	cout << endl;
	potCount = new int*[2];
	potCount[0] = new int[cityLength];
	potCount[1] = new int[cityLength];
}

void MatrixRoads::fixTheCity() {	
	countPotholes();
	checkRepair();
	while(!repaired) {
		int what = 0, n = 0;
		chooseRoad(what, n);
		if(what > 0) {
			repairCol(n);
		} else {
			repairRow(n);
		}
		checkRepair();
	}
	printRoads();
	cout << "Roads are all fixed." << endl;
}

void MatrixRoads::countPotholes() {
	for(int i = 0; i < cityLength; i++) {
		int rowCount = 0, colCount = 0;
		for(int j = 0; j < cityLength; j ++) {
			if(potholes[i][j] < 1) {
				rowCount++;
			}
			if(potholes[j][i] < 1) {
				colCount++;
			}
		}
		potCount[0][i] = rowCount;
		potCount[1][i] = colCount;
	}
}

void MatrixRoads::chooseRoad(int& what, int& n) const {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < cityLength; j++) {
			if(potCount[what][n] < potCount[i][j] ){
				what = i;
				n = j;
			}
		}
	}
}

void MatrixRoads::repairCol(int n) {
	cout << "Column " << n << " repaired." << endl << endl;
	for(int i = 0; i < cityLength; i++) {
		potholes[i][n] = 1;
		potChar[i][n] = 'x';
	}
}

void MatrixRoads::repairRow(int n) {
	cout << "Row " << n << " repaired." << endl << endl;
	for(int i = 0; i < cityLength; i++) {
		potholes[n][i] = 1;
		potChar[n][i] = 'x';
	}
}

void MatrixRoads::checkRepair() {
	countPotholes();
	repaired = true;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < cityLength; j++) {
			if(potCount[i][j] > 0){
				repaired = false;
			} 
		}
	}
}

void MatrixRoads::printRoads() {
	for(int i = 0; i < cityLength; i++) {
		for(int j = 0; j < cityLength; j++) {
			cout << potChar[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


