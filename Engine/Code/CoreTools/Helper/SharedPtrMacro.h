///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 11:05)

#ifndef CORE_TOOLS_HELPER_SHARED_PTR_MACRO_H
#define CORE_TOOLS_HELPER_SHARED_PTR_MACRO_H

#include "UserMacro.h"

#define CORE_TOOLS_SHARED_PTR_DECLARE(className)                                  \
    using SYSTEM_CONCATENATOR(className, SharedPtr) = std::shared_ptr<className>; \
    using SYSTEM_MULTIPLE_CONCATENATOR(Const, className, SharedPtr) = std::shared_ptr<const className>

#define CORE_TOOLS_WEAK_PTR_DECLARE(className)                                \
    using SYSTEM_CONCATENATOR(className, WeakPtr) = std::weak_ptr<className>; \
    using SYSTEM_MULTIPLE_CONCATENATOR(Const, className, WeakPtr) = std::weak_ptr<const className>

#endif  // CORE_TOOLS_HELPER_SHARED_PTR_MACRO_H
