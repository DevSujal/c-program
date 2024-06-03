public class oddevenwithoutmodulo {

    public static void main(String[] args) {

        int number = 12;
        
        String str = "odd";

        if(number/2 == number/2.0){
            str = "even";
        }

        
        
        System.out.println(
                "the given number is " + str
                );
    }
}