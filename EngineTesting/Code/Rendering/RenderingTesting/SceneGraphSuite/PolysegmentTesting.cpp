///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:34)

#include "PolysegmentTesting.h"
#include "Detail/VisualTest.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

Rendering::PolysegmentTesting::PolysegmentTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PolysegmentTesting)

void Rendering::PolysegmentTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::PolysegmentTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();



    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransformTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileTest);


    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::PolysegmentTesting::InitTest() noexcept
{
}

void Rendering::PolysegmentTesting::CopyTest() noexcept
{
}

void Rendering::PolysegmentTesting::TransformTest() noexcept
{
}

void Rendering::PolysegmentTesting::StreamTest() noexcept
{
}

void Rendering::PolysegmentTesting::FileTest() noexcept
{
}
