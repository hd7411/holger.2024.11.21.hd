#include <iostream>
#include <list>

//using namespace std;


typedef std::string ShortUrl ;
typedef std::string LongUrl;

class UrlObject {
	private:
		LongUrl longUrl;
		ShortUrl shortUrl;
	public:
		UrlObject (const LongUrl long_url): longUrl{long_url} {
			shortUrl = ShortUrl (std::string ("https://kurze.url").append(longUrl));  
		} 
		LongUrl getLongUrl () {
			return longUrl;
		}
		ShortUrl getShortUrl () {
			return shortUrl;
		}
};

class UrlManager {
	private:
		std::list <UrlObject*> urlObjectLst;

	public:
	UrlObject* convertLongUrlToShort (const LongUrl longUrl) {
		urlObjectLst.push_back(new UrlObject (longUrl)) ;
		return urlObjectLst.back();
	}

	UrlObject* convertShortUrlToLong (const LongUrl longUrl) {
		urlObjectLst.push_back(new UrlObject (longUrl)) ;
		return urlObjectLst.back();
	}


};



auto  main() -> int
{

	/*
*/
	UrlManager urlManager = UrlManager ();

	LongUrl longUrl = LongUrl ("https://lange.url");

	UrlObject* urlObj = urlManager.convertLongUrlToShort(longUrl);
	std::cout << "ShortUrl :" << urlObj->getShortUrl() << std::endl;

	return 0;
}
