///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/22 22:42)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_CAST_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_CAST_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumCastTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumCastTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumCastTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CastTest();
        void WindowErrorCastTest();
        void ConstexprCastTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_CAST_TESTING_H
