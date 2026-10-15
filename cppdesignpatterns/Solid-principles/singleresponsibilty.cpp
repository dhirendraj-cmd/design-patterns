#include <iostream>
#include <vector>

using namespace std;


class Product{
    public:
        string name;
        double price;

        Product(string name, double price){
            this->name=name;
            this->price=price;
        }

};


class ShoppingCart{
    public:
        // store products
        vector<Product*> products;

        void addProduct(Product* p) { 
            products.push_back(p);
        }

        const vector<Product*>& getProducts(){
            return products;
        }


        // calculate price
        double calculatePrice(){
            double total = 0;
            for(auto x: products){
                total+=x->price;
            }

            return total;
        }

};


class ShoppingCartPrinter{
    private:
        ShoppingCart* cart;

    public:
        ShoppingCartPrinter(ShoppingCart* cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout<<"Printing Invoice: \n";
            for(auto x: cart->getProducts()){
                cout << x->name << " - Rs " << x->price << endl;
            }
            cout << "Total: Rs " << cart->calculatePrice() << endl;
        }
};


int main(){
    ShoppingCart *cart = new ShoppingCart();

    cart->addProduct(new Product("Bottle", 231));
    cart->addProduct(new Product("Keyboard", 3400));

    ShoppingCartPrinter* scp = new ShoppingCartPrinter(cart);
    scp->printInvoice();

    return 0;

}