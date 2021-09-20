///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/01 14:25)

#ifndef COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_PLACEHOLDER_PLACEHOLDER_H
#define COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/ComputingConceptsWithCppEssentials/ComputingConceptsWithCppEssentialsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace ComputingConceptsWithCppEssentials
{
    class COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_PLACEHOLDER_PLACEHOLDER_H
