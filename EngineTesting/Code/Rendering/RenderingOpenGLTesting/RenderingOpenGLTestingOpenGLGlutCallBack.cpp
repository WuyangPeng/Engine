///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:19)

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
    AddRendererEngineSuite();
    AddOpenGLRendererSuite();
}

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddRendererEngineSuite()
{
    auto rendererEngineSuite = GenerateSuite("渲染引擎");

    ADD_TEST(rendererEngineSuite, EnvironmentParameterTesting);
    ADD_TEST(rendererEngineSuite, RenderingEnvironmentTesting);
    ADD_TEST(rendererEngineSuite, PlatformVertexFormatTesting);
    ADD_TEST(rendererEngineSuite, VertexFormatManagementTesting);
    ADD_TEST(rendererEngineSuite, PlatformIndexBufferTesting);
    ADD_TEST(rendererEngineSuite, PlatformVertexBufferTesting);
    ADD_TEST(rendererEngineSuite, BufferLockManageTesting);
    ADD_TEST(rendererEngineSuite, BufferManagementTesting);
    ADD_TEST(rendererEngineSuite, BufferManagementLockEncapsulationTesting);
    ADD_TEST(rendererEngineSuite, PlatformTexture1DTesting);
    ADD_TEST(rendererEngineSuite, PlatformTexture2DTesting);
    ADD_TEST(rendererEngineSuite, PlatformTexture3DTesting);
    ADD_TEST(rendererEngineSuite, PlatformTextureCubeTesting);
    ADD_TEST(rendererEngineSuite, TextureLockManageTesting);
    ADD_TEST(rendererEngineSuite, TextureManagementTesting);
    ADD_TEST(rendererEngineSuite, TextureManagementLockEncapsulationTesting);
    ADD_TEST(rendererEngineSuite, PlatformRenderTargetTesting);
    ADD_TEST(rendererEngineSuite, RenderTargetManagementTesting);

    DoAddSuite(rendererEngineSuite);
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
