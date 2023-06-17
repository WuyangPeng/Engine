///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:00)

#include "SurfacePatchTesting.h"
#include "Detail/TestSurfacePatch.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix2Detail.h"

Rendering::SurfacePatchTesting::SurfacePatchTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SurfacePatchTesting)

void Rendering::SurfacePatchTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::SurfacePatchTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativesTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::SurfacePatchTesting::ParameterTest() noexcept
{
}

void Rendering::SurfacePatchTesting::DerivativesTest() noexcept
{
}
