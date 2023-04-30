int** s(int* a,int len){
	for(int i=len-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	int matrixsize = sqrt(len);
	int** arr = (int**)malloc(sizeof(int*)*matrixsize);
	for(int i=0;i<matrixsize;i++){
		arr[i] = (int*)malloc(sizeof(int)*matrixsize);
		for(int j=0;j<matrixsize;j++){
			arr[i][j] = a[i*matrixsize+j];
		}
	}
	return arr;
}
void print(int** ans,int len){
	int matrixsize = sqrt(len); 
	for(int i=0;i<matrixsize;i++){
		for(int j=0;j<matrixsize;j++){
			printf("%d",ans[i][j]);
		}
		printf("\n");
		free(ans[i]);
	}
	free(ans);
}
