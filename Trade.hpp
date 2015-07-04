//
// Trade.hpp for Trade in /home/levy_b/rendu/trade
// 
// Made by LEVY Alexandre
// Login   <levy_b@epitech.net>
// 
// Started on  Sun Jun  7 14:16:18 2015 LEVY Alexandre
// Last update Sun Jun  7 14:16:21 2015 LEVY Alexandre
//


#ifndef BOT_H_
# define BOT_H_

# include <vector>
# include <string>
# include <sstream>
# include <iostream>

class	Trade
{
public:
  Trade();
  ~Trade();
  void			getMoney();
  void			getDays();
  void			nextDay();
  void			addDayValue(const std::string&);
  int			  getPrevDay() const;
  int			  getDay() const;
  bool			isItTimeToSell();
  bool			isItTimeToBuy();
  int			  nbTransac() const;

protected:
  int			          _money;
  int			          _duration;
  std::vector<int>	      _history;
  int			          _increase;
  int			          _decrease;
  int			          _nb;
};

#endif /* !BOT_H_ */
