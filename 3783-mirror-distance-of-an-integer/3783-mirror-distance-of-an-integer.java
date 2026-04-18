class Solution {
    public int mirrorDistance(int n) {
        int og = n;
        int rev = 0;
        while (n != 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        int result = og - rev;
        return Math.abs(result); 
    }
}