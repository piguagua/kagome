/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "runtime/core_api_factory.hpp"
#include "runtime/runtime_api/core.hpp"

namespace kagome::storage::trie {
  class TrieStorage;
}

namespace kagome::blockchain {
  class BlockHeaderRepository;
}

namespace kagome::runtime {
  class TrieStorageProvider;
  class Memory;
  class RuntimeEnvironmentFactory;
  class RuntimePropertiesCache;
}  // namespace kagome::runtime

namespace kagome::runtime::binaryen {

  class InstanceEnvironmentFactory;
  class BinaryenMemoryFactory;

  class CoreApiFactoryImpl final
      : public runtime::CoreApiFactory,
        public std::enable_shared_from_this<CoreApiFactoryImpl> {
   public:
    CoreApiFactoryImpl(
        std::shared_ptr<const InstanceEnvironmentFactory> instance_env_factory,
        std::shared_ptr<const blockchain::BlockHeaderRepository> header_repo,
        std::shared_ptr<runtime::RuntimePropertiesCache> cache);

    std::unique_ptr<Core> make(
        std::shared_ptr<const crypto::Hasher> hasher,
        const std::vector<uint8_t> &runtime_code) const override;

   private:
    std::shared_ptr<const InstanceEnvironmentFactory> instance_env_factory_;
    std::shared_ptr<const blockchain::BlockHeaderRepository> header_repo_;
    std::shared_ptr<runtime::RuntimePropertiesCache> cache_;
  };

}  // namespace kagome::runtime::binaryen
