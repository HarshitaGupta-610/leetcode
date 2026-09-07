class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
      sort(deck.begin() , deck.end());
      vector<int>answer(n,0);
      int i  = 0;//deck
      int j = 0;//ans
      bool done = false;
      while(i<n){
        if(answer[j] ==0){
            if(done == false){
                answer[j] = deck[i];
                i++;            
        }
        done = !(done);//for altering
      } 
      j = (j+1)%n; 
    }
    return answer;
}

};