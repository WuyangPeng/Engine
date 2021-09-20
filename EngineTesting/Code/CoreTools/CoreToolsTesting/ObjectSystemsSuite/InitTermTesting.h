// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 13:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H

#include "CoreTools/Helper/InitializeTerminatorMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class InitTermTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(InitTermTesting);

    private:
        void MainTest();
        void InitTermTest() noexcept;

        void DoRunUnitTest() override;

    private:
        static bool sm_InitializeCall;
        static bool sm_TerminateCall;
        static bool sm_TestBegin;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_INIT_TERM_TESTING_H