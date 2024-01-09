/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:02)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_H
#define SYSTEM_HELPER_PRAGMA_WARNING_H

#include "System/Helper/ConfigMacro.h"

#define SYSTEM_WARNING_PUSH "System/Helper/PragmaWarning/Push.inl"

#ifdef TCRE_USE_MSVC

    // clang-format off
    #define SYSTEM_WARNING_DISABLE(index) SYSTEM_STRINGIZE(SYSTEM_MULTIPLE_CONCATENATOR(System/Helper/PragmaWarning/Disable, index, .inl))
    // clang-format on

#else  // !TCRE_USE_MSVC

    #define SYSTEM_WARNING_DISABLE(index) "System/Helper/ConfigMacro.h"

#endif  // TCRE_USE_MSVC

#define SYSTEM_WARNING_POP "System/Helper/PragmaWarning/Pop.inl"

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_H
