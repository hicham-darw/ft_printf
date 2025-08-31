char	*ft_strcat_one_char(char *dest, char c)
{
	int	len;

	if (!dest)
		return (0);
	len = 0;
	while (dest[len])
		len++;
	dest[len++] = c;
	dest[len] = '\0';
	return (dest);
}
