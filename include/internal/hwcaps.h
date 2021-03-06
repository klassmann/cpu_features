// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Interface to retrieve hardware capabilities. It relies on Linux's getauxval
// or `/proc/self/auxval` under the hood.
#ifndef CPU_FEATURES_INCLUDE_INTERNAL_HWCAPS_H_
#define CPU_FEATURES_INCLUDE_INTERNAL_HWCAPS_H_

#include <stdint.h>
#include "cpu_features_macros.h"

CPU_FEATURES_START_CPP_NAMESPACE

// To avoid depending on the linux kernel we reproduce the architecture specific
// constants here.

// http://elixir.free-electrons.com/linux/latest/source/arch/arm64/include/uapi/asm/hwcap.h
#define AARCH64_HWCAP_FP (1UL << 0)
#define AARCH64_HWCAP_ASIMD (1UL << 1)
#define AARCH64_HWCAP_AES (1UL << 3)
#define AARCH64_HWCAP_PMULL (1UL << 4)
#define AARCH64_HWCAP_SHA1 (1UL << 5)
#define AARCH64_HWCAP_SHA2 (1UL << 6)
#define AARCH64_HWCAP_CRC32 (1UL << 7)

// http://elixir.free-electrons.com/linux/latest/source/arch/arm/include/uapi/asm/hwcap.h
#define ARM_HWCAP_VFP (1UL << 6)
#define ARM_HWCAP_IWMMXT (1UL << 9)
#define ARM_HWCAP_NEON (1UL << 12)
#define ARM_HWCAP_VFPV3 (1UL << 13)
#define ARM_HWCAP_VFPV3D16 (1UL << 14)
#define ARM_HWCAP_VFPV4 (1UL << 16)
#define ARM_HWCAP_IDIVA (1UL << 17)
#define ARM_HWCAP_IDIVT (1UL << 18)
#define ARM_HWCAP2_AES (1UL << 0)
#define ARM_HWCAP2_PMULL (1UL << 1)
#define ARM_HWCAP2_SHA1 (1UL << 2)
#define ARM_HWCAP2_SHA2 (1UL << 3)
#define ARM_HWCAP2_CRC32 (1UL << 4)

// http://elixir.free-electrons.com/linux/latest/source/arch/mips/include/uapi/asm/hwcap.h
#define MIPS_HWCAP_VZ (1UL << 0)
#define MIPS_HWCAP_EVA (1UL << 1)
#define MIPS_HWCAP_HTW (1UL << 2)
#define MIPS_HWCAP_FPU (1UL << 3)
#define MIPS_HWCAP_MIPS32R2 (1UL << 4)
#define MIPS_HWCAP_MIPS32R5 (1UL << 5)
#define MIPS_HWCAP_MIPS64R6 (1UL << 6)
#define MIPS_HWCAP_DSPR1 (1UL << 7)
#define MIPS_HWCAP_DSPR2 (1UL << 8)
#define MIPS_HWCAP_MSA (1UL << 9)

typedef struct {
  uint32_t hwcaps;
  uint32_t hwcaps2;
} HardwareCapabilities;

HardwareCapabilities GetHardwareCapabilities(void);

CPU_FEATURES_END_CPP_NAMESPACE

#endif  // CPU_FEATURES_INCLUDE_INTERNAL_HWCAPS_H_
