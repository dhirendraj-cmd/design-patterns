from SOLID.ocp.product import Product


class ShoopingCart:
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