///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 22:18)

#ifndef GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GameMasterServer/GameMasterServerCore/GameMasterServerCoreDll.h"

#include "GameMasterServer/GameMasterServerCore/Macro/ExportMacro.h"

namespace GameMasterServerCore
{
    class GAME_MASTER_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H
