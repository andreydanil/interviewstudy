package OOP;

import java.util.HashMap;

public class Contacts {

    enum StatusType { Online, Offline };

    class Status {
        StatusType type;
        String message;
    }

    public static class Contact {
        private int id;
        private String firstName;
        private String lastName;
        private String streetAddress;
        private int zip;
        private int phone;

        public Contact(int id, String firstName, String lastName, String streetAddress, int zip, int phone) {
            this.id = id;
            this.firstName = firstName;
            this.lastName = lastName;
            this.streetAddress = streetAddress;
            this.zip = zip;
            this.phone = phone;
        }

        public void printContact() {
            System.out.println("id: " + id + " FirstName: " + firstName);
        }
    }

    public static void main(String[] args) {


        StatusType type = StatusType.Offline;

        switch(type) {
            case Online: {
                System.out.println("ONLINE");
                break;
            }
            case Offline: {
                System.out.println("OFFLINE");
                break;
            }
            default: {
                break;
            }

        }




        HashMap<Integer,Contact> contacts = new HashMap<Integer, Contact>();

        contacts.put(1,new Contact(1,"Joe","Doe","Streeterville",12345,1232131234));

        contacts.get(1).printContact();
    }
}
