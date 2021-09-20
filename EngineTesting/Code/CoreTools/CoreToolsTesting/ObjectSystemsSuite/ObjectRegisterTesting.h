// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:01)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class ObjectRegisterTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ObjectRegisterTesting);

    private:
        void MainTest();
        void UniqueIDExceptionTest() noexcept;
        void RegisterRootSucceedTest() noexcept;
        void RegisterObjectPtrSucceedTest() noexcept;
        void RegisterObjectPtrArraySucceedTest() noexcept;
        void RegisterObjectSmartPtrSucceedTest() noexcept;
        void RegisterObjectSmartPtrArraySucceedTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_OBJECT_REGISTER_TESTING_H