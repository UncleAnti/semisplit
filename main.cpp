/*
 * main.cpp
 *
 *  Created on: 17 Jun 2019
 *      Author: UncleAnti
 */

#include "semisplit.h"

#include <vector>
#include <algorithm>
#include <fmt/core.h>
#include <fmt/format.h>

using T = std::vector<int>;

template <> struct fmt::formatter<T> {
	constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
		return ctx.begin();
	}

	template <typename FormatContext>
	auto format(const T& arg, FormatContext& ctx) -> decltype(ctx.out()) {
		std::string output;
		for (const auto &it : arg)
			output += fmt::format("{:3},", it);

		if (!output.empty())
			output.resize(output.size()-1);

		return format_to(ctx.out(), "[{}]", output);
	}
};

int main() {
	T sample { 0,4,7,9,12,13,14,20 };
	std::vector<T> results = SemiSplit(sample);

	fmt::print("Sample[{}] = {}\n", sample.size(), sample);

	std::string output;
	for (const auto & first : results)
		output += fmt::format("{},", first);

	if (!output.empty())
		output.resize(output.size()-1);

	fmt::print("Output[{}] = [{}]\n", results.size(),  output);
}
