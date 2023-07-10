package AlorigthmStudy;

import java.util.Scanner;

public class Solved_2869 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println(">>");
        int A = sc.nextInt();
        int B = sc.nextInt();
        int V = sc.nextInt();
        int day = 0;
        
        day = (V - B) / (A - B);
        if((V - B) % (A - B) != 0)      day++;
        System.out.println(day);
        sc.close();
    }
}