/**
 * This is a lightly edited version of code taken from
 * Manley, E.D., & Urness, T. M.,
 * http://nifty.stanford.edu/2016/manley-urness-movie-review-sentiment/CS2SentimentStarterCode.zip,
 * last access Sep 15, 2016.
 *
 */

#include "WordEntry.h"
#include "Entries.h"
#include "Utils.h"

using namespace std;

string word = " ";

// prototypes for functions you will implement
// at the bottom of this file
void main_menu(const Entries& entries);
void single_word_score(const Entries& entries);
void average_score_of(const Entries& entries);
void highest_lowest_words(const Entries& entries);
void split_pos_neg(const Entries& entries);

int main()
{

    //declare a few needed variables for inputing the data
    string message = " ";


    // TODO: change this to read in the name of the input file.
    cout << "Enter name of file with movie reviews : ";
    cin >> message;



    // do input
    Entries entries = read_input_file("movieReviewsSmall.txt");

    main_menu(entries);
}

/**
 * Display the menu, process the choice, exit when selected.
 * @param entries the entries read from the original movie reviews.
 */
void main_menu(const Entries& entries) {
    // TODO: your implementation here
    int choice = 0;
    cout << "Menu" << endl;
    cout << "1) Get score of a word " << endl;
    cout << "2) Get the average score of words in a file (one per line) " << endl;
    cout << "3) Sort words in a file into positive.txt and negative.txt " << endl;
    cout << "4) Find the highest and the lowest scoring words in a file " << endl;
    cout << "5) Exit " << endl;
    cout << "Your choice: ";
    cin >> choice;

    //Entry entries
    switch (choice){
        case 1: single_word_score(entries);
       // case 2: average_score_of();
        //case 3: highest_lowest_words();
      //  case 4: split_pos_neg();
       // case 5: default:
       //     cout << "Exit" << endl;

    }
}

/**
 * Prompts user for a word and then prints how many times
 * the word occurs and it's average score.
 * @param entries the entries read from the original movie reviews.
 */
void single_word_score(const Entries& entries) {
    // TODO: your implementation here
    string word;
    cout << "Enter the word: ";
    cin >> word;
    cout << word << " appeared " << entries << " times. " << endl;
}

/**
 * Prompts user for the name of a file that contains 1 word
 * per line, reads that file and then prints the average score
 * for all words in a file together.
 * This will also print the overall sentiment of the phrase
 * represented by words in the file.
 * Consider an average word score
 * - above 2.01 as an overall positive sentiment,
 * - below 1.9 to have an overall negative sentiment,
 * - othewise to have an overall neutral sentiment.
 *
 * @param entries the entries read from the original movie reviews.
 */
void average_score_of(const Entries& entries) {
    // TODO: your implementation here
    cout << entries.find(word).get_average();

}

/**
 * Prompts user for the name of a file that contains 1 word
 * per line, reads that file and then
 * prints the highest and lowest scoring words in the specified file,
 * including the average score for each.
 *
 * @param entries the entries read from the original movie reviews.
 */
void highest_lowest_words(const Entries& entries) {
    // TODO: your implementation here

}

/**
 * Prompts user for the name of a file that contains 1 word
 * per line, reads that file and then
 * creates 2 new files, positive.txt and negative.txt
 * sorting words that have scores below 1.9 into negative.txt,
 * and words that have scores above 2.1 into positive.txt
 * (and just leave out words in between).
 *
 * @param entries the entries read from the original movie reviews.
 */
void split_pos_neg(const Entries& entries) {
    // TODO: your implementation here

}
