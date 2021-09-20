// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 14:02)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TYPE_CASTING_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TYPE_CASTING_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class TypeCastingTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(TypeCastingTesting);

    private:
        void MainTest();
        void StaticCastSucceedTest() noexcept;
        void DynamicCastSucceedTest() noexcept;
        void PolymorphicCastSucceedTest() noexcept;
        void ExceptionTest() noexcept;

        void SharedPtrDynamicCastSucceedTest() noexcept;
        void SharedPtrPolymorphicCastSucceedTest() noexcept;
        void SharedPtrExceptionTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_TYPE_CASTING_TESTING_H