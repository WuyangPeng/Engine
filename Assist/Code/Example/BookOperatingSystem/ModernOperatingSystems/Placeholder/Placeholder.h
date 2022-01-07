///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:23)

#ifndef MODERN_OPERATING_SYSTEMS_PLACEHOLDER_H
#define MODERN_OPERATING_SYSTEMS_PLACEHOLDER_H

#include "Example/BookOperatingSystem/ModernOperatingSystems/ModernOperatingSystemsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ModernOperatingSystems
{
    class MODERN_OPERATING_SYSTEMS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // MODERN_OPERATING_SYSTEMS_PLACEHOLDER_H
