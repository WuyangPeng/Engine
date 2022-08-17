///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 17:52)

#include "ClodMeshTesting.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Detail/ClodMesh.h"
#include "Rendering/Detail/CreateClodMesh.h"
#include "Rendering/Detail/SwitchNode.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"

#include <random>
#include <vector>

using CoreTools::WriteFileManager;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ClodMeshTesting)

void Rendering::ClodMeshTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ClodMeshTesting::CreateTrianglesMeshFile() noexcept
{
}

void Rendering::ClodMeshTesting::InitTest() noexcept
{
}

void Rendering::ClodMeshTesting::CopyTest() noexcept
{
}

void Rendering::ClodMeshTesting::StreamTest() noexcept
{
}
