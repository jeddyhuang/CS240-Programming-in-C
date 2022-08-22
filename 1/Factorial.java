import java.math.BigInteger;

public class Factorial {
        public static void main(String[] args) {
                BigInteger result = BigInteger.valueOf(1);
                for (int i = 2; i <= 200; i++) {
                        result = result.multiply(BigInteger.valueOf(i));
                }

                System.out.println("Result: " + result);
        }
}