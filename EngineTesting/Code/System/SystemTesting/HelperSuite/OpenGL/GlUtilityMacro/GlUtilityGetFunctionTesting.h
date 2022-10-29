///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/03 11:47)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_GET_FUNCTION_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_GET_FUNCTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GlUtilityGetFunctionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GlUtilityGetFunctionTesting;
        using ParentType = UnitTest;

    public:
        explicit GlUtilityGetFunctionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetFunctionTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_GET_FUNCTION_TESTING_H
