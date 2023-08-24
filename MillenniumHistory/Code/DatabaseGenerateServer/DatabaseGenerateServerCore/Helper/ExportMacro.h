///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/07/31 21:58)

#ifndef DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define DATABASE_GENERATE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(DatabaseGenerateServerCore, implClassName, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE)

#define DATABASE_GENERATE_SERVER_CORE_EXPORT_NON_COPY(implClassName) \
    DATABASE_GENERATE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName);  \
    EXPORT_NON_COPY(DatabaseGenerateServerCore, implClassName, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE);

#endif  // DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H