///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:27)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_INCREMENTABLE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_INCREMENTABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumIncrementableTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumIncrementableTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumIncrementableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SignedPrefixOperatorTest();
        void SignedSuffixOperator0Test();
        void UnsignedPrefixOperatorTest();
        void UnsignedSuffixOperator0Test();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_INCREMENTABLE_TESTING_H
