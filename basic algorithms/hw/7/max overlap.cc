/* https://www.techiedelight.com/maximum-overlapping-intervals-problem/ */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
// Function to find the point when the maximum number of guests are present in an event
void findMaxGuests(vector<int> arrival, vector<int> departure)      // no-ref, no-const
{
    // sort the arrival and departure arrays in increasing order
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
 
    int checked_in = 0;      // keep track of the total number of guests at any time
    int max_checked_in = 0;  // keep track of the maximum number of guests in the event
    int max_event_tm = 0;    // keep track of the time when there are maximum guests
 
    /* The following code is similar to the merge routine of the merge sort */
 
    // Process all events (arrival & departure) in sorted order
    for (int i = 0, j = 0; i < arrival.size() && j < departure.size(); )
    {
        // if the next event is arrival
        if (arrival[i] <= departure[j])
        {
            // increment number of guests
            checked_in++;
 
            // update the maximum count of guests if needed
            if (max_checked_in < checked_in)
            {
                max_checked_in = checked_in;
                max_event_tm = arrival[i];
            }
 
            // increment index of arrival array
            i++;
        }
 
        // if the next event is a departure
        else {
            // decrement number of guests
            checked_in--;
 
            // increment index of departure array
            j++;
        }
    }
 
    cout << "Event Time: " << max_event_tm << endl;
    cout << "The Maximum number of guests is " << max_checked_in << endl;
}
 
int main()
{
    vector<int> arrival = { 1, 2, 4, 7, 8, 12 };
    vector<int> departure = { 2, 7, 8, 12, 10, 15 };
    findMaxGuests(arrival, departure);
}