/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:05)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_TESTING_H

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CompareStringTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = CompareStringTesting;
        using ParentType = UnitTest;

    public:
        explicit CompareStringTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void CompareTest(ComparesStringReturn lhs, ComparesStringReturn rhs);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_COMPARE_STRING_TESTING_H