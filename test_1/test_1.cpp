#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>

int main() {
	setlocale(LC_ALL, "ru");
	
	std::unordered_map<std::string, int> freqs;
	std::string word;
	while (std::cin >> word) {
		if (word == "stop") break;
		++freqs[word];
	}

	std::vector<std::pair<std::string, int>> sortedByFreq(
		freqs.begin(),
		freqs.end()
	);

	std::sort(
		sortedByFreq.begin(),
		sortedByFreq.end(),
		[](const auto& p1, const auto& p2) {
			return std::tie(p2.second, p1.first) < std::tie(p1.second, p1.first);
		}
	);

	for (const std::pair<const std::string, int>& freq : sortedByFreq) {
		std::cout << freq.first << "\t" << freq.second << "\n";
	}
}