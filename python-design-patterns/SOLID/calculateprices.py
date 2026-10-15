from typing import List
from product import Product



class ShoppingCart:
    def __init__(self) -> None:
        self.products: List[Product] = []

    def add_product(self, p: Product):
        self.products.append(p)

    def get_products(self) -> List[Product]:
        return self.products

    def calculate_price(self):
        total = 0
        for i in self.products:
            total+=i.price

        return total