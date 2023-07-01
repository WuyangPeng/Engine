///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:36)

#include "VisualTest.h"
#include "VisualTesting.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/SaveVisual.h"

#include <vector>

Rendering::VisualTesting::VisualTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualTesting)

void Rendering::VisualTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::VisualTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    CameraManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);

    CameraManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::VisualTesting::InitTest() noexcept
{
}

void Rendering::VisualTesting::CopyTest() noexcept
{
}

void Rendering::VisualTesting::TransformTest() noexcept
{
}

void Rendering::VisualTesting::StreamTest() noexcept
{
}

void Rendering::VisualTesting::FileTest() noexcept
{
}
