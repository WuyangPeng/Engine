/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/23 21:10)

#ifndef SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H
#define SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H

/// �����TCRE_CPP_LIB_VERSION��ʾ��׼��汾������TCRE_SYSTEM_STD_LIB��ʾ��׼�����ơ�

#include <cstddef>

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

    /// ���������ڵ�һ����
    /// ��������STLPortͨ��λ��һЩ������Ķ�����
    /// ���ǿ������ռ�⵽��һ��������STLPort��
    #define TCRE_STDLIB_CONFIG "StdLib/STLPort.h"

#else  // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

    /// ������ǵ�std lib����ĳ���汾��STLPort��
    /// ����û�б���⵽��
    /// ��ô����<utility>��
    /// ��Ϊ���ǰ���������C++ std����С��ͷ�ļ���

    /// һЩstd�ⲻ�������ǵ�C++��صĺ���<cstddef>��
    /// �����������İ���ȷ�����ǵõ���Щ���塣
    /// ע�⣺��Ҫ�����ڰ������ͷ�ļ���
    /// ��Ϊ�û����Զ�·���#include��
    /// �������֪����������ʹ���ĸ�std�⡣

    #if !defined(__LIBCOMO__) &&          \
        !defined(__STD_RWCOMPILER_H__) && \
        !defined(_RWSTD_VER) &&           \
        !defined(_LIBCPP_VERSION) &&      \
        !defined(__GLIBCPP__) &&          \
        !defined(__GLIBCXX__) &&          \
        !defined(__STL_CONFIG_H) &&       \
        !defined(__MSL_CPP__) &&          \
        !defined(__IBMCPP__) &&           \
        !defined(MSIPL_COMPILE_H) &&      \
        !defined(_YVALS) &&               \
        !defined(_CPPLIB_VER)

        #include <utility>

    #endif  // !defined(ALL_STDLIB)

    #if defined(__LIBCOMO__)

        /// Comeau STL
        #define TCRE_STDLIB_CONFIG "StdLib/LibComo.h"

    #elif defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)

        /// Rogue Wave��
        #define TCRE_STDLIB_CONFIG "StdLib/RogueWave.h"

    #elif defined(_LIBCPP_VERSION)

        /// libc++
        #define TCRE_STDLIB_CONFIG "StdLib/LibCpp.h"

    #elif defined(__GLIBCPP__) || defined(__GLIBCXX__)

        /// GNU libstdc++ 3
        #define TCRE_STDLIB_CONFIG "StdLib/LibStdCpp3.h"

    #elif defined(__STL_CONFIG_H)

        /// ͨ�� SGI STL
        #define TCRE_STDLIB_CONFIG "StdLib/Sgi.h"

    #elif defined(__MSL_CPP__)

        /// MSL ��׼��
        #define TCRE_STDLIB_CONFIG "StdLib/Msl.h"

    #elif defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

        /// IBM z/OS XL C/C++
        #define TCRE_STDLIB_CONFIG "StdLib/XlCppZos.h"

    #elif defined(__IBMCPP__)

        /// ����Ĭ�ϵ� VaCpp std lib
        #define TCRE_STDLIB_CONFIG "StdLib/VaCpp.hpp"

    #elif defined(MSIPL_COMPILE_H)

        /// Modena C++ ��׼��
        #define TCRE_STDLIB_CONFIG "StdLib/Modena.h"

    #elif (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)

        /// Dinkumware �⣨�����������κο��ܵ��滻��֮��
        #define TCRE_STDLIB_CONFIG "StdLib/Dinkumware.h"

    #else  // !defined(ALL_STDLIB)

        /// ������Ƿ����������һ��������������޷�ʶ���
        #error "��׼���޷�����ȷʶ��"

    #endif  // defined(ALL_STDLIB)

#endif  // defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

#include TCRE_STDLIB_CONFIG

#endif  // SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H
