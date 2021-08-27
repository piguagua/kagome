/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "runtime/wavm/module_factory_impl.hpp"

#include "runtime/wavm/module.hpp"

namespace kagome::runtime::wavm {

  ModuleFactoryImpl::ModuleFactoryImpl(
      std::shared_ptr<CompartmentWrapper> compartment,
      std::shared_ptr<const InstanceEnvironmentFactory> env_factory)
      : compartment_{std::move(compartment)}, env_factory_{std::move(env_factory)} {
    BOOST_ASSERT(compartment_ != nullptr);
    BOOST_ASSERT(env_factory_ != nullptr);
  }

  outcome::result<std::unique_ptr<Module>> ModuleFactoryImpl::make(
      const storage::trie::RootHash &state,
      gsl::span<const uint8_t> code) const {
    return ModuleImpl::compileFrom(compartment_, env_factory_, code);
  }

}  // namespace kagome::runtime::wavm