// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:59)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class EntityManagerTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EntityManagerTesting);

    private:
        void MainTest();

        void ManagerTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H