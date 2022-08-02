///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/23 13:31)

#ifndef GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GatewayServer/GatewayServerCore/GatewayServerCoreDll.h"

#include "GatewayServer/GatewayServerCore/Macro/ExportMacro.h"

namespace GatewayServerCore
{
    class GATEWAY_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H
