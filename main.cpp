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

class Persistor {
public:
  Persistor() = default;
  virtual void addUrlObj(UrlObject*) =0;
  virtual UrlObject* getUrlObjWithShortUrl(ShortUrl) = 0;
  virtual UrlObject* getUrlObjWithLongUrl(LongUrl) = 0;
  //virtual ~Persistor() = default;
};

class PersistorList: public Persistor {
	private:
		std::list <UrlObject*> urlObjectLst;
	public:
		PersistorList () {
			urlObjectLst = {};
		}
		void addUrlObj (UrlObject* urlobj) {
			urlObjectLst.push_back(urlobj) ;
			std::cout << "PersistorList url obj list size = " << urlObjectLst.size() << std::endl;
		}

		UrlObject* getUrlObjWithShortUrl(ShortUrl short_url) {
			std::cout << "Not Yet implemented" << std::endl;
			return new UrlObject (LongUrl ("not yet Implemented"));

		}
		UrlObject* getUrlObjWithLongUrl(LongUrl long_url) {
			
			std::cout << "Not Yet implemented" << std::endl;
			return new UrlObject (LongUrl ("not yet Implemented"));

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

	// Persiror test & check
	Persistor* testPersitor = new PersistorList();
	UrlObject* tmpUrlObj = new UrlObject (LongUrl ("Test ULR"));
	testPersitor->addUrlObj(tmpUrlObj);
	auto aa = testPersitor->getUrlObjWithShortUrl(ShortUrl("Short URL"));


	// basis Funktionalitaet & check
	UrlManager urlManager = UrlManager ();

	LongUrl longUrl = LongUrl ("https://lange.url");

	UrlObject* urlObj = urlManager.convertLongUrlToShort(longUrl);
	std::cout << "ShortUrl :" << urlObj->getShortUrl() << std::endl;

	return 0;
}
