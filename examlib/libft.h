/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 17:40:42 by yyang             #+#    #+#             */
/*   Updated: 2015/01/28 20:42:26 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *s);
int ft_strcmp(char *s1, char *s2);
void ft_strcpy(char *d, char *s);
void ft_strcat(char *d, char *s);
int ft_memcmp(void *s1, void *s2, int n);
char *ft_strstr(char *s, char *needle);
void ft_putchar(char c);
int ft_atoi(char *s);
char *ft_itoa(int n);
int ft_arr_len(void *arr);
void ft_arr_swap(void *arr, int i, int j);
char *ft_strdup(char *s);

#endif
