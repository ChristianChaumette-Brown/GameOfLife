	#include <GameOfLife.h>
	#include <iostream>
	#include <Cell.h>

	GameOfLife::GameOfLife(){
	row=5;
	col=5;

	std::vector<Cell> temp;

	for(int i=0; i<row;i++){
		
		for(int j=0; j<col; j++){
			temp.push_back(Cell());

		}
		Board.push_back(temp);
	}
	Board[2][1].isAlive();
	Board[2][2].isAlive();
	Board[2][3].isAlive();
	//Board[4][0].isAlive();
	//Board[4][1].isAlive();
	//Board[4][2].isAlive();
	}


	void GameOfLife::start(){

	}

	void GameOfLife::stop(){
		
	}

	void GameOfLife::advance(){
		/*Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	Any live cell with two or three live neighbours lives on to the next generation.
	Any live cell with more than three live neighbours dies, as if by overpopulation.
	Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
	*/
	neighborhood();
	for(int i=0; i< row; i++){
		for(int j=0; j<col; j++){
			//neighborhood(i, j);
			if(Board[i][j].lifeState()==true&&(Board[i][j].neighbor==2||Board[i][j].neighbor==3)){
				Board[i][j].isAlive();
			}
			else if(Board[i][j].lifeState()==true&&Board[i][j].neighbor<2){//underpop
				Board[i][j].makeDead();
			}
			else if(Board[i][j].lifeState()==true&&Board[i][j].neighbor>3){//overpop
				Board[i][j].makeDead();
			}
			else if(Board[i][j].lifeState()==false&&Board[i][j].neighbor==3){//zombie
				Board[i][j].isAlive();
			}
		}
	}
	}
	/*void GameOfLife::neighborhood(int i, int j){


		int newneighbor=0;
		if((i-1>=0&&j-1>=0)&&(i+1<row&&j+1<col)){
	for(int k=i-1; k<i+1;k++){
		for(int l=j-1;j<j+1;l++)
		if(Board[k][l].lifeState()==true&&(l!=j&&k!=i)){
			newneighbor++;
		}
	}
	}
	Board[i][j].neighbor=newneighbor;
	

	}*/
	void GameOfLife::neighborhood(){
		for(int i=0; i<row;i++){
			for(int j=0;j<col;j++){
				Board[i][j].neighbor=0;
			}
		}
	for(int i=0; i<row;i++){
		for(int j=0;j<col;j++){
			if(i+1<row){
				if(Board[i+1][j].lifeState()==true){//down of check
					Board[i][j].neighbor++;
				}
			}
			if(j+1<col){
				if(Board[i][j+1].lifeState()==true){//right of check
					Board[i][j].neighbor++;
				}
			}
			if(j>0){
				if(Board[i][j-1].lifeState()==true){//left check
					Board[i][j].neighbor++;
				}
			}
			if(i>0){
				if(Board[i-1][j].lifeState()==true){//upcheck
					Board[i][j].neighbor++;
				}
			}
			if(i>0 && j>0){
				if(Board[i-1][j-1].lifeState()==true){//up left check
				Board[i][j].neighbor++;
				}
			}
			if(i>0&&j+1<col){
				if(Board[i-1][j+1].lifeState()==true){//up right check
				Board[i][j].neighbor++;
				}
			}
			if(i+1<row&&j>0){
				if(Board[i+1][j-1].lifeState()==true){//down left check
				Board[i][j].neighbor++;
				}
			}
			if(i+1<row&&j+1<col){
				if(Board[i+1][j+1].lifeState()==true){//up left check
				Board[i][j].neighbor++;
				}
			}
			//beginning of borderless code i.e. will allow for cells wrapping around the edge of the board
			//need multiple cases for all the wrap types
			if(i==0){//wrap up
			if(Board[row-1][j].lifeState()==true){
				Board[i][j].neighbor++;
			}
			}
			if(j==0){//wrap left
			if(Board[i][col-1].lifeState()==true){
				Board[i][j].neighbor++;
			}
			}
			if(j+1==col){//wrap right
			if(Board[i][0].lifeState()==true){
				Board[i][j].neighbor++;
			}
			}
			if(i+1==row){//wrap down
			if(Board[0][j].lifeState()==true){
				Board[i][j].neighbor++;
			}
			}
			if(i+1==row&&j==0){//edge wrap down left
			if(Board[0][col-1].lifeState()==true){
				Board[i][j].neighbor++;
			}
			if(i+1==row&&j+1==col){//edge wrap down right
			if(Board[0][0].lifeState()==true){
				Board[i][j].neighbor++;
			}
			}
			if(i==0&&j+1==col){//edge wrap up right
			if(Board[row-1][0].lifeState()==true){
				Board[i][j].neighbor++;
			}
			}
			if(i==0&&j==0){//edge wrap up left
			if(Board[row-1][col-1].lifeState()==true){
				Board[i][j].neighbor++;
			}
			}

			}

		}
	}

	}

	ucm::json GameOfLife::getBoard(){
		ucm::json result;
		//ucm::json temps;
	//result.push_back({Board[0][0].lifeState()});
		/*
				result.push_back({Board[0][0].lifeState(),Board[0][1].lifeState(),Board[0][2].lifeState(),Board[0][3].lifeState(),Board[0][4].lifeState()});
				result.push_back({Board[1][0].lifeState(),Board[1][1].lifeState(),Board[1][2].lifeState(),Board[1][3].lifeState(),Board[1][4].lifeState()});
				result.push_back({Board[2][0].lifeState(),Board[2][1].lifeState(),Board[2][2].lifeState(),Board[2][3].lifeState(),Board[2][4].lifeState()});
				result.push_back({Board[3][0].lifeState(),Board[3][1].lifeState(),Board[3][2].lifeState(),Board[3][3].lifeState(),Board[3][4].lifeState()});
				result.push_back({Board[4][0].lifeState(),Board[4][1].lifeState(),Board[4][2].lifeState(),Board[4][3].lifeState(),Board[4][4].lifeState()});
		
	*/
		for(int i=0; i<row;i++){
		ucm::json temps;
		for(int j=0; j<col; j++){
			temps.push_back(Board[i][j].lifeState());

		}
		result.push_back(temps);
		//temps.delete();
		//delete(temps);
	}
		
		return result;
	}

