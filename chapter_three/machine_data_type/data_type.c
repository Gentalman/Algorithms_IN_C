#include <stdio.h>
#include <limits.h>
#include <float.h>

/* printf data type's value range include signed and
   unsigned char, short int, long int, int, float, double */
main()
{
	printf("The signed char value range is %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("The unsigned char value range is %u ~ %u\n", 0, UCHAR_MAX);

	printf("The signed short int value range is %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("The unsigned short int value range is %u ~ %u\n", 0, USHRT_MAX);

	printf("The signed int value range is %d ~ %d\n", INT_MIN, INT_MAX);
	printf("The unsigned int value range is %u ~ %u\n", 0, UINT_MAX);

	printf("The signed long int value range is %ld ~ %ld\n", LONG_MIN, LONG_MAX);
	printf("The unsigned long int value range is %u ~ %lu\n", 0, ULONG_MAX);

	printf("The float value range is %f ~ %f\n", FLT_MIN, FLT_MAX);

	printf("The double value range is %f ~ %f\n", DBL_MIN, DBL_MAX);

	return 0;
}
