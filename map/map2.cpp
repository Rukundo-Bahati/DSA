#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct CityRecord {
  string name;
  uint64_t population;
  double Latitude, Longitude;
};

int main() {
  vector<CityRecord> cities;

  cities.emplace_back(CityRecord{"Kigali", 210000, 2.1, 2.1});
  cities.emplace_back(CityRecord{"Gitega", 210000, 2.1, 2.1});
  cities.emplace_back(CityRecord{"Mogadishu", 210000, 2.1, 2.1});
  cities.emplace_back(CityRecord{"Zanzibar", 210000, 2.1, 2.1});
  cities.emplace_back(CityRecord{"Kampala", 210000, 2.1, 2.1});

  for (const auto& city : cities) {
    if (city.name == "Kigali") {
      cout << "Population of Kigali: " << city.population << endl;
      break;
    }
  }

  map<string, CityRecord> cityMap;
  cityMap["Kigali"] = {"Kigali", 210000, 2.1, 2.1};
  cityMap["Gitega"] = {"Gitega", 210000, 2.1, 2.1};
  cityMap["Mogadishu"] = {"Mogadishu", 210000, 2.1, 2.1};
  cityMap["Zanzibar"] = {"Zanzibar", 210000, 2.1, 2.1};
  cityMap["Kampala"] = {"Kampala", 210000, 2.1, 2.1};

  CityRecord& kampalaData = cityMap["Kampala"];
  cout << "Kampala population: " << kampalaData.population << endl;

  return 0;
}
