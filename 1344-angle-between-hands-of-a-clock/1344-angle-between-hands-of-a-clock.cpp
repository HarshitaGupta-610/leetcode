class Solution {
public:
    double angleClock(int hour, int minutes) {
//The minute hand covers 360° in 60 minutes, so it moves 6° every minute.
//The hour hand covers 360° in 12 hours, so it moves 30° every hour.
double houra = (hour %12)*30 + minutes *0.5;//minute and hour angle 0.5
double minuteA = minutes*6;
double diff = abs(houra - minuteA);
return min(diff , 360-diff);
    }
};