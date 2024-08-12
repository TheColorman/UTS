class Product:
    name: str
    stock: int
    price: float

    def __init__(self, name: str, stock: int, price: float):
        self.name = name
        self.stock = stock
        self.price = price

    def getName(self):
        return self.name

    def isEmpty(self):
        return self.stock == 0

    def has(self, n: int):
        return self.stock >= n

    def sell(self, n: int):
        if not self.has(n):
            print("Not enough stock")
            return 0.0
        self.stock -= n
        return n * self.price

    def restock(self, n: int):
        self.stock += n

    def __repr__(self):
        return (
            self.name + " - " + str(self.stock) + " at $" + self.formatted(self.price)
        )

    def formatted(self, money: float) -> str:
        return f"{money:.2f}"
