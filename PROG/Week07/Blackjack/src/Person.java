
public abstract class Person {
    protected String name;
    protected Hand hand;

    public void drawCard(Deck deck) {
        hand.add(deck.removeCard());
        if (hand.busted())
            System.out.println(name + " busts with " + hand + "!");
    }

    public abstract void haveTurn(Deck deck);

    public String toString() {
        return name + " has " + hand;
    }

}