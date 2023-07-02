package AlorigthmStudy;

import java.util.Scanner;
import java.util.Stack;


public class Solved_10773{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<Integer>();
        int K = sc.nextInt();

        for(int i = 1; i <= K; i++){
            int num = sc.nextInt();

            if(num == 0)    stack.pop();
            else            stack.push(num);
        }

        int sum = 0;
        for(int n : stack){
            sum += n;
        }

        System.out.println(sum);
        sc.close();
    }
}