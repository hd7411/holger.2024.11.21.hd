#include <iostream>
#include <list>
#include <cassert>
#include "urltypes.h"

class Shortener {
	Shortener() = default;
	virtual ShortUrl shorten (LongUrl) = 0;
};

class ShortenerAscii : public Shortener {
	public:
	ShortUrl shorten (LongUrl long_url) {
		return ShortUrl ("not yet implemented");
	}
};

class Persistor {
public:
  Persistor() = default;
  virtual void addUrlObj(UrlObject*) =0;
  virtual UrlObject* getUrlObjWithShortUrl(ShortUrl) = 0;
  virtual UrlObject* getUrlObjWithLongUrl(LongUrl) = 0;
  virtual void listAllEntries () =0;
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
			for (UrlObject* const& listIter : urlObjectLst) {
				if (listIter->getShortUrl() == short_url) {
					return listIter;
				}
			}
			std::cout << "No Url obj for this short URL found: " << short_url << std::endl;
			return NULL;
		}

		UrlObject* getUrlObjWithLongUrl(LongUrl long_url) {
			for (UrlObject* const& listIter : urlObjectLst) {
				if (listIter->getLongUrl() == long_url) {
					return listIter;
				}
			}
			std::cout << "No Url obj for this long URL found: " << long_url << std::endl;
			return NULL;
		}

		void listAllEntries () {
			for (UrlObject* const& listIter : urlObjectLst) {
				std::cout << "List: Long Url: " << listIter->getLongUrl() << " : Short Url: " << listIter->getShortUrl() << std::endl;
			}
		}

		
};

class UrlManager {
	private:
		std::list <UrlObject*> urlObjectLst;
		Persistor* persistor_m;

	public:
	UrlManager (Persistor* persistor) : persistor_m{persistor} {}

	UrlObject* convertLongUrlToShort (const LongUrl longUrl) {
		persistor_m->addUrlObj(new UrlObject (longUrl)) ;
		return persistor_m->getUrlObjWithLongUrl(longUrl);
	}

	UrlObject* convertShortUrlToLong (const ShortUrl short_url) {
		return persistor_m->getUrlObjWithShortUrl(short_url);
	}
};



auto  main() -> int
{

	// Persiror test & check
	Persistor* testPersitor = new PersistorList();
	UrlObject* tmpUrlObj = new UrlObject (LongUrl ("Test ULR"));
	testPersitor->addUrlObj(tmpUrlObj);
	auto aa = testPersitor->getUrlObjWithShortUrl(ShortUrl("Short URL"));
	auto bb = testPersitor->getUrlObjWithLongUrl(LongUrl ("Test ULR"));
	std::cout << "Test: " <<  bb->getLongUrl() << bb->getShortUrl() << std::endl;


	std::cout << "Basic functionality & check" << std::endl;
	Persistor* listPersitor = new PersistorList();
	UrlManager urlManager = UrlManager (listPersitor);

	LongUrl longUrl = LongUrl ("https://lange.url");

	UrlObject* urlObj_1 = urlManager.convertLongUrlToShort(longUrl);
	std::cout << "ShortUrl 1: " << urlObj_1->getShortUrl() << std::endl;
	std::cout << "LongUrl  1: " << urlObj_1->getLongUrl() << std::endl;

	ShortUrl su = urlObj_1->getShortUrl();
	listPersitor->listAllEntries();

	UrlObject* urlObj_2 = urlManager.convertShortUrlToLong(su);
	std::cout << "ShortUrl 2: " << urlObj_2->getShortUrl() << std::endl;
	std::cout << "LongUrl  2: " << urlObj_2->getLongUrl() << std::endl;

	assert (urlObj_1->getLongUrl() == urlObj_2->getLongUrl());
	assert (urlObj_1->getShortUrl() == urlObj_2->getShortUrl());


	return 0;
}
