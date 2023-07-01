///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:08)

#include "VisualEffectInstanceTesting.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/Texture1D.h"

Rendering::VisualEffectInstanceTesting::VisualEffectInstanceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualEffectInstanceTesting)

void Rendering::VisualEffectInstanceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::VisualEffectInstanceTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::VisualEffectInstanceTesting::InitTest() noexcept
{
}

void Rendering::VisualEffectInstanceTesting::CopyTest() noexcept
{
}

void Rendering::VisualEffectInstanceTesting::StreamTest() noexcept
{
}
