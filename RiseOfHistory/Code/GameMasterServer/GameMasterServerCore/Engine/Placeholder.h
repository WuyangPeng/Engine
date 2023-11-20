/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "GameMasterServer/GameMasterServerCore/GameMasterServerCoreDll.h"

#include "GameMasterServer/GameMasterServerCore/Helper/ExportMacro.h"

namespace GameMasterServerCore
{
    class GAME_MASTER_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // GAME_MASTER_SERVER_CORE_ENGINE_PLACEHOLDER_H