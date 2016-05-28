package sorting;

/**
 * @author andreydanilkovich
 *
 */

public class Employee {
	int employeeNumber;
	String firstName;
	String lastName;
	String email;
	
	public Employee() {
		this.employeeNumber = employeeNumber;
	}
	

	
	public int getEmployeeNumber() {
		return employeeNumber;
	}



	public void setEmployeeNumber(int employeeNumber) {
		this.employeeNumber = employeeNumber;
	}



	public String getFirstName() {
		return firstName;
	}



	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}



	public String getLastName() {
		return lastName;
	}



	public void setLastName(String lastName) {
		this.lastName = lastName;
	}



	public String getEmail() {
		return email;
	}



	public void setEmail(String email) {
		this.email = email;
	}



	@Override
	public String toString() {
		return String.valueOf(this.employeeNumber);
	}
}
