///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.12 (2023/06/12 21:48)

#ifndef DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define DATABASE_GENERATE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(DatabaseGenerateServerCore, implClassName, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE)

#endif  // DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H