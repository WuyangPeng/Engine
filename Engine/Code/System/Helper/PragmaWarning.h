///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 17:51)

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
