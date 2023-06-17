///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:03)

#include "DepthStencilStateFaceTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/State/Flags/DepthStencilStateComparison.h"
#include "Rendering/State/Flags/DepthStencilStateOperation.h"

using System::operator++;

Rendering::DepthStencilStateFaceTesting::DepthStencilStateFaceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      fail{ DepthStencilStateOperation::Keep },
      depthFail{ DepthStencilStateOperation::Keep },
      pass{ DepthStencilStateOperation::Keep },
      comparison{ DepthStencilStateComparison::Always },
      depthStencilStateFace{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthStencilStateFaceTesting)

void Rendering::DepthStencilStateFaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::DepthStencilStateFaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetDepthFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetPassTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetComparisonTest);

    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);

    ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
}

void Rendering::DepthStencilStateFaceTesting::ConstructorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceTest);
}

void Rendering::DepthStencilStateFaceTesting::DepthStencilStateFaceTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceSaveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceValueTest);
}

void Rendering::DepthStencilStateFaceTesting::DepthStencilStateFaceValueTest()
{
    ASSERT_ENUM_EQUAL(depthStencilStateFace.GetFail(), fail);
    ASSERT_ENUM_EQUAL(depthStencilStateFace.GetDepthFail(), depthFail);
    ASSERT_ENUM_EQUAL(depthStencilStateFace.GetPass(), pass);
    ASSERT_ENUM_EQUAL(depthStencilStateFace.GetComparison(), comparison);
}

void Rendering::DepthStencilStateFaceTesting::DepthStencilStateFaceSaveTest()
{
    constexpr auto bufferSize = 1024;

    auto objectRegister = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget{ bufferSize, objectRegister };

    depthStencilStateFace.Save(bufferTarget);

    CoreTools::BufferSource bufferSource{ bufferTarget.GetFileBuffer() };
    depthStencilStateFace = DepthStencilStateFace{};
    depthStencilStateFace.Load(bufferSource);
}

void Rendering::DepthStencilStateFaceTesting::SetFailTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilStateFace.SetFail(operation);
        fail = operation;
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceTest);
    }
}

void Rendering::DepthStencilStateFaceTesting::SetDepthFailTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilStateFace.SetDepthFail(operation);
        depthFail = operation;
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceTest);
    }
}

void Rendering::DepthStencilStateFaceTesting::SetPassTest()
{
    for (auto operation = DepthStencilStateOperation::Keep; operation <= DepthStencilStateOperation::Decrease; ++operation)
    {
        depthStencilStateFace.SetPass(operation);
        pass = operation;
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceTest);
    }
}

void Rendering::DepthStencilStateFaceTesting::SetComparisonTest()
{
    for (auto depthStencilStateComparison = DepthStencilStateComparison::Never; depthStencilStateComparison <= DepthStencilStateComparison::Always; ++depthStencilStateComparison)
    {
        depthStencilStateFace.SetComparison(depthStencilStateComparison);
        comparison = depthStencilStateComparison;
        ASSERT_NOT_THROW_EXCEPTION_0(DepthStencilStateFaceTest);
    }
}

void Rendering::DepthStencilStateFaceTesting::EqualTest()
{
    DepthStencilStateFace testDepthStencilStateFace{};

    testDepthStencilStateFace.SetFail(fail);
    testDepthStencilStateFace.SetDepthFail(depthFail);
    testDepthStencilStateFace.SetPass(pass);
    testDepthStencilStateFace.SetComparison(comparison);

    ASSERT_EQUAL(testDepthStencilStateFace, depthStencilStateFace);
}

void Rendering::DepthStencilStateFaceTesting::GetStreamingSizeTest()
{
    auto streamingSize = CoreTools::GetStreamSize(fail);

    streamingSize += CoreTools::GetStreamSize(depthFail);
    streamingSize += CoreTools::GetStreamSize(pass);
    streamingSize += CoreTools::GetStreamSize(comparison);

    ASSERT_EQUAL(depthStencilStateFace.GetStreamingSize(), streamingSize);
}
