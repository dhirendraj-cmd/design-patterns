SOLID Prinicples
=============================================================

S: Single Responsisbility Principle (SRP)
SRP says that A class should have only one reason to change or its main functionality is to do only one thing. 

Example:
Suppose we create a class for shopping cart. 
This class is having below functions:
    - CalculatePrice()
    - PrintInvoice()
    - sendMail()

Then this class is violating the SRP because it instead of one functionality its doing 3 i.e. it is calculating price but at the same time also printing invoice and also sending mail, which is beyond the scope of this class. So it should perform only one functionality.  The main aim of shopping cart is to calculate the prices of added items. so it should focus on that, not on sending mail and printing invoice.

Note: Doing just one functionality doesn't mean that there will be only one fucntion in class, there can be many function but all should together dedicated towards performing one task.


=============================================================
O: Open Closed Principle (OCP)
- OCP says A class should be open for extensions but not for modifications, extension simply means adding new features but for adding features, older code should not be changed/modified.
- To achieve OCP we normally use inheritance, abstraction and polymorphism combination.
- Main thing is in OCP we create abstract/interface class and then achieve the OCP.

Example:
Suppose you already have a SaveToDB class and currently this class is saving in sql db, now the requirement comes to save in nosql db like dynamodb in that case we have to create another function in the class, so now the main class has been modified which viotlates OCP. so to achieve ocp we can create an Abstract DBPersistance class and that class is extended by sql and nosql classes to save in db.


==============================================================
L: Liskov Substituion Principle(LSP):
- LSP says a subclass i.e a child class should be substitutable for their parent class.
- Suppose A is base class and B is child class and there is a client class which is expecting reference of parents i.e A class but instead we pass B class reference than also it should be able to accept it without causing any issue.
- for eg: if Client is expecting A* a = new A() and B is child class the if we pass A* a = new B() then also the prongram should work without error.
- To achieve LSP also we need to take help of abstract or interface concepts. 
- For achieving LSP client should always interact with abstract/interface class and should never directly interact with child classes.
- Best way to follow LSP is to use the abstraction wisely, so that you don't need to use any id-else conditions on client side.

Note: To achieve LSP "A child class should respond and behave like parent class, not just inherit function".

LSP has certain Rules.
1. Signature Rule: 
    - Signature Rule has 3 sub rules:
        - Argument rule: A child should have same argument as parent with same datatypes.
        - Return Type Rule: A child either should have same return type as parent or a narrower reutrn type. for eg if parents return type is Animal then child either return Animal or any specific Animal like Dog or cat etc. 
            Parent - Animal m1(); Child - Dog m1();
        - Exception Rule: Child should throw the same or narrower exception as parent class.
            Parent - Runtime error then child should also throu Runtime error only

2. Property Rule:
    - Property rule has 2 sub rules
        - class invariant: It is a kind of rule which will always hold true and followed.In this we set a rule and implement class in such way that the rule should be followed. eg:  if we set balance >= 0 then we have to implement the class in such a way that the balance should stay positive and minimum balance should be 0 not in negative.
        - History constraint: If parent class says that a particular state should not be changed than the child class should obey it.

3. Method Rule:
    - Method has 2 sub rules:
        - precondition: A condition which should be executed before a method gets called and a child class should also follow the same
        - postcondition: A condition which will be executed after a method is called and a child class should also follow the same


==============================================================
I: Interface Segregation Principle(ISP):
ISP says instead of having one general purpose interface better to have multiple interfaces and a child should not be forced to implement method they don't need.


==============================================================
D: Dependency Inverson Principle(DIP):
High Level module should not depend on low level module instead both should depend on abstraction.
If OCP is the target than DIP is the solution.



Note: when we pass an object as a variable in a class that is called Dependency Injection.
class A{
    private:
        DB* db; -----> Dependency Injection
}


