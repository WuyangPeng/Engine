///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.8.1.0 (2022/08/03 11:06)

#ifndef GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "GameClient/GameClientCore/GameClientCoreDll.h"

#include "GameClient/GameClientCore/Helper/ExportMacro.h"

namespace GameClientCore
{
    class GAME_CLIENT_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // GAME_CLIENT_CORE_ENGINE_PLACEHOLDER_H