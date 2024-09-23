/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanbaek <sanbaek@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:07:16 by sanbaek           #+#    #+#             */
/*   Updated: 2024/09/05 15:07:16 by sanbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

// int main(void)
// {
// 	int i = 0;
// 	while (i++ < 10)
// 	{
// 		char *str = ft_split("   lorem   ipsum dolor      ", ' ')[i]
// 		printf("%s", str);
// 	}
// 	// strlcat
// 		// size_t size = 0;
// 		// size_t size2 = size;
// 		// char *dest = NULL;
// 		// char *dest2 = NULL;
// 		// const char *src = "1234567";
// 		// const char *src2 = "1234567";
// 		// // // char dest[99] = "ABCDEABCDE";
// 		// // char dest2[99] = "ABCDEABCDE";
// 		// // char dest[99] = "";
// 		// // char *dest = NULL;
// 		// // char dest2[99] = "ABCDEABCDE";
// 		// // char dest2[99] = "";
// 		// // const char *src = "1234567";
// 		// // const char *src = NULL;
// 		// // const char *src = NULL;
// 		// // const char *src2 = NULL;
// 		// // const char *src2 = NULL;
// 		// printf("\n");
// 		// printf("실행전\n");
// 		// printf("dest : %s\n", dest);
// 		// printf("src : %s\n", src);
// 		// printf("size : %zu\n", size);
// 		// printf("\n");
// 		// printf("strlcat\n");
// 		// printf("반환값 : %lu\n", strlcat(dest, src, size));
// 		// printf("dest  : %s\n", dest);
// 		// printf("src   : %s\n", src);
// 		// printf("\n");
// 		// printf("ft_strlcat\n");
// 		// printf("반환값 : %zu\n", ft_strlcat(dest2, src2, size2));
// 		// printf("dest2  : %s\n", dest2);
// 		// printf("src2   : %s\n", src2);
// 		// printf("\n");

// 	// strcmp
// 		// char lhs[99] = "aaaaaaa";
// 		// char rhs[99] = "aaadefg";
// 		// int count = 0;
// 		// while (count++ < 8)
// 		// {
// 		//   printf("\n");
// 		//   printf("strncmp    : %d\n", strncmp(lhs, rhs, count));
// 		//   printf("ft_strncmp : %d\n", ft_strncmp(lhs, rhs, count));
// 		// }

// 	// substr
// 		// char *s = "12345";
// 		// unsigned int start = 10;
// 		// size_t len = 5;
//
// 		// // char *s2 = "12345";
// 		// // unsigned int start2 = 10;
// 		// // size_t len2 = 5;
// 		// printf("\n");
// 		// printf("실행전\n");
// 		// printf("s : %s\n", s);
// 		// printf("start : %d\n", start);
// 		// printf("len : %lld\n", len);
// 		// printf("\n");
// 		// printf("substr\n");
// 		// printf("반환값 : %s\n", ft_substr(s, start, len));
// 		// printf("start  : %d\n", start);
// 		// printf("len   : %lld\n", len);
// 		// printf("\n");
// 		// printf("ft_substr\n");
// 		// printf("반환값 : %s\n", ft_substr(s2, start2, len2));
// 		// printf("start2  : %d\n", start2);
// 		// printf("len2   : %ld\n", len2);
// 		// printf("\n");

// 	return (0);
// }

//atoi
// int main(void)
// {
// 	ft_printf("\n----------------------\n");
// 	ft_printf("%d\n", ft_atoi("       +2147483647"));
// 	ft_printf("----------------------\n\n");
// 	return (0);
// }

//memset
// int main(void)
// {
// 	char *str;
// 	str = (char *)malloc(11 * sizeof(char));
// 	ft_memset(str, 't', 11);
// 	str[10] = '\0';
// 	ft_printf("\n----------------------\n");
// 	printf("%s\n", str);
// 	ft_printf("----------------------\n\n");
// 	free(str);
// }

//bzero
// int main(void)
// {
// 	char *str;
// 	str = (char *)malloc(11 * sizeof(char));
// 	char *str2;
// 	str2 = (char *)malloc(11 * sizeof(char));
// 	ft_memset(str, 'a', 10);
// 	ft_memset(str2, 'B', 10);
// 	str[10] = '\0';
// 	str2[10] = '\0';
// 	ft_bzero(str, 3);
// 	int i = 3;
// 	str2[i] = str[i];
// 	ft_printf("\n----------------------\n");
// 	ft_printf("%s\n", str);
// 	ft_printf("%s\n", str2);
// 	ft_printf("----------------------\n\n");
// 	free(str);
// 	free(str2);
// }

//itoa
// int main(void)
// {
// 	char *str;
// 	str = ft_itoa(2147483649);
// 	printf("\n----------------------\n");
// 	printf("%s\n", str);
// 	printf("----------------------\n\n");
// 	free(str);
// 	return (0);
// }

//memchr
// int main(void)
// {
// 	char *str;
// 	str = ft_memchr("1234567890", '5', 10);
// 	printf("\n----------------------\n");
// 	printf("%s\n", str);
// 	printf("----------------------\n\n");
// 	return (0);
// }

//memcmp
// int main(void)
// {
// 	int n;
// 	n = ft_memcmp("1234567890", "1234500000", 10);
// 	printf("\n----------------------\n");
// 	printf("%d\n", n);
// 	printf("----------------------\n\n");
// 	return (0);
// }

//memcpy
// int main(void)
// {
// 	char *str1;
// 	char *str2;
// 	char *str3;
// 	printf("\n----------------------\n");
// 	str1 = (char *)ft_calloc(11, 1);
// 	ft_memcpy(str1, "abcdeABCDE", 11);
// 	printf("%s\n", str1);
// 	str2 = (char *)ft_calloc(11, 1);
// 	ft_memcpy(str2, "12345FGHIJ", 11);
// 	printf("%s\n", str2);
// 	ft_memcpy(str1, str2, 10);
// 	printf("%s\n", str1);
// 	free(str1);
// 	free(str2);
// 	printf("----------------------\n\n");
// 	return (0);
// }

// memmove
// int main(void)
// {
// 	char *str1;
// 	char *str2;
// 	char *str3;
// 	printf("\n----------------------\n");
// 	str1 = (char *)ft_calloc(11, 1);
// 	ft_memmove(str1, "ABCDEABCDE", 11);
// 	printf("str1 : %s\n", str1);
// 	str2 = (char *)ft_calloc(11, 1);
// 	ft_memmove(str2, "abcdeabcde", 11);
// 	printf("str2 : %s\n", str2);
// 	// ft_memmove(str1, str2, 10);
// 	// ft_memmove(str1, str2, 5);
// 	ft_memmove(str1, str2, 1);
// 	printf("\nresult %s\n", str1);
// 	free(str1);
// 	free(str2);
// 	printf("----------------------\n\n");
// 	return (0);
// }

// split
// int main(void)
// {
// 	ft_printf("\n----------------------\n");
// 	char *str1;
// 	char **words;
// 	int i = 3;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCDE abcde 12345", 18);
// 	ft_printf("str1 : %s\n\n", str1);
// 	words = ft_split(str1, ' ');
// 	// while (i < 3)
// 	// {
// 	// 	ft_printf("%s\n", words[i]);
// 	// 	i++;
// 	// }
// 	free(str1);
// 	while (i)
// 		free(words[i--]);
// 	free(words[0]);
// 	free(words);
// 	printf("----------------------\n\n");
// 	return (0);
// }

// strchr
// int main(void)
// {
// 	ft_printf("\n----------------------\n");
// 	char *str1;
// 	char *str2;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCDE abcde 12345", 18);
// 	ft_printf("str1 : %s\n\n", str1);
// 	str2 = ft_strchr(str1, ' ');
// 	ft_printf("str2 : %s\n", str2);
// 	free(str1);
// 	printf("----------------------\n\n");
// 	return (0);
// }

// strdup
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str1;
// 	char *str2;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCDE abcde 12345", 18);
// 	ft_printf("str1 : %s\n", str1);
// 	str2 = ft_strdup(str1);
// 	ft_printf("str2 : %s\n", str2);
// 	free(str1);
// 	free(str2);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

// striteri
// 문자열에서 문자와 인덱스를 함수에 전달함
// 매 인덱스마다에 대해 함수를 실행
// void test_striteri(unsigned int index, char *c)
// {
// 	*c = *c + 1;
// }
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str1;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCDE abcde 12345", 18);
// 	ft_printf("str1 : %s\n", str1);
// 	ft_striteri(str1, test_striteri);
// 	ft_printf("str1 : %s\n", str1);
// 	free(str1);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

// strjoin
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str1;
// 	char *str2;
// 	char *str3;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCDE abcde 12345", 18);
// 	ft_printf("str1 : %s\n", str1);
// 	str2 = ft_strdup(str1);
// 	ft_printf("str2 : %s\n", str2);
// 	str3 = ft_strjoin(str1, str2);
// 	ft_printf("str3 : %s\n", str3);
// 	free(str1);
// 	free(str2);
// 	free(str3);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

// strlcat
// int main(void)
// {
// 	printf("\n----------------------\n");
// 	char *str1;
// 	char *str2;
// 	char *str3;
// 	str1 = (char *)ft_calloc(16, 1);
// 	ft_memmove(str1, "ABCDE", 6);
// 	ft_printf("str1 : %s\n", str1);
// 	str2 = (char *)ft_calloc(11, 1);
// 	ft_memmove(str2, "abcdeabcde", 11);
// 	ft_printf("str2 : %s\n", str2);
// 	ft_strlcat(str1, str2, 9);
// 	printf("\nresult %s\n", str1);
// 	free(str1);
// 	free(str2);
// 	ft_printf("----------------------\n\n");
// 	return (0);
// }

// strlcpy
// void test_striteri(unsigned int index, char *c)
// {
// 	*c = *c + 1;
// }
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str1;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCDE abcde 12345", 18);
// 	ft_printf("str1 : %s\n", str1);
// 	ft_striteri(str1, test_striteri);
// 	ft_printf("str1 : %s\n", str1);
// 	free(str1);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

//strmapi
// char test_strmapi(unsigned int index, char c)
// {
// 	c = c + 1;
// 	return (c);
// }
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str1;
// 	char *str2;
// 	unsigned int i;
// 	i = 0;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCDE abcde 12345", 18);
// 	ft_printf("str1 : %s\n", str1);
// 	str2 = ft_strmapi(str1, test_strmapi);
// 	ft_printf("str2 : %s\n", str2);
// 	free(str1);
// 	free(str2);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

//strncmp
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str1;
// 	char *str2;
// 	int n;
// 	n = 0;
// 	str1 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str1, "ABCD abcd 1234", 15);
// 	ft_printf("str1 : %s\n", str1);
// 	str2 = (char *)ft_calloc(18, 1);
// 	ft_memmove(str2, "ABCD abcd 9234", 15);
// 	ft_printf("str2 : %s\n", str2);
// 	n = ft_strncmp(str1, str2, 11);
// 	ft_printf("n : %d\n", n);
// 	free(str1);
// 	free(str2);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

//strnstr
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *big;
// 	char *little;
// 	char *find;
// 	int n;
// 	n = 0;
// 	big = (char *)ft_calloc(10, 1);
// 	ft_memmove(big, "abcd 1234", 10);
// 	ft_printf("big : %s\n", big);
// 	little = (char *)ft_calloc(5, 1);
// 	ft_memmove(little, "1235", 5);
// 	ft_printf("little : %s\n", little);
// 	find = ft_strnstr(big, little, 11);
// 	ft_printf("find : %s\n", find);
// 	free(big);
// 	free(little);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

//strrchr
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str;
// 	char c = '3';
// 	char *find;
// 	str = (char *)ft_calloc(5, 1);
// 	ft_memmove(str, "3235", 5);
// 	ft_printf("str : %s\n", str);
// 	find = ft_strrchr(str, c);
// 	ft_printf("find : %s\n", find);
// 	free(str);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

//strtrim
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str = "    ABq423423ABABABAB a  BABAB";
// 	char *set = "A B";
// 	char *trimed;
// 	ft_printf("str			: %s\n", str);
// 	ft_printf("set			: %s\n", set);
// 	trimed = ft_strtrim(str, set);
// 	ft_printf("trimed	: %s\n", trimed);
// 	// free(str);
// 	printf("---------------------------\n\n");
// 	return (0);
// }

// strtrim
// int main(void)
// {
// 	ft_printf("\n---------------------------\n");
// 	char *str;
// 	char *sub;
// 	unsigned int start;
// 	size_t len;
// 	str = (char *)ft_calloc(10, 1);
// 	ft_memmove(str, "abcd 1234", 10);
// 	start = 3;
// 	len = 5;
// 	ft_printf("str : %s\n", str);
// 	sub = ft_substr(str, start, len);
// 	ft_printf("sub : %s\n", sub);
// 	free(str);
// 	free(sub);
// 	printf("---------------------------\n\n");
// 	return (0);
// }
