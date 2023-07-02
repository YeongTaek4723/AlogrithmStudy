package Alorigthm;

import java.util.Scanner;

public class Solved_1929{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();

        boolean[] arr = new boolean[10000001];

        arr[0] = arr[1] = true;

        for(int i = 2; i <= Math.sqrt(arr.length); i++){
            if(arr[i])  continue;

            for(int j = i * i; j < arr.length; j += i){
                arr[j] = true;
            }
        }


        for(int i = m; i <= n; i++){
            if(!arr[i])     System.out.println(i);
        }

        sc.close();
    }
}