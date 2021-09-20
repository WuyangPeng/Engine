///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:25)

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
