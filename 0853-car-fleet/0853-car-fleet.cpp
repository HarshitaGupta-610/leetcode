class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
 int n = position.size();

 //Har car ka target tak pahunchne ka time calculate karo, position ke according sort karo, phir closest-to-target se check karo — agar current car ka time fleet ke time se zyada hai toh new fleet, warna woh existing fleet ko join karegi.
 //Fleet tab banegi jab current car ka arrival time, uske aage wali fleet ke arrival time se zyada ho.
 //tc: o(nlogn)
        vector<pair<int,double>>cars;
        for(int i = 0 ; i < n ; i++){
double time = (double)(target-position[i])/speed[i];
cars.push_back({position[i] , time});
        }
        sort(cars.begin(),cars.end());
        int fleets = 0;
        double fleetTime = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            double curr = cars[i].second;
            if(curr > fleetTime){
                fleets++;
                fleetTime = curr;
            }
        }
return fleets;
    }
};