///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:31)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_EXPLICIT_CAST_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <string>

namespace CoreTools
{
    class ExplicitCastTesting final : public UnitTest
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
