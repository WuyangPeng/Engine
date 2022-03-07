// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:02)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H

#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class RttiTestingBase : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(RttiTestingBase);

        CORE_TOOLS_RTTI_DECLARE;

    private:
        void MainTest();
        void RttiTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_BASE_H