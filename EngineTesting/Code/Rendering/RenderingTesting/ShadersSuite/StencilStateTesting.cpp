///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 18:52)

#include "StencilStateTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Shaders/StencilState.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, StencilStateTesting)

void Rendering::StencilStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::StencilStateTesting::InitTest()
{
    StencilState firstStencilState{ CoreTools::DisableNotThrow::Disable };

    ASSERT_FALSE(firstStencilState.IsEnabled());
    ASSERT_ENUM_EQUAL(firstStencilState.GetCompare(), StencilStateFlags::CompareMode::Never);
    ASSERT_EQUAL(firstStencilState.GetReference(), 0u);
    ASSERT_EQUAL(firstStencilState.GetMask(), 0xFFFFFFFF);
    ASSERT_EQUAL(firstStencilState.GetWriteMask(), 0xFFFFFFFF);
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnFail(), StencilStateFlags::OperationType::Keep);
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), StencilStateFlags::OperationType::Keep);
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnZPass(), StencilStateFlags::OperationType::Keep);

    firstStencilState.SetEnabled(true);
    ASSERT_TRUE(firstStencilState.IsEnabled());

    firstStencilState.SetCompare(StencilStateFlags::CompareMode::Greater);
    ASSERT_ENUM_EQUAL(firstStencilState.GetCompare(), StencilStateFlags::CompareMode::Greater);

    firstStencilState.SetReference(5);
    ASSERT_EQUAL(firstStencilState.GetReference(), 5u);

    firstStencilState.SetMask(0xFFFEEFFE);
    ASSERT_EQUAL(firstStencilState.GetMask(), 0xFFFEEFFE);

    firstStencilState.SetWriteMask(0xFDFEEFFE);
    ASSERT_EQUAL(firstStencilState.GetWriteMask(), 0xFDFEEFFE);

    firstStencilState.SetOnFail(StencilStateFlags::OperationType::Invert);
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnFail(), StencilStateFlags::OperationType::Invert);

    firstStencilState.SetOnZFail(StencilStateFlags::OperationType::Increment);
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), StencilStateFlags::OperationType::Increment);

    firstStencilState.SetOnZPass(StencilStateFlags::OperationType::Zero);
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnZPass(), StencilStateFlags::OperationType::Zero);
}

void Rendering::StencilStateTesting::CopyTest()
{
    StencilState firstStencilState{ CoreTools::DisableNotThrow::Disable };

    firstStencilState.SetEnabled(true);
    firstStencilState.SetCompare(StencilStateFlags::CompareMode::Greater);
    firstStencilState.SetReference(5);
    firstStencilState.SetMask(0xFFFEEFFE);
    firstStencilState.SetWriteMask(0xFDFEEFFE);
    firstStencilState.SetOnFail(StencilStateFlags::OperationType::Invert);
    firstStencilState.SetOnZFail(StencilStateFlags::OperationType::Increment);
    firstStencilState.SetOnZPass(StencilStateFlags::OperationType::Zero);

    StencilState secondStencilState(firstStencilState);

    ASSERT_EQUAL(firstStencilState.IsEnabled(), secondStencilState.IsEnabled());
    ASSERT_ENUM_EQUAL(firstStencilState.GetCompare(), secondStencilState.GetCompare());
    ASSERT_EQUAL(firstStencilState.GetReference(), secondStencilState.GetReference());
    ASSERT_EQUAL(firstStencilState.GetMask(), secondStencilState.GetMask());
    ASSERT_EQUAL(firstStencilState.GetWriteMask(), secondStencilState.GetWriteMask());
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnFail(), secondStencilState.GetOnFail());
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), secondStencilState.GetOnZFail());
    ASSERT_ENUM_EQUAL(firstStencilState.GetOnZPass(), secondStencilState.GetOnZPass());

    firstStencilState.SetOnZFail(StencilStateFlags::OperationType::Invert);

    ASSERT_ENUM_EQUAL(firstStencilState.GetOnZFail(), StencilStateFlags::OperationType::Invert);
    ASSERT_ENUM_EQUAL(secondStencilState.GetOnZFail(), StencilStateFlags::OperationType::Increment);
}

void Rendering::StencilStateTesting::StreamTest() noexcept
{
}
