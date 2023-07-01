///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:45)

#ifndef RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H
#define RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class BufferManagementLockEncapsulationTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BufferManagementLockEncapsulationTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferManagementLockEncapsulationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void VertexBufferTest() noexcept;
        void IndexBufferTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_BUFFER_MANAGEMENT_LOCK_ENCAPSULATION_TESTING_H