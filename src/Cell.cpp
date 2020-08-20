#include <Cell.h>
Cell::Cell(){
    life=false;
    neighbor=0;
}
/*int Cell::neighborhood(std::vector<std::vector<Cell>> Boardt, int i, int j){
    neighbor=0;
    if(i-1>0&&j-1>0){
for(int k=i-1; k<i+1;k++){
    for(int l=j-1;j<j+1;l++)
    if(Boardt[k][l].lifeState()==true&&(l!=j&&k!=i)){
        neighbor++;
    }
}
}
    return neighbor;
};*/
bool Cell::lifeState(){
    return life;
    //std::cout<<life;
};
void Cell::isAlive(){
    life=true;
};
void Cell::makeDead(){
    life=false;
};


