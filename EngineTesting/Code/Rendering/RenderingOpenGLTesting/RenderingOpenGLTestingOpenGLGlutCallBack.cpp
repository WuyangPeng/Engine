///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:45)

#include "RenderingOpenGLTestingOpenGLGlutCallBack.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::RenderingOpenGLTestingOpenGLGlutCallBack(int64_t delta)
    : ParentType{ delta, "【渲染库】OpenGL单元测试套件" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RenderingOpenGLTestingOpenGLGlutCallBack)

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddSuite()
{
    AddRenderersSuite();
    AddOpenGLRendererSuite();
}

std::string Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::GetSuiteName() const
{
    return "【渲染库】OpenGL单元测试套件";
}

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddRenderersSuite()
{
    auto renderersSuite = GenerateSuite("渲染器");

    ADD_TEST(renderersSuite, EnvironmentParameterTesting);
    ADD_TEST(renderersSuite, RenderingEnvironmentTesting);
    ADD_TEST(renderersSuite, PlatformVertexFormatTesting);
    ADD_TEST(renderersSuite, VertexFormatManagementTesting);
    ADD_TEST(renderersSuite, PlatformIndexBufferTesting);
    ADD_TEST(renderersSuite, PlatformVertexBufferTesting);
    ADD_TEST(renderersSuite, BufferLockManageTesting);
    ADD_TEST(renderersSuite, BufferManagementTesting);
    ADD_TEST(renderersSuite, BufferManagementLockEncapsulationTesting);
    ADD_TEST(renderersSuite, PlatformTexture1DTesting);
    ADD_TEST(renderersSuite, PlatformTexture2DTesting);
    ADD_TEST(renderersSuite, PlatformTexture3DTesting);
    ADD_TEST(renderersSuite, PlatformTextureCubeTesting);
    ADD_TEST(renderersSuite, TextureLockManageTesting);
    ADD_TEST(renderersSuite, TextureManagementTesting);
    ADD_TEST(renderersSuite, TextureManagementLockEncapsulationTesting);
    ADD_TEST(renderersSuite, PlatformRenderTargetTesting);
    ADD_TEST(renderersSuite, RenderTargetManagementTesting);

    DoAddSuite(renderersSuite);
}

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddOpenGLRendererSuite()
{
    auto openGLRendererSuite = GenerateSuite("OpenGL渲染器");

    ADD_TEST(openGLRendererSuite, OpenGLBindTextureTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatArrayDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataManageTesting);
    ADD_TEST(openGLRendererSuite, OpenGLRenderTargetDataTesting);

    DoAddSuite(openGLRendererSuite);
}
