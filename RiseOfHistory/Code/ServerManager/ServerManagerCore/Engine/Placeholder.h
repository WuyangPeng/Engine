/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:45)

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