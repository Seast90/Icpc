void fwt(int a[],int n,int t){
	for(int d=1;d<n;d<<=1)
		for(int m=d<<1,i=0;i<n;i+=m)
			for(int j=0;j<d;j++){
				int x=a[i+j], y=a[i+j+d];
				if(t==1){
					// xor: a[i+j]=add(x,y), a[i+j+d]=add(x,mod-y);
					// ans: a[i+j]=add(x,y);
					// or:  a[i+j+d]=add(x,y);
				}else {
					//xor: a[i+j]=mul(add(x,y),inv2), a[i+j+d]=mul(add(x,mod-y),inv2);
					//ans: a[i+j]=add(x,mod-y);
					//or: a[i+j+d] = add(y,mod-x);
				}
			}
}
