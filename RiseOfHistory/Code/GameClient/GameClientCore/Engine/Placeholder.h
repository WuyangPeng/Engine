///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	历史的崛起版本：0.8.1.0 (2022/08/03 11:06)

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