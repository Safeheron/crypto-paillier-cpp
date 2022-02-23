//
// Created by 何剑虹 on 2020/10/26.
//

#ifndef CPP_MPC_PAILLIAR_H
#define CPP_MPC_PAILLIAR_H

#include "crypto-bn/bn.h"
#include "paillier.pb.h"

#include "pail_pubkey.h"
#include "pail_privkey.h"


namespace safeheron{
namespace pail {

void CreateKeyPair(PailPrivKey &priv, PailPubKey &pub, int key_bits);

void CreateKeyPair1024(PailPrivKey &priv, PailPubKey &pub);

void CreateKeyPair2048(PailPrivKey &priv, PailPubKey &pub);

void CreateKeyPair3072(PailPrivKey &priv, PailPubKey &pub);

void CreateKeyPair4096(PailPrivKey &priv, PailPubKey &pub);

PailPrivKey CreatePailPrivKey(const std::string& lambda_hex, const std::string& mu_hex, const std::string& n_hex, const std::string& n_sqr_hex,
                              const std::string& p_hex, const std::string& q_hex,
                              const std::string& p_sqr_hex, const std::string& q_sqr_hex,
                              const std::string& p_minus_1_hex, const std::string& q_minus_1_hex,
                              const std::string& hp_hex, const std::string& hq_hex,
                              const std::string& q_inv_p_hex, const std::string& p_inv_q_hex);

PailPrivKey CreatePailPrivKey(const std::string& lambda_hex, const std::string& mu_hex, const std::string& n_hex);

PailPubKey CreatePailPubKey(const std::string& n_hex, const std::string& g_hex);

};
};


#endif //CPP_MPC_PAILLIAR_H
