// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 17:15)

#ifndef CORE_TOOLS_HANDLE_MANAGER_SUITE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_HANDLE_MANAGER_SUITE_HANDLE_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class HandleManagerTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(HandleManagerTesting);

    private:
        void MainTest();
        void SucceedTest() noexcept;
        void AcquireExceptionTest() noexcept;
        void ReleaseExceptionTest() noexcept;
        void DereferenceExceptionTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_HANDLE_MANAGER_SUITE_HANDLE_MANAGER_TESTING_H