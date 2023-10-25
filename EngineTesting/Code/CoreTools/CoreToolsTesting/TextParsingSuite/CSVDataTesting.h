///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:25)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_DATA_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_DATA_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVDataTesting final : public UnitTest
    {
    public:
        using ClassType = CSVDataTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void Vector2Test();
        void Vector3Test();
        void Vector4Test();
        void IntVector2Test() noexcept;
        void IntVector3Test() noexcept;
        void IntVector4Test() noexcept;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_DATA_TESTING_H
