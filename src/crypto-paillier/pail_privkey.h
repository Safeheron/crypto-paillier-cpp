//
// Created by 何剑虹 on 2021/6/9.
//

#ifndef CPP_MPC_PAIL_PRIVKEY_H
#define CPP_MPC_PAIL_PRIVKEY_H

#include <string>
#include "crypto-bn/bn.h"
#include "paillier.pb.h"


namespace safeheron{
namespace pail {

class PailPubKey;

class PailPrivKey {
    friend void CreateKeyPair(PailPrivKey &priv, PailPubKey &pub, int key_bits);

public:
    /**
     * Construct of PailPrivKey
     * @constructor
     */
    PailPrivKey();

    /**
     * Construct of PailPrivKey
     * @param lambda = (p-1)(q-1)
     * @param mu = lambda^-1 mod n
     * @param n = pq
     * @constructor
     */
    PailPrivKey(const safeheron::bignum::BN &lambda, const safeheron::bignum::BN &mu, const safeheron::bignum::BN &n);

    /**
     * Construct of PailPrivKey
     * @param lambda = (p-1)(q-1)
     * @param mu = lambda^-1 mod n
     * @param n = pq
     * @param n_sqr = n * n
     * @param p_sqr = p * p
     * @param q_sqr = q * q
     * @param p_minus_1 = p - 1
     * @param q_minus_1 = q - 1
     * @param hp = Lp[g^(p-1) mod p^2]^(-1) mod p
     * @param hq = Lq[g^(q-1) mod q^2]^(-1) mod q
     * @param q_inv_p = q^(-1) mod p
     * @param p_inv_q = p^(-1) mod q
     * @constructor
     */
    PailPrivKey(const safeheron::bignum::BN &lambda, const safeheron::bignum::BN &mu, const safeheron::bignum::BN &n, const safeheron::bignum::BN &n_sqr,
                const safeheron::bignum::BN &p, const safeheron::bignum::BN &q,
                const safeheron::bignum::BN &p_sqr, const safeheron::bignum::BN &q_sqr,
                const safeheron::bignum::BN &p_minus_1, const safeheron::bignum::BN &q_minus_1,
                const safeheron::bignum::BN &hp, const safeheron::bignum::BN &hq,
                const safeheron::bignum::BN &q_inv_p, const safeheron::bignum::BN &p_inv_q);

    std::string Inspect() const;

    /**
     * Decrypt:
     *     c = L(c^lambda mod n^2) * mu mod n
     *
     * @param {safeheron::bignum::BN} c: encrypted number
     */
    safeheron::bignum::BN Decrypt(const safeheron::bignum::BN &c) const;

    safeheron::bignum::BN Decrypt_v0(const safeheron::bignum::BN &c) const;

    safeheron::bignum::BN n() const { return n_; }

    safeheron::bignum::BN n_sqr() const { return n_sqr_; }

    safeheron::bignum::BN mu() const { return mu_; }

    safeheron::bignum::BN lambda() const { return lambda_; }


    bool ToProtoObject(proto_basic::PailPriv &pail_priv) const;

    bool FromProtoObject(const proto_basic::PailPriv &pail_priv);

    bool ToBase64(std::string &base64) const;

    bool FromBase64(const std::string &base64);

    bool ToJsonString(std::string &json_str) const;

    bool FromJsonString(const std::string &json_str);

private:
    safeheron::bignum::BN lambda_;  // lambda = (p-1)(q-1)
    safeheron::bignum::BN mu_;      // mu = lambda^{-1} mod n
    safeheron::bignum::BN n_;       // n = pq
    safeheron::bignum::BN n_sqr_;   // n_sql = n^2

    safeheron::bignum::BN p_;       // p
    safeheron::bignum::BN q_;       // q
    safeheron::bignum::BN p_sqr_;    // p_sqr = p^2
    safeheron::bignum::BN q_sqr_;    // q_sqr = q^2
    safeheron::bignum::BN p_minus_1_; // p_minus_1 = p-1
    safeheron::bignum::BN q_minus_1_; // q_minus_1 = q-1
    safeheron::bignum::BN hp_;      // hp = Lp[ g^(p-1) mod p^2 ]^(-1) mod p
    safeheron::bignum::BN hq_;      // hq = Lq[ g^(q-1) mod q^2 ]^(-1) mod q
    safeheron::bignum::BN q_inv_p_;   // q_inv_p = q^(-1) mod p
    safeheron::bignum::BN p_inv_q_;   // p_inv_q = p^(-1) mod q
};

};
};

#endif //CPP_MPC_PAIL_PRIVKEY_H
