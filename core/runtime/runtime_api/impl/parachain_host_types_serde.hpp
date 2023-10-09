/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "runtime/runtime_api/parachain_host_types.hpp"
#include "scale/scale.hpp"

namespace kagome::runtime {

  ::scale::ScaleEncoderStream &operator<<(::scale::ScaleEncoderStream &s,
                                          const OccupiedCore &val);
  ::scale::ScaleDecoderStream &operator>>(::scale::ScaleDecoderStream &s,
                                          OccupiedCore &val);
  ::scale::ScaleEncoderStream &operator<<(::scale::ScaleEncoderStream &s,
                                          const PersistedValidationData &val);
  ::scale::ScaleDecoderStream &operator>>(::scale::ScaleDecoderStream &s,
                                          PersistedValidationData &val);
  ::scale::ScaleEncoderStream &operator<<(::scale::ScaleEncoderStream &s,
                                          const Candidate &val);
  ::scale::ScaleDecoderStream &operator>>(::scale::ScaleDecoderStream &s,
                                          Candidate &val);
  ::scale::ScaleEncoderStream &operator<<(::scale::ScaleEncoderStream &s,
                                          const CandidateBacked &val);
  ::scale::ScaleDecoderStream &operator>>(::scale::ScaleDecoderStream &s,
                                          CandidateBacked &val);
  ::scale::ScaleEncoderStream &operator<<(::scale::ScaleEncoderStream &s,
                                          const CandidateIncluded &val);
  ::scale::ScaleDecoderStream &operator>>(::scale::ScaleDecoderStream &s,
                                          CandidateIncluded &val);
  ::scale::ScaleEncoderStream &operator<<(::scale::ScaleEncoderStream &s,
                                          const SessionInfo &val);
  ::scale::ScaleDecoderStream &operator>>(::scale::ScaleDecoderStream &s,
                                          SessionInfo &val);
}  // namespace kagome::runtime
