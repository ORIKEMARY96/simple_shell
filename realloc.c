#include "main."

/**
 * _realloc - reallocates new mem block
 * @ptr: pointer to memory block
 * @old_size: sizein bytes
 * @new_size: new size in bytes
 * Return: new size
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *old_ptr;

	char *new_ptr_chr;

	void *new_ptr;

	unsigned int i, min_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	min_size = (old_size < new_size) ? old_size : new_size;

	old_ptr = (char *)ptr;
	new_ptr_char = (char *)new_ptr;

	for (i = 0; i < min_size; i++)
	{
		new_ptr_char[i] = old_ptr[i];
	}
	free(ptr);
	return (new_ptr);
}
