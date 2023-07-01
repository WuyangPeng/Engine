///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:06)

#include "SaveVisualEffectTesting.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Rendering::SaveVisualEffectTesting::SaveVisualEffectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SaveVisualEffectTesting)

void Rendering::SaveVisualEffectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::SaveVisualEffectTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateVisualEffectFile);
    ASSERT_NOT_THROW_EXCEPTION_0(SaveFile);
    ASSERT_NOT_THROW_EXCEPTION_0(SaveTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::SaveVisualEffectTesting::CreateVisualEffectFile() noexcept
{
}

void Rendering::SaveVisualEffectTesting::SaveFile() noexcept
{
}

void Rendering::SaveVisualEffectTesting::SaveTest() noexcept
{
}
