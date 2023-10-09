/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <memory>
#include <vector>

namespace kagome::host_api {
  class HostApiFactory;
}

namespace kagome::crypto {
  class Hasher;
}

namespace kagome::runtime {

  class Core;

  /**
   * A factory for Core API, used where an isolated runtime environment
   * is required
   */
  class CoreApiFactory {
   public:
    virtual ~CoreApiFactory() = default;

    [[nodiscard]] virtual std::unique_ptr<Core> make(
        std::shared_ptr<const crypto::Hasher> hasher,
        const std::vector<uint8_t> &runtime_code) const = 0;
  };

}  // namespace kagome::runtime
