#include "HTTPClient.h"
#include <curl/curl.h>

size_t HTTPClient::writeCallback(void *contents, size_t size, size_t nmemb,
                                 std::string *userp) {
  userp->append((char *)contents, size * nmemb);
  return size * nmemb;
}

std::string HTTPClient::getData(const std::string &url) {
  CURL *curl = curl_easy_init();
  std::string response_data;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
  }
  return response_data;
}

json HTTPClient::getJson(const std::string &url) {
  std::string data = getData(url);
  return json::parse(data);
}
