package Arraylists;

public class Data {

    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        String name = "Hello ";
        sb.append(name);
        sb.append("World");
        sb.insert(2,"BULLSHIP");

        System.out.println("LAST INDEX OF d: " + sb.lastIndexOf("d"));
        System.out.println(sb);
    }
}
