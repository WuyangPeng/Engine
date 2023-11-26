/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef RECHARGE_SERVER_CORE_HELPER_EXPORT_MACRO_H
#define RECHARGE_SERVER_CORE_HELPER_EXPORT_MACRO_H

#include "CoreTools/Helper/ExportMacro.h"

#define RECHARGE_SERVER_CORE_EXPORT_SHARED_PTR(implClassName) \
    EXPORT_SHARED_PTR(RechargeServerCore, implClassName, RECHARGE_SERVER_CORE_DEFAULT_DECLARE)

#endif  // RECHARGE_SERVER_CORE_HELPER_EXPORT_MACRO_H