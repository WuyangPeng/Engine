///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/28 20:46)

#ifndef CPP_PRIMER_PLUS_PREFACE_BOOK_CONVENTION_H
#define CPP_PRIMER_PLUS_PREFACE_BOOK_CONVENTION_H

#include "Example/BookCpp/CppPrimerPlus/CppPrimerPlusDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookPrimary
{
    namespace CppPrimerPlus
    {
        class CPP_PRIMER_PLUS_DEFAULT_DECLARE BookConvention final
        {
        public:
            using ClassType = BookConvention;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            BookConvention() noexcept;

            [[nodiscard]] int Main();
        };
    }
}

#endif  // CPP_PRIMER_PLUS_PREFACE_BOOK_CONVENTION_H
