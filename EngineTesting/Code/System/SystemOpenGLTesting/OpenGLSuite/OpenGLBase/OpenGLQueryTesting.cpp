///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:21)

#include "OpenGLQueryTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
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
    const auto numExtensionsInteger = GetGLInteger(OpenGLQuery::NumExtensions);

    ASSERT_LESS(0, numExtensionsInteger);

    const auto numExtensionsDouble = GetGLDouble(OpenGLQuery::NumExtensions);

    ASSERT_LESS(0, numExtensionsDouble);

    const auto numExtensionsFloat = GetGLFloat(OpenGLQuery::NumExtensions);

    ASSERT_LESS(0, numExtensionsFloat);

    const auto isNumExtensions = GetGLBoolean(OpenGLQuery::NumExtensions);

    ASSERT_TRUE(isNumExtensions);

    ASSERT_APPROXIMATE(numExtensionsDouble, numExtensionsInteger, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(numExtensionsFloat, numExtensionsInteger, Mathematics::MathF::epsilon);
}

void System::OpenGLQueryTesting::MajorVersionTest()
{
    const auto majorVersion = EnumCastUnderlying(GetOpenGLVersion()) / 10;
    const auto majorVersionInteger = GetGLInteger(OpenGLQuery::MajorVersion);

    ASSERT_EQUAL(majorVersion, majorVersionInteger);

    const auto majorVersionDouble = GetGLDouble(OpenGLQuery::MajorVersion);

    ASSERT_APPROXIMATE(majorVersion, majorVersionDouble, Mathematics::MathD::epsilon);

    const auto majorVersionFloat = GetGLFloat(OpenGLQuery::MajorVersion);

    ASSERT_APPROXIMATE(majorVersion, majorVersionFloat, Mathematics::MathF::epsilon);

    const auto isMajorVersion = GetGLBoolean(OpenGLQuery::MajorVersion);

    ASSERT_TRUE(isMajorVersion);
}

void System::OpenGLQueryTesting::MinorVersionTest()
{
    const auto minorVersion = EnumCastUnderlying(GetOpenGLVersion()) % 10;
    const auto minorVersionInteger = GetGLInteger(OpenGLQuery::MinorVersion);

    ASSERT_EQUAL(minorVersion, minorVersionInteger);

    const auto minorVersionDouble = GetGLDouble(OpenGLQuery::MinorVersion);

    ASSERT_APPROXIMATE(minorVersion, minorVersionDouble, Mathematics::MathD::epsilon);

    const auto minorVersionFloat = GetGLFloat(OpenGLQuery::MinorVersion);

    ASSERT_APPROXIMATE(minorVersion, minorVersionFloat, Mathematics::MathF::epsilon);

    const auto isMinorVersion = GetGLBoolean(OpenGLQuery::MinorVersion);

    ASSERT_TRUE(isMinorVersion);
}

void System::OpenGLQueryTesting::VertexArrayTest()
{
    const auto vertexArrayInteger = GetGLInteger(OpenGLQuery::VertexArray);

    ASSERT_EQUAL(0, vertexArrayInteger);

    const auto vertexArrayDouble = GetGLDouble(OpenGLQuery::VertexArray);

    ASSERT_APPROXIMATE(0.0, vertexArrayDouble, Mathematics::MathD::epsilon);

    const auto vertexArrayFloat = GetGLFloat(OpenGLQuery::VertexArray);

    ASSERT_APPROXIMATE(0.0f, vertexArrayFloat, Mathematics::MathF::epsilon);

    const auto isVertexArray = GetGLBoolean(OpenGLQuery::VertexArray);

    ASSERT_EQUAL(false, isVertexArray);
}

void System::OpenGLQueryTesting::TextureTargetBindingTest()
{
    for (const auto textureTargetBinding : textureTargetBindings)
    {
        const auto result = GetGLInteger(textureTargetBinding);

        ASSERT_EQUAL(0, result);
    }
}

void System::OpenGLQueryTesting::ViewportTest()
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    SetGLViewport(0, 0, width, height);

    ViewportQueryType viewport{};
    GetGLInteger(OpenGLQuery::Viewport, viewport.data());

    ASSERT_EQUAL(viewport.at(0), 0);
    ASSERT_EQUAL(viewport.at(1), 0);
    ASSERT_EQUAL(viewport.at(2), width);
    ASSERT_EQUAL(viewport.at(3), height);
}

void System::OpenGLQueryTesting::DepthRangeTest()
{
    SetGLDepthRange(0.0, 1.0);

    DepthRangeQueryType depthRange{};
    GetGLDouble(OpenGLQuery::DepthRange, depthRange.data());

    ASSERT_APPROXIMATE(depthRange.at(0), 0.0, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(depthRange.at(1), 1.0, Mathematics::MathF::epsilon);
}
