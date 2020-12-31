//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/09 15:44)

#ifndef CORE_TOOLS_HELPER_SHARED_PTR_MACRO_H
#define CORE_TOOLS_HELPER_SHARED_PTR_MACRO_H

#include "UserMacro.h"

#define CORE_TOOLS_SHARED_PTR_DECLARE(className)                                  \
    using SYSTEM_CONCATENATOR(className, SharedPtr) = std::shared_ptr<className>; \
    using SYSTEM_MULTIPLE_CONCATENATOR(Const, className, SharedPtr) = std::shared_ptr<const className>;

#define CORE_TOOLS_WEAK_PTR_DECLARE(className)                                \
    using SYSTEM_CONCATENATOR(className, WeakPtr) = std::weak_ptr<className>; \
    using SYSTEM_MULTIPLE_CONCATENATOR(Const, className, WeakPtr) = std::weak_ptr<const className>;

#endif  // CORE_TOOLS_HELPER_SHARED_PTR_MACRO_H
