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