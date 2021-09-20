// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:29)

#ifndef CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class FileBufferTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FileBufferTesting);

    private:
        void MainTest();
        void ValueTest();
        void DelayCopyTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TESTING_FILE_BUFFER_TESTING_H