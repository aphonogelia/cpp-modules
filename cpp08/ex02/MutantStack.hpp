/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:08:33 by htharrau          #+#    #+#             */
/*   Updated: 2026/03/25 20:49:48 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* std::stack is not a real container. It’s an adapter.
 -> It wraps another container (by default std::deque) and hides iteration.
You can only push, pop, top. No begin() or end() member functions.

It has a protected member we are gonna use:

template <class T, class Container = std::deque<T> >
class stack {
public:
    typedef Container container_type;
    typedef typename Container::value_type value_type;
    typedef typename Container::size_type size_type;

protected:
    container_type c;  // <-- the important part - allows inheritance

public:
    stack() : c() {}
    explicit stack(const container_type& cont) : c(cont) {}

    bool empty() const { return c.empty(); }
    size_type size() const { return c.size(); }

    value_type& top() { return c.back(); }
    const value_type& top() const { return c.back(); }

    void push(const value_type& val) { c.push_back(val); }

    void pop() { c.pop_back(); }
};

*/

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    /* Coplien: inherited, nothing to add */
    MutantStack() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other) {
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};
