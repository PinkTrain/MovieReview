/**
 * This is based on code taken from
 * Manley, E.D., & Urness, T. M.,
 * http://nifty.stanford.edu/2016/manley-urness-movie-review-sentiment/CS2SentimentStarterCode.zip,
 * last access Sep 15, 2016.
 *
 */

#include "Entries.h"
#include <algorithm>

unsigned int index = 0;
WordEntry wEntry;

/**
 * Creates a new Entries object.
 */
Entries::Entries() { }

/**
 * Returns true iff the word is in the entries.
 * @param word the word to search for.
 * @return true iff the word is in the entries.
 */
bool Entries::contains(string word) const {
    // TODO: your implementation here.

    for (auto & wEntry : data){
        if (wEntry.get_word() == word)
            return true;
    }
    return false;
}

/**
 *  First, look to see if word already exists in the Entries
 *  + if so, add_new_appearence with the score to the WordEntry
 *  + if not, create a new WordEntry and insert it
 *
 * @param word the word to enter
 * @param score the score of the word to enter
 */
void Entries::put(string word, int score) {
    // TODO: your implementation here.
    //WordEntry wEntry;
    if (this->contains(word)){
        wEntry = this->find(word);
        wEntry.add_new_appearance(score);
        data.at(index) = wEntry;
        cout << word << " appeared " << wEntry.get_num_appearances() << " times. " << endl;

    }else{
        data.push_back(WordEntry(word, score));
        cout << word << " appeared " << 1 << " times. " << endl;
    }

}

/**
 * Returns the average value for the word.  If not found,
 * returns 2.0 (neutral result).
 * Must first find the corresponding word in the entries
 * and then return the average.
 *
 * @param the word to find.
 * @return the average value for the word.  If not found,
 * returns 2.0 (neutral result).
 */
double Entries::get_average(string word) const {
    // TODO: your implementation here.
    auto word_match_fn = [word](auto data) {
        return data.get_word() == word;
    };
    auto word_it = find_if(begin(data), end(data), word_match_fn);
    if (word_it == end(data)){
        //match found
        cout << "match found" << endl;
        cout << "word average = ";
        return wEntry.get_average();

    } else{
        return 2.0;
    }

}

/**
 * Returns the WordEntry for the given word.  If the word
 * is not among the entries it returns the result of calling the
 * no-argument constructor of the WordEntry class.
 *
 * @param word the word to search for.
 * @return the WordEntry for the given word.  If the word
 * is not among the entries it returns the result of calling the
 * no-argument constructor of the WordEntry class.
 */
WordEntry Entries::find(string word) const {
    // TODO: your implementation here.
    unsigned int i = 0;
    for (auto & wEntry : data){
        if (wEntry.get_word() == word){
            index = i;
            return wEntry;
        }
        i++;
    }
    return WordEntry();
}
