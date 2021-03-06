/************************************************************************/
/* matrix.h, matriisi-kamat.                                            */
/************************************************************************/
/* special kiitokset icalle ja otm:lle.                                 */
/************************************************************************/

#ifndef _chem_matrix_h
#define _chem_matrix_h


/************************************************************************/
/* includes:                                                            */
/************************************************************************/
#include "bstructs.h"


/************************************************************************/
/* kertoo kaksi matriisia kesken��n ja palauttaa tuloksen matriisissa a */
/************************************************************************/
void matriisi_kerro(matriisi a, matriisi b) /* return to a */
{
  matriisi tmp;
  int i, j;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      tmp[i][j] = a[i][0] * b[0][j] +
                  a[i][1] * b[1][j] +
                  a[i][2] * b[2][j];
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
      a[i][j] = tmp[i][j];
/* 3dica:
   � a b c �   � k l m �   � ak+bn+cq al+bo+cr am+bp+cs �
   � d e f � * � n o p � = � dk+en+fq dl+eo+fr dm+ep+fs �
   � h i j �   � q r s �   � hk+in+jq hl+io+jr hm+ip+js �
*/
}


/************************************************************************/
/* kertoo vektorin matriisilla.                                         */
/************************************************************************/
inline void vektori_kertaa_matriisi(vertextype vekto, vertextype *result, matriisi mat)
{
 vertextype vek = vekto;

 result->x = mat[0][0] * vek.x + mat[1][0] * vek.y + mat[2][0] * vek.z;
 result->y = mat[0][1] * vek.x + mat[1][1] * vek.y + mat[2][1] * vek.z;
 result->z = mat[0][2] * vek.x + mat[1][2] * vek.y + mat[2][2] * vek.z;

/*
 3dica:
                � a b c 0 �
   (Xi+Yj+Zk) * � e f g 0 � = (aX+eY+iZ+m)i + (bX+fY+jZ+n)j +
                � i j k 0 �   (cX+gY+kZ+o)k
                � m n o 1 �
*/
}

/************************************************************************/
/* tekee py�ritysmatriisin.                                             */
/************************************************************************/
void teepyoritysmatriisi(matriisi m, float sx, float sy, float sz,
                         float cx, float cy, float cz)
{
 m[0][0] = cy * cz;
 m[0][1] = cy * sz;
 m[0][2] = -sy;

 m[1][0] = sx * sy * cz - cx * sz;
 m[1][1] = sx * sy * sz + cx * cz;
 m[1][2] = sx * cy;

 m[2][0] = cx * sy * cz + sx * sz;
 m[2][1] = cx * sy * sz - sx * cz;
 m[2][2] = cx * cy;

/*3dica:
                     � cy*cz          cy*sz          -sy    0 �
                     � sx*sy*cz-cx*sz sx*sy*sz+cx*cz  sx*cy 0 �
       [X]*[Y]*[Z] = � cx*sy*cz+sx*sz cx*sy*sz-sx*cz  cx*cy 0 �
                     � 0              0               0     1 �
*/
}


/************************************************************************/
/* alustaa matriisin tyhj�ksi.                                          */
/************************************************************************/
void teetyhjamatriisi(matriisi m)
{
 m[0][0] = 1; m[1][0] = 0; m[2][0] = 0;
 m[0][1] = 0; m[1][1] = 1; m[2][1] = 0;
 m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
/* 3dica:
     � 1 0 0 0 �
     � 0 1 0 0 �
     � 0 0 1 0 �
     � 0 0 0 1 �
*/
}

#endif
