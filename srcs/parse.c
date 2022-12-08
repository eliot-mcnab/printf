/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:11:35 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/08 11:10:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

/**
 * @brief Parses a string as of a valid modifer, as described by ft_ismod(char).
 *
 * Stores any modifier arguments associated to the current argument into
 * moddata, where a modifier argument is an int value associated to the
 * modifier. Arguments are stored in moddata by modifier index, as specified by
 * t_e_modifier.
 *
 * @param str (cosnt char **): double pointer to the string being parsed. Must
 *        point to the first character to occurr after a modifier.
 * @param mod (t_e_modifier): the modifier for which to parse arguments.
 * @param moddata (int *): modifer data array. Stores parametes associated to
 *        each modifier, should they occurr in the current format.
 *
 * @author Eliot McNab
 * @date 12/08/2022
 */
static void	ft_parse_moddata(const char **str, t_e_modifier mod, int *moddata)
{
	while (ft_isdigit(**str))
	{
		moddata[mod] = moddata[mod] * 10 + ft_todigit(**str);
		(*str)++;
	}
	(*str)--;
}

/**
 * @brief Parses a string as of a FORM_INDICATOR and hashes the parsed format
 *        and modifiers into a formdata 32-bit representation.
 *
 * Formdata consists of two bytes, where the first byte is a hash of the 
 * parsed modifiers and the second byte is the indexe associated to of format as
 * specified in the t_e_format enum. Retrieval of the format is done through a
 * binary & with 0xFF.
 *
 * Parsing stops at the first character in str which is not a modifier, a
 * modifier argument or a format.
 *
 * @param str (cosnt char **): double pointer to the string being parsed. Must
 *        point to the first character after a FORM_INDICATOR.
 * @param moddata (int *): modifer data array. Stores parametes associated to
 *        each modifier, should they occurr in the current format.
 *
 * @return (short): formdata 32-bit representation of parsed format and
 *         modifiers. 0 if a format error occurred.
 *
 * @author Eliot McNab
 * @date 12/08/2022
 */
static short	ft_parse_formdata(const char **str, int *moddata)
{
	char			modgroup;
	t_e_format		format;
	t_e_modifier	modifier;

	if (!str || !*str)
		return (FORMAT_NONE);
	modgroup = 0;
	format = FORMAT_NONE;
	modifier = MODIFIER_NONE;
	while (format == FORMAT_NONE)
	{
		if (ft_ismod(**str))
		{
			modifier = ft_get_modidifier(**str);
			modgroup = ft_modify(modgroup, modifier);
		}
		else if (ft_isdigit(**str))
			ft_parse_moddata(str, modifier, moddata);
		else
			format = ft_get_format(**str);
		(*str)++;
	}
	return (ft_formdata(modgroup, format) * (format != FORMAT_NONE));
}

/**
 * @brief Parses string as of a FORM_INDICATOR and stores parsed data into a
 *        t_s_printdata struct.
 *
 * Printdata structs contain all the data necessary for formatter function to
 * convert a specific format to a string and add it to the buffer.
 *
 * @param str (const char **): must point to a FORM_INDICATOR in the string
 *        being parsed.
 * @param moddata (int *): modifer data array. Stores parametes associated to
 *        each modifier, should they occurr in the current format.
 * @param valist (va_list *): pointer to the variable argument list used to
 *        retrieve the value to format.
 * @param buffer (t_s_buffer *): buffer used to display format.
 *
 * @return (t_s_printdata *): struct of data used to display current format.
 *
 * @author Eliot McNab
 * @date 12/08/2022
 */
static t_s_printdata	*ft_parse_printdata(
		const char **str,
		int *moddata,
		va_list *valist,
		t_s_buffer *buffer)
{
	short	formatdata;

	if (!str || !*str)
		return (NULL);
	(*str)++;
	formatdata = ft_parse_formdata(str, moddata);
	if (!formatdata)
		return (NULL);
	return (ft_printdata(formatdata, moddata, valist, buffer));
}

/**
 * @brief Parses a string for FORM_INDICATORs and replaces those by the
 *        specified format.
 *
 * Whenever a FORM_INDICATOR is found, tries to extract the format directly
 * after it. Format is displayed using a formatter function specific to that
 * format. Formatter functions handle converting each format to a string and
 * adding it to the buffer. Parsing stops when the end of the string has been 
 * reached or an error has occurred. These can be a PARSE_ERROR if an invalid
 * format was detected or a WRITE_ERROR if buffer was unable to write to STDOUT.
 *
 * @param str (const char *): the format sting to parse.
 * @param valist (va_list): list of arguments passed to ft_printf.
 *
 * @return (ssize_t): total number of character written by to ft_printf buffer
 *         over parsing lifecycle. Error code if negative.
 *
 * @see ft_printf(const char *, ...)
 * @see errors.h
 * @see formatters.h
 * @see formdata.h
 *
 * @author Eliot McNab
 * @date 12/08/2022
 */
ssize_t	ft_parse(const char *str, va_list *valist)
{
	t_s_buffer		*buffer;
	int				moddata[MODIFIER_SIZE];
	t_s_printdata	*printdata;

	buffer = ft_buffinit();
	ft_bzero(moddata, MODIFIER_SIZE * sizeof(*moddata));
	printdata = 0;
	while (*str)
	{
		while (*str == FORM_INDICATOR)
		{
			printdata = ft_parse_printdata(&str, moddata, valist, buffer);
			if (!printdata)
			{
				ft_buffclose(buffer);
				return (PARSE_ERROR);
			}
			ft_apply_format(printdata);
			free(printdata);
		}
		if (*str && ft_buffadd(buffer, *str) < 0)
			return (WRITE_ERROR);
		str += (*str != '\0');
	}
	return (ft_buffclose(buffer));
}
