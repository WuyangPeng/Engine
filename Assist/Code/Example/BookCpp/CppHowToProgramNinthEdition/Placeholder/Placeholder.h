///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 1:19)

#ifndef CPP_HOW_TO_PROGRAM_NINTH_EDITION_PLACEHOLDER_PLACEHOLDER_H
#define CPP_HOW_TO_PROGRAM_NINTH_EDITION_PLACEHOLDER_PLACEHOLDER_H

#include "Example/BookCpp/CppHowToProgramNinthEdition/CppHowToProgramNinthEditionDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace CppHowToProgramNinthEdition
{
    class CPP_HOW_TO_PROGRAM_NINTH_EDITION_DEFAULT_DECLARE Placeholder
    {
    public:
        using ClassType = Placeholder;

    public:
        CLASS_INVARIANT_DECLARE;

    public:
        Placeholder() noexcept;
    };
}

#endif  // CPP_HOW_TO_PROGRAM_NINTH_EDITION_PLACEHOLDER_PLACEHOLDER_H
