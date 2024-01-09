///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:32)

#include "CullerTesting.h"
#include "Detail/SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Rendering/Visibility/Culler.h"

#include <random>
#include <vector>

Rendering::CullerTesting::CullerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CullerTesting)

void Rendering::CullerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::CullerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(CameraTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PlaneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpatialPtrTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VisibleTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::CullerTesting::CameraTest() noexcept
{
}

void Rendering::CullerTesting::PlaneTest() noexcept
{
}

void Rendering::CullerTesting::SpatialPtrTest() noexcept
{
}

void Rendering::CullerTesting::VisibleTest() noexcept
{
}
