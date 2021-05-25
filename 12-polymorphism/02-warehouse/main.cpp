#include "warehouse.h"
#include "pen.h"

int main()
{
    // ItemWithQuantity* p1 = new Pen("Schneider", 0.30, 100, 6);
    // ItemWithQuantity* p2 = new Pen("Nataraj", 0.60, 55, 4);
    // ItemWithQuantity* p3 = new Pen("ErichKrause", 0.50, 80, 5);

    // Warehouse warehouse;
    // warehouse.add_product(p1);
    // warehouse.add_product(p2);
    // warehouse.add_product(p3);

    // std::cout << "Inventory: \n";
    // warehouse.print_statistics();
    // std::cout << '\n';

    // std::cout << "Total: " << warehouse.get_total_price_of_items() << '\n';

    char* ch = new char[10];
    std::cin >> ch;
    for (int i = 0; i < 10; i++)
    {
        std::cout << ch[i] << ' ';
    }
    

}