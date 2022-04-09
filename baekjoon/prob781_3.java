import java.util.Scanner;

public class prob781_3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i<=n; i++){
            System.out.print(Integer.toBinaryString(i));
        }
    }
}