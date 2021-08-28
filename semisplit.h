#include <vector>
#include <algorithm>

#ifndef SEMISPLIT_H
#define SEMISPLIT_H

template <class T>
std::vector<std::vector<T>> SemiSplit(std::vector<T> &InVec) {
	std::vector<std::vector<T>> OutVecVec;

	// Sort and reject duplicates
	std::sort(InVec.begin(), InVec.end());						// Sort List
	const auto &it = std::unique(InVec.begin(), InVec.end());	// Find Unique
	InVec.resize(std::distance(InVec.begin(), it) );			// Drop extras

	std::vector<T> tmpList;
	for(auto vit = InVec.begin(); vit != InVec.end(); ++vit)
	{
		const T curNumber = *vit;								// Save Value
		tmpList.emplace_back(*vit);     				// Push to List

		if (std::next(vit) != InVec.end())			// Have valid next?
		{
			const T nextNumber = *std::next(vit);	// Get Next Value

			if (curNumber + 1 != nextNumber)			// Consecutive?
			{
				if (curNumber + 2 == nextNumber)		// Make it consecutive?
					tmpList.push_back(curNumber + 1);	// Push a dummy
				else
					OutVecVec.emplace_back(move(tmpList));	// Push list and start again
			}
		} else
			OutVecVec.emplace_back(tmpList);			// Push list and end
	}

	return OutVecVec;
}

#endif  //SEMISPLIT_H
