///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:34)

#include "PolypointTesting.h"
#include "VisualTest.h"
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
#include "Rendering/SceneGraph/Polypoint.h"
#include "Rendering/SceneGraph/SaveVisual.h"

#include <vector>

Rendering::PolypointTesting::PolypointTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PolypointTesting)

void Rendering::PolypointTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void Rendering::PolypointTesting::MainTest()
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

void Rendering::PolypointTesting::InitTest() noexcept
{
}

void Rendering::PolypointTesting::CopyTest() noexcept
{
}

void Rendering::PolypointTesting::TransformTest() noexcept
{
}

void Rendering::PolypointTesting::StreamTest() noexcept
{
}

void Rendering::PolypointTesting::FileTest() noexcept
{
}
