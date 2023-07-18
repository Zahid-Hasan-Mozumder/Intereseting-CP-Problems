// Problem link: https://vjudge.net/problem/UVA-10541
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
import java.math.BigInteger;
import java.util.Scanner;
    
class Main {
    
    public static void main(String args[]) {
        BigInteger[] fact=new BigInteger[205];
        fact[0]=BigInteger.ONE;
        for(int i=1;i<=200;i++) {
            fact[i]=fact[i-1].multiply(BigInteger.valueOf(i));
        }
        
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        for(int cs = 1; cs <= t; cs++){
            int n = sc.nextInt();
            int k = sc.nextInt();
            int sum = 0;
            for(int i = 0; i < k; i++){
                int x = sc.nextInt();
                if(i < k - 1) sum += x + 1;
                else sum += x;
            }
            if(sum > n){
                System.out.println("0");
            }
            else{
                int stars = n - sum;
                int bars = k;
                BigInteger ans = fact[stars + bars];
                ans = ans.divide(fact[stars]);
                ans = ans.divide(fact[bars]);
                System.out.println(ans);
            }
        }
    }
}
