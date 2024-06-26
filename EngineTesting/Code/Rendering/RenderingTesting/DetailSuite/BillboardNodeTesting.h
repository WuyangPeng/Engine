///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:46)

#ifndef RENDERING_DETAIL_SUITE_BILLBOARD_NODE_TESTING_H
#define RENDERING_DETAIL_SUITE_BILLBOARD_NODE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class BillboardNodeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BillboardNodeTesting;
        using ParentType = UnitTest;

    public:
        explicit BillboardNodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest() noexcept;
        void CopyTest() noexcept;
        void TransformTest() noexcept;
        void StreamTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DETAIL_SUITE_BILLBOARD_NODE_TESTING_H