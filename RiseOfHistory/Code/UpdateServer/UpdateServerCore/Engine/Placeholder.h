/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "UpdateServer/UpdateServerCore/UpdateServerCoreDll.h"

#include "UpdateServer/UpdateServerCore/Helper/ExportMacro.h"

namespace UpdateServerCore
{
    class UPDATE_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // UPDATE_SERVER_CORE_ENGINE_PLACEHOLDER_H