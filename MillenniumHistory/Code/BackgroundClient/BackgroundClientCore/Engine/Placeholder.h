/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef BACKGROUND_CLIENT_CORE_ENGINE_PLACEHOLDER_H
#define BACKGROUND_CLIENT_CORE_ENGINE_PLACEHOLDER_H

#include "BackgroundClient/BackgroundClientCore/BackgroundClientCoreDll.h"

#include "BackgroundClient/BackgroundClientCore/Helper/ExportMacro.h"

namespace BackgroundClientCore
{
    class BACKGROUND_CLIENT_CORE_DEFAULT_DECLARE Placeholder final
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // BACKGROUND_CLIENT_CORE_ENGINE_PLACEHOLDER_H