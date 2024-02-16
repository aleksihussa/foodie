#include "HTTPClient.h"
#include "foodie.h"
#include <iostream>
using namespace std;

int main() {
  // LunchMenuChecker checker;
  // checker.fetchMenu();
  std::string url = "https://api.example.com/data";
  string test = "https://unisafka.fi/static/json/2024/7/v.json";
  try {
    json jsonResponse = HTTPClient::getJson(test);
    std::cout << jsonResponse.dump(4) << std::endl; // Pretty print the JSON
  } catch (const json::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
