/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.0 (2024/06/20 15:14)

#ifndef SERVER_MANAGER_CORE_ENGINE_PLACEHOLDER_H
#define SERVER_MANAGER_CORE_ENGINE_PLACEHOLDER_H

#include "ServerManager/ServerManagerCore/ServerManagerCoreDll.h"

#include "ServerManager/ServerManagerCore/Helper/ExportMacro.h"

namespace ServerManagerCore
{
    class SERVER_MANAGER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // SERVER_MANAGER_CORE_ENGINE_PLACEHOLDER_H