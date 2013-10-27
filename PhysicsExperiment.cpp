const double g = 10.0;

// input
int N;// number of balls
int H;// height
int R, T;

double y[N];// the final position of balls

// calculate the positions of balls at T
double calc(int T){
	if(T < 0) return H;

	// calculate which process does the ball in
	double t = sqrt(2 * H / g);
	int k = (int)(T / t);

	if(k % 2 == 0){
		double d = T - k * t;
		return H - g * d * d / 2;
	}else{
		double d = k * t + t - T;
		return H - g * d * d / 2;
	}
}

int main(){
	// calculate the positions of balls when regarded as mass point
	for(int i = 0; i < N; i++){
		y[i] = calc(T - i);
	}

	sort(y, y + N);

	for(int i = 0; i < N; i++){
		printf("%.2f%c", y[i] + 2 * R * i / 100.0, i + 1 == N ? '\n' : ' ');
	}

	return 0;
}