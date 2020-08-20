#ifndef MYCELL
#define MYCELL


class Cell{
public:
Cell();
bool life = false;
int neighbor=2;
//int neighborhood(std::vector<std::vector<Cell>>,int, int);
bool lifeState();
void isAlive();
void makeDead();
};
#endif
