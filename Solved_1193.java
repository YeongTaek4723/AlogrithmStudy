package AlorigthmStudy;

import java.util.Scanner;

public class Solved_1193 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int line = 0;       // X가 가리키는 분수가 위치한 line
        int x, y;
        int cnt = 0;        // 모든 line에 분수 개수 

        while(cnt < X){
            line++;
            cnt = line * (line + 1) / 2;     // 등차수열의 합으로 구한 분수의 개수
        } 
        int lineCnt = X - line * (line - 1) / 2;    // X가 가리키는 분수가 위치한 곳을 찾기 위해 line - 1의 등차수열 합공식을 이용한 값을 X에 뺸다.
        
        if(line % 2 == 0){
            x = lineCnt;        // line의 시작 분수의 제일 큰 값은 line의 값이 되기에 그것을 기준으로 짝수라면 분자의 값에 홀수라면 분모의 값에 넣는다.                               
            y = line + 1 - x;
        }
        else{
            y = lineCnt;        // ex) line이 5라면 홀수이니 line시작 분수가 5/1이다. (X값이 14일 경우)
                                // lineCnt의 값이 4인데 문제의 표를 보면 5/1부터 시작해서 분자가 감소하고 분모가 증가하여 2/4가 된다. 
            x = line + 1 - y;
        }
        System.out.println(x + "/" + y);
        sc.close();
    }
}