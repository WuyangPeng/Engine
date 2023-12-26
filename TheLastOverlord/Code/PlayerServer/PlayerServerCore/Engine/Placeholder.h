/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#ifndef PLAYER_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define PLAYER_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "PlayerServer/PlayerServerCore/PlayerServerCoreDll.h"

#include "PlayerServer/PlayerServerCore/Helper/ExportMacro.h"

namespace PlayerServerCore
{
    class PLAYER_SERVER_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // PLAYER_SERVER_CORE_ENGINE_PLACEHOLDER_H