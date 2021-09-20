///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 0:14)

#ifndef EXCEPTIONAL_CPP_STYLE_PLACEHOLDER_PLACEHOLDER_H
#define EXCEPTIONAL_CPP_STYLE_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/ExceptionalCppStyle/ExceptionalCppStyleDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ExceptionalCppStyle
{
    class EXCEPTIONAL_CPP_STYLE_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // EXCEPTIONAL_CPP_STYLE_PLACEHOLDER_PLACEHOLDER_H
