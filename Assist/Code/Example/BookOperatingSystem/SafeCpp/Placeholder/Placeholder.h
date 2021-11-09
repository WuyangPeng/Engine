///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:22)

#ifndef SAFE_CPP_PLACEHOLDER_H
#define SAFE_CPP_PLACEHOLDER_H

#include "Example/BookOperatingSystem/SafeCpp/SafeCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace SafeCpp
{
    class SAFE_CPP_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // SAFE_CPP_PLACEHOLDER_H
