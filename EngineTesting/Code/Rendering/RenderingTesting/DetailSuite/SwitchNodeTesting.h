///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:46)

#ifndef RENDERING_DETAIL_SUITE_SWITCH_NODE_TESTING_H
#define RENDERING_DETAIL_SUITE_SWITCH_NODE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class SwitchNodeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SwitchNodeTesting;
        using ParentType = UnitTest;

    public:
        explicit SwitchNodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest() noexcept;
        void CopyTest() noexcept;
        void TransformTest() noexcept;
        void ChildTest() noexcept;
        void StreamTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DETAIL_SUITE_SWITCH_NODE_TESTING_H