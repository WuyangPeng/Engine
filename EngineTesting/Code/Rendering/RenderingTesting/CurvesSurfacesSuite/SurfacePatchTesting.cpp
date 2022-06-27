///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 19:46)

#include "SurfacePatchTesting.h"
#include "Detail/TestSurfacePatch.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SurfacePatchTesting)

void Rendering::SurfacePatchTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(ParameterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativesTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::SurfacePatchTesting::ParameterTest() noexcept
{
}

void Rendering::SurfacePatchTesting::DerivativesTest() noexcept
{
}
