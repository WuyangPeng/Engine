/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/12 19:28)

#ifndef CORE_TOOLS_CHARACTER_STRING_SUITE_BASE64_TESTING_H
#define CORE_TOOLS_CHARACTER_STRING_SUITE_BASE64_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class Base64Testing final : public UnitTest
    {
    public:
        using ClassType = Base64Testing;
        using ParentType = UnitTest;

    public:
        explicit Base64Testing(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void EncodeTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_BASE64_TESTING_H
