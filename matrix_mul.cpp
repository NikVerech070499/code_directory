#include <stdio>

void matrix_mul(const float* A, const float* B, unsigned N, float* M) {
	for (unsigned c = 0; c != N; c++)
		for (unsigned r = 0; r != N; r++) {
			float K = 0;
			for (unsigned i = 0; i != N; i++)
				K = K + A[i * N + r] * B[c * N + i];
			M[c * N + r] = K;
		}
}

void matrix_mul_256(const float* A, const float* B, unsigned N, float* M) {

	unsigned zmm_size = sizeof(__m256) / sizeof(float);

	for (unsigned c = 0; c != N; c++)
		for (unsigned r = 0; r != N / zmm_size; r++) {
			__m256 K = _mm256_setzero_ps();
			for (unsigned i = 0; i != N; i++) {
				__m256 a = _mm256_loadu_ps(&A[i * N + r * zmm_size]);
				__m256 b = _mm256_loadu_ps(&B[c * N + i]);
				__m256 m = _mm256_mul_ps(a, b);
				K = _m256_add_ps(K, m);
			}
			_m256_storeu_ps(&M[c * N + r * zmm_size], K);
		}
}


int main() {

	unsigned N = 
	const float* A = 
	const float* B =
	float* M = 

	matrix_mul(A, B, N, M);

	std::cout << 

	return 0

}
