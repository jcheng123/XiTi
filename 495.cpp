#include <iostream>
#include <vector>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) 
{
	int time_dur = 0;

	for(auto i = 1; i != timeSeries.size(); ++i)
		time_dur += min(timeSeries[i] - timeSeries[i - 1], duration);

    time_dur += duration;

    return time_dur;
}
