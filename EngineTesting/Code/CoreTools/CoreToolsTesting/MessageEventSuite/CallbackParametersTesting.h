///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 15:28)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CallbackParametersTesting final : public UnitTest
    {
    public:
        using ClassType = CallbackParametersTesting;
        using ParentType = UnitTest;

    public:
        explicit CallbackParametersTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void BuiltInTest();
        void ParametersInterfaceTest();
        void InvalidParametersTest();
        void InvalidTypeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H