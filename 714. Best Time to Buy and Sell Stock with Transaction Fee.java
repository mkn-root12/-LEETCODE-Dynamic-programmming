class Solution {
    public int maxProfit(int[] prices, int fee) {

        int n;
        if(prices ==null || (n=prices.length)==0 )return 0;
        
        // Initial state: profit by selling is 0, buying results in negative profit
        int cash = 0,hold = -prices[0],oldCash;
        for(int i=1;i<n;i++){
            // At every step, buy represents the max profit in buy status, given 
            // that the last action you took is a buy action in the past
            //  And you have the right to sell in future, or do nothing. Similar for sell
            oldCash = cash;
            cash = Math.max(cash,hold+prices[i]-fee); //keep the same as previous day, or sell from buy status of previous day
            hold = Math.max(hold,oldCash-prices[i]); // keep the same as previous , or buy from sell status of previous day
        }
        return cash;
    }
}
