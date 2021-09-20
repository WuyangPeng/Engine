// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 18:56)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class TableTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TableTesting);

    private:
        void MainTest();
        void IntegerTest();
        void StringTest();
        void OperatorTest();
        void ConstructorTest();
        void CompileErrorTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H