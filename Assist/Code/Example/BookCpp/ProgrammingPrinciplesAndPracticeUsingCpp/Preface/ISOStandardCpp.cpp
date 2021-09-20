///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/03 13:17)

#include "Example/BookCpp/ProgrammingPrinciplesAndPracticeUsingCpp/ProgrammingPrinciplesAndPracticeUsingCppExport.h"

#include "ISOStandardCpp.h"
#include "Example/BookCpp/ProgrammingPrinciplesAndPracticeUsingCpp/Helper/ProgrammingPrinciplesAndPracticeUsingCppClassInvariantMacro.h"

#include <vector>

using std::vector;

BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp::ISOStandardCpp::ISOStandardCpp() noexcept
{
    PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp, ISOStandardCpp)

void BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp::ISOStandardCpp::ISOStandardCpp14() const
{
    PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_CLASS_IS_VALID_CONST_9;

    // C++ 14风格的拷贝构造
    vector<int> v1;
    vector<int> v2{ v1 };
}

void BookPrimary::ProgrammingPrinciplesAndPracticeUsingCpp::ISOStandardCpp::ISOStandardCpp98() const
{
    PROGRAMMING_PRINCIPLES_AND_PRACTICE_USING_CPP_CLASS_IS_VALID_CONST_9;

    // C++ 98风格的拷贝构造
    vector<int> v1;
    vector<int> v2 = v1;
}
