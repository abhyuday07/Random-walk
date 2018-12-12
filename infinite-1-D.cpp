//Abhyuday Pandey Codes September 3rd 2018 
//This code is for Random walk in infinite distance in 1-D
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//Helper function to perform experiment iters times and given threshold on steps
void call(int iters, int steps, int i){
	int sum=0;
	//This loop runs iters times
	while(iters--){
		int pos=i;
		int s=steps;
		//This loop terminates after origin is reached or threshold steps are reached
		while(s--){
			if(rand()%2) pos++;
			else pos--;
			if(pos==0){sum++; break;}
		}
	}
	//print the probability for given i, steps and iters=10,000
	printf("For %d steps P(i=%d)=%lf\n",steps,i,(double)(sum)/10000.0);
}
int main(){
	//clock will give running time
	clock_t start=clock();
	//iters is number of times experiment is run (default 10,000)
	int iters=10000;
	//Each step in {10^8,10^7,10^6,10^5...10}
	for(int steps=100000000;steps>=10;steps/=10) call(iters,steps,1);
	for(int steps=100000000;steps>=10;steps/=10) call(iters,steps,10);
	printf("---------%f--------\n",(double)(clock()-start)/CLOCKS_PER_SEC);	
	return 0;
}
