///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/07 18:48)

#ifndef CPP_TEMPLATES_PLACEHOLDER_PLACEHOLDER_H
#define CPP_TEMPLATES_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/CppTemplates/CppTemplatesDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CppTemplates
{
    class CPP_TEMPLATES_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CPP_TEMPLATES_PLACEHOLDER_PLACEHOLDER_H
