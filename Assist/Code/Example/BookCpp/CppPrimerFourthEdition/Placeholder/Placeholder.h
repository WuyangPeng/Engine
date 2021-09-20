///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/24 22:01)

#ifndef CPP_PRIMER_FOURTH_EDITION_PLACEHOLDER_PLACEHOLDER_H
#define CPP_PRIMER_FOURTH_EDITION_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/CppPrimerFourthEdition/CppPrimerFourthEditionDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CppPrimerFourthEdition
{
    class CPP_PRIMER_FOURTH_EDITION_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CPP_PRIMER_FOURTH_EDITION_PLACEHOLDER_PLACEHOLDER_H
