/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:18:03 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/10 13:18:05 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	frame0(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "  ██████╗ ███████╗██████╗ ██████╗ ███████╗"
		   "██████╗ ███████╗       _.---._       \n"
		   "  ██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝"
		   "██╔══██╗██╔════╝   .\'\"\".\'/|\\`.\"\"\'.\n"
		   "  ██████╔╝█████╗  ██████╔╝██████╔╝█████╗  "
		   "██████╔╝█████╗    :  .' / | \\ `.  :	\n"
		   "  ██╔═══╝ ██╔══╝  ██╔═══╝ ██╔═══╝ ██╔══╝  "
		   "██╔══██╗██╔══╝    '.'  /  |  \\  `.'	\n"
		   "  ██║     ███████╗██║     ██║     ███████╗"
		   "██║  ██║███████╗   `. /   |   \\ .'	\n"
		   "  ╚═╝     ╚══════╝╚═╝     ╚═╝     ╚══════╝"
		   "╚═╝  ╚═╝╚══════╝     `-.__|__.-'		\n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "CC_CYN
		   "tutti"CC_WHT " & "CC_CYN "nessuno"CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}

void	frame1(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "███████╗██████╗ ██████╗ ███████╗██████╗ "
		   "███████╗       _.---._        ██████╗\n"
		   "██╔════╝██╔══██╗██╔══██╗██╔════╝██╔══██╗"
		   "██╔════╝   .\'\"\".\'/|\\`.\"\"\'.    ██╔══██╗\n"
		   "█████╗  ██████╔╝██████╔╝█████╗  ██████╔╝"
		   "█████╗    :  .' / | \\ `.  :   ██████╔╝\n"
		   "██╔══╝  ██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══██╗"
		   "██╔══╝    '.'  /  |  \\  `.'   ██╔═══╝ \n"
		   "███████╗██║     ██║     ███████╗██║  ██║"
		   "███████╗   `. /   |   \\ .'    ██║     \n"
		   "╚══════╝╚═╝     ╚═╝     ╚══════╝╚═╝  ╚═╝"
		   "╚══════╝     `-.__|__.-'      ╚═╝     \n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}

void	frame2(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "██████╗ ██████╗ ███████╗██████╗ ███████╗"
		   "         _.---._        ██████╗ ███████╗\n"
		   "██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝"
		   "     .\'\"\".\'/|\\`.\"\"\'.    ██╔══██╗██╔════╝\n"
		   "██████╔╝██████╔╝█████╗  ██████╔╝█████╗  "
		   "    :  .' / | \\ `.  :   ██████╔╝█████╗  \n"
		   "██╔═══╝ ██╔═══╝ ██╔══╝  ██╔══██╗██╔══╝  "
		   "    '.'  /  |  \\  `.'   ██╔═══╝ ██╔══╝  \n"
		   "██║     ██║     ███████╗██║  ██║███████╗"
		   "     `. /   |   \\ .'    ██║     ███████╗\n"
		   "╚═╝     ╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝"
		   "       `-.__|__.-'      ╚═╝     ╚══════╝\n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}

void	frame3(void)
{
	write(1, "\r\033[2K", 5);
	printf("\n" CC_BHYEL
		   "██████╗ ███████╗██████╗ ███████╗  "
		   "     _.---._        ██████╗ ███████╗██████╗ \n"
		   "██╔══██╗██╔════╝██╔══██╗██╔════╝  "
		   " .\'\"\".\'/|\\`.\"\"\'.    ██╔══██╗██╔════╝██╔══██╗\n"
		   "██████╔╝█████╗  ██████╔╝█████╗    "
		   ":  .' / | \\ `.  :   ██████╔╝█████╗  ██████╔╝\n"
		   "██╔═══╝ ██╔══╝  ██╔══██╗██╔══╝    "
		   "'.'  /  |  \\  `.'   ██╔═══╝ ██╔══╝  ██╔═══╝ \n"
		   "██║     ███████╗██║  ██║███████╗  "
		   " `. /   |   \\ .'    ██║     ███████╗██║     \n"
		   "╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝  "
		   "   `-.__|__.-'      ╚═╝     ╚══════╝╚═╝     \n"
		   CC_WHT "\t\t\t\t\t\t       Fatto da "
		   CC_CYN "tutti"
		   CC_WHT " & "
		   CC_CYN "nessuno"
		   CC_RESET "\n"
		   "                          PREMI CTRL + \\ O "
		   "PREMI CTRL + C                            \n");
}
