// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_TARGET_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_TARGET_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class BufferTargetTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferTargetTesting);

    private:
        void MainTest() noexcept;

        // 		void WriteBoolTest();
        // 		void WriteStringTest();
        // 		void WriteIntTest();
        // 		void WriteEnumTest();
        // 		void WriteNullObjectTest();
        // 		void WriteObjectPointerTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_TARGET_TESTING_H