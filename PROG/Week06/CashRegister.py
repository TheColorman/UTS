class CashRegister:
    cash: float

    def __init__(self):
        self.cash = 0.0

    def add(self, money: float):
        self.cash += money

    def __repr__(self) -> str:
        return "Cash: $" + self.formatted(self.cash)

    def formatted(self, amount: float) -> str:
        return f"{amount:.2f}"
