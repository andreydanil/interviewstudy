package OOP;

public class Slope {

    public static class Points {
        Double x;
        Double y;

        public Points(Double x, Double y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] main) {
        Points[] points = new Points[2];

        points[0] = new Points(-1.0,-2.0);
        points[1] = new Points(1.0,1.0);

        System.out.println("Point 1: (" + points[0].x + ", " + points[0].y + ")");
        System.out.println("Point 2: (" + points[1].x + ", " + points[1].y + ")");

        double slope = (points[1].y - points[0].y) / (points[1].x - points[0].x);

        System.out.println("This is the slope: " + slope);


    }


}
