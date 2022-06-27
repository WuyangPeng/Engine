///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/14 19:27)

#include "CameraNodeTesting.h"
#include "SpatialTest.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/CameraNode.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, CameraNodeTesting)

void Rendering::CameraNodeTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChildTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::CameraNodeTesting::InitTest() noexcept
{
}

void Rendering::CameraNodeTesting::CopyTest() noexcept
{
}

void Rendering::CameraNodeTesting::TransformTest() noexcept
{
}

void Rendering::CameraNodeTesting::ChildTest() noexcept
{
}

void Rendering::CameraNodeTesting::StreamTest() noexcept
{
}