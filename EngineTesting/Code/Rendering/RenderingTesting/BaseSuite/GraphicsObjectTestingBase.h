///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.2 (2022/09/30 11:10)

#ifndef RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_H
#define RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class GraphicsObjectTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = GraphicsObjectTestingBase;
        using ParentType = UnitTest;

    public:
        explicit GraphicsObjectTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        template <typename TestingType>
        void RttiTest();

        template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
        void GraphicsObjectRttiTrueTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs);

        template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
        void GraphicsObjectRttiFalseTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs);
    };

  
  

}

#endif  // RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_H