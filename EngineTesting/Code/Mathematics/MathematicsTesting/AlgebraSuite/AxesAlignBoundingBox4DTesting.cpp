// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 14:08)

#include "AxesAlignBoundingBox4DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox4Detail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

namespace Mathematics
{
    template class AxesAlignBoundingBox4<float>;
    template class AxesAlignBoundingBox4<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AxesAlignBoundingBox4DTesting)

void Mathematics::AxesAlignBoundingBox4DTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
}

void Mathematics::AxesAlignBoundingBox4DTesting ::ConstructionTest()
{
    const Vector4F firstVector(3.0f, 7.0f, 6.0f, 6.0f);
    const Vector4F secondVector(5.0f, 11.0f, 17.0f, 12.0f);

    const AxesAlignBoundingBox4F firstAABB(firstVector, secondVector);

    ASSERT_TRUE(Vector4ToolsF::Approximate(firstAABB.GetMaxPoint(), Vector4F(5.0f, 11.0f, 17.0f, 12.0f)));
    ASSERT_TRUE(Vector4ToolsF::Approximate(firstAABB.GetMinPoint(), Vector4F(3.0f, 7.0f, 6.0f, 6.0f)));

    const AxesAlignBoundingBox4D secondAABB(firstAABB);

    ASSERT_TRUE(Vector4ToolsD::Approximate(secondAABB.GetMaxPoint(), Vector4D(5.0, 11.0, 17.0, 12.0)));
    ASSERT_TRUE(Vector4ToolsD::Approximate(secondAABB.GetMinPoint(), Vector4D(3.0, 7.0, 6.0, 6.0)));
}
