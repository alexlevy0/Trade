//
// Trade.cpp for Trade in /home/levy_b/rendu/trade
// 
// Made by LEVY Alexandre
// Login   <levy_b@epitech.net>
// 
// Started on  Sun Jun  7 14:16:06 2015 LEVY Alexandre
// Last update Sun Jun  7 14:16:29 2015 LEVY Alexandre
//

#include "Trade.hpp"

Trade::Trade()
{
  _duration = 0;
  _increase = 0;
  _decrease = 0;
  _nb = 0;
  this->getMoney();
  this->getDays();
}

Trade::~Trade()
{
}

void		Trade::getMoney()
{
  std::string	value;
  std::cin >> value;
  std::istringstream	iss(value);
  iss >> this->_money;
}

void		Trade::getDays()
{
  std::string	days;
  std::cin >> days;
  std::istringstream	iss(days);
  iss >> this->_duration;
}

void		Trade::nextDay()
{
  this->_duration++;
}

void		Trade::addDayValue(const std::string &value)
{
  int		val;
  std::istringstream	iss(value);
  iss >> val;
  _history.push_back(val);
}

int		Trade::getDay() const
{
  return (this->_history.back());
}

int		Trade::getPrevDay() const
{
  return (this->_history[this->_history.size() - 2]);
}

bool		Trade::isItTimeToSell()
{
  if (getPrevDay() > getDay())
    {
      _increase = 0;
      _decrease++;
    }
  if (this->_decrease >= 3 && _nb > 0)
    {
      _nb--;
      _money += getDay();
      return (true);
    }
  return (false);
}

bool		Trade::isItTimeToBuy()
{
  if (getPrevDay() < getDay())
    {
      _decrease = 0;
      _increase++;
    }
  if (this->_increase >= 5 && this->_money >= getDay())
    {
      _nb++;
      _money -= getDay();
      return (true);
    }
  return (false);
}

int		Trade::nbTransac() const
{
  return (this->_history.size());
}

int             main()
{
  std::string	value;
  Trade		b;

  std::cin >> value;
  while (value != "--end--")
  {
    b.addDayValue(value);
    if (b.nbTransac() > 1 && b.isItTimeToSell())
      std::cout << "sell " << 1 << std::endl;
    else if (b.nbTransac() > 1 && b.isItTimeToBuy())
      std::cout << "buy " << 1 << std::endl;
    else
      std::cout << "wait" << std::endl;
    b.nextDay();
    std::cin >> value;
  }
  return (0);
}
