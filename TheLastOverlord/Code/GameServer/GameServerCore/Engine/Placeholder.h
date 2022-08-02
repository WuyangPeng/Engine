///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/24 21:56)

#ifndef GAME_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GAME_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GameServer/GameServerCore/GameServerCoreDll.h"

#include "GameServer/GameServerCore/Macro/ExportMacro.h"

namespace GameServerCore
{
    class GAME_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // GAME_SERVER_CORE_ENGINE_PLACEHOLDER_H
