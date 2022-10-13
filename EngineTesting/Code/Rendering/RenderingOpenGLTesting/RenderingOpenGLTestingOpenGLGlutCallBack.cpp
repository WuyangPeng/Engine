///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/17 22:17)

#include "RenderingOpenGLTestingOpenGLGlutCallBack.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using std::string;

Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::RenderingOpenGLTestingOpenGLGlutCallBack(int64_t delta)
    : ParentType{ delta, "����Ⱦ�⡿OpenGL��Ԫ�����׼�" }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RenderingOpenGLTestingOpenGLGlutCallBack)

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddSuite()
{
    AddRenderersSuite();
    AddOpenGLRendererSuite();
}

string Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::GetSuiteName() const
{
    return "����Ⱦ�⡿OpenGL��Ԫ�����׼�";
}

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddRenderersSuite()
{
    auto renderersSuite = GenerateSuite("��Ⱦ��");

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
    auto openGLRendererSuite = GenerateSuite("OpenGL��Ⱦ��");

    ADD_TEST(openGLRendererSuite, OpenGLBindTextureTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatArrayDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataManageTesting);
    ADD_TEST(openGLRendererSuite, OpenGLRenderTargetDataTesting);

    DoAddSuite(openGLRendererSuite);
}
