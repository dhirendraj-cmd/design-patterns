from product import Product
from calculateprices import ShoppingCart
from printinvoice import ShoppingCartPrinter


cart = ShoppingCart()
cart.add_product(Product("Bag", 250))
cart.add_product(Product("mpose", 128.50))

cart.get_products()

printer = ShoppingCartPrinter(cart=cart)
printer.print_invoice()