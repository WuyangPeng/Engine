///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 13:55)

#include "OpenGLGlutTesting.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::OpenGLGlutTesting::OpenGLGlutTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutTesting)

void System::OpenGLGlutTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GlutInitTest);

    // SystemOpenGLTesting��OpenGL�����Ĳ��ԡ�
    // GlutMainLoopTesting�к���GlutMainLoop�Ĳ��ԡ�
}

void System::OpenGLGlutTesting::GlutInitTest() noexcept
{
    constexpr auto bufferSize = 1;
    array<char, bufferSize> buffer{};
    auto count = bufferSize;
    auto argv = buffer.data();

    GlutInit(&count, &argv);
}
