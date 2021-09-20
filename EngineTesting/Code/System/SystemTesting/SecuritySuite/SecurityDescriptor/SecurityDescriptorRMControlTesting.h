// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.1 (2020/01/14 15:15)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_RM_CONTROL_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_RM_CONTROL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SecurityDescriptorRMControlTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityDescriptorRMControlTesting;
        using ParentType = UnitTest;

    public:
        explicit SecurityDescriptorRMControlTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RMControlTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_RM_CONTROL_TESTING_H