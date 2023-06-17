///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:50)

#include "AxesAlignBoundingBox4DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox4Detail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

namespace Mathematics
{
    template class AxesAlignBoundingBox4<float>;
    template class AxesAlignBoundingBox4<double>;
}

Mathematics::AxesAlignBoundingBox4DTesting::AxesAlignBoundingBox4DTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AxesAlignBoundingBox4DTesting)

void Mathematics::AxesAlignBoundingBox4DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AxesAlignBoundingBox4DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::AxesAlignBoundingBox4DTesting::ConstructionTest()
{
    const Vector4F vector0(3.0f, 7.0f, 6.0f, 6.0f);
    const Vector4F vector1(5.0f, 11.0f, 17.0f, 12.0f);

    const AxesAlignBoundingBox4F aabb0(vector0, vector1);

    ASSERT_TRUE(Vector4ToolsF::Approximate(aabb0.GetMaxPoint(), Vector4F(5.0f, 11.0f, 17.0f, 12.0f)));
    ASSERT_TRUE(Vector4ToolsF::Approximate(aabb0.GetMinPoint(), Vector4F(3.0f, 7.0f, 6.0f, 6.0f)));

    const AxesAlignBoundingBox4D aabb1(aabb0);

    ASSERT_TRUE(Vector4ToolsD::Approximate(aabb1.GetMaxPoint(), Vector4D(5.0, 11.0, 17.0, 12.0)));
    ASSERT_TRUE(Vector4ToolsD::Approximate(aabb1.GetMinPoint(), Vector4D(3.0, 7.0, 6.0, 6.0)));
}
