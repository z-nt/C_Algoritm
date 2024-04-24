#include <stdio.h>
#include <stdlib.h>
#include <curlver.h>
#include <C:\MinGW\include\curl.h>





int main(void){
  
    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();


    if(curl==NULL){
        fprintf(stderr,"http request faild\n");
        return -1;
    }
    

    curl_easy_setopt(curl,CURLOPT_URL,"https://www.google.com");

    result= curl_easy_perform(curl);

        if(result != CURLE_OK){
            fprintf(stderr,"ERRor:%s\n",curl_easy_strerror(result));
        }


    curl_easy_cleanup(curl);


    return 0;
}