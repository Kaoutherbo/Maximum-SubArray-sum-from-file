#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//To find the maximum
int maximum(int a,int b){
	return (a>b)?a:b;
}
//To check whether the array contains only the positives numbers or not
bool is_positive(int a[],int n){
	int i=0;bool positive=true;
	while(i<n&&positive){
		if(a[i]<0){
			positive=false;break;
		}
	}
	return positive;
}
//Find the maximum Sum of Sub array from a file 
int FindMaxSubArrayFromFile(const char*Arrayfile){
	FILE *f=fopen(Arrayfile,"r");
    //Check whether the file is existing or not
	if(f==NULL){
		printf("This file dose not exist ");
	}else{
		printf("The file exist \n");
	}
	int t[100];
	int n=0;
	while(fgetc(f)!=EOF){
		if(fgetc(f)!='\n'){
			t[n]=(int)fgetc(f);
			n++;
		}
	}
	t[n];

	if(is_positive(t,n)){
		int s=0;
		for(size_t i=0;i<n;i++){
			s+=t[i];
		}
		return s;
	}

	else{
		int sum=0,max_sum=t[0];
	for(size_t i=0;i<n;i++){
		for(size_t j=i;j<=n;j++){
			for(size_t k=i;k<=j;k++){
			sum+=t[k];
			max_sum= maximum(max_sum,sum);
		}
	}
}
		return max_sum;
	}
}

//Driver code
int main(){
	FILE *fp;
	fp=fopen("arrayFile.txt","w");
	int n;
	printf("Enter the size of Array ");
	scanf("%d",&n);
	int a[n];
    for(size_t k=0;k<n;k++){
		printf("Enter a number ");
		scanf("%d",&a[k]);
		fprintf(fp,"%d\n",a[k]);
		}
	printf("The maximum sum of sub array of this array is : %d",FindMaxSubArrayFromFile("arrayFile.txt"));
	fclose(fp);
	
	return 0;
	
}