//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 15:05)

#ifndef SYSTEM_HELPER_DEPRECATE_MACRO_H
#define SYSTEM_HELPER_DEPRECATE_MACRO_H

// ��ƽ̨�ĺ������һ����������Ϊ��ʱ

#include "UserMacro.h"

#ifdef TCRE_USE_GCC
    #define SYSTEM_DEPRECATED __attribute__((deprecated))
#elif defined(TCRE_USE_MSVC)
    #define SYSTEM_DEPRECATED __declspec(deprecated)
#else  // !defined(TCRE_USE_MSVC) && !defined(TCRE_USE_GCC)
    #define SYSTEM_DEPRECATED
    #pragma message("������δ����SYSTEM_DEPRECATED")
#endif  // TCRE_USE_GCC

#endif  // SYSTEM_HELPER_DEPRECATE_MACRO_H
