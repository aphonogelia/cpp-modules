/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:11:51 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/25 11:50:49 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// CONSTRUCTOR
Contact::Contact()
    : first_name(""), last_name(""), nick_name(""), phone_number(""), darkest_secret("") {}

// GETTERS
std::string Contact::getFirstName() const { return first_name; }
std::string Contact::getLastName() const { return last_name; }
std::string Contact::getNickName() const { return nick_name; }
std::string Contact::getPhoneNumber() const { return phone_number; }
std::string Contact::getDarkestSecret() const { return darkest_secret; }

// NEW CONTACT
void Contact::setContact(const std::string& first, const std::string& last, const std::string& nick,
                         const std::string& phone, const std::string& dark) {
    first_name = first;
    last_name = last;
    nick_name = nick;
    phone_number = phone;
    darkest_secret = dark;
}