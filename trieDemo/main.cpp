#include <iostream>
#include "othertrie.hpp"

using namespace mytrie;


int main(int argc, char *argv[])
{
	std::string text = "dfjosjdfoiasjfoiasjdofijasiodfjsdoidfjasodifjoasidj"\
	"fjoisjdfoijsdofijasoidfjoiasffidsjdfoiasjdfohnasoguhw9jqijrojiowdjimeoiqjwoeij"\
	"osdjfoisjfoijsdifjijijweiiejiojtgijerogjonvkoijqowijeqijofjeorijfoiewrjfo"\
	"jofijaosdifjo;jfoiofidfdewroqiuuqoiurijhdfdkvlknvjajffopq[roeoirjoiwejrowe"\
	"joisjdfoisjdfoijsodfijosffidijoweijoiruoqiueriuqtihodfhgodfjkskdkljsldjnxsdkfjlk"\
	"soidfjoijdfoijroeiwjfoiiijqijeoipeirpqet[ofjoeijfoijeoiiwejfoijweoifjwoejfoi";
	std::string key1 = "fjoi";
	std::string key2 = "sffid";
	std::string key3 = "fidfd";
	std::string key4 = "jdo";
	std::string key5 = "dfd";
	std::string key6 = "ssdfsf";
	std::string key7 = "---------------------";

	// 创建trie字典树
	basic_trie<char> *finder = new basic_trie<char>;

	finder->insert(key1);
	finder->insert(key2);
	finder->insert(key3);
	finder->insert(key4);
	finder->insert(key5);
	finder->insert(key6);
	finder->insert(key7);

	// 当插入关键词为原关键词的子串, 形成包含映射, 如 "dfd" 和 "fidfd"
	finder->settingfailure();

	// 解析文章
	/* 数据结构
	class result{
	public:
	    std::basic_string<CharType> sentence;
	    unsigned int start;
	    unsigned int fin;
	public:
		    explicit result(){
	        start = 0;
	        fin = 0;
	    }
	    explicit result(const std::basic_string<CharType>& sentence, unsigned int start, unsigned int fin):
        sentence(sentence), start(start), fin(fin){}
	};
	*/

	// 验证结果
	std::vector<result<char>> res = finder->search(text);
	for (auto i = 0; i < res.size(); ++i)
	{
		std::cout << res[i].sentence << '\n';
		std::cout << "start==" << res[i].start << ",	";
		std::cout << "fin==" << res[i].fin << '\n';
		std::cout << "=========================" << '\n';
	}

	return 0;
}
