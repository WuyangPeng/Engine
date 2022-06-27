///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 20:50)

#include "IKGoalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Controllers/IKGoal.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, IKGoalTesting)

void Rendering::IKGoalTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::IKGoalTesting::InitTest() noexcept
{
}

void Rendering::IKGoalTesting::CopyTest() noexcept
{
}

void Rendering::IKGoalTesting::StreamTest() noexcept
{
}
