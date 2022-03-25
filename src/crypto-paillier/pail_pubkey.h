//
// Created by Sword03 on 2021/6/9.
//

#ifndef CPP_MPC_PAIL_PUBKEY_H
#define CPP_MPC_PAIL_PUBKEY_H

#include <string>
#include "crypto-bn/bn.h"
#include "paillier.pb.h"

namespace safeheron{
namespace pail {

class PailPrivKey;

class PailPubKey {
    friend void CreateKeyPair(PailPrivKey &priv, PailPubKey &pub, int key_bits);

public:
    PailPubKey();

    /**
     * Constructor of PailPubKey
     * @param n = pq
     * @param g = n + 1
     * @constructor
     */
    PailPubKey(const safeheron::bignum::BN &n, const safeheron::bignum::BN &g);

    std::string Inspect() const;

    /**
     * Encrypt:
     *     c = g^m * r^n mod n^2
     *       = (1 + m*n) * r^n mod n^2
     *
     * @param {safeheron::bignum::BN} m: number to be encrypted
     * @param {safeheron::bignum::BN} r : random number
     */
    safeheron::bignum::BN EncryptWithR(const safeheron::bignum::BN &m, const safeheron::bignum::BN &r) const;

    safeheron::bignum::BN EncryptWithR_v0(const safeheron::bignum::BN &m, const safeheron::bignum::BN &r) const;

    /**
     * Encrypt:
     *     c = g^m * r^n mod n^2
     *       = (1 + m*n) * r^n mod n^2
     *
     * @param {safeheron::bignum::BN} m: number to be encrypted
     */
    safeheron::bignum::BN Encrypt(const safeheron::bignum::BN &m) const;

    safeheron::bignum::BN Encrypt_v0(const safeheron::bignum::BN &m) const;

    /**
     * Homomorphic add:
     *     E(a+b) = E(a) * E(b) mod n^2
     * @param {safeheron::bignum::BN} e_a: encrypted num a
     * @param {safeheron::bignum::BN} e_b: encrypted num b
     */
    safeheron::bignum::BN Add(const safeheron::bignum::BN &e_a, const safeheron::bignum::BN &e_b) const;

    /**
     * Homomorphic add:
     *     E(a+b) = E(a) * g^b mod n^2
     *            = E(a) * (1 + b*n) mod n^2
     * @param {safeheron::bignum::BN} e_a: encrypted num a
     * @param {safeheron::bignum::BN} b: plain num b
     */
    safeheron::bignum::BN AddPlain(const safeheron::bignum::BN &e_a, const safeheron::bignum::BN &b) const;

    safeheron::bignum::BN AddPlain_v0(const safeheron::bignum::BN &e_a, const safeheron::bignum::BN &b) const;

    /**
     * Homomorphic multiple:
     *     E(ka) = E(a) ^ k mod n^2
     * @param {safeheron::bignum::BN} e_a: encrypted num a
     * @param {safeheron::bignum::BN} k: plain num to multiple
     */
    safeheron::bignum::BN Mul(const safeheron::bignum::BN &e_a, const safeheron::bignum::BN &k) const;

    safeheron::bignum::BN n() const { return n_; }

    safeheron::bignum::BN g() const { return g_; }

    safeheron::bignum::BN n_sqr() const { return n_sqr_; }

    bool ToProtoObject(safeheron::proto::PailPub &pail_pub) const;

    bool FromProtoObject(const safeheron::proto::PailPub &pail_pub);

    bool ToBase64(std::string &base64) const;

    bool FromBase64(const std::string &base64);

    bool ToJsonString(std::string &json_str) const;

    bool FromJsonString(const std::string &json_str);

private:
    safeheron::bignum::BN n_;   // n = pq
    safeheron::bignum::BN g_;   // g = n + 1
    safeheron::bignum::BN n_sqr_;

};

};
};


#endif //CPP_MPC_PAIL_PUBKEY_H
