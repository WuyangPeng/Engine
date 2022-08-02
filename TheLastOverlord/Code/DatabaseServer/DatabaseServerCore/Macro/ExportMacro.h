///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 20:49)

#ifndef DATABASE_SERVER_CORE_MACRO_EXPORT_MACRO_H
#define DATABASE_SERVER_CORE_MACRO_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define DATABASE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(DatabaseServerCore, implClassName, DATABASE_SERVER_CORE_DEFAULT_DECLARE)

#endif  // DATABASE_SERVER_CORE_MACRO_EXPORT_MACRO_H