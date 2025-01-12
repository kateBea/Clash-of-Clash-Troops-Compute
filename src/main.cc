#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <vector>
#include <unordered_map>
#include <iostream>

struct Troop {
    std::string name{};
    const std::int32_t housingSpace{};
    std::int32_t count{};
};

struct Army {
    std::string name{};
    std::unordered_map<std::string, Troop> troops{};
    std::int32_t housingSpace{};
};

auto I_ComputeArmy(const std::vector<Troop>& troops, std::int32_t maxHousingSpace, Army& army, std::int32_t index) -> void {
	if (army.housingSpace == maxHousingSpace) {
		return;
	}

	for ( ; index < troops.size(); ) {
		const auto& troop{ troops[index] };

		if (army.housingSpace + troop.housingSpace <= maxHousingSpace) {
			auto it{ army.troops.find(troop.name) };

			if (it != army.troops.end()) {
			    it->second.count += 1;
			}
			else {
				auto newIt{ army.troops.emplace(std::make_pair(troop.name, troop)) };
                newIt.first->second.count += 1;
			}

			army.housingSpace += troop.housingSpace;
			I_ComputeArmy(troops, maxHousingSpace, army, index);
		}
		else {
			++index;
		}
	}
}

auto ComputeArmies(const std::vector<Troop>& troops, std::int32_t maxHousingSpace) {
	std::vector<Army> armies{};

	for (auto currentTroopindex{ 0 }; currentTroopindex < troops.size(); ++currentTroopindex) {
		Army army{
            .name{ "Army " + std::to_string(armies.size() + 1) },
            .troops{},
            .housingSpace{ 0 },
        };

		I_ComputeArmy(troops, maxHousingSpace, army, currentTroopindex);

		if (army.housingSpace == maxHousingSpace) {
			armies.emplace_back(army);
		}
	}

	return armies;
}

std::ostream& operator<<(std::ostream & os, const std::vector<Army>&armies) {
	for (const auto& army : armies) {
		os << "Army: " << army.name << ", space: " << army.housingSpace << '\n';

		for (const auto& [name, troop] : army.troops) {
			os << "[ Troop name: " << name << " | Troop space: " << troop.housingSpace << " | Troop count: " << troop.count << " ]\n";
		}
		os << std::endl;
	}

    std::cout << "Coumputed combinations: " << armies.size() << std::endl;

	return os;
}

int main() {
	const std::vector<Troop> troops{
		{ "Barbarian", 1},
		{"Archer", 1},
		{"Giant", 5},
		{"Goblin", 1},
		{"Wall Breaker", 2},
		{"Balloon", 5},
		{"Wizard", 4},
		{"Healer", 14},
		{"Dragon", 20},
		{"P.E.K.K.A", 25},
		{"Baby Dragon", 10},
		{"Miner", 5},
		{"Electro Dragon", 30},
		{"Yeti", 18},
		{"Sneaky Goblin", 1},
		{"Super Barbarian", 1},
		{"Super Archer", 1},
		{"Super Giant", 5},
		{"Super Wall Breaker", 2},
		{"Super Wizard", 4},
		{"Super Valkyrie", 8},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
		{"Inferno Dragon", 30},
		{"Super Baby Dragon", 10},
		{"Super P.E.K.K.A", 25},
		{"Super L.A.S.S.I", 5},
		{"Rocket Balloon", 8},
		{"Electro Owl", 14},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
		{"Inferno Dragon", 30},
		{"Super Baby Dragon", 10},
		{"Super P.E.K.K.A", 25},
		{"Super L.A.S.S.I", 5},
		{"Rocket Balloon", 8},
		{"Electro Owl", 14},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
		{"Inferno Dragon", 30},
		{"Super Baby Dragon", 10},
		{"Super P.E.K.K.A", 25},
		{"Super L.A.S.S.I", 5},
		{"Rocket Balloon", 8},
		{"Electro Owl", 14},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
		{"Archer", 1},
		{"Giant", 5},
		{"Goblin", 1},
		{"Wall Breaker", 2},
		{"Balloon", 5},
		{"Wizard", 4},
		{"Healer", 14},
		{"Dragon", 20},
		{"P.E.K.K.A", 25},
		{"Baby Dragon", 10},
		{"Miner", 5},
		{"Electro Dragon", 30},
		{"Yeti", 18},
		{"Sneaky Goblin", 1},
		{"Super Barbarian", 1},
		{"Super Archer", 1},
		{"Super Giant", 5},
		{"Super Wall Breaker", 2},
		{"Super Wizard", 4},
		{"Super Valkyrie", 8},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
		{"Inferno Dragon", 30},
		{"Super Baby Dragon", 10},
		{"Super P.E.K.K.A", 25},
		{"Super L.A.S.S.I", 5},
		{"Rocket Balloon", 8},
		{"Electro Owl", 14},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
		{"Inferno Dragon", 30},
		{"Super Baby Dragon", 10},
		{"Super P.E.K.K.A", 25},
		{"Super L.A.S.S.I", 5},
		{"Rocket Balloon", 8},
		{"Electro Owl", 14},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
		{"Inferno Dragon", 30},
		{"Super Baby Dragon", 10},
		{"Super P.E.K.K.A", 25},
		{"Super L.A.S.S.I", 5},
		{"Rocket Balloon", 8},
		{"Electro Owl", 14},
		{"Super Minion", 2},
		{"Ice Hound", 30},
		{"Headhunter", 6},
		{"Super Witch", 12},
    };
	
    std::cout << "Input the max housing space: ";
    std::int32_t maxHousingSpace{};
    std::cin >> maxHousingSpace;

	auto armies{ ComputeArmies(troops, maxHousingSpace) };
	std::cout << armies << std::endl;
}