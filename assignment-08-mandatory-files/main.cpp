#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

struct Length
{
	int minutes;							// #minutes (0..)
	int seconds;							// #seconds (0..59)
};

struct Track
{
	string artist;                          // name of artist
	string cd;                              // cd title
	int    year;                            // year of appearance (if known)
	int    track;							// track number
	string title;                           // track title
	string tags;                            // tags
	Length time;							// playing time
	string country;                         // main countr(y/ies) of artist
};

struct TrackDisplay
{
	bool showArtist;						// if true, show name of artist
	bool showAlbum;							// if true, show cd title
	bool showYear;							// if true, show year of appearance
	bool showTrack;							// if true, show track number
	bool showTitle;							// if true, show track title
	bool showTags;                          // if true, show tags
	bool showLength;						// if true, show playing time
	bool showCountry;                       // if true, show countr(y/ies) of artist
};

bool match (string sub, string source)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    Result is true only if sub is a literal (case sensitive) sub string of source.
*/
    return source.find(sub) != string::npos ;
}

ostream& operator<< (ostream& out, const Length length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length is shown via out in the format: minutes, ':', seconds (two digits)
*/
    if (length.seconds >= 10)
        out << length.minutes << ':' << length.seconds;
    else
        out << length.minutes << ':' << '0' << length.seconds;
    return out;
}

istream& operator>> (istream& in, Length& length)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the value of length has been read from in: first minutes, then ':', then seconds
*/
    char colon = ':';
    in >> length.minutes >> colon >> length.seconds;
    return in;
}

Length operator+ (const Length& a, const Length& b)
{// Precondition:
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*  Postcondition:
    Result is the sum of a and b.
*/
    Length sum;
    int totalSeconds = a.seconds + b.seconds;
    int actualSeconds = totalSeconds % 60;
    int bonusMinutes = totalSeconds / 60;
    sum.minutes = a.minutes + b.minutes + bonusMinutes;
    sum.seconds = actualSeconds;
    return {sum};
}

void show_track (Track track, TrackDisplay lt, ostream& os)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    only the members of track are shown for which the corresponding member in lt is true.
*/
    if (lt.showArtist == true)
        os << track.artist << endl;
    if (lt.showAlbum == true)
        os << track.cd << endl;
    if (lt.showYear == true)
        os << track.year << endl;
    if (lt.showTrack == true)
        os << track.track << endl;
    if (lt.showTitle == true)
        os << track.title << endl;
    if (lt.showTags == true)
        os << track.tags << endl;
    if (lt.showLength == true)
        os << track.time << endl;
    if (lt.showCountry == true)
        os << track.country << endl;   
}

int match_tracks (const vector<Track>& tracks, string title, bool display)
{// Precondition:
    assert (true);
/*  Postcondition:
    return value is the number of tracks in `tracks` that have a title matching `title`
    if `display` is true, all matched tracks have been printed to `cout`
*/
    int counts = 0;
    string thisTitle;
    for (int no = 0; no < ssize(tracks); no++)
    {
        if (match(title, tracks.at(no).title) == true) // the title matches
        {
            if (tracks.at(no).title != thisTitle) // Repeated title is counted only once
            {
                counts++;
                thisTitle = tracks.at(no).title;
            }       
            if (display == true)
            {
                cout << "Matched Track: " << tracks.at(no).title << endl ;
                cout << "Artist: " << tracks.at(no).artist << endl ;
                cout << "CD: " << tracks.at(no).cd << endl ;
                cout << "Year: " << tracks.at(no).year << endl ;
                cout << "Track: " << tracks.at(no).track << endl ;
                cout << "Tags: " << tracks.at(no).tags << endl ;
                cout << "Time: " << tracks.at(no).time.minutes <<':'<< tracks.at(no).time.seconds << endl ;
                cout << "Country: " << tracks.at(no).country << endl ;
            }
        }
    }       
    return counts;
}

int match_artists (const vector<Track>& tracks, string artist, bool display)
{// Precondition:
    assert (true);
/*  Postcondition:
    return value is the number of tracks in `tracks` that have an artist matching `artist`, where each artist is only matched once
    if `display` is true, all matched tracks have been printed to `cout`
*/
    int counts = 0;
    string thisArtist;
    for (int no = 0; no < ssize(tracks); no++)
    {
        if (match(artist, tracks.at(no).artist) == true) // the artist matches
        {
            if (tracks.at(no).artist != thisArtist) // Repeated artist is counted only once
            {
                counts++;
                thisArtist = tracks.at(no).artist;
            }                                 
            if (display == true)
            {
                cout << "Matched Artist: " << tracks.at(no).artist << endl ;
                cout << "Track: " << tracks.at(no).title << endl ;
                cout << "CD: " << tracks.at(no).cd << endl ;
                cout << "Year: " << tracks.at(no).year << endl ;
                cout << "Track: " << tracks.at(no).track << endl ;
                cout << "Tags: " << tracks.at(no).tags << endl ;
                cout << "Time: " << tracks.at(no).time.minutes <<':'<< tracks.at(no).time.seconds << endl ;
                cout << "Country: " << tracks.at(no).country << endl ;
            }
        }
    }       
    return counts;
}

int match_cds (const vector<Track>& tracks, string cds, bool display)
{// Precondition:
    assert (true);
/*  Postcondition:
    return value is the number of tracks in `tracks` that have an artist matching `artist`, where each (artist, cd) pair is only matched once
    if `display` is true, all matched tracks have been printed to `cout`
*/
    int counts = 0;
    string thisCd;
    for (int no = 0; no < ssize(tracks); no++)
    {
        if (match(cds, tracks.at(no).cd) == true) // the cd matches
        {
            if (tracks.at(no).cd != thisCd) // Repeated cd is counted only once
            {
                counts++;
                thisCd = tracks.at(no).cd;
            }  
            if (display == true)
            {
                cout << "Matched CD: " << tracks.at(no).cd << endl ;
                cout << "Track: " << tracks.at(no).title << endl ;
                cout << "Artist: " << tracks.at(no).artist << endl ;
                cout << "Year: " << tracks.at(no).year << endl ;
                cout << "Track: " << tracks.at(no).track << endl ;
                cout << "Tags: " << tracks.at(no).tags << endl ;
                cout << "Time: " << tracks.at(no).time.minutes <<':'<< tracks.at(no).time.seconds << endl ;
                cout << "Country: " << tracks.at(no).country << endl ;
            }
        }
    }       
    return counts;
}

int number_of_cds (const vector<Track>& tracks)
{// Precondition:
    assert (true);
/*  Postcondition:
    return value is the number of tracks in `tracks` that have an unique (artist, cd) pair, where each pair is counted once
*/
    int counts = 0;
    string thisArtist, thisCd;
    for (int no = 0; no < ssize(tracks); no++)
    {
        if (tracks.at(no).artist != thisArtist || tracks.at(no).cd != thisCd)
        {
            counts++;
            thisArtist = tracks.at(no).artist;
            thisCd = tracks.at(no).cd;
        }
    }
    return counts;
}

istream& operator>> (istream& in, Track& track)
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the content of the first 8 lines from in have been read and are stored in the corresponding members of track.
    The following (empty) line from in has also been read.
*/
    char colon = ':';
    char delim = '\n';
    string emptyLine;
    in >> track.artist >> delim >> track.cd >> delim >> track.year >> delim >> track.track 
    >> delim >> track.title >> delim >> track.tags >> delim >> track.time.minutes >> colon 
    >> track.time.seconds >> delim >> track.country >> delim;  
    return in;
}

int read_tracks (string filename, vector<Track>& tracks, bool show_content)
{// Precondition:
    assert (true);
/*  Postcondition:
    tracks is a copy of the tracks that are found in the file with file name filename, and result
    is the number of tracks that have been read.
    Only if show_content, then all read tracks are shown on screen.
*/
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return 0;
    }

    string line;
    Track currentTrack;

    while(getline(infile, line))
    {      
        if(line.empty())
        {
            tracks.push_back(currentTrack);
            if(show_content == true)
            {
                cout << "Matched Track: " << currentTrack.title << endl ;
                cout << "Artist: " << currentTrack.artist << endl ;
                cout << "CD: " << currentTrack.cd << endl ;
                cout << "Year: " << currentTrack.year << endl ;
                cout << "Track: " << currentTrack.track << endl ;
                cout << "Tags: " << currentTrack.tags << endl ;
                cout << "Time: " << currentTrack.time.minutes <<':'<< currentTrack.time.seconds << endl ;
                cout << "Country: " << currentTrack.country << endl ;
            }
        }

        else
            infile >> currentTrack;    
    }

    infile.close();
    return ssize(tracks);
}

#ifndef TESTING
int main ()
{// Precondition:
    assert (true) ;
/*  Postcondition:
    the music database "Tracks.txt" has been read (if present and correctly formatted),
    and the number of tracks read and the number of cds has been printed to `cout`
*/
    vector<Track>tracks;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    int trackNum = read_tracks(filename, tracks, false);
    int CDNum = number_of_cds (tracks);
    cout << "Track number in " << filename << " is " << trackNum << endl;
    cout << "CD number in " << filename << " is " << CDNum << endl;
	return 0;
}
#endif
