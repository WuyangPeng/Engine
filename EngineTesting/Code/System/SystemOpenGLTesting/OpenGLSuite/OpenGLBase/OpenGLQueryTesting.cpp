/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:42)

#include "OpenGLQueryTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLUtility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

System::OpenGLQueryTesting::OpenGLQueryTesting(const OStreamShared& stream)
    : ParentType{ stream },
      textureTargetBindings{ TextureTargetBinding::Binding1D,
                             TextureTargetBinding::Binding2D,
                             TextureTargetBinding::Binding3D,
                             TextureTargetBinding::BindingCube,
                             TextureTargetBinding::Binding1DArray,
                             TextureTargetBinding::Binding2DArray,
                             TextureTargetBinding::BindingCubeArray }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLQueryTesting)

void System::OpenGLQueryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLQueryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NumExtensionsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MajorVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MinorVersionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VertexArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TextureTargetBindingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ViewportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthRangeTest);
}

void System::OpenGLQueryTesting::NumExtensionsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(GreaterZeroTest, OpenGLQuery::NumExtensions);
}

void System::OpenGLQueryTesting::GreaterZeroTest(OpenGLQuery openGLQuery)
{
    const auto integerResult = GetGLInteger(openGLQuery);

    ASSERT_LESS(0, integerResult);

    const auto doubleResult = GetGLDouble(openGLQuery);

    ASSERT_LESS(0.0, doubleResult);

    const auto floatResult = GetGLFloat(openGLQuery);

    ASSERT_LESS(0.0f, floatResult);

    const auto boolResult = GetGLBoolean(openGLQuery);

    ASSERT_EQUAL(0 < integerResult, boolResult);

    ASSERT_APPROXIMATE(doubleResult, integerResult, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(floatResult, integerResult, Mathematics::MathF::epsilon);
}

void System::OpenGLQueryTesting::MajorVersionTest()
{
    const auto majorVersion = EnumCastUnderlying(GetOpenGLVersion()) / 10;
    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, OpenGLQuery::MajorVersion, majorVersion);
}

void System::OpenGLQueryTesting::EqualTest(OpenGLQuery openGLQuery, int version)
{
    const auto integerResult = GetGLInteger(openGLQuery);

    ASSERT_EQUAL(version, integerResult);

    const auto doubleResult = GetGLDouble(openGLQuery);

    ASSERT_APPROXIMATE(version, doubleResult, Mathematics::MathD::epsilon);

    const auto floatResult = GetGLFloat(openGLQuery);

    ASSERT_APPROXIMATE(version, floatResult, Mathematics::MathF::epsilon);

    const auto boolResult = GetGLBoolean(openGLQuery);

    ASSERT_EQUAL(0 < version, boolResult);
}

void System::OpenGLQueryTesting::MinorVersionTest()
{
    const auto minorVersion = EnumCastUnderlying(GetOpenGLVersion()) % 10;
    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, OpenGLQuery::MinorVersion, minorVersion);
}

void System::OpenGLQueryTesting::VertexArrayTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(EqualZeroTest, OpenGLQuery::VertexArray);
}

void System::OpenGLQueryTesting::EqualZeroTest(OpenGLQuery openGLQuery)
{
    ASSERT_NOT_THROW_EXCEPTION_2(EqualTest, openGLQuery, 0);
}

void System::OpenGLQueryTesting::TextureTargetBindingTest()
{
    for (const auto textureTargetBinding : textureTargetBindings)
    {
        const auto result = GetGLInteger(textureTargetBinding);

        ASSERT_EQUAL(result, 0);
    }
}

void System::OpenGLQueryTesting::ViewportTest()
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    SetGLViewport(0, 0, width, height);

    const auto viewport = GetGLViewport();

    ASSERT_EQUAL(viewport.at(0), 0);
    ASSERT_EQUAL(viewport.at(1), 0);
    ASSERT_EQUAL(viewport.at(2), width);
    ASSERT_EQUAL(viewport.at(3), height);

    ViewportQueryType query{};
    GetGLInteger(OpenGLQuery::Viewport, query.data());

    ASSERT_EQUAL(viewport, query);
}

void System::OpenGLQueryTesting::DepthRangeTest()
{
    constexpr auto nearDepthRange = 0.0;
    constexpr auto farDepthRange = 1.0;

    SetGLDepthRange(nearDepthRange, farDepthRange);

    const auto depthRange = GetGLDepthRange();

    ASSERT_APPROXIMATE(depthRange.at(0), nearDepthRange, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(depthRange.at(1), farDepthRange, Mathematics::MathF::epsilon);

    DepthRangeQueryType query{};
    GetGLDouble(OpenGLQuery::DepthRange, query.data());

    ASSERT_APPROXIMATE(depthRange.at(0), query.at(0), Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(depthRange.at(1), query.at(1), Mathematics::MathF::epsilon);
}
