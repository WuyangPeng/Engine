///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:09)

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