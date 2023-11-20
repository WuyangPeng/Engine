/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef FIGHTING_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define FIGHTING_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "FightingServer/FightingServerCore/FightingServerCoreDll.h"

#include "FightingServer/FightingServerCore/Helper/ExportMacro.h"

namespace FightingServerCore
{
    class FIGHTING_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // FIGHTING_SERVER_CORE_ENGINE_PLACEHOLDER_H