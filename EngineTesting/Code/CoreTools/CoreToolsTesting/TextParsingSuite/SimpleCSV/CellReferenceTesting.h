///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:16)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_REFERENCE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_REFERENCE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>

namespace CoreTools
{
    class CellReferenceTesting final : public UnitTest
    {
    public:
        using ClassType = CellReferenceTesting;
        using ParentType = UnitTest;

    public:
        explicit CellReferenceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CellAddressTest();
        NODISCARD bool RowTest();
        void OneLetterColumnTest();
        NODISCARD bool TwoLetterRowTest();
        NODISCARD bool ThreeLetterRowTest();
        void OperatorTest();

    private:
        static constexpr auto alphabetSize = 26;

    private:
        std::default_random_engine randomEngine;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_REFERENCE_TESTING_H
