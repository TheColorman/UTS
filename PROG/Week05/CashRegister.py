class CashRegister:
    cash: float

    def __init__(self, cash: float = 0) -> None:
        self.cash = cash

    def add(self, n: float):
        self.cash += n

    def subtract(self, n: float):
        self.cash -= n

    def __repr__(self) -> str:
        return f"Cash register: ${self.cash:.2f}"
