/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef WEAK_FROM_SHARED_HPP
#define WEAK_FROM_SHARED_HPP

#include <memory>

namespace kagome {

  template <typename T>
  std::weak_ptr<T> weak_from_shared(const std::shared_ptr<T> &val) {
    return {val};
  }

}  // namespace kagome

#endif  // WEAK_FROM_SHARED_HPP
