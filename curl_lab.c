#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <curl/curl.h>
#include <string.h>
 
typedef struct {
    char* data;
    size_t len;
  } download_data;

int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
  fprintf(stderr, "\n\n\n\n\n!!!!!!!! %ld of %ld\n", dlnow, dltotal);
  return 0;
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
  download_data *d = userdata;
  d->data = realloc(d->data, d->len + nmemb);
  memcpy(d->data + d->len, ptr, nmemb);
  d->len += nmemb;
  return nmemb;
}

int main(int argc, char *argv[]) {
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, progress_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    download_data datums = {NULL, 0};
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &datums);
 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    else {
      printf("%s\n", datums.data);
    }
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}