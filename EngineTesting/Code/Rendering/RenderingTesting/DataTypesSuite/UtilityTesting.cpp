///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:58)

#include "UtilityTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/Utility.h"

#include <random>
#include <vector>

Rendering::UtilityTesting::UtilityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, UtilityTesting)

void Rendering::UtilityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::UtilityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReflectXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ReflectYTest);
}

void Rendering::UtilityTesting::ReflectXTest() noexcept
{
}

void Rendering::UtilityTesting::ReflectYTest() noexcept
{
}
