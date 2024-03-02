int bestTimeToBuyAndSellStock(vector<int>&prices) {
    int mini=prices[0]; 
    int profit=0;
    for(int i=0;i<prices.size();i++){
      int cost =prices[i]-mini;
      profit=max(cost,profit);
      mini=min(prices[i],mini);
    }
    return profit;
}



Time Complexity:   O(N)

Space Complexity:  O(1) 
