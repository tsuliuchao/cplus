#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <curl/curl.h>
#include <stdio.h>
using namespace std;

struct FtpFile 
{
	const char *filename;
	FILE *stream;
};

static size_t FetchFiles(void *buffer, size_t size, size_t nmemb, void *stream)
{
	struct FtpFile *out = (struct FtpFile *)stream;
	if (out && !out->stream) 
	{
		// open file for writing 
		out->stream = fopen(out->filename, "wb");
		if (!out->stream)
			return -1; // failure, can't open file to write
	}
	return fwrite(buffer, size, nmemb, out->stream);
}

int DownloadFtpFile()
{
	CURL *curl;
	CURLcode res;
	struct FtpFile ftpfile = {
		"artist_black_fans_info_day_20171121.gz", // name to store the file as if succesful//
		NULL
	};

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if (curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, "ftp://118.192.65.164:22221/20171121/artist_fans_number_day_20171121.gzip");
		curl_easy_setopt(curl, CURLOPT_USERPWD, "baiduwiki:im1nerToBaidu_*(wiki)");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, FetchFiles);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ftpfile);

	    curl_easy_setopt(curl, CURLOPT_FTP_SKIP_PASV_IP, 1L);

		// Switch on full protocol/debug output //
		// curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		res = curl_easy_perform(curl);

		// always cleanup 
		curl_easy_cleanup(curl);

		if (CURLE_OK != res) 
		{
			//we failed 
			fprintf(stderr, "curl told us %d\n", res);
		}
	}

	if (ftpfile.stream)
		fclose(ftpfile.stream); // close the local file 

	curl_global_cleanup();

	getchar();

	return 0;
}

int main(void)
{
	//DownloadFtpFile();

	CURL *curl = curl_easy_init();
	CURLcode res;
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "ftp://118.192.65.164:22221/20171121/artist_red_fans_info_day_20171121.gzip");
		curl_easy_setopt(curl, CURLOPT_USERPWD, "baiduwiki:im1nerToBaidu_*(wiki)");
		/* please ignore the IP in the PASV response */
		curl_easy_setopt(curl, CURLOPT_FTP_SKIP_PASV_IP, 1L);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		/* please ignore the IP in the PASV response */
		curl_easy_setopt(curl, CURLOPT_FTP_SKIP_PASV_IP, 1L);
		res = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
		if (CURLE_OK != res) 
		{
			//we failed 
			fprintf(stderr, "curl told us %d\n", res);
		}
	}
	return 0;
}
