#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

const int MAX_NO_OF_TERMS = 100;         // the maximum number of terms to read for a word sequence
const int MAX_NO_OF_WORDS = 25000;       // the maximum number of words to read from a text file

bool read_word (ifstream& infile, string& word)
{// precondition:
    assert (infile.is_open());
/*  postcondition:
    result is true only if a word is read from `infile`, and this word is assigned to `word`.
    result is false otherwise, and the value of `word` should not be used.
*/
    infile >> word;
    return !infile.fail();
}

int enter_command (string filename, string content [MAX_NO_OF_WORDS])
{// precondition:
    assert (true);
/*  postcondition:
    if result is a positive number then the text file with file name `filename` has been successfully opened and closed after reading, and result number of words
    have been read from that file (at most MAX_NO_OF_WORDS) and are stored in that order in `content`.
    if result is zero, then either the text file was empty or has not been opened.
*/
    ifstream file (filename);  // Open File  
    if (file.fail())
    {
        cerr << "Error: File "<< filename << " could not be opened." << endl;
        return 0;
    }    
    else
    {
        int no_of_words = 0; // array index of content
        string next_word;
        while (read_word (file, next_word) == true && no_of_words < MAX_NO_OF_WORDS) // When there are still words left in file and index doesn't reach the maximum
        {
            content[no_of_words] = next_word;
            no_of_words++;
        }
    file.close();
    return no_of_words++;
    }
}

int count_command (string content [MAX_NO_OF_WORDS], int no_of_words, string terms [MAX_NO_OF_TERMS], int no_of_terms)
{// precondition:
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);
/*  postcondition:
    result is the number of occurrences of the word sequence `terms` (which has `no_of_terms` elements) in `content` (which has `no_of_words` elements)
    (the result is obviously zero in case `no_of_words` < `no_of_terms`)
*/
    int count = 0;
    int word_in_term = 0;
    for (int i = 0; i < no_of_words; i++)
    {
        if (content[i] == terms[word_in_term]) // index where the word same as the first word in term
        {
            int j = i + 1;
            int k = i + no_of_terms -1;
            word_in_term++;
            while (j < k && content[j] == terms[word_in_term])
            {
                j++;
                word_in_term++;
            }
            if (j == k) // we find a term in ieration i
            {
            count++;
            }
            word_in_term = 0;
        }
    }
    return count;
}

int where_command (string content [MAX_NO_OF_WORDS], int no_of_words, string terms [MAX_NO_OF_TERMS], int no_of_terms)
{// precondition:
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);
/*  postcondition:
    result is the number of occurrences of the word sequence `terms` (which has `no_of_terms` elements) in `content` (which has `no_of_words` elements)
    (the result is obviously zero in case `no_of_words` < `no_of_terms`)
*/
    
    // implement this function
    return 0;
}

int context_command (int m, string content [MAX_NO_OF_WORDS], int no_of_words, string terms [MAX_NO_OF_TERMS], int no_of_terms)
{// precondition:
    m >= 1;
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);
/*  postcondition:
    result is the number of occurrences of the word sequence `terms` (which has `no_of_terms` elements) in `content` (which has `no_of_words` elements)
    (the result is obviously zero in case `no_of_words` < `no_of_terms`)
*/
    
    // implement this function
    return 0;
}

#ifndef TESTING
int main ()
{// precondition:
    assert(true);
/*  postcondition:
    program has presented interactive interface to user, allowing commands to be entered and executed
*/
    return 0;
}
#endif
