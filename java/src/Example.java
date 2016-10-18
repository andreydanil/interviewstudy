

public class Example {
	public static void main(String[] args) {
		
		Dog myDog = new Dog();
		Dog yourDog = new Dog();
		
		myDog.size = 50;
		yourDog.size = 15;
		
		myDog.bark();
		yourDog.bark();
		
		yourDog = myDog;
		myDog.bark();
		yourDog.bark();
		
		yourDog.size = 10;
		myDog.bark();
	}
}
