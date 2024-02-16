#include "HTTPClient.h"
#include "foodie.h"
#include <iostream>
using namespace std;

int main() {
  string test = "https://unisafka.fi/static/json/2024/7/v.json";
  json jsonResponse = HTTPClient::getJson(test);
  std::cout << jsonResponse.dump(4) << std::endl;
  return 0;
}
