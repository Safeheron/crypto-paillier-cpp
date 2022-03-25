//
// Created by Sword03 on 2020/10/22.
//
#include "gtest/gtest.h"
#include "crypto-bn/rand.h"
#include "crypto-bn/bn.h"
#include "exception/located_exception.h"
#include "crypto-paillier/pail.h"
using namespace std;
using namespace safeheron::bignum;
using safeheron::pail::PailPrivKey;
using safeheron::pail::PailPubKey;

int main(int argc, char **argv) {
    PailPrivKey priv;
    PailPubKey pub;
    CreateKeyPair(priv, pub, 1024);
    std::string jsonStr;
    priv.ToJsonString(jsonStr);
    std::cout << "priv = " << jsonStr << std::endl;
    pub.ToJsonString(jsonStr);
    std::cout << "pub = " << jsonStr << std::endl;

    std::string s;
    BN m = safeheron::rand::RandomBNLt(pub.n());
    m.ToHexStr(s);
    std::cout << "m = " << s << std::endl;
    BN c = pub.Encrypt(m);
    c.ToHexStr(s);
    std::cout << "c = " << s << std::endl;
    BN expect_m = priv.Decrypt(c);
    expect_m.ToHexStr(s);
    std::cout << "expect_m = " << s << std::endl;
    EXPECT_EQ(m , expect_m);
    return 0;
}
