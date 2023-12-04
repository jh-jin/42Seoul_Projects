#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <list>
# include <ctime>

std::vector<int> vecFordJohnson(std::vector<int> input);
std::list<int> listFordJohnson(std::vector<int> input);
std::vector<int> checkInput(int argc, char **argv);
bool compare(std::pair<int, int> a, std::pair<int, int> b);

template <typename PC>
PC makePairs(std::vector<int> input) {
	PC pairs;

	for (size_t i = 0; i < input.size() - 1; i += 2) {
		if (input[i] > input[i + 1]) // 큰 게 더 앞으로 오게 쌍 만들기
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else 
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}
	return pairs;
}

template <typename C, typename PC>
C makeResultBase(PC pairInput) {
	typename PC::iterator pairIt;
	C result;

	for (pairIt = pairInput.begin(); pairIt != pairInput.end(); pairIt++) {
		result.push_back((*pairIt).first);
	}
	result.insert(result.begin(), pairInput.front().second); // 맨 앞에 비교 없이 하나 넣기 (초항 처리)
	return result;
}

template <typename T>
void printContainer(T c) {
	typename T::iterator it = c.begin();
	for (; it != c.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif