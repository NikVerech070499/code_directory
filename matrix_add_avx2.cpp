// n mod 16 = 0
// M <- A + B
/*
void matrix_add_avx512(const float* A, const float* B, unsigned n, float* M){
	unsigned zmm_size = sizeof(__m512) / sizeof(float)
	for (unsigned int c = 0; c < n; c++)
		for (unsigned int r = 0; r < n / zmm_size; r++)
			// M[c * n + r] = A[c * n + r] + B[c * n + r];
			// Тут мы применяем встроенные функции intel
			__m512 v = _mm512_loadu_ps(&A[c * n + r * zmm_size]);
			__m512 u = _mm512_loadu_ps(&B[c * n + r * zmm_size]);
			__m512 z = _mm512_add_ps(v, u);
			_mm512_storeu_ps(&M[c * n + r * zmm_size], z);
			// u в loadu означает unaligned
*/

void matrix_add_avx2(const float* A, const float* B, unsigned n, float* M) {

	unsigned zmm_size = sizeof(__m256) / sizeof(float);

	for (unsigned int c = 0; c < n; c++)
		for (unsigned int r = 0; r < n / zmm_size; r++) {
			__m256 v = _mm256_loadu_ps(&A[c * n + r * zmm_size]);
			__m256 u = _mm256_loadu_ps(&B[c * n + r * zmm_size]);
			__m256 z = _mm256_add_ps(v, u);
			_mm256_storeu_ps(&M[c * n + r * zmm_size], z);
		}

}
