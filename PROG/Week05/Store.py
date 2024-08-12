from CashRegister import CashRegister
from Product import Product


class Store:
    _sticky_tape: Product
    _cash_register: CashRegister

    def __init__(self) -> None:
        self._sticky_tape = Product("Sticky tape", 2.99, 200)
        self._cash_register = CashRegister()

    def sell(self):
        n = int(input("Number: "))
        try:
            earned = self._sticky_tape.sell(n)
            self._cash_register.add(earned)
        except ValueError as e:
            print(e)

    def restock(self):
        n = int(input("Number: "))
        self._sticky_tape.add(n)

    def view_stock(self):
        print(self._sticky_tape)

    def view_cash(self):
        print(self._cash_register)

    def use(self):
        while True:
            c = input("Choice (s/r/v/c/x): ").lower()

            match c:
                case "?":
                    self.print_help()
                case "s":
                    self.sell()
                case "r":
                    self.restock()
                case "v":
                    self.view_stock()
                case "c":
                    self.view_cash()
                case "x":
                    exit(0)

    @staticmethod
    def print_help(_self=None):  # can use both self.print_help() and Store.print_help()
        print("Menu options")
        print("s = sell")
        print("r = restock")
        print("v = view stock")
        print("c = view cash")
        print("x = exit")


if __name__ == "__main__":
    Store().use()
