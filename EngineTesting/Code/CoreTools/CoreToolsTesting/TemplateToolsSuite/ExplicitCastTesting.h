///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 11:15)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <string>

namespace CoreTools
{
    class ExplicitCastTesting : public UnitTest
    {
    public:
        using ClassType = ExplicitCastTesting;
        using ParentType = UnitTest;

    public:
        explicit ExplicitCastTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void CastTest();
        void IntegerTest(int value);
        void StringTest(const std::string& value);
        void PtrTest(const std::string* value);

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H
