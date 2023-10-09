/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "runtime/executor.hpp"

#include <gmock/gmock.h>

#include "mock/core/runtime/runtime_context_factory_mock.hpp"
#include "mock/core/runtime/runtime_properties_cache_mock.hpp"

namespace kagome::runtime {

  class ExecutorMock : public Executor {
   public:
    ExecutorMock()
        : Executor(std::make_shared<RuntimeContextFactoryMock>(),
                   std::make_shared<RuntimePropertiesCacheMock>()) {}

    ExecutorMock(std::shared_ptr<RuntimeContextFactoryMock> ctx_factory,
                 std::shared_ptr<RuntimePropertiesCacheMock> cache)
        : Executor(ctx_factory, cache) {}

    MOCK_METHOD(outcome::result<Buffer>,
                callWithCtx,
                (RuntimeContext & ctx,
                 std::string_view name,
                 BufferView encoded_args),
                (override));
  };

}  // namespace kagome::runtime
