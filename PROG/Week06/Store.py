from CashRegister import CashRegister
from Product import Product


class Store:
    cashRegister: CashRegister
    products: list[Product] = []

    def __init__(self):
        self.products.append(Product("Whiteboard Marker", 85, 1.5))
        self.products.append(Product("Whiteboard Eraser", 45, 5))
        self.products.append(Product("Black Pen", 100, 1.5))
        self.products.append(Product("Red Pen", 100, 1.5))
        self.products.append(Product("Blue Pen", 100, 1.5))
        self.cashRegister = CashRegister()

    def readChoice(self) -> str:
        return input("Choice (s/r/v/c/p/x): ")[0]

    def use(self):
        while True:
            match self.readChoice():
                case "s":
                    self.sell()
                case "r":
                    self.restock()
                case "v":
                    self.viewStock()
                case "c":
                    self.viewCash()
                case "p":
                    self.pruneProducts()
                case "x":
                    print("Done")
                    exit(0)
                case _:
                    self.help()

    def findProducts(self, name: str) -> list[Product]:
        name = name.lower()
        matches = []
        for product in self.products:
            if name in product.getName().lower():
                matches.append(product)

        if len(matches) == 0:
            return None
        return matches

    def sell(self):
        name = self.readName()
        ps = self.findProducts(name)
        if ps is None:
            print("No such product")
            return

        if len(ps) > 1:
            print("Multiple products match:")
            for product in ps:
                print(product)
            return

        print("Selling " + ps[0].getName())
        n = self.readNumber()
        self.cashRegister.add(ps[0].sell(n))

    def restock(self):
        name = self.readName()
        ps = self.findProducts(name)
        if ps is None:
            print("Adding new product")
            n = self.readNumber()
            price = self.readPrice()
            self.products.append(Product(name, n, price))
            return

        for p in ps:
            print("Restocking " + p.getName())
            n = self.readNumber()
            p.restock(n)

    def viewStock(self):
        for product in self.products:
            print(product)

    def viewCash(self):
        print(self.cashRegister)

    def pruneProducts(self):
        toDelete = []
        for product in self.products:
            if product.isEmpty():
                toDelete.append(product)
        for product in toDelete:
            self.products.remove(product)

    def readName(self) -> str:
        return input("Name: ")

    def readPrice(self) -> float:
        return float(input("Price: $"))

    def readNumber(self) -> int:
        return int(input("Number: "))

    def help(self):
        print("Menu options")
        print("s = sell")
        print("r = restock")
        print("v = view stock")
        print("c = view cash")
        print("p = prune products")
        print("x = exit")


if __name__ == "__main__":
    Store().use()
