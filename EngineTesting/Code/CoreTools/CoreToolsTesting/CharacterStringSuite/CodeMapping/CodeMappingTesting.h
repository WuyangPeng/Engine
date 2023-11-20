///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 13:31)

#ifndef CORE_TOOLS_CHARACTER_STRING_SUITE_CODE_MAPPING_TESTING_H
#define CORE_TOOLS_CHARACTER_STRING_SUITE_CODE_MAPPING_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CodeMappingTesting final : public UnitTest
    {
    public:
        using ClassType = CodeMappingTesting;
        using ParentType = UnitTest;

    public:
        explicit CodeMappingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetElementFailTest();
        void InsertSuccessTest();
        void InsertFailTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_CODE_MAPPING_TESTING_H
