/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alletond <alletond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:46:51 by alletond          #+#    #+#             */
/*   Updated: 2023/11/02 16:23:39 by alletond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		check_error(int fd, char **stack);
char	*stackcut(char *stack, int pos);
char	*get_next_line(int fd);
char	*fill_stack(char *stack, int fd, int *readret);
int		check_line(char *str);
char	*ft_strndup_custom(const char *s, size_t pos);
//int		ft_strlen(const char *str);
//char	*ft_strjoin(char *s1, char *s2);

#endif