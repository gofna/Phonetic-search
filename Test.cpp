/**
 * AUTHORS: <Maor Ovadia and Gofna Ivry>
 * 
 * Date: 2020-03
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p, P, b, B") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text, "habPy") == string("happy"));
    CHECK(find(text, "haBpy") == string("happy"));
    CHECK(find(text, "haBBy") == string("happy"));
    CHECK(find(text, "haPPy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "hAPpI") == string("Happi"));
    CHECK(find(text, "happI") == string("Happi"));
}

TEST_CASE("Test replacement of b, B, f, F, p, P") {
    string text = "baby xxx yyy";
    CHECK(find(text, "baby") == string("baby"));
    CHECK(find(text, "faby") == string("baby"));
    CHECK(find(text, "fafy") == string("baby"));
    CHECK(find(text, "papy") == string("baby"));
    CHECK(find(text, "PaPy") == string("baby"));
    CHECK(find(text, "faBy") == string("baby"));
    CHECK(find(text, "Bapy") == string("baby"));
    CHECK(find(text, "baBy") == string("baby"));
    CHECK(find(text, "BaBy") == string("baby"));
    CHECK(find(text, "FaFy") == string("baby"));
    text = "xxx bafalo yyy";
    CHECK(find(text, "fapalo") == string("bafalo"));
    CHECK(find(text, "papalo") == string("bafalo"));
    CHECK(find(text, "FaBalo") == string("bafalo"));
    CHECK(find(text, "BaFalo") == string("bafalo"));
    CHECK(find(text, "Babalo") == string("bafalo"));
    CHECK(find(text, "faFalo") == string("bafalo"));
    CHECK(find(text, "babalo") == string("bafalo"));
    CHECK(find(text, "bafalo") == string("bafalo"));
}

TEST_CASE("Test replacement of c, C, k, K, q, Q") {
    string text = "chick xxx chicken yyy";
    CHECK(find(text, "chikken") == string("chicken"));
    CHECK(find(text, "qhikqen") == string("chicken"));
    CHECK(find(text, "qhiqqen") == string("chicken"));
    CHECK(find(text, "khiccen") == string("chicken"));
    CHECK(find(text, "chiccen") == string("chicken"));
    CHECK(find(text, "chicken") == string("chicken"));
    CHECK(find(text, "ChiCCen") == string("chicken"));
    CHECK(find(text, "KhiKKen") == string("chicken"));
    CHECK(find(text, "Qhikcen") == string("chicken"));
    CHECK(find(text, "chicQen") == string("chicken"));
    CHECK(find(text, "chicqen") == string("chicken"));
    CHECK(find(text, "Chicken") == string("chicken"));

}

TEST_CASE("Test replacement of s, S, z, Z") {
    string text = "xxx Suzi stack yyy in zzz the suZuki";
    CHECK(find(text, "suzi") == string("Suzi"));
    CHECK(find(text, "SuZi") == string("Suzi"));
    CHECK(find(text, "susi") == string("Suzi"));
    CHECK(find(text, "zuzi") == string("Suzi"));
    CHECK(find(text, "suZi") == string("Suzi"));
    CHECK(find(text, "ztack") == string("stack"));
    CHECK(find(text, "Stack") == string("stack"));
    CHECK(find(text, "suzuki") == string("suZki"));
    CHECK(find(text, "zuzuki") == string("suZuki"));
    CHECK(find(text, "ZuZuki") == string("suZuki"));
}

TEST_CASE("Test replacement of v, V, w, W") {
    string text = "aviv xxx view";
    CHECK(find(text, "wiev") == string("view"));
    CHECK(find(text, "VieW") == string("view"));
    CHECK(find(text, "Viev") == string("view"));
    CHECK(find(text, "wiew") == string("view"));
    CHECK(find(text, "aviv") == string("aviv"));
    CHECK(find(text, "aViV") == string("aviv"));
    CHECK(find(text, "aWiw") == string("aviv"));
    CHECK(find(text, "aviw") == string("aviv"));
    text = "wow xxx";
    CHECK(find(text, "vov") == string("wow"));
    CHECK(find(text, "WoW") == string("wow"));
    CHECK(find(text, "Vow") == string("wow"));
    CHECK(find(text, "woW") == string("wow"));
    CHECK(find(text, "wov") == string("wow"));
    CHECK(find(text, "VoV") == string("wow"));
    CHECK(find(text, "vow") == string("wow"));
}

TEST_CASE("Test replacement of g, G, j, J") {
    string text = "xxx beginning yyy the city Grajewo";
    CHECK(find(text, "beginninj") == string("beginnig"));
    CHECK(find(text, "beGinninG") == string("beginnig"));
    CHECK(find(text, "bejinninj") == string("beginnig"));
    CHECK(find(text, "beJinninj") == string("beginnig"));
    CHECK(find(text, "bejinninG") == string("beginnig"));
    CHECK(find(text, "GraJewo") == string("Grajewo"));
    CHECK(find(text, "GraGewo") == string("Grajewo"));
    CHECK(find(text, "jraJewo") == string("Grajewo"));
    CHECK(find(text, "Jragewo") == string("Grajewo"));

}

TEST_CASE("Test replacement of u, U, o, O") {
    string text = "you xxx out yyy";
    CHECK(find(text, "yOU") == string("you"));
    CHECK(find(text, "yoU") == string("you"));
    CHECK(find(text, "yuo") == string("you"));
    CHECK(find(text, "yUo") == string("you"));
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "oUt") == string("out"));
    CHECK(find(text, "out") == string("out"));
    CHECK(find(text, "OUt") == string("out"));
    CHECK(find(text, "uot") == string("out"));
    CHECK(find(text, "UOt") == string("out"));
    CHECK(find(text, "Out") == string("out"));
}

TEST_CASE("Test replacement of d, D, t, T"){
    string text = "daTe xxx ted yyy";
    CHECK(find(text, "date") == string("daTe"));
    CHECK(find(text, "DaTe") == string("daTe"));
    CHECK(find(text, "tade") == string("daTe"));
    CHECK(find(text, "Tate") == string("daTe"));
    CHECK(find(text, "daTe") == string("daTe"));
    CHECK(find(text, "taDe") == string("daTe"));
    CHECK(find(text, "dade") == string("daTe"));
    CHECK(find(text, "daDe") == string("daTe"));
    CHECK(find(text, "ted") == string("ted"));
    CHECK(find(text, "det") == string("ted"));
    CHECK(find(text, "TeD") == string("ted"));
    CHECK(find(text, "teT") == string("ted"));
    CHECK(find(text, "teD") == string("ted")); 
    text = "ted"; 
    CHECK(find(text, "Det") == string("ted"));
    CHECK(find(text, "ted") == string("ted"));
    CHECK(find(text, "teD") == string("ted"));
}

TEST_CASE("Test replacement of i, I, y, Y"){
    string text = "Billy xxx yay";
    CHECK(find(text, "Billy") == string("Billy"));
    CHECK(find(text, "BIlly") == string("Billy"));
    CHECK(find(text, "BillY") == string("Billy"));
    CHECK(find(text, "BillI") == string("Billy"));
    CHECK(find(text, "Bylly") == string("Billy"));
    CHECK(find(text, "BYlly") == string("Billy"));
    CHECK(find(text, "Bylli") == string("Billy"));
    CHECK(find(text, "yay") == string("yay"));
    CHECK(find(text, "yaY") == string("yay"));
    CHECK(find(text, "iai") == string("yay"));
    CHECK(find(text, "iay") == string("yay"));
    CHECK(find(text, "yai") == string("yay"));
    CHECK(find(text, "Yai") == string("yay"));
    CHECK(find(text, "IaI") == string("yay"));
}