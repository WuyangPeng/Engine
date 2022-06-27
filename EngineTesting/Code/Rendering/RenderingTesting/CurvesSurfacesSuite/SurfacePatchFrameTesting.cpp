///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 19:45)

#include "SurfacePatchFrameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/CurvesSurfaces/SurfacePatchFrame.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SurfacePatchFrameTesting)

void Rendering::SurfacePatchFrameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::SurfacePatchFrameTesting::InitTest() noexcept
{
}
