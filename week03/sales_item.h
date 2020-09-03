#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include <iostream>
#include <vector>
#include <string>

struct SalesItem
{
  std::string m_isbn;
  double m_revenue = 0;
  int m_units_sold = 0;

  SalesItem()
  {
  }

SalesItem(std::string isbn, double revenue, int units_sold)
  : m_isbn(isbn), m_revenue(revenue), m_units_sold(units_sold)
  {
  }

  SalesItem(const SalesItem& sale)
  {
    std::cout << "Copied.\n";
  }
  friend std::ostream& operator<<(std::ostream& stream, const SalesItem& others);
};

std::ostream& operator<<(std::ostream& stream, const SalesItem& others)
{
  stream << "ISBN: " << others.m_isbn << " Revenue: " << others.m_revenue << " Units Sold: " << others.m_units_sold << "\n";
  return stream;
}


#endif /* SALES_ITEM_H */
