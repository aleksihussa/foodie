#include "foodie.h"
#include "HTTPClient.h"
#include <array>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

const array<string, 7> WeekDays = {"su", "ma", "ti", "ke", "to", "pe", "la"};
const string tty = "restaurants_tty";
const string hertsi = "res_hertsi";
const string newton = "res_newton";
const string reaktori = "res_reaktori";
const string konehuone = "res_konehuone";

enum commands { help };

string getVersionUrl(string year, string weekNumber) {
  return "https://unisafka.fi/static/json/" + year + "/" + weekNumber +
         "/v.json";
}

string getMenuUrl(const string &year, const string &weekNumber,
                  const string &version, const string &weekDay) {
  return "https://unisafka.fi/static/json/" + year + "/" + weekNumber + "/" +
         version + "/" + weekDay + ".json";
}

void LunchMenuChecker::fetchMenu(int argc, char *args[]) {
  if (argc > 1) {
    cout << "not implemented yet" << endl;
  } else {
    try {
      time_t t = time(nullptr);
      tm *const pTInfo = localtime(&t);

      int year = pTInfo->tm_year + 1900;

      string weekDay = WeekDays.at(pTInfo->tm_wday);

      int weekNum = pTInfo->tm_yday / 7 + 1;

      string vUrl = getVersionUrl(to_string(year), to_string(weekNum));
      json versionJson = HTTPClient::getJson(vUrl);
      auto version = versionJson["v"].get<std::string>();
      string menuUrl =
          getMenuUrl(to_string(year), to_string(weekNum), version, weekDay);

      json menuJson = HTTPClient::getJson(menuUrl);

      auto ttyRestaurants = menuJson[tty].get<json>();
      for (auto &[restaurant, value] : ttyRestaurants.items()) {

        cout << restaurant << endl;
        auto meals = value["meals"].get<json>();

        cout << "Meals: " << endl;
        for (auto &[meal, value] : meals.items()) {
          cout << meal << endl;
          cout << value.dump(2) << endl;
        }

        cout << "--------------------------------------------------" << endl;
        cout << endl;
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
    }
  }
  return;
}
