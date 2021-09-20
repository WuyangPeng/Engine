// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:02)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H

#include "RttiTestingBase.h"
#include "CoreTools/Helper/RttiMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class RttiTesting : public RttiTestingBase
    {
    public:
        using ClassType = RttiTesting;
        using ParentType = RttiTestingBase;

    public:
        explicit RttiTesting(const OStreamShared& stream);
        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void RttiTest();

        void DoRunUnitTest() override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_RTTI_TESTING_H