from calculateprices import ShoppingCart


class ShoppingCartPrinter:
    def __init__(self, cart: ShoppingCart):
        self.cart = cart

    def print_invoice(self):
        print("Printing Invoice: ")
        for p in self.cart.get_products():
            print(f"{p.name} - Rs {p.price}")
        print(f"Total: Rs {self.cart.calculate_price()}")




