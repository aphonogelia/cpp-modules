/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htharrau <htharrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:06:18 by htharrau          #+#    #+#             */
/*   Updated: 2026/01/22 12:39:13 by htharrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Line.hpp"
#include "Point.hpp"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define GRAY "\033[90m"
#define WIDTH 30
#define HEIGHT 20

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

int main() {
    Fixed aa(10);
    Fixed bb(5.f);
    Fixed cc = aa / bb;
    std::cout << cc << std::endl;
    std::cout << cc.toFloat() << std::endl;

    int xa = 1;
    int ya = 0;
    int xb = 1;
    int yb = 2;
    int xc = 4;
    int yc = 2;
    int xk = 2;
    int yk = 1;
    char grid[HEIGHT][WIDTH];

    // Fill matrice
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x) grid[y][x] = ' ';

    // Fill the points points
    grid[HEIGHT - ya - 1][xa] = 'a';
    grid[HEIGHT - yb - 1][xb] = 'b';
    grid[HEIGHT - yc - 1][xc] = 'c';
    grid[HEIGHT - yk - 1][xk] = 'x';

    // Print the grid with colors, only once
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] == 'a' || grid[y][x] == 'b' || grid[y][x] == 'c')
                std::cout << BOLD << CYAN << "● " << RESET;
            else if (grid[y][x] == 'x')
                std::cout << BOLD << YELLOW << "● " << RESET;
            else
                std::cout << GRAY << ". " << RESET;
        }
        std::cout << std::endl;
    }

    Point a((Fixed(xa)), (Fixed(ya)));
    Point b((Fixed(xb)), (Fixed(yb)));
    Point c((Fixed(xc)), (Fixed(yc)));
    Point k((Fixed(xk)), (Fixed(yk)));

    bsp(a, b, c, k);

    Point d(Fixed(4.5f), Fixed(5.5f));
    Point e(Fixed(4.5f), Fixed(5.5f));
    Point f(Fixed(3.5f), Fixed(5.5f));
    Point l(Fixed(1.5f), Fixed(7.5f));

    bsp(d, e, f, l);

    return (0);
}
