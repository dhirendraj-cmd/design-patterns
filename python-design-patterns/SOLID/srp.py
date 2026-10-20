class Product:

    def __init__(self, name: str, price: float):
        self.name = name
        self.price = price


class ShoppingCart:
    def __init__(self) -> None:
        self.products: list[Product] = []

    def add_product(self, p: Product):
        self.products.append(p)

    def get_products(self) -> list[Product]:
        return self.products

    def calculate_price(self):
        total = 0
        for i in self.products:
            total+=i.price

        return total


class ShoppingCartPrinter:
    def __init__(self, cart: ShoppingCart):
        self.cart = cart

    def print_invoice(self):
        print("Printing Invoice: ")
        for p in self.cart.get_products():
            print(f"{p.name} - Rs {p.price}")
        print(f"Total: Rs {self.cart.calculate_price()}")



cart = ShoppingCart()
cart.add_product(Product("Bag", 250))
cart.add_product(Product("mpose", 128.50))

cart.get_products()

printer = ShoppingCartPrinter(cart=cart)
printer.print_invoice()