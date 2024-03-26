/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:45)

#include "OpenGLPolygonModeTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLPolygon.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLPolygonModeTesting::OpenGLPolygonModeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      rasterizerStates{ RasterizerStateFillMode::Fill,
                        RasterizerStateFillMode::Line }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLPolygonModeTesting)

void System::OpenGLPolygonModeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLPolygonModeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLPolygonModeTest);
}

void System::OpenGLPolygonModeTesting::OpenGLPolygonModeTest() noexcept
{
    for (const auto rasterizerState : rasterizerStates)
    {
        SetGLPolygonMode(RasterizerStateCullFace::FrontAndBack, rasterizerState);
    }
}
