struct vir{
	db r, i;
	vir(db r = 0.0, db i = 0.0) : r(r), i(i){}
	void print() {printf("%f %f\n", r, i);}
	vir operator +(const vir &c) {return vir(r + c.r, i + c.i);}
	vir operator -(const vir &c) {return vir(r - c.r, i - c.i);}
	vir operator *(const vir &c) {return vir(r * c.r - i * c.i, r * c.i + i * c.r);}
	vir operator *(const double &c) {return vir(r * c,i * c);}
	vir operator /(const double &c) {return vir(r / c,i / c);}
} w[2][M];

struct FFT{
	int N, na, nb, rev[M];
	vir A[M], B[M];
	void fft(vir *a, int f){
		vir x, y;
		rep(i, 0, N) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int i = 1; i < N; i <<= 1)
			for (int j = 0, t = N/(i<<1); j < N; j += i<<1)
				for (int k = 0, l = 0; k < i; k++, l += t) 
					x = w[f][l] * a[j+k+i], y = a[j+k], a[j+k] = y+x, a[j+k+i] = y-x;
		if (f) rep(i, 0, N) a[i].r /= N;
	}
	void work(){
		int d = __builtin_ctz(N);
		rep(i, 0, N) {
			rev[i] = (rev[i>>1] >> 1) | ((i&1) << (d-1));
			w[1][i] = w[0][i] = vir(cos(2*pi*i/N), sin(2*pi*i/N));
			w[1][i].i = -w[1][i].i;
		}
	}	
	void doit(int *a,int *b, int &na, int nb){ // [0, na)
		for (N = 1; N < na + nb - 1; N <<= 1);
		rep(i, 0, na) A[i] = vir(a[i], 0); rep(i, na, N) A[i] = vir(0, 0);
		rep(i, 0, nb) B[i] = vir(b[i], 0); rep(i, nb, N) B[i] = vir(0, 0);
		work(), fft(A, 0), fft(B, 0);
		rep(i, 0, N) A[i] = A[i] * B[i];
		fft(A, 1); 
		rep(i, 0, N) a[i] = (int)(A[i].r + 0.5);  
		na = N;
		while(na && a[na - 1] == 0) na--;
		//rep(i, 0, N) a[i].print();
	}
} fft;
