#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class HTTPClient {
public:
  static std::string getData(const std::string &url);
  static json getJson(const std::string &url);

private:
  static size_t writeCallback(void *contents, size_t size, size_t nmemb,
                              std::string *userp);
};

#endif
