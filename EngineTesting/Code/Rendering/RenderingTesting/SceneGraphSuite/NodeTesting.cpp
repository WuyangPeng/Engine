///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 20:21)

#include "NodeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/Node.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, NodeTesting)

void Rendering::NodeTesting::MainTest()
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

void Rendering::NodeTesting::InitTest() noexcept
{
}

void Rendering::NodeTesting::CopyTest() noexcept
{
}

void Rendering::NodeTesting::TransformTest() noexcept
{
}

void Rendering::NodeTesting::ChildTest() noexcept
{
}

void Rendering::NodeTesting::StreamTest() noexcept
{
}