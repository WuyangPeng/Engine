///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 13:40)

#ifndef SYSTEM_HELPER_PRAGMA_WARNING_H
#define SYSTEM_HELPER_PRAGMA_WARNING_H

#include "System/Helper/ConfigMacro.h"

#define STSTEM_WARNING_PUSH "System/Helper/PragmaWarning/Push.h"

// clang-format off
#define SYSTEM_WARNING_DISABLE(index) SYSTEM_STRINGIZE(SYSTEM_MULTIPLE_CONCATENATOR(System/Helper/PragmaWarning/Disable, index, .h))
// clang-format on

#define STSTEM_WARNING_POP "System/Helper/PragmaWarning/Pop.h"

#endif  // SYSTEM_HELPER_PRAGMA_WARNING_H
