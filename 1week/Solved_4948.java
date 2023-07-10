package AlorigthmStudy;

import java.util.Scanner;

public class Solved_4948{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.println(">>");
            int n = sc.nextInt();
            if(n == 0)  break;

            boolean[] arr = new boolean[246913];
            int M = n * 2;

            arr[0] = arr[1] = true;

            for(int i = 2; i <= Math.sqrt(arr.length); i++){
                if(arr[i])  continue;

                for(int j = i * i; j < arr.length; j += i){
                    arr[j] = true;
                }
            }

            int cnt = 0;
            for(int i = n + 1; i <= M; i++){
                if(!arr[i])   cnt++;
            }
            System.out.println(cnt);
        }

        sc.close();
    }
}