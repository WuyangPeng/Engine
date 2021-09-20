///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/09 17:23)

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
