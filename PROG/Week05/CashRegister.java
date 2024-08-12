import java.text.*;

/**
 * The cash register stores cash.
 *
 * You can add cash to the cash register.
 */
public class CashRegister {
    private double cash;

    public CashRegister(double cash) {
        this.cash = cash;
    }

    public CashRegister() {
        cash = 0;
    }

    public void add(double n) {
        cash += n;
    }

    public void subtract(double n) {
        cash -= n;
    }

    /**
     * Return a string in the form:
     *
     * Cash register: $[cash]
     *
     * e.g. "Cash register: $29.90"
     *
     * If there is no cash, instead return:
     *
     * "Cash register: empty"
     */
    @Override
    public String toString() {
        if (cash > 0)
            return String.format("Cash register: $%.2f", cash);
        else return "Cash register: empty";
    }
}
