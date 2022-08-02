///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 22:09)

#ifndef RECHARGE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define RECHARGE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "RechargeServer/RechargeServerCore/RechargeServerCoreDll.h"

#include "RechargeServer/RechargeServerCore/Macro/ExportMacro.h"

namespace RechargeServerCore
{
    class RECHARGE_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // RECHARGE_SERVER_CORE_ENGINE_PLACEHOLDER_H
