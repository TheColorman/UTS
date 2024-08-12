import java.util.*;

public class Store {
    private CashRegister cashRegister;
    private LinkedList<Product> products = new LinkedList<Product>();

    public Store() {
        products.add(new Product("Whiteboard Marker", 85, 1.5));
        products.add(new Product("Whiteboard Eraser", 45, 5));
        products.add(new Product("Black Pen", 100, 1.5));
        products.add(new Product("Red Pen", 100, 1.5));
        products.add(new Product("Blue Pen", 100, 1.5));
        cashRegister = new CashRegister();
    }

    public static void main(String[] args) {
        new Store().use();
    }

    private char readChoice() {
        System.out.print("Choice (s/r/v/c/p/x): ");
        return In.nextChar();
    }

    public void use() {
        while (true) {
            switch (readChoice()) {
                case 's':
                    sell();
                    break;
                case 'r':
                    restock();
                    break;
                case 'v':
                    viewStock();
                    break;
                case 'c':
                    viewCash();
                    break;
                case 'p':
                    pruneProducts();
                    break;
                case 'x':
                    System.out.println("Done");
                    System.exit(0);
                    break;
                default:
                    help();
                    break;
            }
        }
    }

    private ArrayList<Product> findProducts(String name) {
        ArrayList<Product> matches = new ArrayList<Product>();
        name = name.toLowerCase();
        for (Product product : products) {
            if (product.getName().toLowerCase().contains(name))
                matches.add(product);
        }
        if (matches.size() == 0)
            return null;
        return matches;
    }

    private void sell() {
        String name = readName();
        ArrayList<Product> ps = findProducts(name);
        if (ps == null) {
            System.out.println("No such product");
            return;
        }
        if (ps.size() > 1) {
            System.out.println("Multiple products match:");
            for (Product product : ps) {
                System.out.println(product);
            }
            return;
        }
        System.out.println("Selling " + ps.get(0).getName());
        int n = readNumber();
        cashRegister.add(ps.get(0).sell(n));
    }

    private void restock() {
        String name = readName();
        ArrayList<Product> ps = findProducts(name);
        if (ps == null) {
            System.out.println("Adding new product");
            int n = readNumber();
            double price = readPrice();
            products.add(new Product(name, n, price));
            return;
        }
        for (Product p : ps) {
            System.out.println("Restocking " + p.getName());
            int n = readNumber();
            p.restock(n);
        }
    }

    private void viewStock() {
        for (Product product : products)
            System.out.println(product);

    }

    private void viewCash() {
        System.out.println(cashRegister);
    }

    private void pruneProducts() {
        ArrayList<Product> toDelete = new ArrayList<>();
        for (Product product : products) {
            if (product.isEmpty())
                toDelete.add(product);
        }
        for (Product product : toDelete) {
            products.remove(product);
        }
    }

    private String readName() {
        System.out.print("Name: ");
        return In.nextLine();

    }

    private double readPrice() {
        System.out.print("Price: $");
        return In.nextDouble();
    }

    private int readNumber() {
        System.out.print("Number: ");
        return In.nextInt();

    }

    private void help() {
        System.out.println("Menu options");
        System.out.println("s = sell");
        System.out.println("r = restock");
        System.out.println("v = view stock");
        System.out.println("c = view cash");
        System.out.println("p = prune products");
        System.out.println("x = exit");
    }
}