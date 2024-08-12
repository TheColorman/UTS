/**
 * The store has and sells one product: Sticky tape.
 *
 * You can sell and restock a product, view stock and view cash.
 */
public class Store {
    public static void main(String[] args) {
        new Store().use();
    }

    private Product stickyTape = new Product("Sticky tape", 2.99, 200);
    private CashRegister cashRegister = new CashRegister();

    public Store() {
        // No need to do anything..
    }

    public void use() {
        while (true) {
            System.out.print("Choice (s/r/v/c/x): ");
            char c = In.nextChar();

            switch (c) {
                case '?':
                    help();
                    break;
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
                case 'x':
                    System.exit(0);
                    break;

                default:
                    break;
            }
        }
    }

    private void sell() {
        System.out.print("Number: ");
        int n = In.nextInt();
        try {
            double earned = stickyTape.sell(n);
            cashRegister.add(earned);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }

    private void restock() {
        System.out.print("Number: ");
        int n = In.nextInt();
        stickyTape.restock(n);
    }

    private void viewStock() {
        System.out.println(stickyTape);
    }

    private void viewCash() {
        System.out.println(cashRegister);
    }

    private void help() {
        System.out.println("Menu options");
        System.out.println("s = sell");
        System.out.println("r = restock");
        System.out.println("v = view stock");
        System.out.println("c = view cash");
        System.out.println("x = exit");
    }
}
