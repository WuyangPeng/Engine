//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	„ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//	Ѕ™ѕµ„ч’я£Ї94458936@qq.com
//
//	±к„Љ£Їstd:c++17
//	“э«ж∞ж±Њ£Ї0.5.1.0 (2020/09/21 15:05)

#ifndef SYSTEM_HELPER_PRAGMA_MESSAGE_MACRO_H
#define SYSTEM_HELPER_PRAGMA_MESSAGE_MACRO_H

#include "UserMacro.h"

#if defined(TCRE_USE_NVCC)
    #pragma message("±а“л∆ч: NVIDIA CUDA C++")
#endif  // defined(TCRE_USE_NVCC)

#if defined(TCRE_USE_GCC_XML)
    #pragma message("±а“л∆ч: GCC-XML")
#elif defined(TCRE_USE_CRAY)
    #pragma message("±а“л∆ч: Cray")
#elif defined(TCRE_USE_COMEAU)
    #pragma message("±а“л∆ч: Comeau")
#elif defined(TCRE_USE_PATH_SCALE)
    #pragma message("±а“л∆ч: PathScale EKOPath")
#elif defined(TCRE_USE_INTEL)
    #pragma message("±а“л∆ч: Intel C/C++")
#elif defined(TCRE_USE_CLANG)
    #pragma message("±а“л∆ч: clang")
#elif defined(TCRE_USE_DIGITAL_MARS)
    #pragma message("±а“л∆ч: Digital Mars")
#elif defined(TCRE_USE_GCC)
    #pragma message("±а“л∆ч: GNU C++")
#elif defined(TCRE_USE_KAI)
    #pragma message("±а“л∆ч: Kai C++")
#elif defined(TCRE_USE_SGI_MIPSPRO)
    #pragma message("±а“л∆ч: SGI MIPSpro C++")
#elif defined(TCRE_USE_COMPAQ_CXX)
    #pragma message("±а“л∆ч: Compaq Tru64 Unix cxx")
#elif defined(TCRE_USE_GREENHILLS)
    #pragma message("±а“л∆ч: Greenhills C++")
#elif defined(TCRE_USE_CODE_GEAR)
    #pragma message("±а“л∆ч: CodeGear")
#elif defined(TCRE_USE_BORLANDC)
    #pragma message("±а“л∆ч: Borland")
#elif defined(TCRE_USE_METROWERKS)
    #pragma message("±а“л∆ч: CodeWarrior")
#elif defined(TCRE_USE_SUNPRO_CC)
    #pragma message("±а“л∆ч: Sun Workshop C++")
#elif defined(TCRE_USE_HP_ACC)
    #pragma message("±а“л∆ч: HP aCC")
#elif defined(TCRE_USE_MPW)
    #pragma message("±а“л∆ч: MPW")
#elif defined(TCRE_USE_XLCPP)
    #pragma message("±а“л∆ч: IBM XL C/C++ (–°ґЋ)")
#elif defined(TCRE_USE_VACPP)
    #pragma message("±а“л∆ч: IBM Visual Age їт  IBM XL C/C++ (іуґЋ)")
#elif defined(TCRE_USE_PGI)
    #pragma message("±а“л∆ч: Portland Group Inc")
#elif defined(TCRE_USE_MSVC)
    #pragma message("±а“л∆ч: Visual C++")
#else  // !defined(ALL_COMPILER)
    #error "±а“л∆чќёЈ®±ї’э»Ј ґ±р°£"
#endif  // defined(ALL_COMPILER)

#endif  // SYSTEM_HELPER_PRAGMA_MESSAGE_MACRO_H
