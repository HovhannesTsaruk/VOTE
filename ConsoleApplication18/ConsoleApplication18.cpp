
using namespace std;

// take out stuff from a file 
// checking for the dublicate names and sum of the votes 



int main()
{
	string names[10]; //gets the names from the file
	int pre_votes[10]; //gets the votes from the file
	string Candidates[5];
	int votes[5];
	double percentVote[5];
	int sum = 0;
	bool draw = false;


	//gets the names and votes from file 
	ifstream file("Votes.txt");
	if (file.is_open())
	{
		for (int i = 0; i < 10; i++)
		{
			file >> names[i];
			file >> pre_votes[i];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (names[i] == names[j]) {
				names[j] = "";
				pre_votes[i] = pre_votes[i] + pre_votes[j];
				pre_votes[j] = 0;

			}
		}

	}

	int size = sizeof(pre_votes) / sizeof(pre_votes[0]);
	for (int i = 5; i < size - 1; i++) {
		pre_votes[i] = pre_votes[i + 1]; // shift elements to the left
		names[i] = names[i + 1]; // shift elements to the left
	}
	size--;

	for (int n = 0; n < 5; n++) {
		votes[n] = pre_votes[n];
		Candidates[n] = names[n];
		cout << Candidates[n] << ":" << votes[n] << endl;
		sum = votes[n] + sum;
	}

	//counting the votes percent
	for (int p = 0; p < 5; p++) {
		percentVote[p] = (votes[p] * 100) / sum;

	}

	//get the bigest vote percent or draw
	int maxVotes = 0;
	int draw_of_one = 0;
	int draw_of_two = 0;
	double winner_of_the_votes = 0;
	for (int s = 1; s < 5; s++) {
		if (percentVote[maxVotes] < percentVote[s]) {
			maxVotes = s;
			winner_of_the_votes = percentVote[maxVotes];
			draw = false;
		}
		else if (percentVote[maxVotes] = percentVote[s]) {
			draw_of_one = maxVotes;
			draw_of_two = s;
			draw = true;
			break;
		}
	}
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";

	//outputs of names and winner
	cout << right << "The Candidates are " << setw(6) << " The votes " << setw(6)
		<< " The percent of votes " << setw(6) << " The Total " << endl;
	for (int k = 0; k < 5; k++) {


		cout << left << setw(10) << Candidates[k] << setw(15) << right
			<< votes[k] << setw(20) << percentVote[k] << "%" << endl;

	}
	cout << right << setw(57) << sum << " Votes!";


	//the winner if draw or no draw
	if (draw == false) {
		cout << "\n\n\n\nThe winner of the votes is: " << Candidates[maxVotes]
			<< " with " << winner_of_the_votes << "%" << " of votes!" << endl;
	}
	else {
		
		cout << "\n\n\n\nThere is no winner becasue: " << Candidates[draw_of_one]
			<< " and " << Candidates[draw_of_two] << " both have equal percent of votes!" << endl;
	}

	

}