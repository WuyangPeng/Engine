///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:56)

#include "BoundTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Rendering/DataTypes/Bound.h"

#include <random>
#include <vector>

Rendering::BoundTesting::BoundTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BoundTesting)

void Rendering::BoundTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::BoundTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GrowToContainTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformByTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ComputeFromDataTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LineIntersectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoundIntersectionTest);
}

void Rendering::BoundTesting::BaseTest() noexcept
{
}

void Rendering::BoundTesting::GrowToContainTest() noexcept
{
}

void Rendering::BoundTesting::TransformByTest() noexcept
{
}

void Rendering::BoundTesting::ComputeFromDataTest() noexcept
{
}

void Rendering::BoundTesting::LineIntersectionTest() noexcept
{
}

void Rendering::BoundTesting::BoundIntersectionTest() noexcept
{
}