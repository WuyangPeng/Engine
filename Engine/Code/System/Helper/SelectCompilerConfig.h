///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/04 21:48)

#ifndef SYSTEM_HELPER_SELECT_COMPILER_CONFIG_H
#define SYSTEM_HELPER_SELECT_COMPILER_CONFIG_H

// 定义宏TCRE_COMPILER_VERSION表示编译器版本，定义TCRE_SYSTEM_COMPILER表示编译器名称。

#if defined(__CUDACC__)

    // 适用于GPU的NVIDIA CUDA C ++编译器
    #include "Compiler/Nvcc.h"
#endif  // __CUDACC__

#if defined(__GCCXML__)

    // GCC-XML模拟其他编译器，它必须作为第一个出现！
    #define TCRE_COMPILER_CONFIG "Compiler/GccXml.h"

#elif defined(_CRAYC)

    // 基于EDG的Cray编译器
    #define TCRE_COMPILER_CONFIG "Compiler/Cray.h"

#elif defined(__COMO__)

    // Comeau C++
    #define TCRE_COMPILER_CONFIG "Compiler/Comeau.h"

#elif defined(__PATHSCALE__) && (4 <= __PATHCC__)

    // PathScale EKOPath编译器（必须先于clang和gcc）
    #define TCRE_COMPILER_CONFIG "Compiler/PathScale.h"

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)

    // Intel
    #define TCRE_COMPILER_CONFIG "Compiler/Intel.h"

#elif defined(__clang__) && !defined(__CUDACC__) && !defined(__ibmxl__)

    // Clang C++模拟GCC，所以它必须出现更早。
    #define TCRE_COMPILER_CONFIG "Compiler/Clang.h"

#elif defined(__DMC__)

    // Digital Mars C++
    #define TCRE_COMPILER_CONFIG "Compiler/DigitalMars.h"

#elif defined(__DCC__)

    //  Wind River Diab C++
    #define TCRE_COMPILER_CONFIG "Compiler/Diab.h"

#elif defined(__PGI)

    // Portland Group Inc
    #define TCRE_COMPILER_CONFIG "Compiler/Pgi.h"

#elif defined(__GNUC__) && !defined(__ibmxl__)

    // GNU C++
    #define TCRE_COMPILER_CONFIG "Compiler/Gcc.h"

#elif defined(__KCC)

    // Kai C++
    #define TCRE_COMPILER_CONFIG "Compiler/Kai.h"

#elif defined(__sgi)

    // SGI MIPSpro C++
    #define TCRE_COMPILER_CONFIG "Compiler/SgiMipspro.h"

#elif defined(__DECCXX)

    // Compaq Tru64 Unix cxx
    #define TCRE_COMPILER_CONFIG "Compiler/CompaqCxx.h"

#elif defined(__ghs)

    //  Greenhills C++
    #define TCRE_COMPILER_CONFIG "Compiler/Greenhills.h"

#elif defined(__CODEGEARC__)

    // CodeGear——必须在Borland之前检查
    #define TCRE_COMPILER_CONFIG "Compiler/CodeGear.h"

#elif defined(__BORLANDC__)

    // Borland
    #define TCRE_COMPILER_CONFIG "Compiler/Borland.h"

#elif defined(__MWERKS__)

    // Metrowerks CodeWarrior
    #define TCRE_COMPILER_CONFIG "Compiler/Metrowerks.h"

#elif defined(__SUNPRO_CC)

    // Sun Workshop C++ 编译器
    #define TCRE_COMPILER_CONFIG "Compiler/SunproCc.h"

#elif defined(__HP_aCC)

    // HP aCC
    #define TCRE_COMPILER_CONFIG "Compiler/HpAcc.h"

#elif defined(__MRC__) || defined(__SC__)

    // MPW MrCpp 或 SCpp
    #define TCRE_COMPILER_CONFIG "Compiler/Mpw.h"

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

    //  IBM z/OS XL C/C++
    #define TCRE_COMPILER_CONFIG "Compiler/XlcppZos.h"

#elif defined(__ibmxl__)

    // 用于Linux的IBM XL C/C++（小端）
    #define TCRE_COMPILER_CONFIG "Compiler/Xlcpp.h"

#elif defined(__IBMCPP__)

    // IBM Visual Age 或用于Linux的IBM XL C/C++（大端）
    #define TCRE_COMPILER_CONFIG "Compiler/Vacpp.h"

#elif defined _MSC_VER

    // 微软Visual C++，必须保持在最后一个#elif，因为一些其他供应商（例如Metrowerks），也定义_MSC_VER
    #define TCRE_COMPILER_CONFIG "Compiler/Visualc.h"

#else  // !defined(ALL_COMPILER)

    // 这必须在最后，生成一个错误，如果我们无法识别编译器。
    #error "编译器无法被正确识别。"

#endif  // defined(ALL_COMPILER)

#include TCRE_COMPILER_CONFIG

#endif  // SYSTEM_HELPER_SELECT_COMPILER_CONFIG_H
