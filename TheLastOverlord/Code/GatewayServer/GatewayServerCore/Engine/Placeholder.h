/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GatewayServer/GatewayServerCore/GatewayServerCoreDll.h"

#include "GatewayServer/GatewayServerCore/Helper/ExportMacro.h"

namespace GatewayServerCore
{
    class GATEWAY_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // GATEWAY_SERVER_CORE_ENGINE_PLACEHOLDER_H