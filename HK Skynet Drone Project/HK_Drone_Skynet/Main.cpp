#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
	
	// Generate random location on 8x8 grid
	cout << "Generating random location on 8x8 grid....\n";
	
	// sets seed for random number based off computer's time
	srand(time(0));

	// sets highest number on grid to 64
	int searchGridHighNumber = 64;
	
	// sets lowest number on grid to 1
	int searchGridLowNumber = 1;
	
	// sets enemy location to random number on the grid
	int enemyLocation = rand() % searchGridHighNumber + searchGridLowNumber;

	cout << "The enemy has been found at location #" << enemyLocation
		<< "on the full 8x8 grid with 1x64 sectors.\n";

	cout << "Initializing Skynet HK-Aerial software...\n";

	// number of target location predictions it took to find enemy
	int targetLocationPredictionCounter = 0;

	// Is the target found or destroyed
	bool targetFound = false;

	while (targetFound == false)
	{
		// implements the binary search algorithm to search for the specific number
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		
		// adds 1 to targetLocationPredictionCounter
		targetLocationPredictionCounter++;

		// sends out ping on radar to enemy location
		cout << "Sending out ping toward enemy location...\n";

		// tells if the location prediction is higher than enemy location
		if (targetLocationPrediction > enemyLocation)
		{
			// displays the enemy was lower than predicted location and tries again
			cout << "The prediction " << targetLocationPrediction << "was higher than the enemy location of " << enemyLocation << "\n";
			cout << "The new searchGridHighNumber #" << searchGridHighNumber << "\n\n"

		}
		// tells if the location prediction is lower than the enemy location
		else if (targetLocationPrediction < enemyLocation)
		{
			// displays the enemy was lower than predicted location and tries again
			cout << "The prediction " << targetLocationPrediction << "was lower than the enemy location of " << enemyLocation << "\n";
			cout << "The new searchGridLowNumber #" << searchGridLowNumber << "\n\n"
		}
		// if the enemy is found display this
		else if (targetLocationPrediction == enemyLocation)
		{
			// reveal enemy location
			cout << "The enemy was found at location # " << enemyLocation << "\n";
			//display counters added for each search attempt
			cout << "The drone software took " << targetLocationPredictionCounter << "predictions to find the enemy location."
			
			// the target is found
			targetFound = true;
		}
		else
		{
			//This ends the simulation if the target is found
			cout << "Drone low on battery. Please return to drop-off location effective immediately.\n"
			targetFound = true;
		}
	}

	// pauses screen for user to exit
	system("pause");
	return 0;
}