class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int hh, mm, totalMinutes;

        for(string timePoint:timePoints){
            hh = stoi(timePoint.substr(0,2));
            mm = stoi(timePoint.substr(3,2));
            totalMinutes = hh*60+mm;
            minutes.emplace_back(totalMinutes);
        }

        sort(minutes.begin(), minutes.end());
        int ans=720;

        for(int i=0; i<minutes.size()-1; i++){
            ans=min(ans,(minutes[i+1]-minutes[i]));
        }

        ans=min(ans,(24*60+minutes[0]-minutes[minutes.size()-1]));

        return ans;
    }
};