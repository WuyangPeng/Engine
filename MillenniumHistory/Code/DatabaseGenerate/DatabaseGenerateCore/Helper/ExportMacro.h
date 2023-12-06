/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_GENERATE_CORE_HELPER_EXPORT_MACRO_H
#define DATABASE_GENERATE_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define DATABASE_GENERATE_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(DatabaseGenerateCore, implClassName, DATABASE_GENERATE_CORE_DEFAULT_DECLARE)

#define DATABASE_GENERATE_CORE_EXPORT_NON_COPY(implClassName) \
    DATABASE_GENERATE_CORE_EXPORT_SHARED_PTR(implClassName);  \
    EXPORT_NON_COPY(DatabaseGenerateCore, implClassName, DATABASE_GENERATE_CORE_DEFAULT_DECLARE);

#endif  // DATABASE_GENERATE_CORE_HELPER_EXPORT_MACRO_H