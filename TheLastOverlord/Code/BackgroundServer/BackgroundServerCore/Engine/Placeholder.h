///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 18:08)

#ifndef BACKGROUND_SERVER_CORE_ENGINE_PLACEHOLDER_H
#define BACKGROUND_SERVER_CORE_ENGINE_PLACEHOLDER_H

#include "BackgroundServer/BackgroundServerCore/BackgroundServerCoreDll.h"

#include "BackgroundServer/BackgroundServerCore/Macro/ExportMacro.h"

namespace BackgroundServerCore
{
    class BACKGROUND_SERVER_CORE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        Placeholder() noexcept;

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // BACKGROUND_SERVER_CORE_ENGINE_PLACEHOLDER_H
