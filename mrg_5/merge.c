#include"merge.h"


student** createArray(int n){
	student** arr = (student**)malloc(n*sizeof(student*));

	int i;
	for(i = 0; i<n; i++){
		arr[i] = (student*)malloc(sizeof(student));
		arr[i]->name = (char*)malloc(10*sizeof(char));
	}
	return arr;
}

void readfile(FILE *f, student** arr, int n){
	int i;
	for(i=0;!feof(f);i++){
		fscanf(f,"%[^,],%f\n", arr[i]->name, &arr[i]->cgpa);
	}
}

void printArray(student** arr, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%s,%.2f\n", arr[i]->name, arr[i]->cgpa);
	}
}

void copy(student* a, student* b){
	memcpy(a->name, b->name, 10*sizeof(char));
	a->cgpa = b->cgpa;
}
int compare(student* a, student* b){
	if(a->cgpa<b->cgpa) return 1;
	else return 0;
}

void merge(student** arr1, int sz1, student** arr2, int sz2, student** mrg){
//	mrg = createArray(sz1+sz2);
	int i=0, i1=0,i2=0;
	for(i =0; i1<sz1 && i2<sz2; ){
		if(compare(arr1[i1],arr2[i2])){
			copy(mrg[i++], arr1[i1]);
			i1++;
		}
		else{
			copy(mrg[i++], arr2[i2]);
			i2++;
		}	

	}

	while(i1<sz1){
		copy(mrg[i++],arr1[i1++]);
	}
	while(i2<sz2){
		copy(mrg[i++],arr2[i2++]);
	}
	
	printArray(mrg,2);

//	arr1 = (student**)realloc(arr1,(sz1+sz2)*sizeof(student*));
	
}

void mergeSort(student** arr, int st, int en){
	if(en-st<1) return;
	int mid = (st+en)/2;
	student** temp = createArray(en-st+1);// (student**)malloc((en-st+1)*sizeof(student*));
	student** half = &arr[mid+1];

	mergeSort(arr, st, mid);
	mergeSort(arr, mid+1, en);
	
	merge(arr, mid-st+1, half, en-mid, temp);
	int i;
	for(i=0;i<(en-st+1); i++){
		copy(arr[st+i],temp[i]);
	}
	free(temp);
	printArray(arr,5);
	printf("%d,%d\n",st,en);

}

