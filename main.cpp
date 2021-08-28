/*
 * main.cpp
 *
 *  Created on: 17 Jun 2019
 *      Author: UncleAnti
 */

#include <vector>
#include <algorithm>
#include <iostream>

#include "semisplit.h"

int main() {
	std::vector<int> sample { 0,4,7,9,12,13,14,20 };
	std::vector<std::vector<int>> results = SemiSplit(sample);

	for (const auto & first : results) {
		std::cout << "Set size = " << first.size() << "\n";

		for (const auto & second : first) {
			std::cout << second << '\n';
		}
	}
}
