///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 17:52)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_H
#define SYSTEM_HELPER_PRAGMA_WARNING_H

#include "System/Helper/ConfigMacro.h"

#define STSTEM_WARNING_PUSH "System/Helper/PragmaWarning/Push.h"

// clang-format off
#define SYSTEM_WARNING_DISABLE(index) SYSTEM_STRINGIZE(SYSTEM_MULTIPLE_CONCATENATOR(System/Helper/PragmaWarning/Disable, index, .h))
// clang-format on

#define STSTEM_WARNING_POP "System/Helper/PragmaWarning/Pop.h"

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_H
