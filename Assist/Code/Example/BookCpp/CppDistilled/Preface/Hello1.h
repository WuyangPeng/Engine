///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2020/12/31 23:06)

#ifndef CPP_DISTILLED_PREFACE_HELLO1_H
#define CPP_DISTILLED_PREFACE_HELLO1_H

#include "Example/BookCpp/CppDistilled/CppDistilledDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookPrimary
{
    namespace CppDistilled
    {
        class CPP_DISTILLED_DEFAULT_DECLARE Hello1 final
        {
        public:
            using ClassType = Hello1;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            Hello1() noexcept;

            [[nodiscard]] int Main() const;
        };
    }
}

#endif  // CPP_DISTILLED_PREFACE_HELLO1_H
