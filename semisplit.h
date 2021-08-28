#ifndef SEMISPLIT_H
#define SEMISPLIT_H

#include <vector>
#include <algorithm>

template < template<typename,typename> class Container = std::vector, class T >
Container<T, std::allocator<T>> SemiSplit(T &InVec) {
	Container<T, std::allocator<T>> OutVecVec;

	std::sort(InVec.begin(), InVec.end());					// Sort List

	const auto it = std::unique(InVec.begin(), InVec.end());		// Find Unique
	InVec.resize( std::distance(InVec.begin(), it) );			// Drop extras

	T tmpList;
	for(auto vit = InVec.begin(); vit != InVec.end(); ++vit) {

		const typename T::value_type curNumber = *vit;			// Save Value
		tmpList.emplace_back(*vit);     				// Push to List

		if (std::next(vit) != InVec.end()) {				// Have valid next?
			const typename T::value_type nextNumber = *std::next(vit);// Get Next Value

			if (curNumber + 1 != nextNumber) {			// Consecutive?
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
