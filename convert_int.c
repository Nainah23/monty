#include <stdlib.h>
/**
 * int_get - gets a new char *string with an integer
 * @number: number to be conerted to a string
 * Return: new char *string and NULL if fail
 */
char *int_get(int number)
{
	char *ret;
	long number_1 = 0;
	unsigned int tmp;
	int len = 0;

	tmp = _abs(number);
	len = get_bufLen(tmp, 10);

	if (number < 0 || number_1 < 0)
		len++;
	ret = malloc(len + 1);

	if (!ret)
		return (NULL);

	buff_fill(tmp, 10, ret, len);
	if (number < 0 || number_1 < 0)
		ret[0] = '-';
	return (ret);
}

 /**
  * get_bufLen - Retrieves the length of the buffer
  * required for an unsigned integer.
  * @number: The number for which the length is to be determined.
  * @base: The base of the number representation used by the buffer.
  * Return: An integer indicating the length of the buffer
  * needed (excluding the null byte)
  */
int get_bufLen(unsigned int number, unsigned int base)
{
	int length = 1;

	while (number > base - 1)
	{
		length++;
		number /= base;
	}
	return (length);
}
/**
 * _abs - give an interger's absolute value
 * @x: int to get its absolute value
 * Return: unsigned int absolute val of x
 */
unsigned int _abs(int x)
{
	if (x < 0)
		return (-(unsigned int)x);
	return ((unsigned int)x);
}
/**
 * buff_fill - up to base 36, all buffers are filled with correct
 * numbers
 * @number: integer to be converted to string
 * @numbase: number base during conversion
 * @buffer: buffer to store the conversion result
 * @buff_len: byte-size of buffer
 * return: void
 */
void buff_fill(unsigned int number, unsigned int numbase,
		 char *buffer, int buff_len)
{
	int x;
	int y = buff_len - 1;

	buffer[buff_len] = '\0';
	while (y >= 0)
	{
		x = number % numbase;
		if (x > 9)
			buffer[y] = x + 87;
		else
			buff[y] = x + '\0';
		number /= numbase;
		y--;
	}
}
