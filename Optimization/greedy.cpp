//Rushdi AL-Hasan
//CSCI 4350/5350
//OLA2
//10/25/2018
//Description: Develop a software agent in C++ to find the maximum value of the Sum of Gaussians (SoG) function
//greedy.cpp
#include <iostream>
#include <cstdlib>
#include<iomanip>
#include "SumofGaussians.h"

using namespace std;

int getRandomNum();

int main(int argc, char *argv []){
	
	int seed = atoi(argv[1]);
	int D = atoi(argv[2]);
	int N = atoi(argv[3]);
	
	int size = 100;
	double Dcube[size];
	
	srand(seed);
	
	SumofGaussians sog(D,N);
	
	//hardcode Dcube 
	double j = 0;
	for(int i = 0; i <= size; i ++){
		Dcube[i] = j;
		j+=.1;
				
	}
	
	
	//obtain random starting position based on dimensions given	
	if(D == 1){
		int startPos = getRandomNum();
		double x [1];
		x[0] = Dcube[startPos];
		
		//obtain G value 
		double gVal= sog.eval(x);		
		cout << x[0] <<" " << gVal << endl;
		
		
		double step[D];
		
		double curr = gVal; //store curr g val
		sog.deriv(x,step) ;	
		x[0] += 0.01 * step[0];//determine step size
		gVal= sog.eval(x);	
		
		while( gVal- curr > 0.00000001){//while tolerance not reached
		
		cout << x[0] << " " << gVal << endl;
		
		curr = gVal;
		sog.deriv(x,step) ;	
		x[0] += 0.01 * step[0];
		gVal= sog.eval(x);
		}
	}
	 
	else if (D == 2){
		int startPos= getRandomNum();
		int startPos2 = getRandomNum();
		
		double x2[D];
		
		x2[0] = Dcube[startPos];		
		x2[1] = Dcube[startPos2];		
		//obtain G value 
		double gVal= sog.eval(x2);		
		cout << x2[0] <<" " << x2[1] << " " << gVal << endl;
		
		
		double step[1];
		double curr = gVal;
		sog.deriv(x2,step);
		
		x2[0] += 0.01 * step[0];
		x2[1] += 0.01 * step[0];
		gVal = sog.eval(x2);
		
		while(gVal - curr > 0.00000001){
			
			cout<<x2[0] << " " << x2[1] << " " << gVal << endl;
			curr = gVal;
			sog.deriv(x2,step);			
			x2[0] += 0.01 * step[0];
			x2[1] += 0.01 * step[0];
			gVal = sog.eval(x2);
		}
		
					
	}
	else if(D == 3 ){
		
		int startPos= getRandomNum();
		int startPos2 = getRandomNum();
		int startPos3 = getRandomNum();
		
		double x3[D];
		
		x3[0] = Dcube[startPos];		
		x3[1] = Dcube[startPos2];		
		x3[2] = Dcube[startPos3];
		//obtain G value 
		double gVal= sog.eval(x3);		
		cout << x3[0] <<" " << x3[1] << " " <<x3[2] <<" "<< gVal << endl;
		
		
		double step[1];
		double curr = gVal;
		sog.deriv(x3,step);
		
		x3[0] += 0.01 * step[0];
		x3[1] += 0.01 * step[0];
		x3[2] += 0.01 * step[0];
		gVal = sog.eval(x3);
		
		while(gVal - curr > 0.00000001){
			
			cout<<x3[0] << " " << x3[1] <<" " <<x3[2] << " " << gVal << endl;
			curr = gVal;
			sog.deriv(x3,step);			
			x3[0] += 0.01 * step[0];
			x3[1] += 0.01 * step[0];
			x3[2] += 0.01 * step[0];
			gVal = sog.eval(x3);
			
		}	
		
	}
	else if(D == 4){
		
		int startPos= getRandomNum();
		int startPos2 = getRandomNum();
		int startPos3 = getRandomNum();
		int startPos4 = getRandomNum();
		double x4[D];
		
		x4[0] = Dcube[startPos];		
		x4[1] = Dcube[startPos2];		
		x4[2] = Dcube[startPos3];
		x4[3] = Dcube[startPos4];
		//obtain G value 
		double gVal= sog.eval(x4);		
		cout << x4[0] <<" " << x4[1] << " " <<x4[2] <<" "<<x4[3]<<" "<< gVal << endl;
		
		
		double step[1];
		double curr = gVal;
		sog.deriv(x4,step);
		
		x4[0] += 0.01 * step[0];
		x4[1] += 0.01 * step[0];
		x4[2] += 0.01 * step[0];
		x4[3] += 0.01 * step[0];
		gVal = sog.eval(x4);
		
		while(gVal - curr > 0.00000001){
			
			cout<<x4[0] << " " << x4[1] <<" " <<x4[2] << " "<<x4[3]<<" " << gVal << endl;
			curr = gVal;
			sog.deriv(x4,step);			
			x4[0] += 0.01 * step[0];
			x4[1] += 0.01 * step[0];
			x4[2] += 0.01 * step[0];
			x4[3] += 0.01 * step[0];
			gVal = sog.eval(x4);
			
		}
	}
	
	else if(D == 5){
		
		int startPos= getRandomNum();
		int startPos2 = getRandomNum();
		int startPos3 = getRandomNum();
		int startPos4 = getRandomNum();
		int startPos5 = getRandomNum();
		double x5[D];
		
		x5[0] = Dcube[startPos];		
		x5[1] = Dcube[startPos2];		
		x5[2] = Dcube[startPos3];
		x5[3] = Dcube[startPos4];
		x5[4] = Dcube[startPos5];
		//obtain G value 
		double gVal= sog.eval(x5);		
		cout << x5[0] <<" " << x5[1] << " " <<x5[2] <<" "<<x5[3]<<" "<<x5[4]<<" "<< gVal << endl;
		
		
		double step[1];
		double curr = gVal;
		sog.deriv(x5,step);
		
		x5[0] += 0.01 * step[0];
		x5[1] += 0.01 * step[0];
		x5[2] += 0.01 * step[0];
		x5[3] += 0.01 * step[0];
		x5[4] += 0.01 * step[0];
		gVal = sog.eval(x5);
		
		while(gVal - curr > 0.00000001){
			
			cout<<x5[0] << " " << x5[1] <<" " <<x5[2] << " "<<x5[3]<<" "<<x5[4]<<" " << gVal << endl;
			curr = gVal;
			sog.deriv(x5,step);			
			x5[0] += 0.01 * step[0];
			x5[1] += 0.01 * step[0];
			x5[2] += 0.01 * step[0];
			x5[3] += 0.01 * step[0];
			x5[4] += 0.01 * step[0];
			
			gVal = sog.eval(x5);
			
		}
	}

	
	return 0;
	
}

int getRandomNum(){
	return ( rand() % 101+ 1);
}