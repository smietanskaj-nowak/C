#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <gsl\gsl_matrix_double.h>
#include <gsl\gsl_blas.h>
#include <gsl\gsl_linalg.h>
  struct atom{
    int numer;
    int mol;
 double x;
 double y;
 double z;
 double N;
 double C;
 double O;
 double S;
 double ADP;
 double SOF;   
};
std::vector <atom> load_file(const char *s, int *rozmiar);
gsl_matrix * gsl_matrix_invert(gsl_matrix *matrix, size_t size);
int main(void)
{
  int rozmiar;
    std::vector <atom> Hyp_7=load_file("Lista_atomy_Hyp_7_reduced.txt", &rozmiar);
    double base[3][3]={
      {146.29, 0, 0},
      {0, 146.29, 0},
      {0, 0, 42.6514}
      };
  std::vector<atom>::iterator itr=Hyp_7.begin();
  for(int i=0; i<rozmiar; i++){
    for(int j=0; j<3; j++){
      (*itr).x;
    }  
  }
        
    return 0;
}
std::vector <atom> load_file(const char *s, int *rozmiar){
    std::vector <atom> Hyp_7;
    struct atom pozycje;
    double prob, x, y, z, N, C, O, S, SOF, ADP;
    int numer, mol, N_atom=0;
    gsl_matrix *base=gsl_matrix_alloc(3, 3);
    gsl_matrix_set_zero(base);
    gsl_matrix_set(base, 0, 0, 146.29);
    gsl_matrix_set(base, 1, 1, 146.29);
    gsl_matrix_set(base, 2, 2, 42.6514);
    gsl_matrix *base_inv=gsl_matrix_invert(base, 3);
    gsl_vector *r=gsl_vector_alloc(3);
    gsl_vector *r_reduced=gsl_vector_alloc(3);
    FILE *fp = fopen(s, "r");
    if (fp!=NULL){
    while(!feof(fp)){
        N_atom=N_atom+1;
        fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &numer, &mol, &x, &y, &z, &N, &C, &O, &S, &prob, &SOF, &ADP);
        pozycje.numer=numer;
        pozycje.mol=mol;
        pozycje.x=x;
        pozycje.y=y;
        pozycje.z=z;
        pozycje.N=N;
        pozycje.C=C;
        pozycje.O=O;
        pozycje.S=S;
        pozycje.SOF=SOF*prob;
        pozycje.ADP=ADP;
        Hyp_7.push_back(pozycje);
        gsl_vector_set(r, 1, x);
        gsl_vector_set(r, 2, y);
        gsl_vector_set(r, 3, z);
        gsl_blas_dgemv(CblasNoTrans, 1, base_inv, r, 0, r_reduced);
        pozycje.x=gsl_vector_get(r, 1);
        pozycje.y=gsl_vector_get(r, 2);
        pozycje.z=gsl_vector_get(r, 3);
        Hyp_7.push_back(pozycje);
        printf("%f %f %f\n", pozycje.x, pozycje.y, pozycje.z);
        
                }
              }
    else {
      printf("Failure");
    }
    fclose(fp);
    *rozmiar=N_atom;
    return Hyp_7;
}
gsl_matrix * gsl_matrix_invert(gsl_matrix *matrix, size_t size)
{
    gsl_permutation *p = gsl_permutation_alloc(size);
    int s;

    // Compute the LU decomposition of this matrix
    gsl_linalg_LU_decomp(matrix, p, &s);

    // Compute the  inverse of the LU decomposition
    gsl_matrix *inv = gsl_matrix_alloc(size, size);
    gsl_linalg_LU_invert(matrix, p, inv);

    gsl_permutation_free(p);

    return inv;
}
