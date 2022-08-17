///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 14:44)

#include "TrianglesFanTesting.h"
#include "VisualTest.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/SaveVisual.h"
#include "Rendering/SceneGraph/TrianglesFan.h"

#include <random>
#include <vector>

using CoreTools::WriteFileManager;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, TrianglesFanTesting)

void Rendering::TrianglesFanTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    CameraManager::Create();
    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateModelSpaceTest);

    RendererManager::Destroy();
    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::TrianglesFanTesting::CreateTrianglesMeshFile() noexcept
{
}

void Rendering::TrianglesFanTesting::InitTest() noexcept
{
}

void Rendering::TrianglesFanTesting::CopyTest() noexcept
{
}

void Rendering::TrianglesFanTesting::TransformTest() noexcept
{
}

void Rendering::TrianglesFanTesting::StreamTest() noexcept
{
}

void Rendering::TrianglesFanTesting::FileTest() noexcept
{
}

void Rendering::TrianglesFanTesting::UpdateModelSpaceTest() noexcept
{
}
