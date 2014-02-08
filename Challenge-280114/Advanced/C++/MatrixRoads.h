/**
@file MatrixRoads.h
@author Kaleb Goering */

#ifndef _MATRIXROADS_H
#define _MATRIXROADS_H

#include <iostream>

using namespace std;

class MatrixRoads {
	public:
		/** Default Constructor
		@param None. */
		MatrixRoads();
		/** Make the decisions on how to fix the city.
		@param None.
		@pre None.
		@post Fixed the city fastest way possible.
		@return None.*/
		void fixTheCity();
	private:
		int** potholes;
		int** potCount;
		int cityLength;
		bool repaired;
		char** potChar;
		/** Counts up the potholes on each road.
		@param None.
		@pre None.
		@post The potholes for each road are counted.
		@return None. */
		void countPotholes();
		/** Chooses which road to fix.
		@param what An int telling whether a row or column should be fixed.
		@param n An int telling which road to be fixed.
		@pre None.
		@post None.
		@return None. */
		void chooseRoad(int& what, int& n) const;
		/** Repair a column road
		@param n The index of the column to be fixed.
		@pre None.
		@post To 1 in the int array and x in char array.
		@return None. */
		void repairCol(int n);
		/** Repair a row road
		@param n The index of the row to be fixed.
		@pre None.
		@post To 1 in the int array and x in char array.
		@return None. */
		void repairRow(int n);
		/** Checks on the status of the roads.
		@param None.
		@pre None.
		@post None.
		@return None. */
		void checkRepair();
		/** Displays the roads in a grid format.
		@param None.
		@pre None.
		@post None.
		@return None. */
		void printRoads();
};

#endif
