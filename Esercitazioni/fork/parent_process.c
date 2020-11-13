#include "parent_process.h"
#include <curl/curl.h>
#include <stdio.h>

void parent_process(char * args)
{
    puts("sto eseguendo il processo padre");
    CURL * handle = curl_easy_init();
    CURLcode results;

    if(!handle)
    {
        perror("Error initializating resources.");
    }
    else
    {
        results = curl_easy_setopt(handle, CURLOPT_URL, "https://www.google.com"); //set url
        if(results != CURLE_OK)
        {
            perror(curl_easy_strerror(results));
        }
        else
        {
            results = curl_easy_setopt(handle, CURLOPT_SSL_VERIFYPEER, 0L);
            if(results != CURLE_OK)
            {
                perror(curl_easy_strerror(results));
            }
            else
            {
                results = curl_easy_setopt(handle, CURLOPT_SSL_VERIFYHOST, 0L);
                if(results != CURLE_OK)
                {
                    perror(curl_easy_strerror(results));
                }
                else
                {
                    /*finally get the page, since non file or writing function has been specified, everything will be written to stdout*/
                    results = curl_easy_perform(handle);

                    if(results != CURLE_OK)
                    {
                        perror(curl_easy_strerror(results));
                    }
                    else
                    {
                        printf("Did it!\n");
                    }
                    
                }
                
            }
            
        }
        
        curl_easy_cleanup(handle);
    }
    
    return;
}