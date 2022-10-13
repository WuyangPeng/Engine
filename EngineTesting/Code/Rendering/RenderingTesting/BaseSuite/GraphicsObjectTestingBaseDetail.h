///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/30 13:38)

#ifndef RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_DETAIL_H
#define RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_DETAIL_H

#include "GraphicsObjectTestingBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"

template <typename TestingType>
void Rendering::GraphicsObjectTestingBase::RttiTest()
{
    using namespace std::literals;

    const auto graphicsObjectType = GraphicsObjectType::None;
    const auto name = "GraphicsObjectTest"s;

    auto graphicsObjectTest = TestingType::Create(name, graphicsObjectType);

    GraphicsObjectRttiTrueTest(graphicsObjectTest, graphicsObjectTest);

    const auto nullObject = TestingType::GetNullObject();

    GraphicsObjectRttiFalseTest(graphicsObjectTest, nullObject);
    GraphicsObjectRttiFalseTest(nullObject, graphicsObjectTest);
}

template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
void Rendering::GraphicsObjectTestingBase::GraphicsObjectRttiTrueTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs)
{
    ASSERT_TRUE(lhs->IsExactly(rhs->GetRttiType()));
    ASSERT_TRUE(lhs->IsDerived(rhs->GetRttiType()));

    ASSERT_TRUE(lhs->IsExactlyTypeOf(rhs.get()));
    ASSERT_TRUE(lhs->IsDerivedTypeOf(rhs.get()));
}

template <typename LhsTestingTypeSharedPtr, typename RhsTestingTypeSharedPtr>
void Rendering::GraphicsObjectTestingBase::GraphicsObjectRttiFalseTest(const LhsTestingTypeSharedPtr& lhs, const RhsTestingTypeSharedPtr& rhs)
{
    ASSERT_FALSE(lhs->IsExactly(rhs->GetRttiType()));
    ASSERT_FALSE(lhs->IsDerived(rhs->GetRttiType()));

    ASSERT_FALSE(lhs->IsExactlyTypeOf(rhs.get()));
    ASSERT_FALSE(lhs->IsDerivedTypeOf(rhs.get()));
}

#endif  // RENDERING_BASE_SUITE_GRAPHICS_OBJECT_TESTING_BASE_DETAIL_H
