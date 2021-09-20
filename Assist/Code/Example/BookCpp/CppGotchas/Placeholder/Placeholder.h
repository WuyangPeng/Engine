///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:29)

#ifndef CPP_GOTCHAS_PLACEHOLDER_PLACEHOLDER_H
#define CPP_GOTCHAS_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/CppGotchas/CppGotchasDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CppGotchas
{
    class CPP_GOTCHAS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CPP_GOTCHAS_PLACEHOLDER_PLACEHOLDER_H
