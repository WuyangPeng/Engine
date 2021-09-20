///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/03 13:17)

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
