/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef OFFLINE_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define OFFLINE_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define OFFLINE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(OfflineServerCore, implClassName, OFFLINE_SERVER_CORE_DEFAULT_DECLARE)

#endif  // OFFLINE_SERVER_CORE_HELPER_EXPORT_MACRO_H