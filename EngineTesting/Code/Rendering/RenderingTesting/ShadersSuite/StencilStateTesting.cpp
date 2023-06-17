///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:07)

#include "StencilStateTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Shaders/StencilState.h"

Rendering::StencilStateTesting::StencilStateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, StencilStateTesting)

void Rendering::StencilStateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::StencilStateTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
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
