#include "sales_item.h"

int main()
{
  SalesItem sale1("A", 1.1, 11), sale2("B", 2.2, 22), sale3("C", 3.3, 33);
  SalesItem sale4("D", 4.4, 44);
  std::vector<SalesItem> sales;
  sales.reserve(4);
  sales.reserve(4);
  sales.emplace_back("A", 1.1, 11);
  sales.emplace_back("B", 2.2, 22);
  sales.emplace_back("C", 3.3, 33);
  sales.emplace_back("D", 4.4, 44);

  SalesItem sale5("E", 5.5, 55);
  for(auto sale:sales)
    {
      sale = sale5;
      std::cout << sale;
    }
  std::cout << "\n";

  for(const auto& sale:sales)
    {
      std::cout << sale;
    }

}
