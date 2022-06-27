///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 20:13)

#ifndef RENDERING_CONTROLLERS_SUITE_IK_JOINT_TESTING_H
#define RENDERING_CONTROLLERS_SUITE_IK_JOINT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class IKJointTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IKJointTesting);

    private:
        void MainTest();
        void InitTest() noexcept;
        void CopyTest() noexcept;
        void StreamTest() noexcept;
        void UpdateTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_CONTROLLERS_SUITE_IK_JOINT_TESTING_H