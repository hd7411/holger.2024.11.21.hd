#include <iostream>

//using namespace std;


typedef std::string ShortUrl ;
typedef std::string LongUrl;

class UrlObject {
	private:
		LongUrl longUrl;
		ShortUrl shortUrl;
	public:
		UrlObject (const LongUrl longurl): longUrl{longUrl} {
			shortUrl = ShortUrl ("https://kurze.url");
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

	public:
	UrlObject* convertLongUrlToShort (const LongUrl longUrl) {
		return new UrlObject (longUrl);
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

/*
	const int maximum = 10;
	for(int i=0; i<maximum; i++) {
		//std::cout << "Hello" << std::endl;
	}
*/
	return 0;
}
