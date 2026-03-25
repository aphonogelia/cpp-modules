/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:13 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/25 11:50:51 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{

private:

	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;


public:

	Contact();
	std::string  getFirstName() 	const;
	std::string  getLastName() 		const;
	std::string  getNickName() 		const;
	std::string  getPhoneNumber() 	const;
	std::string  getDarkestSecret() const;
	void setContact(const std::string& first, const std::string& last,
		const std::string& nick, const std::string& phone,
		const std::string& dark);

};

#endif
