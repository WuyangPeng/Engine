///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/12 21:17)

#ifndef DESIGNING_AND_CODING_REUSABLE_CPP_PREFACE_CONSTRUCTOR_H
#define DESIGNING_AND_CODING_REUSABLE_CPP_PREFACE_CONSTRUCTOR_H

#include "Example/BookCpp/DesigningAndCodingReusableCpp/DesigningAndCodingReusableCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace DesigningAndCodingReusableCpp
    {
        class DESIGNING_AND_CODING_REUSABLE_CPP_DEFAULT_DECLARE Constructor final
        {
        public:
            using ClassType = Constructor;

        public:
            Constructor() noexcept;

            CLASS_INVARIANT_DECLARE;

            void Main() const noexcept;
        };
    }
}

#endif  // DESIGNING_AND_CODING_REUSABLE_CPP_PREFACE_CONSTRUCTOR_H
