///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.2 (2022/09/04 21:48)

#ifndef SYSTEM_HELPER_SELECT_COMPILER_CONFIG_H
#define SYSTEM_HELPER_SELECT_COMPILER_CONFIG_H

// �����TCRE_COMPILER_VERSION��ʾ�������汾������TCRE_SYSTEM_COMPILER��ʾ���������ơ�

#if defined(__CUDACC__)

    // ������GPU��NVIDIA CUDA C ++������
    #include "Compiler/Nvcc.h"
#endif  // __CUDACC__

#if defined(__GCCXML__)

    // GCC-XMLģ����������������������Ϊ��һ�����֣�
    #define TCRE_COMPILER_CONFIG "Compiler/GccXml.h"

#elif defined(_CRAYC)

    // ����EDG��Cray������
    #define TCRE_COMPILER_CONFIG "Compiler/Cray.h"

#elif defined(__COMO__)

    // Comeau C++
    #define TCRE_COMPILER_CONFIG "Compiler/Comeau.h"

#elif defined(__PATHSCALE__) && (4 <= __PATHCC__)

    // PathScale EKOPath����������������clang��gcc��
    #define TCRE_COMPILER_CONFIG "Compiler/PathScale.h"

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)

    // Intel
    #define TCRE_COMPILER_CONFIG "Compiler/Intel.h"

#elif defined(__clang__) && !defined(__CUDACC__) && !defined(__ibmxl__)

    // Clang C++ģ��GCC��������������ָ��硣
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

    // CodeGear����������Borland֮ǰ���
    #define TCRE_COMPILER_CONFIG "Compiler/CodeGear.h"

#elif defined(__BORLANDC__)

    // Borland
    #define TCRE_COMPILER_CONFIG "Compiler/Borland.h"

#elif defined(__MWERKS__)

    // Metrowerks CodeWarrior
    #define TCRE_COMPILER_CONFIG "Compiler/Metrowerks.h"

#elif defined(__SUNPRO_CC)

    // Sun Workshop C++ ������
    #define TCRE_COMPILER_CONFIG "Compiler/SunproCc.h"

#elif defined(__HP_aCC)

    // HP aCC
    #define TCRE_COMPILER_CONFIG "Compiler/HpAcc.h"

#elif defined(__MRC__) || defined(__SC__)

    // MPW MrCpp �� SCpp
    #define TCRE_COMPILER_CONFIG "Compiler/Mpw.h"

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

    //  IBM z/OS XL C/C++
    #define TCRE_COMPILER_CONFIG "Compiler/XlcppZos.h"

#elif defined(__ibmxl__)

    // ����Linux��IBM XL C/C++��С�ˣ�
    #define TCRE_COMPILER_CONFIG "Compiler/Xlcpp.h"

#elif defined(__IBMCPP__)

    // IBM Visual Age ������Linux��IBM XL C/C++����ˣ�
    #define TCRE_COMPILER_CONFIG "Compiler/Vacpp.h"

#elif defined _MSC_VER

    // ΢��Visual C++�����뱣�������һ��#elif����ΪһЩ������Ӧ�̣�����Metrowerks����Ҳ����_MSC_VER
    #define TCRE_COMPILER_CONFIG "Compiler/Visualc.h"

#else  // !defined(ALL_COMPILER)

    // ��������������һ��������������޷�ʶ���������
    #error "�������޷�����ȷʶ��"

#endif  // defined(ALL_COMPILER)

#include TCRE_COMPILER_CONFIG

#endif  // SYSTEM_HELPER_SELECT_COMPILER_CONFIG_H
