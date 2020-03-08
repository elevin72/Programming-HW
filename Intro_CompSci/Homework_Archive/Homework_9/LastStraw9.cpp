/* 
File Name:
Description of program:
Course Name: Introduction to Computer Science
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date:
Last Modification date:
*/
#include <iostream>
#include <math.h>
using namespace std;

const int R = 50, C = 3;

enum choices {EXIT, ADD, DELETE, PRINT, SEARCH, AVG_TRAVEL, AVG_STOPS, SHORTEST_TRAVEL};

void addLine(int buses[][3], int & numBuses, int line, int stops, int durationOfRide);
int Search(int buses[][3], int numBuses, int line);
void SwapRows(int arr[][C], int index1, int index2);
void Sort(int arr[][C], int numBuses);
void deleteLine(int buses[][3], int & numBuses, int line);
void print(int buses[][C], int numBuses);
float averageTravel(int buses[][3], int numBuses);

int main()
{ 
    int buses[R][C] = {{77,10,11},{74,20,21},{75,30,31},{18,40,41},{19,70,75}};
	int numBuses = 5;

    int line=15, stops=50, durationOfRide=51;

    float fl = 5.7;
    cout << round(fl);

    return 0;

}

//swap rows of a 2d array using pointers
void SwapRows(int arr[][C], int index1, int index2){
    for(int i = 0; i < C; i++){
        int t = *(*(arr+index1)+i);
        *(*(arr+index1)+i) = *(*(arr+index2)+i);
        *(*(arr+index2)+i) = t;
    }
}

void Sort(int buses[][C], int numBuses){
    for (int i = 0; i < numBuses; i++){
        for (int j=i; j > 0 ; j--){
            if ( *(*(buses+j)) >= *(*(buses+j-1)) ){
                break;
            } else{
                SwapRows(buses, j, j-1);
            }
        }  
    } 
}

int Search(int buses[][3], int numBuses, int line){
    // set the top and bottom of where we're searching.
    int left = 0, right= numBuses - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if( *(*(buses + middle)) == line){
            return middle;
        }

        // search to the left of middle
        if (line > *(*(buses+middle)) ){
            left = middle + 1;
            if(line > *(*(buses + right))){
                return -1;
            }
        }
        // search to the right of middle
        if (line < *(*buses+middle)){
            right = middle - 1;
            if(line < *(*(buses+left))){
                return -1;
            }
        }
    }
    // if loop completed, the num doesn't exist in array
    return -1;
}

void addLine(int buses[][3], int & numBuses, int line, int stops, int durationOfRide){

	while (line < 1){
		cin >> line;
	}
	while (stops < 1){
		cin >> stops;
	}
	while (durationOfRide < 1){
		cin >> durationOfRide;
	}
	
	if(numBuses == R){ // array is full
		//cout error message
	}
	else { 
	 // array is not full
		//go to numBuses and insert line there
		if(Search(buses, numBuses, line) != -1){
			cout << "ERROR" << endl;
		}
		else {
			*(*(buses+numBuses)) = line;
			*(*(buses+numBuses)+1) = stops;
			*(*(buses+numBuses)+2) = durationOfRide;
            Sort(buses, ++numBuses);
			//numBuses++;
		}
	}		
}

void deleteLine(int buses[][3], int & numBuses,int line){
	//copy every row onto the previous row starting from the first 0 row
	//what happens when you have no zero row?
	//overwrite delete row to zero and copy next row to previous row until numBuses

	//find which row the line exists in
	int row = Search(buses, numBuses, line);
	if(row == -1){
		return;
	}
	else{
		for (int i = 0; i < C; i++){ // delete that line
			*(*(buses+row)+i) = 0;
		}

		for (int i = row; i < numBuses; i++){ //copy each next line into current line
			for (int j = 0; j < C; j++){
				*(*(buses+i)+j) = *(*(buses+i+1)+j);
			}
		}
		print(buses, --numBuses);
	}
}

void print(int buses[][C], int numBuses){

	for (int i = 0; i<numBuses; i++) { // for each bus that is present in the database
		for (int j = 0; j<C; j++) { // prints the 3 pieces of data of the bus
			cout << *(*(buses + i) + j)<<" ";
		}
		cout << endl;
	}
}

float averageTravel(int buses[][3], int numBuses){
	//duration is the second column of the array
	//go through array until numBuses and take each value from seond column and average
	float sum = 0;
	for (int i = 0; i < numBuses; i++){
		sum += *(*(buses+i)+2);
	}
	return sum/static_cast<float>(numBuses);
}