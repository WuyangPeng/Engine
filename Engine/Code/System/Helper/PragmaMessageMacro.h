//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 15:05)

#ifndef SYSTEM_HELPER_PRAGMA_MESSAGE_MACRO_H
#define SYSTEM_HELPER_PRAGMA_MESSAGE_MACRO_H

#include "UserMacro.h"

#if defined(TCRE_USE_NVCC)
    #pragma message("������: NVIDIA CUDA C++")
#endif  // defined(TCRE_USE_NVCC)

#if defined(TCRE_USE_GCC_XML)
    #pragma message("������: GCC-XML")
#elif defined(TCRE_USE_CRAY)
    #pragma message("������: Cray")
#elif defined(TCRE_USE_COMEAU)
    #pragma message("������: Comeau")
#elif defined(TCRE_USE_PATH_SCALE)
    #pragma message("������: PathScale EKOPath")
#elif defined(TCRE_USE_INTEL)
    #pragma message("������: Intel C/C++")
#elif defined(TCRE_USE_CLANG)
    #pragma message("������: clang")
#elif defined(TCRE_USE_DIGITAL_MARS)
    #pragma message("������: Digital Mars")
#elif defined(TCRE_USE_GCC)
    #pragma message("������: GNU C++")
#elif defined(TCRE_USE_KAI)
    #pragma message("������: Kai C++")
#elif defined(TCRE_USE_SGI_MIPSPRO)
    #pragma message("������: SGI MIPSpro C++")
#elif defined(TCRE_USE_COMPAQ_CXX)
    #pragma message("������: Compaq Tru64 Unix cxx")
#elif defined(TCRE_USE_GREENHILLS)
    #pragma message("������: Greenhills C++")
#elif defined(TCRE_USE_CODE_GEAR)
    #pragma message("������: CodeGear")
#elif defined(TCRE_USE_BORLANDC)
    #pragma message("������: Borland")
#elif defined(TCRE_USE_METROWERKS)
    #pragma message("������: CodeWarrior")
#elif defined(TCRE_USE_SUNPRO_CC)
    #pragma message("������: Sun Workshop C++")
#elif defined(TCRE_USE_HP_ACC)
    #pragma message("������: HP aCC")
#elif defined(TCRE_USE_MPW)
    #pragma message("������: MPW")
#elif defined(TCRE_USE_XLCPP)
    #pragma message("������: IBM XL C/C++ (С��)")
#elif defined(TCRE_USE_VACPP)
    #pragma message("������: IBM Visual Age ��  IBM XL C/C++ (���)")
#elif defined(TCRE_USE_PGI)
    #pragma message("������: Portland Group Inc")
#elif defined(TCRE_USE_MSVC)
    #pragma message("������: Visual C++")
#else  // !defined(ALL_COMPILER)
    #error "�������޷�����ȷʶ��"
#endif  // defined(ALL_COMPILER)

#endif  // SYSTEM_HELPER_PRAGMA_MESSAGE_MACRO_H
