///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 19:45)

#include "PrincipalCurvatureInfoTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/CurvesSurfaces/PrincipalCurvatureInfo.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PrincipalCurvatureInfoTesting)

void Rendering::PrincipalCurvatureInfoTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::PrincipalCurvatureInfoTesting::InitTest() noexcept
{
}
