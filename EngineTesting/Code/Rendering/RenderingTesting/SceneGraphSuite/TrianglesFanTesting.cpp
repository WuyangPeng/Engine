///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:35)

#include "TrianglesFanTesting.h"
#include "Detail/VisualTest.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#include <random>
#include <vector>

Rendering::TrianglesFanTesting::TrianglesFanTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TrianglesFanTesting)

void Rendering::TrianglesFanTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::TrianglesFanTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();



    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateModelSpaceTest);


    CoreTools::InitTerm::ExecuteTerminator();
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
