///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.5 (2023/04/03 09:46)

#ifndef DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define DATABASE_GENERATE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(DatabaseGenerateServerCore, implClassName, DATABASE_GENERATE_SERVER_CORE_DEFAULT_DECLARE)

#endif  // DATABASE_GENERATE_SERVER_CORE_HELPER_EXPORT_MACRO_H