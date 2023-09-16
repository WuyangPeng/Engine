///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 13:50)

#include "OpenGLGlutCallBack.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackUnitTestSuiteDetail.h"

System::OpenGLGlutCallBack::OpenGLGlutCallBack(int64_t delta)
    : ParentType{ delta, "��ϵͳ�⡿OpenGL��Ԫ�����׼�" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutCallBack)

void System::OpenGLGlutCallBack::AddSuite()
{
    AddOpenGLSuite();
}

void System::OpenGLGlutCallBack::AddOpenGLSuite()
{
    auto openGLSuite = GenerateSuite("OpenGL");

    openGLSuite.AddSuite(GetOpenGLUtilitySuite());
    ADD_TEST(openGLSuite, OpenGLInitTesting);
    openGLSuite.AddSuite(GetOpenGLBaseSuite());
    openGLSuite.AddSuite(GetOpenGLBuffersSuite());
    openGLSuite.AddSuite(GetOpenGLTexturesSuite());
    openGLSuite.AddSuite(GetOpenGLPolygonSuite());
    openGLSuite.AddSuite(GetOpenGLSamplersSuite());
    openGLSuite.AddSuite(GetOpenGLProgramSuite());
    openGLSuite.AddSuite(GetOpenGLShaderSuite());
    openGLSuite.AddSuite(GetOpenGLGlutSuite());

    DoAddSuite(openGLSuite);
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLUtilitySuite()
{
    auto openGLUtilitySuite = GenerateSuite("OpenGL ������");

    ADD_TEST(openGLUtilitySuite, OpenGLErrorDescriptionTesting);
    ADD_TEST(openGLUtilitySuite, OpenGLSupportsExtensionTesting);
    ADD_TEST(openGLUtilitySuite, OpenGLVersionTesting);
    ADD_TEST(openGLUtilitySuite, WglSupportsExtensionTesting);

    return openGLUtilitySuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLBaseSuite()
{
    auto openGLBaseSuite = GenerateSuite("OpenGL ����");

    ADD_TEST(openGLBaseSuite, OpenGLBaseTesting);
    ADD_TEST(openGLBaseSuite, OpenGLQueryTesting);
    ADD_TEST(openGLBaseSuite, OpenGLBlendTesting);
    ADD_TEST(openGLBaseSuite, OpenGLDepthTesting);
    ADD_TEST(openGLBaseSuite, OpenGLMaskTesting);
    ADD_TEST(openGLBaseSuite, OpenGLStateTesting);
    ADD_TEST(openGLBaseSuite, OpenGLStencilTesting);

    return openGLBaseSuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLBuffersSuite()
{
    auto openGLBuffersSuite = GenerateSuite("OpenGL ������");

    ADD_TEST(openGLBuffersSuite, OpenGLGetBuffersTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLSetBufferTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLSetBufferSubDataTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLSetCopyBufferSubDataTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLFrameBufferTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLBindFrameBufferTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLVertexArraysTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLBindVertexBufferTesting);
    ADD_TEST(openGLBuffersSuite, OpenGLDrawBuffersTesting);

    return openGLBuffersSuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLTexturesSuite()
{
    auto openGLTexturesSuite = GenerateSuite("OpenGL ����");

    ADD_TEST(openGLTexturesSuite, OpenGLGetTexturesTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLBindTexturesTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLPixelStoreTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLTexturesParameterTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLTextures1DTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLTextures2DTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLTexturesCubeTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLTextures3DTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLTexturesCubeArrayTesting);
    ADD_TEST(openGLTexturesSuite, OpenGLFrameBufferTextures2DTesting);

    return openGLTexturesSuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLPolygonSuite()
{
    auto openGLPolygonSuite = GenerateSuite("OpenGL �����");

    ADD_TEST(openGLPolygonSuite, OpenGLPolygonModeTesting);
    ADD_TEST(openGLPolygonSuite, OpenGLPolygonOffsetTesting);

    return openGLPolygonSuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLSamplersSuite()
{
    auto openGLSamplersSuite = GenerateSuite("OpenGL Samplers");

    ADD_TEST(openGLSamplersSuite, OpenGLGetSamplersTesting);
    ADD_TEST(openGLSamplersSuite, OpenGLSetSamplerParameterTesting);

    return openGLSamplersSuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLProgramSuite()
{
    auto openGLProgramSuite = GenerateSuite("OpenGL Program");

    ADD_TEST(openGLProgramSuite, OpenGLCreateProgramTesting);
    ADD_TEST(openGLProgramSuite, OpenGLProgramAttributesTesting);
    ADD_TEST(openGLProgramSuite, OpenGLProgramLinkTesting);
    ADD_TEST(openGLProgramSuite, OpenGLProgramResourceTesting);
    ADD_TEST(openGLProgramSuite, OpenGLProgramStatusTesting);
    ADD_TEST(openGLProgramSuite, ComputeWorkGroupSizeTesting);
    ADD_TEST(openGLProgramSuite, OpenGLProgramInterfaceTesting);

    return openGLProgramSuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLShaderSuite()
{
    auto openGLShaderSuite = GenerateSuite("OpenGL ��ɫ��");

    ADD_TEST(openGLShaderSuite, OpenGLAttachShaderTesting);
    ADD_TEST(openGLShaderSuite, OpenGLCompileShaderTesting);
    ADD_TEST(openGLShaderSuite, OpenGLCreateShaderTesting);
    ADD_TEST(openGLShaderSuite, OpenGLGetUniformLocationTesting);
    ADD_TEST(openGLShaderSuite, OpenGLShaderAttributesTesting);
    ADD_TEST(openGLShaderSuite, OpenGLShaderStatusTesting);

    return openGLShaderSuite;
}

CoreTools::Suite System::OpenGLGlutCallBack::GetOpenGLGlutSuite()
{
    auto openGLGlutSuite = GenerateSuite("OpenGL Glut");

    ADD_TEST(openGLGlutSuite, OpenGLGlutCallbackTesting);
    ADD_TEST(openGLGlutSuite, OpenGLGlutCreateWindowTesting);
    ADD_TEST(openGLGlutSuite, OpenGLGlutDestroyTesting);

    return openGLGlutSuite;
}
