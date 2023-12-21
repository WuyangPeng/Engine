/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:45)

#ifndef FIGHTING_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define FIGHTING_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define FIGHTING_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(FightingServerCore, implClassName, FIGHTING_SERVER_CORE_DEFAULT_DECLARE)

#endif  // FIGHTING_SERVER_CORE_HELPER_EXPORT_MACRO_H