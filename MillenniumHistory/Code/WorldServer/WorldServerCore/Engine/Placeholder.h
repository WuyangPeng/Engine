/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef WORLD_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define WORLD_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "WorldServer/WorldServerCore/WorldServerCoreDll.h"

#include "WorldServer/WorldServerCore/Helper/ExportMacro.h"

namespace WorldServerCore
{
    class WORLD_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // WORLD_SERVER_CORE_ENGINE_PLACEHOLDER_H