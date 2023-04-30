void Swap(int* A, int* B){
    char a,b;
    int a1,b1;
    int temp;
    scanf(" %c %c %d %d",&a,&b,&a1,&b1);
    switch (a){
    case 'A':
        switch (b){
        case 'A':
            temp=A[a1];
            A[a1]=A[b1];
            A[b1]=temp;
            break;
        case 'B':
            temp=A[a1];
            A[a1]=B[b1];
            B[b1]=temp;
            break;
        }
        break;
    case 'B':
        switch (b){
        case 'A':
            temp=B[a1];
            B[a1]=A[b1];
            A[b1]=temp;
            break;
        case 'B':
            temp=B[a1];
            B[a1]=B[b1];
            B[b1]=temp;
            break;
        }
        break;
    }
    return;
}

void Replace(int* A, int* B){
    char a;
    int pos,val;
    scanf(" %c %d %d",&a,&pos,&val);
    switch (a){
    case 'A':
        A[pos]=val;
        break;
    case 'B':
        B[pos]=val;
        break;
    }
    return;
}

void Switch(int** A, int** B){
    int len = sizeof(A)/sizeof(int*);
    for(int i=0;i<len;i++){
        int* tmp=A[i];
        A[i]=B[i];
        B[i] = tmp;
    }
    return;
}