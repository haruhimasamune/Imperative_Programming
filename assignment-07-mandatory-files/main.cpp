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
        int no_of_words = 0; // index of array `content` 
        string next_word;
        while (read_word (file, next_word) == true && no_of_words < MAX_NO_OF_WORDS) // When there are still words left in file and index doesn't reach the maximum
        {
            content[no_of_words] = next_word;
            no_of_words++;
        }
    file.close();
    return no_of_words;
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
            int j = i;
            int k = i + no_of_terms -1; // index of the last word in term starting at index i
            while (j < k && content[j] == terms[word_in_term]) // check if the current word in content is the same as the word in term with corresponding index
            {
                j++;
                word_in_term++;
            }
            if (j == k) // we find a term
            {
            count++;
            }
            word_in_term = 0;
        }
    }
    return count;
}

int where_command (int term_order, string content [MAX_NO_OF_WORDS], int no_of_words, string terms [MAX_NO_OF_TERMS], int no_of_terms)
{// precondition:
    assert(term_order >= 0 && term_order < MAX_NO_OF_TERMS);
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);
/*  postcondition:
    result is the starting index of occurrences of the word sequence `terms` in order `term_order`
*/
    
    int count = 0;
    int word_in_term = 0;
    int term_index[MAX_NO_OF_TERMS];
    for (int i = 0; i < no_of_words; i++)
    {
        if (content[i] == terms[word_in_term]) // index where the word same as the first word in term
        {
            int j = i;
            int k = i + no_of_terms -1; // index of the last word in term starting at index i
            while (j < k && content[j] == terms[word_in_term]) // check if the current word in content is the same as the word in term with corresponding index
            {
                j++;
                word_in_term++;
            }
            if (j == k) // we find a term in ieration i
            {
            term_index[count]=i;        
            count++;
            }
            word_in_term = 0;
        }
    }
    return term_index[term_order] + 1; // starts from 1 not 0
}

int context_command (int con_length, int term_order, string content [MAX_NO_OF_WORDS], int no_of_words, string terms [MAX_NO_OF_TERMS], int no_of_terms)
{// precondition:
    assert(con_length >= 1);
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);
/*  postcondition:
    If both the above text and below text has the exact same length as `con_length`, return 0
    If only the above text has length shorter than `con_length`, return 1
    If only the below text has length shorter than `con_length`, return 2
    If only the below text has length shorter than `con_length`, return 3
*/
    return 0;
}

#ifndef TESTING
int main ()
{// precondition:
    assert(true);
/*  postcondition:
    program has presented interactive interface to user, allowing commands to be entered and executed
*/
    string filename;
    string content [MAX_NO_OF_WORDS];
    cout << "Enter the filename: ";
    cin >> filename;
    int no_of_words = enter_command(filename, content);
    if (no_of_words != 0)
    {
        cout << "Enter your term: ";
        int no_of_terms;
        string terms[MAX_NO_OF_TERMS];
        for(no_of_terms = 0; no_of_terms < MAX_NO_OF_WORDS; ++no_of_terms)
        {
            cin >> terms[no_of_terms];
        }
        cout << "You entered term: ";
        for(int i = 0; i < no_of_terms; ++i)
        {
            cout << terms[i] << " ";
        }
        int choice;
        cout << "What command do you want? count-1, where-2, context-3: ";
        cin >> choice;
        switch (choice)
        {
            case 1:               
                cout << "Found sequence " << count_command (content, no_of_words, terms, no_of_terms) <<" times in " << no_of_words <<"words";
                break;
            case 2:
                for(int term_order = 0; term_order < count_command (content, no_of_words, terms, no_of_terms); ++term_order)
                {
                    cout << "Found occurance at index " << where_command (term_order,content, no_of_words, terms, no_of_terms);
                }
                break;
            case 3:

                break;
            default:
                cout << "Invalid command, please type 1,2 or 3.";
                break;
        }
    }    

    return 0;
}
#endif
