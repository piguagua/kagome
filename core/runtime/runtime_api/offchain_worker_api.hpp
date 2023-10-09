/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "outcome/outcome.hpp"
#include "primitives/block_header.hpp"
#include "primitives/common.hpp"

namespace kagome::runtime {

  class OffchainWorkerApi {
   public:
    virtual ~OffchainWorkerApi() = default;

    /**
     * @brief calls offchain_worker method of OffchainWorker runtime api
     * @param header header of related block
     * @return success or error
     */
    virtual outcome::result<void> offchain_worker(
        const primitives::BlockHash &block,
        const primitives::BlockHeader &header) = 0;
  };

}  // namespace kagome::runtime
