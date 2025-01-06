/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.2.0 (2025/01/06 10:02)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H
#define SERVER_MANAGER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define SERVER_MANAGER_MIDDLE_LAYER_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(ServerManagerMiddleLayer, implClassName, SERVER_MANAGER_MIDDLE_LAYER_DEFAULT_DECLARE)

#endif  // SERVER_MANAGER_MIDDLE_LAYER_HELPER_EXPORT_MACRO_H