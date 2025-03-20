/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.2.0 (2025/01/06 10:38)

#ifndef GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "GameClient/GameClientCore/GameClientCoreDll.h"

#include "GameClient/GameClientCore/Helper/ExportMacro.h"

namespace GameClientCore
{
    class GAME_CLIENT_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H