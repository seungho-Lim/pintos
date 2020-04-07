#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define f (1<<14)
#define INT_MAX ((1<<31)-1)
#define INT_MIN (-(1<<31))

// All x,y is represent fixed point number in 17.14 format.
// All n is integer.
int int_to_fp(int n);			/* Change integer to fixed point. */
int fp_to_int(int x);			/* Change fixed point to integer using round toward zero. */
int fp_to_int_round(int x);		/* Change fixed point to integer using round to nearest. */
int add_fp(int x, int y);		/* Add x and y. */
int add_mixed(int x, int n);		/* Add x and n. */
int sub_fp(int x, int y);		/* Subtract x from y.*/
int sub_mixed(int x, int n);		/* Subtract x from n.*/
int mult_fp(int x, int y);		/* Multifly x by y.*/
int mult_mixed(int x, int n);		/* Multifly x by n.*/
int div_fp(int x, int y);		/* Divide x by y. */
int div_mixed(int x, int n);		/* Divide x by n. */

int int_to_fp(int n)
{
  return n*f;
}
int fp_to_int(int x)
{
  return x/f;
}
int fp_to_int_round(int x)
{
  return (x>=0)?(x+f/2)/f : (x-f/2)/f;
}
int add_fp(int x, int y)
{
  return x+y;
}
int add_mixed(int x, int n)
{
  return x+n*f;
}
int sub_fp(int x, int y)
{
  return x-y;
}
int sub_mixed(int x, int n)
{
  return x-n*f;
}
int mult_fp(int x, int y)
{
  return ((int64_t)x)*y/f;
}
int mult_mixed(int x, int n)
{
  return x*n;
}
int div_fp(int x, int y)
{
  return ((int64_t)x)*f/y;
}
int div_mixed(int x, int n)
{
  return x/n;
}

#endif
