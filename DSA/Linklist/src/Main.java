import java.util.Scanner;

public class Main {
    static int Round(double n) {
        if (n >= 0) {
            return (int) (n + 0.5);
        } else {
            return (int) (n - 0.5);
        }
    }

    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        double n = Input.nextDouble();
        System.out.println(Round(n));
    }
}