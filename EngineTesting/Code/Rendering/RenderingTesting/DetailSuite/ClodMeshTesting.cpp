///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:48)

#include "ClodMeshTesting.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Detail/ClodMesh.h"
#include "Rendering/Detail/SwitchNode.h"

#include <random>
#include <vector>

Rendering::ClodMeshTesting::ClodMeshTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ClodMeshTesting)

void Rendering::ClodMeshTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ClodMeshTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

  


    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);



    CoreTools::InitTerm::ExecuteTerminator();
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
