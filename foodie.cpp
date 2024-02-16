#include "foodie.h"
#include <array>
#include <ctime>
#include <string>

using namespace std;

const array<string, 7> WeekDays = {"su", "ma", "ti", "ke", "to", "pe", "la"};

string getVersionUrl(string year, string weekNumber) {
  return "https://unisafka.fi/static/json/" + year + "/" + weekNumber +
         "/v.json";
}

string getMenuUrl(const string &year, const string &weekNumber,
                  const string &version, const string &weekDay) {
  return "https://unisafka.fi/static/json/" + year + "/" + weekNumber + "/" +
         version + "/" + weekDay + ".json";
}
void LunchMenuChecker::fetchMenu() {

  time_t t = time(nullptr);
  tm *const pTInfo = localtime(&t);

  int year = pTInfo->tm_year;

  string weekDay = WeekDays.at(pTInfo->tm_wday);

  int weekNum = pTInfo->tm_yday / 7 + 1;

  string vUrl = getVersionUrl(to_string(year), to_string(weekNum));
  auto version = "";
  string menuUrl =
      getMenuUrl(to_string(year), to_string(weekNum), version, weekDay);
}
