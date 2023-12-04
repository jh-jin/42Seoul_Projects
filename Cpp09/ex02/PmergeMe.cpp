#include "PmergeMe.hpp"

std::vector<int> checkInput(int argc, char **argv) {
	std::vector<int> input;
	std::string sNum;
	int num;

	for (int i = 1; i < argc; i++) {
		sNum = argv[i];
		std::stringstream ss(sNum);

		if (!(ss >> num) || ss.tellg() != -1)
			throw std::runtime_error("Error: invalid number");
		if (num <= 0)
			throw std::runtime_error("Error: input should be positive integer");
		input.push_back(num);
	}
	return input;
}

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
	return a.first < b.first;
}

std::vector<int> vecMainChain(std::vector<int> result, std::vector<std::pair<int, int> > pairs, size_t inputSize, int lastElem) {
	size_t jacobsthal[20] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	size_t pendSize = inputSize / 2 - 1;
	std::vector<int>::iterator boundIt = result.begin();
	std::pair<int, int> target;
	int jacobIdx = 0, lastVisitedJacobsthal = 1, pairIdx = 1;

	while (pendSize-- > 0) {
		if (lastVisitedJacobsthal == pairIdx) {
			lastVisitedJacobsthal = jacobsthal[jacobIdx];
			jacobIdx++;
			pairIdx = jacobsthal[jacobIdx] <= inputSize / 2 ? jacobsthal[jacobIdx] : inputSize / 2; // 다음 jacobsal 설정하되 마지막 페어를 넘어가지 않게 설정
			target = pairs[pairIdx - 1]; // 배열은 0부터 시작하니까 1 빼줌
			while (target.first != *boundIt) // 페어의 second를 삽입할건데 second < first이므로 first 이상은 볼 필요 없으니 boundIt를 페어 first까지 증가시켜 경계를 설정
				boundIt++;
		} else {
			target = pairs[pairIdx - 1];
			while (target.first != *boundIt)
				boundIt--;
		}
		result.pop_back(); // 삽입 전 0으로 채워진 뒤쪽의 0 하나 삭제
		result.insert(std::lower_bound(result.begin(), boundIt, target.second), target.second); // boundIt 포함 오른쪽은 볼 필요 없고, target.second를 삽입 정렬
		boundIt++; // 하나 삽입했으므로 boundIt 증가
		pairIdx--; // 하나 작은 애 볼 것임. 1, 3 2, 5 4, 11 10 9 8 7 6
	}
	if (inputSize % 2 == 1){ // 홀수였을 때 남겨둔 마지막 원소 삽입
		result.pop_back();
		result.insert(std::lower_bound(result.begin(), result.end(), lastElem), lastElem);
	}
	return result;
}

std::list<int> listMainChain(std::list<int> result, std::list<std::pair<int, int> > pairs, size_t inputSize, int lastElem) {
	size_t jacobsthal[20] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	size_t pendSize = inputSize / 2 - 1;
	std::list<int>::iterator boundIt = result.begin();
	std::list<std::pair<int, int> >::iterator pairIt = pairs.begin();
	std::pair<int, int> target;
	int jacobIdx = 0, lastVisitedJacobsthal = 1, pairIdx = 1;

	while (pendSize-- > 0) {
		if (lastVisitedJacobsthal == pairIdx) {
			pairIdx = jacobsthal[jacobIdx + 1] <= inputSize / 2 ? jacobsthal[jacobIdx + 1] : inputSize / 2;
			for (int i = lastVisitedJacobsthal; i < pairIdx; i++)
				pairIt++;
			lastVisitedJacobsthal = jacobsthal[jacobIdx];
			jacobIdx++;
			target = *pairIt;
			while (target.first != *boundIt)
				boundIt++;
		} else {
			target = *pairIt;
			while (target.first != *boundIt)
				boundIt--;
		}
		result.insert(std::lower_bound(result.begin(), boundIt, target.second), target.second);
		boundIt++;
		pairIt--;
		pairIdx--;
	}
	if (inputSize % 2 == 1)
		result.insert(std::lower_bound(result.begin(), result.end(), lastElem), lastElem);
	return result;
}

std::vector<int> vecFordJohnson(std::vector<int> input) {
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> result;

	if (input.size() == 1)
		return input;
	/* make main array */
	pairs = makePairs<std::vector<std::pair<int, int> > >(input);
	sort(pairs.begin(), pairs.end(), compare);
	result = makeResultBase<std::vector<int>, std::vector<std::pair<int, int> > >(pairs);
	result.resize(input.size());

	/* do main chain */
	return vecMainChain(result, pairs, input.size(), input.back());
}

std::list<int> listFordJohnson(std::vector<int> input) {
	std::list<std::pair<int, int> > pairs;
	std::list<int> result;

	if (input.size() == 1)
		return std::list<int>(1, input[0]);
	/* make main array */
	pairs = makePairs<std::list<std::pair<int, int> > >(input);
	pairs.sort(compare);
	result = makeResultBase<std::list<int>, std::list<std::pair<int, int> > >(pairs);

	/* do main chain */
	return listMainChain(result, pairs, input.size(), input.back());
}