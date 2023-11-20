/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef SERVER_MANAGER_CORE_HELPER_EXPORT_MACRO_H
#define SERVER_MANAGER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define SERVER_MANAGER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(ServerManagerCore, implClassName, SERVER_MANAGER_CORE_DEFAULT_DECLARE)

#endif  // SERVER_MANAGER_CORE_HELPER_EXPORT_MACRO_H