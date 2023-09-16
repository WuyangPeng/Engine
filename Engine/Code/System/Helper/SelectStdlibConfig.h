///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 17:50)

#ifndef SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H
#define SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H

// �����TCRE_CPPLIB_VERSION��ʾ��׼��汾������TCRE_SYSTEM_STDLIB��ʾ��׼�����ơ�

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

        // Comeau STL
        #define TCRE_STDLIB_CONFIG "StdLib/Libcomo.h"

    #elif defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)

        // Rogue Wave��
        #define TCRE_STDLIB_CONFIG "StdLib/Roguewave.h"

    #elif defined(_LIBCPP_VERSION)

        // libc++
        #define TCRE_STDLIB_CONFIG "StdLib/Libcpp.h"

    #elif defined(__GLIBCPP__) || defined(__GLIBCXX__)

        // GNU libstdc++ 3
        #define TCRE_STDLIB_CONFIG "StdLib/Libstdcpp3.h"

    #elif defined(__STL_CONFIG_H)

        // ͨ�� SGI STL
        #define TCRE_STDLIB_CONFIG "StdLib/Sgi.h"

    #elif defined(__MSL_CPP__)

        // MSL ��׼��
        #define TCRE_STDLIB_CONFIG "StdLib/Msl.h"

    #elif defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

        // IBM z/OS XL C/C++
        #define TCRE_STDLIB_CONFIG "StdLib/XlcppZos.h"

    #elif defined(__IBMCPP__)

        // ����Ĭ�ϵ� VACPP std lib
        #define TCRE_STDLIB_CONFIG "StdLib/Vacpp.hpp"

    #elif defined(MSIPL_COMPILE_H)

        // Modena C++ ��׼��
        #define TCRE_STDLIB_CONFIG "StdLib/Modena.h"

    #elif (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)

        // Dinkumware �⣨�����������κο��ܵ��滻��֮��
        #define TCRE_STDLIB_CONFIG "StdLib/Dinkumware.h"

    #else  // !defined(ALL_STDLIB)

        // ������Ƿ����������һ��������������޷�ʶ���
        #error "��׼���޷�����ȷʶ��"

    #endif  // defined(ALL_STDLIB)

#endif  // defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

#include TCRE_STDLIB_CONFIG

#endif  // SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H
