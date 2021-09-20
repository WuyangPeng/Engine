///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/03 13:17)

#ifndef PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_PREFACE_ISO_STANDARD_CPP_H
#define PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_PREFACE_ISO_STANDARD_CPP_H

#include "Example/BookCpp/ProgrammingPrinciplesAndPracticeUsingCpp/ProgrammingPrinciplesAndPracticeUsingCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookPrimary
{
    namespace ProgrammingPrinciplesAndPracticeUsingCpp
    {
        class PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_DEFAULT_DECLARE ISOStandardCpp final
        {
        public:
            using ClassType = ISOStandardCpp;

        public:
            CLASS_INVARIANT_DECLARE;

        public:
            ISOStandardCpp() noexcept;

            void ISOStandardCpp14() const;

            void ISOStandardCpp98() const;
        };
    }
}

#endif  // PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_PREFACE_ISO_STANDARD_CPP_H
