#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**********************************************************************
 * API
 *********************************************************************/

typedef struct _matrix matrix;

/* Creates a "rows by cols" matrix with all values 0.
 * Returns NULL if rows <=0 or cols <= 0 and otherwise
 * a pointer to the new matrix.
 */

matrix * newMatrix(int rows, int cols);

/* Copies a matrix.  Returns NULL if mtx is NULL.
 */

matrix * copyMatrix(matrix const * mtx);

/* Deletes a matrix.  Returns 0 if successful and -1
 * if mtx is NULL.
 */

void deleteMatrix(matrix * mtx);

/* Sets the (row, col) element of mtx to val.
 * Returns 0 if successful, -1 if mtx is NULL, and
 * -2 if row or col are outside of the dimensions of
 * mtx.
 */

int setElement(matrix * mtx, int row, int col,
               double val);

/* Sets the reference val to the value of the
 * (row,col) element of mtx.  Returns 0 if successful,
 * -1 if either mtx or val is NULL, and -2 if row or
 * col are outside of the dimensions of mtx.
 */

int getElement(matrix const * mtx, int row, int col,
               double * val);

/* Sets the reference n to the number of rows of mtx.
 * Returns 0 if successful and -1 if mtx or n is NULL.
 */

int nRows(matrix const * mtx, int * n);

/* Sets the reference n to the number of columns of mtx.
 * Returns 0 if successful and -1 if mtx or n is NULL.
 */

int nCols(matrix const * mtx, int * n);

/* Prints the matrix to stdout.  Returns 0 if successful
 * and -1 if mtx is NULL.
 */

int printMatrix(matrix const * mtx);

/* Writes the transpose of matrix in into matrix out.
 * Returns 0 if successful, -1 if either in or out is
 * NULL, and -2 if the dimensions of the matrices are
 * incompatible.
 */

int transpose(matrix const * in, matrix * out);

/* Writes the sum of matrices mtx1 and mtx2 into
 * matrix sum.  Returns 0 if successful, -1 if any
 * of the matrices are NULL, and -2 if the dimensions
 * of the matrices are incompatible.
 */

int sum(matrix const * mtx1, matrix const * mtx2,
        matrix * sum);

/* Writes the product of the matrices mtx1 and mtx2 into
 * matrix prod.  Returns 0 if successful, -1 if any
 * of the matrices are NULL, and -2 if the dimensions
 * of the matrices are incompatible.
 */

int product(matrix const * mtx1, matrix const * mtx2,
            matrix * prod);

/* Writes the dot product of vectors v1 and v2 into
 * reference prod.  Returns 0 if successful, -1 if any
 * of v1, v2, or prod are NULL, -2 if either matrix
 * is not a vector, and -3 if the vectors are of
 * incompatible dimensions. */

int dotProduct(matrix const * v1, matrix const * v2,
               double * prod);

/* Returns 1 if a matrix is square and 0 otherwise. */
int isSquare(matrix const * mtx);

/* Sets a square matrix to the identity.  Returns 0
 * if successful; returns -1 if m is null or the
 * matrix is not square.
 */

int identity(matrix * m);

/* Returns 1 if m is a diagonal matrix and 0
 * otherwise.
 */

int isDiagonal(matrix const * mtx);

/* Returns 1 if m is an upper-triangular
 * matrix and 0 otherwise.
 */

int isUpperTriangular(matrix const * mtx);

/* Constructs a diagonal matrix from a vector.
 * Returns 0 if successful; returns -1 if either
 * argument is null, if the matrix is not square,
 * or if matrix and vector have incompatible
 * dimensions.
 */

int diagonal(matrix const * v, matrix * mtx);

/* Return 1 if mtx is square and symmetric and 0
 * otherwise (including if mtx is null).
 */

int symmetric(matrix const * mtx);

/* Returns column col of mtx as a new vector. Returns NULL
 * if mtx is NULL or col is inconsistent with mtx's
 * dimensions.
 */

matrix * getColumn(matrix const * mtx, int col);

/* Returns row row of mtx as a row vector. Returns NULL
 * if mtx is NULL or row is inconsistent with mtx's
 * dimensions.
 */

matrix * getRow(matrix const * mtx, int row);

/* Sets each element of mtx to the product of that element
 * with s. Returns -1 if mtx is NULL and 0 otherwise.
 */

int scalarProduct(double s, matrix * mtx);

/**********************************************************************
 * Application
 *********************************************************************/

/* Basic test of the library. */
void testBasic(void);

/* Test the new functions. */
void testSymmetric(void);
void testGetColumnGetRow(void);
void testScalarProduct(void);

int main(void) {
  testBasic();
  testSymmetric();
  testGetColumnGetRow();
  testScalarProduct();
  return 0;
}

void testBasic(void) {
  matrix * A, * Ac, * B, * c, * d, * M, * ct, * mdp;
  double dp;
  int err;
  A = newMatrix(3, 3); assert(A);
  err = setElement(A, 1, 1, 1.0); assert(!err);
  err = setElement(A, 1, 2, .25); assert(!err);
  err = setElement(A, 1, 3, -.1); assert(!err);
  err = setElement(A, 2, 2, .4); assert(!err);
  err = setElement(A, 2, 3, .3); assert(!err);
  err = setElement(A, 3, 2, .1); assert(!err);
  err = setElement(A, 3, 3, -.3); assert(!err);
  printf("Matrix A:\n");
  err = printMatrix(A); assert(!err);

  Ac = copyMatrix(A); assert(Ac);
  printf("\nCopy of A:\n");
  err = printMatrix(Ac); assert(!err);

  B = newMatrix(3, 3); assert(B);
  err = setElement(B, 1, 1, .5); assert(!err);
  err = setElement(B, 2, 2, 2.0); assert(!err);
  err = setElement(B, 3, 3, 1.0); assert(!err);
  printf("\nMatrix B:\n");
  err = printMatrix(B); assert(!err);

  c = newMatrix(3, 1); assert(c);
  err = setElement(c, 1, 1, 1.0); assert(!err);
  err = setElement(c, 3, 1, 1.0); assert(!err);
  printf("\nVector c:\n");
  err = printMatrix(c); assert(!err);

  d = newMatrix(3, 1); assert(d);
  err = setElement(d, 2, 1, 1.0); assert(!err);
  err = setElement(d, 3, 1, 1.0); assert(!err);
  printf("\nVector d:\n");
  err = printMatrix(d); assert(!err);

  M = newMatrix(3, 3); assert(M);
  err = transpose(A, M); assert(!err);
  printf("\nA':\n");
  err = printMatrix(M); assert(!err);

  ct = newMatrix(1, 3); assert(ct);
  err = transpose(c, ct); assert(!err);
  printf("\nc':\n");
  err = printMatrix(ct); assert(!err);

  err = sum(A, B, M); assert(!err);
  printf("\nA + B:\n");
  err = printMatrix(M); assert(!err);

  err = product(A, B, M); assert(!err);
  printf("\nA * B:\n");
  err = printMatrix(M); assert(!err);

  mdp = newMatrix(1, 1); assert(mdp);
  err = product(ct, d, mdp); assert(!err);
  err = getElement(mdp, 1, 1, &dp); assert(!err);
  printf("\nDot product (1): %.2f\n", dp);

  err = dotProduct(c, d, &dp); assert(!err);
  printf("\nDot product (2): %.2f\n", dp);

  err = product(A, c, d); assert(!err);
  printf("\nA * c:\n");
  err = printMatrix(d); assert(!err);

  deleteMatrix(A);
  deleteMatrix(Ac);
  deleteMatrix(B);
  deleteMatrix(c);
  deleteMatrix(d);
  deleteMatrix(M);
  deleteMatrix(ct);
  deleteMatrix(mdp);
}

void testSymmetric(void) {
	matrix * A, *An;
	int err, isSymm; 
	printf("\nSymmetric Matrix Test\n"); 
	A = newMatrix(3,3); assert(A); 
	err = setElement(A, 1, 1, 1.0); assert(err == 0); 
	err = setElement(A, 1, 2, -2.5); assert(err == 0); 
	err = setElement(A, 1, 3, -1.0); assert(err == 0); 
	err = setElement(A, 2, 1, -2.5); assert(err == 0);
	err = setElement(A, 2, 2, -4.0); assert(err == 0);
	err = setElement(A, 2, 3, -2.5); assert(err == 0);
	err = setElement(A, 3, 1, -1.0); assert(err == 0);
	err = setElement(A, 3, 2, -2.5); assert(err == 0);
	err = setElement(A, 3, 3, 6.8); assert(err == 0); 
	
	err = printMatrix(A); assert(err == 0); 
	isSymm = symmetric(A); assert(isSymm==-1);

	printf("Symmetric Matrix Test done\n\n");
	printf("Assymetric Matrix Test\n"); 
	
	err = setElement(A, 1, 1, 3.2); assert(err==0);
	err = setElement(A, 1, 2, 3.1); assert(err==0);
	err = setElement(A, 2, 1, 6.8); assert(err==0);
	err = setElement(A, 3, 1, 1.3); assert(err==0);
	err = setElement(A, 1, 3, 2.3); assert(err==0);

	isSymm= symmetric(A);
	assert(isSymm==0);
    printf("Assymmetric Matrix Test done\n\n");
    

	printf("Square Matrix nm Test\n");
    An = newMatrix(3,4); assert(An);
    
    err = setElement(An, 1, 1, 1.0); assert(err == 0);
    err = setElement(An, 1, 2, -2.5); assert(err == 0);
    err = setElement(An, 1, 3, -1.0); assert(err == 0);
    err = setElement(An, 1, 4, -5.0); assert(err == 0);
    err = setElement(An, 2, 1, -2.5); assert(err == 0);
    err = setElement(An, 2, 2, -4.0); assert(err == 0);
    err = setElement(An, 2, 3, -3.0); assert(err == 0);
    err = setElement(An, 2, 4, -5.0); assert(err == 0);
    err = setElement(An, 3, 1, 1.0); assert(err == 0);
    err = setElement(An, 3, 2, 3.0); assert(err == 0);
    err = setElement(An, 3, 3, 6.8); assert(err == 0);
    err = setElement(An, 3, 4, 8.8); assert(err == 0);
    

	isSymm = symmetric(An);
	assert(isSymm==0);
    printf("Square Matrix nm Test done\n\n");

	printf("NULL Input Test\n");
    
	isSymm = symmetric(NULL);
	assert(isSymm==0);
    
    printf("NULL Inputs Test done\n\n");
}

void testGetColumnGetRow(void) {
	printf("GetColumn Vector Test\n");
    
	int err; 
	matrix * A, *cV1;
	A = NULL; 
    cV1 = newMatrix(3,1); assert(cV1 != NULL);
    
    cV1 = getColumn(A, 1); assert(cV1 == NULL);
	deleteMatrix(A);
    deleteMatrix(cV1);
	
	matrix * B, *cV2;
	B = newMatrix(3,3); assert(B != NULL);
    cV2 = newMatrix(3, 1); assert(cV2 != NULL);
    
	err = setElement (B, 1, 1, 1); assert(err == 0); 
	err = setElement(B, 1, 2, 2); assert(err == 0);
	err = setElement(B, 1, 3, 3); assert(err == 0); 
	err = setElement(B, 2, 1, 4); assert(err == 0); 
	err = setElement(B, 2, 2, 5); assert(err == 0); 
	err = setElement(B, 2, 3, 6); assert(err == 0); 
	err = setElement(B, 3, 1, 7); assert(err == 0); 
	err = setElement(B, 3, 2, 8); assert(err == 0); 
	err = setElement(B, 3, 3, 9); assert(err == 0); 
	cV2 = getColumn(B, 4);
	assert(cV2 == NULL);
	deleteMatrix(B);
    deleteMatrix(cV2);
	
	matrix * C, *cV3;
	C = newMatrix(3, 3); assert(C !=NULL);
    cV3 = newMatrix(3, 1); assert(cV3 != NULL);
    
	err = setElement(C, 1, 1, 1); assert(err == 0); 
	err = setElement(C, 1, 2, 2); assert(err == 0); 
	err = setElement(C, 1, 3, 3); assert(err == 0); 
	err = setElement(C, 2, 1, 4); assert(err == 0); 
	err = setElement(C, 2, 2, 5); assert(err == 0); 
	err = setElement(C, 2, 3, 6); assert(err == 0); 
	err = setElement(C, 3, 1, 7); assert(err == 0); 
	err = setElement(C, 3, 2, 8); assert(err == 0); 
	err = setElement(C, 3, 3, 9); assert(err == 0); 
	cV3 = getColumn(C, -1);
	assert(cV3 == NULL);
	deleteMatrix(C);
    deleteMatrix(cV3);
	
	matrix * D, *cV4;
	D = newMatrix(3,3); assert(D != NULL);
    cV4 = newMatrix(3, 1); assert(cV4 != NULL);
    
	err = setElement(D, 1, 1, 1); assert(err == 0); 
	err = setElement(D, 1, 2, 2); assert(err == 0); 
	err = setElement(D, 1, 3, 3); assert(err == 0); 
	err = setElement(D, 2, 1, 4); assert(err == 0); 
	err = setElement(D, 2, 2, 5); assert(err == 0); 
	err = setElement(D, 2, 3, 6); assert(err == 0);
	err = setElement(D, 3, 1, 7); assert(err == 0);	
	err = setElement(D, 3, 2, 8); assert(err == 0);
	err = setElement(D, 3, 3, 9); assert(err == 0);
	cV4 = getColumn(D, 2);
    assert(cV4 != NULL);
    err = printMatrix(cV4); assert(err == 0);
	deleteMatrix(D);
    deleteMatrix(cV4);
    
    printf("GetColumn Vector Test done\n\n");
	
	
	printf("GetRow Vector Test\n");
    
    A = NULL;
    cV1 = newMatrix(1,3); assert(cV1 != NULL);
    cV1 = getRow(A, 1); assert(cV1 == NULL);
    deleteMatrix(A);
    deleteMatrix(cV1);
    
    printf(" End test 1 of GetRow Vector\n");
	

	
	B = newMatrix(3,3); assert(B != NULL);
    cV2 = newMatrix(1,3); assert(cV2 != NULL);
    
	err = setElement (B, 1, 1, 1); assert(err == 0); 
	err = setElement(B, 1, 2, 2); assert(err == 0);
	err = setElement(B, 1, 3, 3); assert(err == 0); 
	err = setElement(B, 2, 1, 4); assert(err == 0); 
	err = setElement(B, 2, 2, 5); assert(err == 0); 
	err = setElement(B, 2, 3, 6); assert(err == 0); 
	err = setElement(B, 3, 1, 7); assert(err == 0); 
	err = setElement(B, 3, 2, 8); assert(err == 0); 
	err = setElement(B, 3, 3, 9); assert(err == 0);
    cV2 = getRow(B, 4); assert(cV2 == NULL);
	deleteMatrix(B);
    deleteMatrix(cV2);
    printf("\n End test 2 of GetRow Vector\n");
    
	
	C = newMatrix(3, 3); assert(C !=NULL);
    cV3 = newMatrix(1,3); assert(cV3 != NULL);
	err = setElement(C, 1, 1, 1); assert(err == 0); 
	err = setElement(C, 1, 2, 2); assert(err == 0); 
	err = setElement(C, 1, 3, 3); assert(err == 0); 
	err = setElement(C, 2, 1, 4); assert(err == 0); 
	err = setElement(C, 2, 2, 5); assert(err == 0); 
	err = setElement(C, 2, 3, 6); assert(err == 0); 
	err = setElement(C, 3, 1, 7); assert(err == 0); 
	err = setElement(C, 3, 2, 8); assert(err == 0); 
	err = setElement(C, 3, 3, 9); assert(err == 0); 
	cV3 = getColumn(C, -1);
	assert(cV3 == NULL);
	deleteMatrix(C);
    deleteMatrix(cV3);
    printf("\n End test 3 of GetRow Vector\n");
	
	D = newMatrix(3,3); assert(D != NULL);
    cV4 = newMatrix(1,3); assert(cV4 != NULL);
	err = setElement(D, 1, 1, 1); assert(err == 0); 
	err = setElement(D, 1, 2, 2); assert(err == 0); 
	err = setElement(D, 1, 3, 3); assert(err == 0); 
	err = setElement(D, 2, 1, 4); assert(err == 0); 
	err = setElement(D, 2, 2, 5); assert(err == 0); 
	err = setElement(D, 2, 3, 6); assert(err == 0);
	err = setElement(D, 3, 1, 7); assert(err == 0);	
	err = setElement(D, 3, 2, 8); assert(err == 0);
	err = setElement(D, 3, 3, 9); assert(err == 0);
	cV4 = getColumn(D, 2);
	assert(cV4 != NULL);
    err = printMatrix(cV4); assert(err == 0);
	deleteMatrix(D);
    deleteMatrix(cV4);
    printf("\n End test 4 of GetRow Vector\n");
    
    printf("GetRow Vector Test done\n\n");
	
}

	
void testScalarProduct(void) {
	printf("Scalar Product Test\n");
	int err;
    double s;
	matrix * A; 
	A = NULL; 
	assert(scalarProduct(1, A) == -1); 
	deleteMatrix(A); 
	
	matrix * B; 
	B = newMatrix(3,3); assert(B != NULL); 
	err = setElement (B, 1, 1, 1); assert(err == 0); 
	err = setElement(B, 1, 2, 2); assert(err == 0);
	err = setElement(B, 1, 3, 3); assert(err == 0); 
	err = setElement(B, 2, 1, 4); assert(err == 0); 
	err = setElement(B, 2, 2, 5); assert(err == 0); 
	err = setElement(B, 2, 3, 6); assert(err == 0); 
	err = setElement(B, 3, 1, 7); assert(err == 0); 
	err = setElement(B, 3, 2, 8); assert(err == 0); 
	err = setElement(B, 3, 3, 9); assert(err == 0);
    
    printf(" Matrix\n");
    err = printMatrix(B); assert(err == 0);
    
    s = 4.1;
	assert(scalarProduct(s, B) == 0);
    
    printf("\n Scalar Product with %6.2f\n",s );
    err = printMatrix(B); assert(err == 0);
	deleteMatrix(B);
    
    B = newMatrix(3,3); assert(B != NULL);
    err = setElement (B, 1, 1, 1); assert(err == 0);
    err = setElement(B, 1, 2, 2); assert(err == 0);
    err = setElement(B, 1, 3, 3); assert(err == 0);
    err = setElement(B, 2, 1, 4); assert(err == 0);
    err = setElement(B, 2, 2, 5); assert(err == 0);
    err = setElement(B, 2, 3, 6); assert(err == 0);
    err = setElement(B, 3, 1, 7); assert(err == 0);
    err = setElement(B, 3, 2, 8); assert(err == 0);
    err = setElement(B, 3, 3, 9); assert(err == 0);
    
    printf("\n Matrix\n");
    err = printMatrix(B); assert(err == 0);
    
    s = 0.;
    assert(scalarProduct(s, B) == 0);
    
    printf("\n Scalar Product with %6.2f\n",s );
    err = printMatrix(B); assert(err == 0);
    deleteMatrix(B);
}

/**********************************************************************
 * Library implementation
 *********************************************************************/

struct _matrix {
  int rows;
  int cols;
  double * data;
};

static double getE(matrix const * mtx, int row, int col) {
  return mtx->data[(col-1) * mtx->rows + row - 1];
}

static void setE(matrix * mtx, int row, int col, double val) {
  mtx->data[(col-1) * mtx->rows + row - 1] = val;
}

static int badArgs(matrix const * mtx, int row, int col) {
  if (!mtx || !mtx->data)
    return -1;
  if (row <= 0 || row > mtx->rows ||
      col <= 0 || col > mtx->cols)
    return -2;
  return 0;
}

matrix * newMatrix(int rows, int cols) {
  int i;
  matrix * m;
  if (rows <=0 || cols <= 0) return NULL;

  /* allocate a matrix structure */
  m = (matrix *) malloc(sizeof(matrix));
  if (!m) return NULL;

  /* set dimensions */
  m->rows = rows;
  m->cols = cols;

  /* allocate a double array of length rows * cols */
  m->data = (double *) malloc(rows*cols*sizeof(double));
  if (!m->data) {
    free(m);
    return NULL;
  }
  /* set all data to 0 */
  for (i = 0; i < rows*cols; i++)
    m->data[i] = 0.0;

  return m;
}

void deleteMatrix(matrix * mtx) {
  if (mtx) {
    /* free mtx's data */
    free(mtx->data);
    /* free mtx itself */
    free(mtx);
  }
}

matrix * copyMatrix(matrix const * mtx) {
  matrix * cp;
  if (!mtx) return NULL;

  /* create a new matrix to hold the copy */
  cp = newMatrix(mtx->rows, mtx->cols);
  if (!cp) return NULL;

  /* copy mtx's data to cp's data */
  memcpy(cp->data, mtx->data,
         mtx->rows * mtx->cols * sizeof(double));

  return cp;
}

int setElement(matrix * mtx, int row, int col,
               double val) {
  int err = badArgs(mtx, row, col);
  if (err) return err;
  setE(mtx, row, col, val);
  return 0;
}

int getElement(matrix const * mtx, int row, int col,
               double * val) {
  int err = badArgs(mtx, row, col);
  if (err) return err;
  if (!val) return -1;

  *val = getE(mtx, row, col);
  return 0;
}

int nRows(matrix const * mtx, int * n) {
  if (!mtx || !n) return -1;
  *n = mtx->rows;
  return 0;
}

int nCols(matrix const * mtx, int * n) {
  if (!mtx || !n) return -1;
  *n = mtx->cols;
  return 0;
}

int printMatrix(matrix const * mtx) {
  int row, col;

  if (!mtx) return -1;

  for (row = 1; row <= mtx->rows; row++) {
    for (col = 1; col <= mtx->cols; col++) {
      /* Print the floating point element with
       *  - either a - if negative of a space if positive
       *  - at least 3 spaces before the .
       *  - precision to the hundredths place */
      printf("% 6.2f ", getE(mtx, row, col));
    }
    /* separate rows by newlines */
    printf("\n");
  }
  return 0;
}

int transpose(matrix const * in, matrix * out) {
  int row, col;
  if (!in || !out)
    return -1;
  if (in->rows != out->cols || in->cols != out->rows)
    return -2;

  for (row = 1; row <= in->rows; row++)
    for (col = 1; col <= in->cols; col++)
      setE(out, col, row, getE(in, row, col));
  return 0;
}

int sum(matrix const * mtx1, matrix const * mtx2,
        matrix * sum) {
  int row, col;
  if (!mtx1 || !mtx2 || !sum) return -1;
  if (mtx1->rows != mtx2->rows ||
      mtx1->rows != sum->rows ||
      mtx1->cols != mtx2->cols ||
      mtx1->cols != sum->cols)
    return -2;

  for (col = 1; col <= mtx1->cols; col++)
    for (row = 1; row <= mtx1->rows; row++)
      setE(sum, row, col, getE(mtx1, row, col) + getE(mtx2, row, col));
  return 0;
}

int product(matrix const * mtx1, matrix const * mtx2,
            matrix * prod) {
  int row, col, k;
  if (!mtx1 || !mtx2 || !prod) return -1;
  if (mtx1->cols != mtx2->rows ||
      mtx1->rows != prod->rows ||
      mtx2->cols != prod->cols)
    return -2;

  for (col = 1; col <= mtx2->cols; col++)
    for (row = 1; row <= mtx1->rows; row++) {
      double val = 0.0;
      for (k = 1; k <= mtx1->cols; k++)
        val += getE(mtx1, row, k) * getE(mtx2, k, col);
      setE(prod, row, col, val);
    }
  return 0;
}

int dotProduct(matrix const * v1, matrix const * v2,
               double * prod) {
  int i;
  if (!v1 || !v2 || !prod) return -1;
  if (v1->cols != 1 || v2->cols != 1) return -2;
  if (v1->rows != v2->rows) return -3;

  *prod = 0;
  for (i = 1; i <= v1->rows; i++)
    *prod += getE(v1, i, 1) * getE(v2, i, 1);
  return 0;
}

int isSquare(matrix const * mtx) {
  return mtx && mtx->rows == mtx->cols;
}

int identity(matrix * m) {
  int row, col;
  if (!isSquare(m)) return -1;
  for (col = 1; col <= m->cols; col++)
    for (row = 1; row <= m->rows; row++)
      if (row == col)
        setE(m, row, col, 1.0);
      else
        setE(m, row, col, 0.0);
  return 0;
}

int isDiagonal(matrix const * mtx) {
  int row, col;
  if (!isSquare(mtx)) return 0;
  for (col = 1; col <= mtx->cols; col++)
    for (row = 1; row <= mtx->rows; row++)
      if (row != col && getE(mtx, row, col) != 0.0)
        return 0;
  return 1;
}

int isUpperTriangular(matrix const * mtx) {
  int row, col;
  if (!isSquare(mtx)) return 0;
  for (col = 1; col <= mtx->cols; col++)
    for (row = col+1; row <= mtx->rows; row++)
      if (getE(mtx, row, col) != 0.0)
        return 0;
  return 1;
}

int diagonal(matrix const * v, matrix * mtx) {
  int row, col;
  if (!v || !mtx || v->rows != mtx->rows ||
      mtx->rows != mtx->cols)
    return -1;
  for (col = 1; col <= mtx->cols; col++)
    for (row = 1; row <= mtx->rows; row++)
      if (row == col)
        setE(mtx, row, col, getE(v, row, 1));
      else
        setE(mtx, row, col, 0.0);
  return 0;
}

int symmetric(matrix const *mtx){
	int row, col; 
	if(!mtx || !isSquare(mtx)) return 0;
	for(col = 1; col <mtx ->cols; col++)
	  for (row = col + 1; row <= mtx -> rows; row ++)
	    if(getE(mtx, row, col) != getE(mtx, col, row))
	      return 0;
	return -1;
}

matrix *getColumn(matrix const * mtx, int col){
    
    if(!mtx || mtx->cols < col || col <=0) return NULL;
    int row;
    matrix * vct = newMatrix(mtx->rows, 1);
    for (row = 1; row <= mtx -> rows; row ++){
        setE(vct, row, 1, getE(mtx, row, col));
    }
    return vct;
            
}

matrix *getRow(matrix const * mtx, int row){
    if(!mtx || mtx->rows < row || row<=0) return NULL;
    int col;
    matrix * vct = newMatrix(1, mtx->cols);
    for (col = 1; col <= mtx ->cols; col ++)
        setE(vct, 1, col, getE(mtx, row, col));
    return vct;
    
}

int scalarProduct(double s, matrix *mtx){
    if (!mtx) return -1;
    int row, col;
    for (col = 1; col <= mtx->cols; col++)
        for (row = 1; row <= mtx->rows; row++)
            setE(mtx, row, col, s*getE(mtx, row, col));
    return 0;
}