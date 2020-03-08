/* 
File Name: HW9.cpp
Description of program: Organizational system for bus company, using only pointers
Course Name: Introduction to Computer Science
Exercise# and Question#: 9
Name: Eli Levin 341318228
Creation date: 5/1/20
Last Modification date: 5/1/20
*/
#include <iostream>
using namespace std;

const int R = 50, C = 3;

enum choices {EXIT, ADD, DELETE, PRINT, SEARCH, AVG_TRAVEL, AVG_STOPS, SHORTEST_TRAVEL};

void AddLine(int buses[][C],int & numBuses,int line,int stops,int durationOfRide);
void DeleteLine(int buses[][C], int & numBuses,int line);
int Search(int buses[][C], int numBuses, int line);
float AverageTravel(int buses[][C], int numBuses);
float AverageStops(int buses[][C], int numBuses);
int Shortest(int buses[][C], int numBuses);
void Print(int buses[][C], int numBuses);

void Sort(int buses[][C], int numBuses);
void SwapRows(int arr[][C], int index1, int index2);

int  main(){
	int buses[R][C] = {0};
	int numBuses = 0;
	int line;
	int stops;
	int durationOfRide;
	int choice;
	do {
		cout << "enter 0-7" << endl;
		cin >> choice;
		switch(choice){
		case ADD: // add a line to the array of buses
			cout << "enter the line to add" << endl;
			//make it illegal to enter zero or negative
			cin >> line;
			cout << "enter the number of stops" << endl;
			cin >> stops;
			cout << "enter the duration of the ride" << endl;
			cin >> durationOfRide;

			AddLine(buses, numBuses, line, stops, durationOfRide);       
			Print(buses,numBuses);	
			break;

		case DELETE:	// delete a line from the array of buses					
			cout << "enter the line to delete" << endl;
			cin >> line;
			DeleteLine(buses, numBuses, line); 
			Print(buses,numBuses);
			break;
		case PRINT: // print all lines
			Print(buses,numBuses);
			break;
		case SEARCH : // search for a particular line
			cout << "enter the line to search for" << endl;
			cin >> line;
			cout << Search(buses, numBuses, line)<<endl;
			break;
		case AVG_TRAVEL : // calculate average travel time of all buses
			cout << AverageTravel(buses, numBuses)<<endl;
			break;
		case AVG_STOPS:  // calcuate average stops of all buses
			cout << AverageStops(buses, numBuses)<<endl;
			break;
		case SHORTEST_TRAVEL:// calculate the bus with the shortest travel time
			cout << Shortest(buses,numBuses)<<endl;
			break;
		case EXIT: break;   // exit the program

		default:  cout << "ERROR"<<endl;
		}// switch
	} while (choice != 0);

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

//insertion sort method, requires swap
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

int Search(int buses[][C], int numBuses, int line){
    // set the left and right bounds of where we're searching.
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
        if (line < *(*(buses+middle)) ){
            right = middle - 1;
            if(line < *(*(buses+left))){
                return -1;
            }
        }
    }
    // if loop completed, the num doesn't exist in array
    return -1;
}

void AddLine(int buses[][C], int & numBuses, int line, int stops, int durationOfRide){

	//make sure all of our inputs are non-zero and positive
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
		if(Search(buses, numBuses, line) != -1){ // means that the busline already exists
			cout << "ERROR" << endl;
		}
		else {
			// input information in correct location
			*(*(buses+numBuses)) = line;
			*(*(buses+numBuses)+1) = stops;
			*(*(buses+numBuses)+2) = durationOfRide;
            Sort(buses, ++numBuses); //sort and increase numBuses by 1
		}
	}		
}

//this function deletes a bus line
void DeleteLine(int buses[][C], int & numBuses,int line){

	//find which row the line exists in
	int row = Search(buses, numBuses, line);
	if(row == -1){
		return;
	}
	else{
		for (int i = 0; i < C; i++){ // delete the row that Search returned
			*(*(buses+row)+i) = 0;
		}
		for (int i = row; i < numBuses; i++){ //copy each next line into current line to fill in the space
			for (int j = 0; j < C; j++){
				*(*(buses+i)+j) = *(*(buses+i+1)+j);
			}
		}
		numBuses--;
	}
}

// returns float of average travel time over all the bus lines
float AverageTravel(int buses[][C], int numBuses){
	//duration is the second column of the array
	//go through array until numBuses and take each value from second column and average
	float sum = 0;
	for (int i = 0; i < numBuses; i++){
		sum += *(*(buses+i)+2);
	}
	return sum/static_cast<float>(numBuses);
}

// returns float fo average number of stops
float AverageStops(int buses[][C], int numBuses){
	//stops is the first column of the array
	//go through array until numBuses and take each value from first column and average
	float sum = 0;
	for (int i = 0; i < numBuses; i++){
		sum += *(*(buses+i)+1);
	}
	
	return sum/static_cast<float>(numBuses);
}

//returns shortest busline, as measured in time
int Shortest(int buses[][C], int numBuses){
	//find shortest duration
	//if no bus lines the return -1
	if(numBuses==0){
		return -1;
	}

	int shortest = *(*(buses)+2); //first possible duration in array
	int shortestLine = *(*(buses));
		for (int i = 1; i < numBuses; i++){
			if(shortest > *(*(buses+i)+2)){ //if any other duration is shorter...
				shortest = *(*(buses+i)+2); //make that the new shortest one
				shortestLine = *(*(buses+i)); // and remember which busline is associated with it
			}
		}
	return shortestLine;
}

// prints out the buses that are saved in the database
void Print(int buses[][C], int numBuses) {

	for (int i = 0; i<numBuses; i++) { // for each bus that is present in the database
		for (int j = 0; j<C; j++) { // prints the 3 pieces of data of the bus
			cout << *(*(buses + i) + j)<<" ";
		}
		cout << endl;
	}
}





