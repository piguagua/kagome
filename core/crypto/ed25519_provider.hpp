/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "crypto/bip39/bip39_types.hpp"
#include "crypto/ed25519_types.hpp"

namespace kagome::crypto {

  class Ed25519Provider {
   public:
    using Junctions = gsl::span<const bip39::RawJunction>;

    virtual ~Ed25519Provider() = default;

    /**
     * @brief generates key pair by seed
     * @param seed seed value
     * @return ed25519 key pair
     */
    virtual outcome::result<Ed25519Keypair> generateKeypair(
        const Ed25519Seed &seed, Junctions junctions) const = 0;

    /**
     * Sign message \param msg using \param keypair. If computed value is less
     * than \param threshold then return optional containing this value and
     * proof. Otherwise none returned
     * @param keypair pair of public and private ed25519 keys
     * @param message bytes to be signed
     * @return signed message
     */
    virtual outcome::result<Ed25519Signature> sign(
        const Ed25519Keypair &keypair,
        gsl::span<const uint8_t> message) const = 0;

    /**
     * Verifies that \param message was derived using \param public_key on
     * \param signature
     */
    virtual outcome::result<bool> verify(
        const Ed25519Signature &signature,
        gsl::span<const uint8_t> message,
        const Ed25519PublicKey &public_key) const = 0;
  };
}  // namespace kagome::crypto
