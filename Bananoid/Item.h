#pragma once

#include <vector>

class CItem
{
public:
  CItem(void);
  virtual ~CItem(void);
  void Run(unsigned int step);
  void Collide(std::vector<CItem *> items);
  void Draw(void);
private:
  CPoint m_position;
};
