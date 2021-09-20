///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/06 15:44)

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