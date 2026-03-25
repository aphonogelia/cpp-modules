/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:11:23 by htharrau          #+#    #+#             */
/*   Updated: 2025/01/12 13:26:37 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

// CONSTRUCTOR
PhoneBook::PhoneBook() : count(0) {}

// GETTER
int PhoneBook::getCount() const { return count; }

// HELPER FUNCTIONS -> PRIVATE
std::string PhoneBook::nonEmpty(std::string prompt) const {
    std::string str;

    std::cout << prompt;
    std::getline(std::cin, str);
    while (str == "") {
        std::cout << prompt;
        std::getline(std::cin, str);
    }
    return (str);
}

std::string PhoneBook::truncate(const std::string &str) const {
    if (str.length() > 10) return (str.substr(0, 9) + '.');
    return str;
}

// ADD CONTACT
void PhoneBook::addContact() {
    std::string firstname, lastname, nickname, phonenb, secret;
    Contact newcontact;

    firstname = nonEmpty("FIRST NAME: ");
    lastname = nonEmpty("LAST NAME: ");
    nickname = nonEmpty("NICKNAME: ");
    phonenb = nonEmpty("PHONE NUMBER: ");
    secret = nonEmpty("DARKEST SECRET: ");

    newcontact.setContact(firstname, lastname, nickname, phonenb, secret);

    if (count < 8)
        contacts[count++] = newcontact;
    else {
        for (int i = 0; i < 7; i++) contacts[i] = contacts[i + 1];
        contacts[7] = newcontact;
    }
    std::cout << '\n';
}

// SEARCH CONTACT
void PhoneBook::searchContact() const {
    std::string indexS;
    int index;
    Contact contact;

    if (count == 0) {
        std::cout << "No contact yet. \n\n";
        return;
    }

    printContacts();

    while (true) {
        std::cout << "\033[34m";
        std::cout << "Enter an index: ";
        std::cout << "\033[0m";

        std::getline(std::cin, indexS);
        index = std::atoi(indexS.c_str());

        if (index < 1 || index > count)
            std::cout << "Index invalid." << std::endl;
        else {
            contact = getContact(index - 1);
            std::cout << "\t"
                      << "First name: " << contact.getFirstName() << '\n';
            std::cout << "\t"
                      << "Last name: " << contact.getLastName() << '\n';
            std::cout << "\t"
                      << "Nickname: " << contact.getNickName() << '\n';
            std::cout << "\t"
                      << "Phone number: " << contact.getPhoneNumber() << '\n';
            std::cout << "\t"
                      << "Darkest secret: " << contact.getDarkestSecret() << '\n'
                      << std::endl;
            break;
        }
    }
}

// GET CONTACT
Contact PhoneBook::getContact(int index) const {
    if (index >= 0 && index < count) return contacts[index];
    return Contact();  // Return an empty contact if index is out of bounds
}

void PhoneBook::printContacts() const {
    for (int i = 0; i < count; i++) {
        std::cout << "\t" << std::setw(2) << std::right << (i + 1) << " | " << std::setw(10)
                  << std::right << truncate(contacts[i].getFirstName()) << " | " << std::setw(10)
                  << std::right << truncate(contacts[i].getLastName()) << " | " << std::setw(10)
                  << std::right << truncate(contacts[i].getNickName()) << '\n';
    }
}

/*
SEARCH: display a specific contact
◦ Display the saved contacts as a list of 4 columns: index, first name, last
name and nickname.
◦ Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).
◦ Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line
 */