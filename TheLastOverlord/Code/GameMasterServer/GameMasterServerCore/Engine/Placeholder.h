///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 22:18)

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
