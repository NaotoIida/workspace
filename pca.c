/****************************/
/* 主成分分析               */
/*      coded by Y.Suganuma */
/****************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int principal(int, int, double **, double *, double **, double, int);
int Jacobi(int, int, double, double **, double **, double **, double **, double **);

int main()
{
	int i1, i2, n, p, sw,i3,i4;
	FILE *inpf;
	char str[3168][15]; 
	double r[200];
	double x[200][3168];
	double a[200][200];

/*original code*/ 	scanf("%d %d", &p, &n);   // 変数の数とデータの数
/*Subsutitute dimention and numbers of words to variable*/
	p = 200;//dimention
	n = 3168;//numbers of words

/*Open inputfile stream*/
	inpf = fopen("Wakatidate1.txt","r");
	if(inpf == NULL){
		printf("Input File not found\n");
		return -1;
	}


	//for (i1 = 0; i1 < n; i1++) {   // データ
	i1=0;i3=0;
		while(fscanf(inpf,"%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",str,&x[i2][i1],&x[i2+1][i1],&x[i2+2][i1],&x[i2+3][i1],&x[i2+4][i1],&x[i2+5][i1],&x[i2+6][i1],&x[i2+7][i1],&x[i2+8][i1],&x[i2+9][i1],&x[i2+10][i1],&x[i2+11][i1],&x[i2+12][i1],&x[i2+13][i1],&x[i2+14][i1],&x[i2+15][i1],&x[i2+16][i1],&x[i2+17][i1],&x[i2+18][i1],&x[i2+19][i1],&x[i2+20][i1],&x[i2+21][i1],&x[i2+22][i1],&x[i2+23][i1],&x[i2+24][i1],&x[i2+25][i1],&x[i2+26][i1],&x[i2+27][i1],&x[i2+28][i1],&x[i2+29][i1],&x[i2+30][i1],&x[i2+31][i1],&x[i2+32][i1],&x[i2+33][i1],&x[i2+34][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1],&x[i2][i1]) != ','){
		for (i2 = 0; i2 < p; i2++){
			scanf("%lf", &x[i2][i1]);
			printf("%lf,", &x[i2][i1]);
		}
		return 0;
	//}

	sw = principal(p, n, x, r, a, 1.0e-10, 200);

	if (sw == 0) {
		for (i1 = 0; i1 < p; i1++) {
			printf("主成分 %f", r[i1]);
			printf(" 係数");
			for (i2 = 0; i2 < p; i2++)
				printf(" %f", a[i1][i2]);
			printf("\n");
		}
	}
	else
		printf("***error  解を求めることができませんでした\n");

	for (i1 = 0; i1 < p; i1++) {
		delete [] x[i1];
		delete [] a[i1];
	}
	delete [] x;
	delete [] a;
	delete [] r;

	return 0;
}

/***********************************/
/* 主成分分析                      */
/*      p : 変数の数               */
/*      n : データの数             */
/*      x : データ                 */
/*      r : 分散（主成分）         */
/*      a : 係数                   */
/*      eps : 収束性を判定する規準 */
/*      ct : 最大繰り返し回数      */
/*      return : =0 : 正常         */
/*               =1 : エラー       */
/***********************************/
int principal(int p, int n, double **x, double *r, double **a, double eps, int ct)
{
	double **A1, **A2, **C, mean, **X1, **X2, s2;
	int i1, i2, i3, sw = 0;
					// 領域の確保
	C  = new double * [p];
	A1 = new double * [p];
	A2 = new double * [p];
	X1 = new double * [p];
	X2 = new double * [p];
	for (i1 = 0; i1 < p; i1++) {
		C[i1]  = new double [p];
		A1[i1] = new double [p];
		A2[i1] = new double [p];
		X1[i1] = new double [p];
		X2[i1] = new double [p];
	}
					// データの基準化
	for (i1 = 0; i1 < p; i1++) {
		mean = 0.0;
		s2   = 0.0;
		for (i2 = 0; i2 < n; i2++) {
			mean += x[i1][i2];
			s2   += x[i1][i2] * x[i1][i2];
		}
		mean /= n;
		s2   /= n;
		s2    = n * (s2 - mean * mean) / (n - 1);
		s2    = sqrt(s2);
		for (i2 = 0; i2 < n; i2++)
			x[i1][i2] = (x[i1][i2] - mean) / s2;
	}
					// 分散強分散行列の計算
	for (i1 = 0; i1 < p; i1++) {
		for (i2 = i1; i2 < p; i2++) {
			s2 = 0.0;
			for (i3 = 0; i3 < n; i3++)
				s2 += x[i1][i3] * x[i2][i3];
			s2        /= (n - 1);
			C[i1][i2]  = s2;
			if (i1 != i2)
				C[i2][i1] = s2;
		}
	}
					// 固有値と固有ベクトルの計算（ヤコビ法）
	sw = Jacobi(p, ct, eps, C, A1, A2, X1, X2);

	if (sw == 0) {
		for (i1 = 0; i1 < p; i1++) {
			r[i1] = A1[i1][i1];
			for (i2 = 0; i2 < p; i2++)
				a[i1][i2] = X1[i2][i1];
		}
	}
					// 領域の解放
	for (i1 = 0; i1 < p; i1++) {
		delete [] C[i1];
		delete [] A1[i1];
		delete [] A2[i1];
		delete [] X1[i1];
		delete [] X2[i1];
	}
		delete [] A1[i1];
		delete [] A2[i1];
		delete [] X1[i1];
		delete [] X2[i1];
	}
	delete [] C;
	delete [] A1;
	delete [] A2;
	delete [] X1;
	delete [] X2;

	return sw;
}

/*************************************************************/
/* 実対称行列の固有値・固有ベクトル（ヤコビ法）              */
/*      n : 次数                                             */
/*      ct : 最大繰り返し回数                                */
/*      eps : 収束判定条件                                   */
/*      A : 対象とする行列                                   */
/*      A1, A2 : 作業域（nxnの行列），A1の対角要素が固有値   */
/*      X1, X2 : 作業域（nxnの行列），X1の各列が固有ベクトル */
/*      return : =0 : 正常                                   */
/*               =1 : 収束せず                               */
/*      coded by Y.Suganuma                                  */
/*************************************************************/
#include <math.h>

int Jacobi(int n, int ct, double eps, double **A, double **A1, double **A2,
           double **X1, double **X2)
{
	double max, s, t, v, sn, cs;
	int i1, i2, k = 0, ind = 1, p = 0, q = 0;
					// 初期設定
	for (i1 = 0; i1 < n; i1++) {
		for (i2 = 0; i2 < n; i2++) {
			A1[i1][i2] = A[i1][i2];
			X1[i1][i2] = 0.0;
		}
		X1[i1][i1] = 1.0;
	}
					// 計算
	while (ind > 0 && k < ct) {
						// 最大要素の探索
		max = 0.0;
		for (i1 = 0; i1 < n; i1++) {
			for (i2 = 0; i2 < n; i2++) {
				if (i2 != i1) {
					if (fabs(A1[i1][i2]) > max) {
						max = fabs(A1[i1][i2]);
						p   = i1;
						q   = i2;
					}
				}
			}
		}
						// 収束判定
							// 収束した
		if (max < eps)
			ind = 0;
							// 収束しない
		else {
								// 準備
			s  = -A1[p][q];
			t  = 0.5 * (A1[p][p] - A1[q][q]);
			v  = fabs(t) / sqrt(s * s + t * t);
			sn = sqrt(0.5 * (1.0 - v));
			if (s*t < 0.0)
				sn = -sn;
			cs = sqrt(1.0 - sn * sn);
								// Akの計算
			for (i1 = 0; i1 < n; i1++) {
				if (i1 == p) {
					for (i2 = 0; i2 < n; i2++) {
						if (i2 == p)
							A2[p][p] = A1[p][p] * cs * cs + A1[q][q] * sn * sn -
                                       2.0 * A1[p][q] * sn * cs;
						else if (i2 == q)
							A2[p][q] = 0.0;
						else
							A2[p][i2] = A1[p][i2] * cs - A1[q][i2] * sn;
					}
				}
				else if (i1 == q) {
					for (i2 = 0; i2 < n; i2++) {
						if (i2 == q)
							A2[q][q] = A1[p][p] * sn * sn + A1[q][q] * cs * cs +
                                       2.0 * A1[p][q] * sn * cs;
						else if (i2 == p)
							A2[q][p] = 0.0;
						else
							A2[q][i2] = A1[q][i2] * cs + A1[p][i2] * sn;
					}
				}
				else {
					for (i2 = 0; i2 < n; i2++) {
						if (i2 == p)
							A2[i1][p] = A1[i1][p] * cs - A1[i1][q] * sn;
						else if (i2 == q)
							A2[i1][q] = A1[i1][q] * cs + A1[i1][p] * sn;
						else
							A2[i1][i2] = A1[i1][i2];
					}
				}
			}
								// Xkの計算
			for (i1 = 0; i1 < n; i1++) {
				for (i2 = 0; i2 < n; i2++) {
					if (i2 == p)
						X2[i1][p] = X1[i1][p] * cs - X1[i1][q] * sn;
					else if (i2 == q)
						X2[i1][q] = X1[i1][q] * cs + X1[i1][p] * sn;
					else
						X2[i1][i2] = X1[i1][i2];
				}
			}
								// 次のステップへ
			k++;
			for (i1 = 0; i1 < n; i1++) {
				for (i2 = 0; i2 < n; i2++) {
					A1[i1][i2] = A2[i1][i2];
					X1[i1][i2] = X2[i1][i2];
				}
			}
		}
	}

	return ind;
}

25 57 19 81
74 47 64 47
39 33 48 46
14 22 9 69
67 60 49 26
42 40 77 65
11 80 0 86
32 0 43 74
68 69 44 68
24 49 9 71
42 74 28 46
60 58 73 28
36 37 33 68
24 44 19 83
30 40 31 50
55 40 60 49
63 47 94 41
72 30 100 45
19 22 13 75
43 39 43 34
90 83 92 31
51 77 52 82
53 70 34 31
28 51 53 44
40 62 42 79
31 48 22 68
57 29 51 30
64 89 57 42
49 82 72 29
53 31 55 43
79 52 70 10
45 19 43 57
35 34 34 89
4 69 0 100
49 49 66 66
92 82 97 6
5 89 0 100
65 26 83 28
56 36 64 38
48 50 25 22
30 30 15 55
40 65 38 42
14 67 9 67
84 96 90 8
53 64 51 54
50 89 60 52
76 41 68 9
49 40 53 49
78 66 66 17
76 58 90 29
41 15 40 49
63 60 55 33
40 36 49 67
78 54 71 18
62 72 69 12
64 47 42 53
56 64 9 15
77 35 56 25
44 12 46 87
80 9 56 19
36 21 52 78
48 63 64 48
43 61 50 47
58 23 28 50
90 12 100 0
13 33 11 77
67 44 48 28
75 45 68 17
81 22 89 9
46 45 59 55
56 49 64 55
65 62 72 27
34 49 29 77
45 33 60 63
20 45 14 99
33 38 26 87
44 51 69 52
64 57 64 48
44 64 51 28
63 48 56 11
29 39 33 84
40 48 51 54
40 38 26 62
68 46 61 26
58 45 68 48
64 44 77 63
59 62 44 66
81 53 93 19
23 34 12 68
51 35 55 46
74 70 84 17
42 33 56 44
46 31 46 53
33 57 38 63
40 24 20 42
53 36 60 31
0 34 0 100
