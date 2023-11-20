/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef SERVER_MANAGER_CORE_HELPER_EXPORT_MACRO_H
#define SERVER_MANAGER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define SERVER_MANAGER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(ServerManagerCore, implClassName, SERVER_MANAGER_CORE_DEFAULT_DECLARE)

#endif  // SERVER_MANAGER_CORE_HELPER_EXPORT_MACRO_H