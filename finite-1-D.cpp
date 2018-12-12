//Abhyuday Pandey Codes September 3rd 2018 
//This code is for Random walk for finite distance in 1-D
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	//clock will give running time
	clock_t start=clock();
	//Set N=20 and iters=10^6, p[N] will store p(i)*iters for each i
	int N=20,iters=1000000;
	int p[N];
	//Initialize all p[i]'s to zero
	for(int i=0;i<N;i++) p[i]=0;
	//This loop will run exactly iters times
	while(iters--){
		//For each 'i' we compute probability
		for(int i=1;i<N;i++){
			int steps=i;
			//This loop will terminate when house/bar is reached
			while(1){
			    int random=rand()%2;
			    if(random) steps++;
			    else steps--;
			    if(steps==0){p[i]++; break;}
			    if(steps==N){break;} 
	    	}
		}
	}
	printf("---------%f--------\n",(double)(clock()-start)/CLOCKS_PER_SEC);	
	//--------------------PLOTTING PART--------------------------------
	//Graph plotting
	long long int sum=0;
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set terminal postscript eps enhanced color font 'Helvetica,10'\n");
    fprintf(gnuplotPipe, "set output 'graph31.eps'\n");
    fprintf(gnuplotPipe, "set xlabel 'i'\nset ylabel 'P(i)\nset title 'P(i)'\n");
	fprintf(gnuplotPipe, "plot '-' pointtype 7\n");
    for( int idx = 1 ; idx < N ; idx++ ){
    		fprintf(gnuplotPipe,"%lf %lf\n", (double)(idx), (double)(p[idx])/1000000.0);
    		printf("For i=%d, p(i)=%lf\n",idx, (double)(p[idx])/1000000.0);
    }
    fprintf(gnuplotPipe, "e\n");
	//Graph end
	return 0;
}