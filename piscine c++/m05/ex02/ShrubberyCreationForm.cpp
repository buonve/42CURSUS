/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 12:38:42 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/08/13 12:38:42 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("shrubbery", 137, 145)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form): Form(form)
{
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const
{
	return(_target);
}

void ShrubberyCreationForm::execute() const
{
	std::string filename;
	filename = this->getTarget() + "_shruberry";
	std::ofstream outfile(filename.c_str(), std::ios::out);
	outfile <<	"###########################\'`################################\n" <<
				"###########################  V##\'############################\n" <<
				"#########################V\'  `V  ############################\n" <<
				"########################V\'      ,############################\n" <<
				"#########`#############V      ,A###########################V\n" <<
				"########\' `###########V      ,###########################V\',#\n" <<
				"######V\'   ###########l      ,####################V~~~~\'\',###\n" <<
				"#####V\'    ###########l      ##P\' ###########V~~\'   ,A#######\n" <<
				"#####l      d#########l      V\'  ,#######V~\'       A#########\n" <<
				"#####l      ##########l         ,####V\'         ,###########\n" <<
				"#####l        `V######l        ,###V\'   .....;A##############\n" <<
				"#####A,         `######A,     ,##V\' ,A#######################\n" <<
				"#######A,        `######A,    #V\'  A########\'##########\'\n" <<
				"##########,,,       `####A,           `#\'           \'  ,,,\n" <<
				"#############A,                               ,,,     ,######\n" <<
				"######################oooo,                 ;####, ,#########\n" <<
				"##################P\'                   A,   ;#####V##########\n" <<
				"#####P\'    \'       ,###             `#,     `V############\n" <<
				"##P\'                ,d###;              ##,       `V#########\n" <<
				"##########A,,   #########A              )##,    ##A,..,ooA###\n" <<
				"#############A, Y#########A,            )####, ,#############\n" <<
				"###############A ############A,        ,###### ##############\n" <<
				"###############################       ,#######V##############\n" <<
				"###############################      ,#######################\n" <<
				"##############################P    ,d########################\n" <<
				"##############################\'    d#########################\n" <<
				"##############################     ##########################\n" <<
				"##############################     ##########################\n" <<
				"#############################P     ##########################\n" <<
				"#############################\'     ##########################\n" <<
				"############################P      ##########################\n" <<
				"###########################P\'     ;##########################\n" <<
				"###########################\'     ,###########################\n" <<
				"##########################       ############################\n" <<
				"#########################       ,############################\n" <<
				"########################        d###########P\'    `Y#########\n" <<
				"#######################        ,############        #########\n" <<
				"######################        ,#############        #########\n" <<
				"#####################        ,##############b.    ,d#########\n" <<
				"####################        ,################################\n" <<
				"###################         #################################\n" <<
				"##################          #######################P\'  `V##P\'\n" <<
				"#######P\'     `V#           ###################P\'\n" <<
				"#####P\'                    ,#################P\'\n" <<
				"###P\'                      d##############P\'\n" <<
				"##P\'                       V##############\'\n" <<
				"#P\'                         `V###########\'\n" <<
				"#\'                             `V##P\' 		--- VBUONVIN ---" << std::endl;
}



