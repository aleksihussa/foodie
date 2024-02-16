// lunchMenuChecker.cpp
#include "foodie.h"
#include <ctime>
#include <iostream>
using namespace std;

string getMenuUrl(string year, string weekNumber) {
  return "https://unisafka.fi/static/json/" + year + "/" + weekNumber +
         "/v.json";
}

string getVersionUrl(const string &year, const string &weekNumber,
                     const string &version, const string &weekDay) {
  return "https://unisafka.fi/static/json/" + year + "/" + weekNumber + "/" +
         version + "/" + weekDay + ".json";
}
void LunchMenuChecker::fetchMenu() {

  time_t t = time(nullptr);
  tm *const pTInfo = localtime(&t);

  auto year = pTInfo->tm_year;

  auto weeDay = pTInfo->tm_wday;

  cout << "Fetching lunch menu..." << endl;
  // Add your fetching and parsing logic here
}

// You can add more function definitions related to lunch menu checking here
