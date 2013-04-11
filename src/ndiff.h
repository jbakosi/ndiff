#ifndef NDIFF_H
#define NDIFF_H

/*
 o---------------------------------------------------------------------o
 |
 | Numdiff
 |
 | Copyright (c) 2012+ laurent.deniau@cern.ch
 | Gnu General Public License
 |
 o---------------------------------------------------------------------o
  
   Purpose:
     numerical diff of files
     provides the main numdiff loop
 
 o---------------------------------------------------------------------o
*/

#include <stdio.h>
#include "types.h"

// ----- types

struct utest;
struct ndiff;
struct context;
struct constraint;

// ----- interface

#define T struct ndiff
#define C struct constraint

T*    ndiff_alloc    (FILE *lhs, FILE *rhs, struct context*, int n_);
void  ndiff_clear    (T*);
void  ndiff_free     (T*);
void  ndiff_option   (T*, const int *keep_, const int *blank_, const int *check_);

// high level API
void  ndiff_loop     (T*);

// low level API
int   ndiff_skipLine (T*);
int   ndiff_readLine (T*);
int   ndiff_fillLine (T*, const char *lhs, const char *rhs);

int   ndiff_gotoLine (T*, const C*);
int   ndiff_gotoNum  (T*, const C*);

int   ndiff_nextNum  (T*, const C*); // return 0 if no number is found
int   ndiff_testNum  (T*, const C*, double scl); // scale the difference

void  ndiff_getInfo  (const T*, int *row_, int *col_, int *cnt_, long *num_);
int   ndiff_feof     (const T*, int both);
int   ndiff_isempty  (const T*);

#undef T
#undef C

// ----- testsuite

#ifndef NTEST

void ndiff_utest (struct utest*);

#endif // NTEST
#endif
