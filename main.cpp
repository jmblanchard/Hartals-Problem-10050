#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int numTests = 0;
    std::vector<int> parties;

    std::cin >> numTests;

    for (int i = 0; i < numTests; ++i) {
        int numDays = 0;
        int numParties = 0;
        int totalHartals = 0;
        parties.clear();

        std::cin >> numDays >> numParties;

        for (int j = 0; j < numParties; ++j) {
            int hartalParameter;
            std::cin >> hartalParameter;

            parties.push_back(hartalParameter);
        }

        std::sort(parties.begin(), parties.end());

        // run simulation of days
        for (int currDay = 1; currDay <= numDays; ++currDay) {
            // make sure we aren't on holiday
            if (currDay % 7 != 0 && currDay % 7 != 6) {
                // loop through parties
                for (int j = 0; j < parties.size(); ++j) {
                    // if a party has a hartal, count and break
                    if (currDay % parties[j] == 0) {
                        totalHartals++;
                        break;
                    }
                }
            }
        }

        std::cout << totalHartals << "\n";
    }

    return 0;
}
