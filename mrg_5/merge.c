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
	for(i=0;!feof(f)&&i<n;i++){
		fscanf(f,"%[^,],%f\n", arr[i]->name, &arr[i]->cgpa);
	}
}

void printArray(student** arr, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%s,%.2f\n", arr[i]->name, arr[i]->cgpa);
	}
}
void fprintArray(FILE* f, student** arr, int n){
	int i;
	for(i=0; i<n; i++){
		fprintf(f,"%s,%.2f\n", arr[i]->name, arr[i]->cgpa);
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
	if(sz1<=0||sz2<=0) return;
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
	
//	printArray(arr1,sz1);
//	printArray(arr2,sz2);	
//	printf("%d,%d\n",sz1,sz2);
//	printArray(mrg,sz1+sz2);
//	printf("\n");

//	arr1 = (student**)realloc(arr1,(sz1+sz2)*sizeof(student*));
	
}

void mergeSortRec(student** arr, int st, int en){
	if(en-st<1) return;
	int mid = (st+en)/2;
	student** temp = createArray(en-st+1);// (student**)malloc((en-st+1)*sizeof(student*));
//	student** half = &arr[mid+1];

//	printArray(arr+st,en-st+1);
//	printf("b%d,%d\n",st,en);
	mergeSortRec(arr, st, mid);
//	printArray(arr+st,en-st+1);
//	printf("d%d,%d\n",st,en);
	mergeSortRec(arr, mid+1, en);
//	printArray(arr+st,en-st+1);
//	printf("a%d,%d\n",st,en);

//	printArray(arr,mid-st+2);printf(".");
//	printArray(arr+mid+1,en-mid);
	merge(arr+st, mid-st+1, (arr+mid+1), en-mid, temp);
	int i;
//	printArray(temp,en-st+1);
//	printf("\n");
	for(i=0;i<(en-st+1); i++){
		copy(arr[st+i],temp[i]);
	}
	free(temp);
//	printf("%d,%d\n",st,en);

}

void mergeSortIter(student** arr, int st, int en){
	int i,j,k, n= en-st+1;
	
	student** temp = createArray(en-st+1);
	for(i=1; i<n; i*=2){
	//	printf("i=%d",i);
		for(j=0; j<n; j+=2*i){
			int t = (j+2*i<n)? i:(n-j-i);
			merge((arr+j),i, (arr+j+(i)), t, temp);
//		printf("j");
			for(k=0; t>0&&k<i+t; k++){
				copy(arr[j+k], temp[k]);
//		printf("k");
			}
//		printArray(arr+j,2*i);
		}
	}

	free(temp);
}

int storeK(FILE* f,int k){
	student** arr = createArray(k);
	int fileno = 0;
	char name[10];
	while(!feof(f)){
		readfile(f, arr, k);
		mergeSortIter(arr, 0, k-1);
		snprintf(name,10, "%d", fileno);
		FILE* ft = fopen(name, "w");
		fprintArray(ft, arr, k);
		fclose(ft);
		fileno++;
	}
	return fileno;
}

char* itostr(int n){
//	size_t l = snprintf(NULL, 0, "%d", n);
//	l+=sizeof(char);
	char* str = (char*)malloc(9);
//	char str[9];
	snprintf(str, 9, "%d", n); 
	return str;
}


void mergeFiles(int fi1, int fi2){
	FILE* f1 = fopen(itostr(fi1), "r");
	FILE* f2 = fopen(itostr(fi2), "r");
	FILE* out = fopen("out", "w");

	student **temp1 = createArray(1), **temp2 = createArray(1);
	student* r1=temp1[0], *r2=temp2[0];
	printf("hello");
	fscanf(f1,"%[^,],%f\n", r1->name, &r1->cgpa);
	fscanf(f2,"%[^,],%f\n", r2->name, &r2->cgpa);
	do{	
		if(compare(r1,r2)){
			fprintf(out,"%s,%.2f\n", r1->name, r1->cgpa);
			fscanf(f1,"%[^,],%f\n", r1->name, &r1->cgpa);
		}
		else{
			fprintf(out,"%s,%.2f\n", r2->name, r2->cgpa);
			fscanf(f2,"%[^,],%f\n", r2->name, &r2->cgpa);
		}
	}
	while(!feof(f1)&&!feof(f2));
	if(compare(r1,r2)){
		fprintf(out,"%s,%.2f\n", r1->name, r1->cgpa);

//		while(!feof(f1)){
//			fscanf(f1,"%[^,],%f\n", r1->name, &r1->cgpa);
//			fprintf(out,"%s,%.2f\n", r1->name, r1->cgpa);
//		}
//	
//		while(!feof(f2)){
//			fscanf(f2,"%[^,],%f\n", r2->name, &r2->cgpa);
//			fprintf(out,"%s,%.2f\n", r2->name, r2->cgpa);
//		}
			
	}
	else{
		fprintf(out,"%s,%.2f\n", r2->name, r2->cgpa);
	}

	while(!feof(f1)){
	//	f1--;
		fscanf(f1,"%[^,],%f\n", r1->name, &r1->cgpa);
		fprintf(out,"%s,%.2f\n", r1->name, r1->cgpa);
	}
//	fprintf(out,"%s,%.2f\n", r1->name, r1->cgpa);

	while(!feof(f2)){
	//	f2--;
		fscanf(f2,"%[^,],%f\n", r2->name, &r2->cgpa);
		fprintf(out,"%s,%.2f\n", r2->name, r2->cgpa);
	}
//	fprintf(out,"%s,%.2f\n", r2->name, r2->cgpa);

	fclose(f1);
	fclose(f2);
	fclose(out);
}
