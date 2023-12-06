/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define DATABASE_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define DATABASE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(DatabaseServerCore, implClassName, DATABASE_SERVER_CORE_DEFAULT_DECLARE)

#endif  // DATABASE_SERVER_CORE_HELPER_EXPORT_MACRO_H