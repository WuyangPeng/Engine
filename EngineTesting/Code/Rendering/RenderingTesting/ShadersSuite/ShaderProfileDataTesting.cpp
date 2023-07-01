///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:07)

#include "ShaderProfileDataTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"

Rendering::ShaderProfileDataTesting::ShaderProfileDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderProfileDataTesting)

void Rendering::ShaderProfileDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ShaderProfileDataTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::ShaderProfileDataTesting::InitTest() noexcept
{
}

void Rendering::ShaderProfileDataTesting::CopyTest() noexcept
{
}
