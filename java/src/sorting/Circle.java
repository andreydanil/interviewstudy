package sorting;

public class Circle {

	private double radius;
	
	public Circle(double radius) {
		this.radius = radius;
	}
	
	public double area() {
		return Math.PI * this.radius * this.radius;
	}
	
	public double perimeter() {
		return 2 * Math.PI * this.radius;
	}
	
	public double getRadius() {
		return this.radius;
	}
	
	@Override
	public String toString() {
		return String.valueOf(this.radius);
	}
}
