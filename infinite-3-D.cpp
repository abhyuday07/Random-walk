//Abhyuday Pandey Codes September 3rd 2018 
//This code is for Random walk in infinite distance in 3-D
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//Helper function to perform experiment iters times and given threshold on steps
void call(int iters, int steps,int x,int y,int z){
	int sum=0;
	//This loop runs iters times
	while(iters--){
		int pos1=x,pos2=y,pos3=z;
		int s=steps;
		//This loop terminates after origin is reached or threshold steps are reached
		while(s--){
			int randint=rand()%6;
			if(randint==5) pos3++;
			else if(randint==4) pos3--;
			else if(randint==3) pos1++;
			else if(randint==2) pos1--;
			else if(randint==1) pos2++;
			else pos2--;
			if(pos1==0&&pos2==0&&pos3==0){sum++; break;}
		}
	}
	//print the probability for given (x,y,z), steps and iters=10000
	printf("Given %d steps,P(i)=%lf\n",steps,(double)(sum)/10000.0);
}
int main(){
	//clock will give running time
	clock_t start=clock();
	//iters is number of times experiment is run (default 10,000)
	int iters=10000;
	//Each step in {10^7,10^6,10^5...10}
	for(int steps=10000000;steps>=10;steps/=10)  call(iters,steps,1,0,0);
	printf("---------%f--------\n",(double)(clock()-start)/CLOCKS_PER_SEC);	
	return 0;
}
