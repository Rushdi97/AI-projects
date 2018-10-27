//Rushdi AL-Hasan
//CSCI 4350/5350
//OLA2
//10/25/2018
//Description: Develop a software agent in C++ to find the maximum value of the Sum of Gaussians (SoG) function
//sa.cpp

#include <iostream>
#include <cstdlib>
#include <random>
#include "SumofGaussians.h"

using namespace std;

std::random_device                  rand_dev;
std::mt19937                        generator(rand_dev());

std::uniform_real_distribution<>  runif(-0.01, 0.01);

double T = 1;//temp initial value
double const e = 2.71828182845904523536; 

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
	
	if(D==1){
		
		double prev;
		double curr;
	
		double x[1];
	
		int startPos = getRandomNum();
		x[0] = Dcube[startPos];
		
		cout << x[0] << " " << sog.eval(x) << endl;
	
		double y[1];
		
		int count=0;
		for(int i= 0; i < 100000;i++){
			prev = sog.eval(x);
			
			if(count == 100){
				T -= 0.0001;
				count = 0;
			}
		
			y[0] = x[0] + runif(generator);
			
			//if G(Y) > G(X) then accept
			if(sog.eval(y) > sog.eval(x)){
				x[0] = y[0];
			
			}
			//else accept y
			else{
				x[0] += pow(e,sog.eval(y)-sog.eval(x)/T);
			}
	
				curr =sog.eval(x);
			
			if(curr - prev< 0.00000001){
				
				return 0;				
			}
			
			cout <<x[0] << " " << sog.eval(x) <<endl;
			count++;		
	
	}
}

	if(D==2){
		
		double prev;
		double curr;
	
		double x[D];
	
		int startPos = getRandomNum();
		x[0] = Dcube[startPos];
		x[1] = Dcube[startPos];
		
		cout << x[0] <<" " <<x[1] <<" " << sog.eval(x) << endl;
	
		double y[D];
	
		int count=0;
		for(int i= 0; i < 100000;i++){
			prev = sog.eval(x);
			
			if(count == 100){
				T -= 0.0001;
				count = 0;
			}
		
			y[0] = x[0] + runif(generator);
			y[1] = x[1] + runif(generator);
			
			//if G(Y) > G(X) then accept
			if(sog.eval(y) > sog.eval(x)){
				x[0] = y[0];
				x[1] = y[1];
				
			
			}
			//else accept y
			else{
				x[0] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[1] += pow(e,sog.eval(y)-sog.eval(x)/T);
			}
	
				curr =sog.eval(x);
			
			if(curr - prev< 0.00000001){
				
				return 0;				
			}
			
			cout <<x[0] <<" " <<x[1]<< " " << sog.eval(x) <<endl;
			count++;		
	
	}
}

	if(D==3){
		
		double prev;
		double curr;
	
		double x[D];
	
		int startPos = getRandomNum();
		x[0] = Dcube[startPos];
		x[1] = Dcube[startPos];
		x[2] = Dcube[startPos];
		
		cout << x[0] <<" " <<x[1] <<" "<<x[2]<<" " << sog.eval(x) << endl;
	
		double y[D];
	
		int count=0;
		for(int i= 0; i < 100000;i++){
			prev = sog.eval(x);
			
			if(count == 100){
				T -= 0.0001;
				count = 0;
			}
		
			y[0] = x[0] + runif(generator);
			y[1] = x[1] + runif(generator);
			y[2] = x[2] + runif(generator);
			
			//if G(Y) > G(X) then accept
			if(sog.eval(y) > sog.eval(x)){
				x[0] = y[0];
				x[1] = y[1];
				x[2] = y[2];
				
			
			}
			//else accept y
			else{
				x[0] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[1] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[2] += pow(e,sog.eval(y)-sog.eval(x)/T);
			}
	
				curr =sog.eval(x);
			
			if(curr - prev< 0.00000001){
				
				return 0;				
			}
			
			cout <<x[0] <<" " <<x[1]<< " " <<x[2] <<" "<< sog.eval(x) <<endl;
			count++;		
	
	}
}

		if(D==4){
		
		double prev;
		double curr;
	
		double x[D];
	
		int startPos = getRandomNum();
		x[0] = Dcube[startPos];
		x[1] = Dcube[startPos];
		x[2] = Dcube[startPos];
		x[3] = Dcube[startPos];
		
		cout << x[0] <<" " <<x[1] <<" "<<x[2]<<" " <<x[3]<<" "<< sog.eval(x) << endl;
	
		double y[D];
	
		int count=0;
		for(int i= 0; i < 100000;i++){
			prev = sog.eval(x);
			
			if(count == 100){
				T -= 0.0001;
				count = 0;
			}
		
			y[0] = x[0] + runif(generator);
			y[1] = x[1] + runif(generator);
			y[2] = x[2] + runif(generator);
			y[3] = x[3] + runif(generator);
			
			//if G(Y) > G(X) then accept
			if(sog.eval(y) > sog.eval(x)){
				x[0] = y[0];
				x[1] = y[1];
				x[2] = y[2];
				x[3] = y[3];
				
			
			}
			//else accept y
			else{
				x[0] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[1] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[2] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[3] += pow(e,sog.eval(y)-sog.eval(x)/T);
			}
	
				curr =sog.eval(x);
			
			if(curr - prev< 0.00000001){
				
				return 0;				
			}
			
			cout <<x[0] <<" " <<x[1]<< " " <<x[2] <<" "<< x[3]<<" "<< sog.eval(x) <<endl;
			count++;		
	
	}
}

	if(D==5){
		
		double prev;
		double curr;
	
		double x[D];
	
		int startPos = getRandomNum();
		x[0] = Dcube[startPos];
		x[1] = Dcube[startPos];
		x[2] = Dcube[startPos];
		x[3] = Dcube[startPos];
		x[4] = Dcube[startPos];
		
		cout << x[0] <<" " <<x[1] <<" "<<x[2]<<" " <<x[3]<<" "<<x[4]<<" "<< sog.eval(x) << endl;
	
		double y[D];
	
		int count=0;
		for(int i= 0; i < 100000;i++){
			prev = sog.eval(x);
			
			if(count == 100){
				T -= 0.0001;
				count = 0;
			}
		
			y[0] = x[0] + runif(generator);
			y[1] = x[1] + runif(generator);
			y[2] = x[2] + runif(generator);
			y[3] = x[3] + runif(generator);
			y[4] = x[4] + runif(generator);
			
			//if G(Y) > G(X) then accept
			if(sog.eval(y) > sog.eval(x)){
				x[0] = y[0];
				x[1] = y[1];
				x[2] = y[2];
				x[3] = y[3];
				x[4] = y[4];
				
			
			}
			//else accept y
			else{
				x[0] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[1] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[2] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[3] += pow(e,sog.eval(y)-sog.eval(x)/T);
				x[4] += pow(e,sog.eval(y)-sog.eval(x)/T);
			}
	
				curr =sog.eval(x);
			
			if(curr - prev< 0.00000001){
				
				return 0;				
			}
			
			cout <<x[0] <<" " <<x[1]<< " " <<x[2] <<" "<< x[3]<<" "<<x[4]<<" "<< sog.eval(x) <<endl;
			count++;		
	
	}
}
	
	return 0;
	
} 

int getRandomNum(){
	return ( rand() % 101+ 1);
}