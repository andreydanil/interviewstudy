package OOP;

public class Fractions {

    public static class Fraction {
        double numerator;
        double denominator;

        public Fraction(double numerator, double denominator) {
            this.numerator = numerator;
            this.denominator = denominator;
        }

        public double getNumerator() {
            return numerator;
        }

        public void setNumerator(double numerator) {
            this.numerator = numerator;
        }

        public double getDenominator() {
            return denominator;
        }

        public void setDenominator(double denominator) {
            this.denominator = denominator;
        }
    }

    public static void main(String[] main) {

        Fraction[] points = new Fraction[2];

        points[0] = new Fraction(2,3);
        points[1] = new Fraction(1,2);

        double result;
        double multiplier0 = points[0].denominator;
        double multiplier1 = points[1].denominator;

        points[0].setNumerator(points[0].numerator * multiplier1);
        points[0].setDenominator(points[0].denominator * multiplier1);
        System.out.println(points[0].numerator + " " + points[0].denominator);

        points[1].setNumerator(points[1].numerator * multiplier0);
        points[1].setDenominator(points[1].denominator* multiplier0);
        System.out.println(points[1].numerator + " " + points[1].denominator);

        result = (7 / 6);

        System.out.println("result: " + result);

    }
}
