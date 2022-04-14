// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/09 12:52)

#include "RenderingOpenGLTestingOpenGLGlutCallBack.h"
#include "Testing.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using std::string;

Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::RenderingOpenGLTestingOpenGLGlutCallBack(int64_t delta)
    : ParentType{ delta, "¡¾äÖÈ¾¿â¡¿OpenGLµ¥Ôª²âÊÔÌ×¼ş" }
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
    return "¡¾äÖÈ¾¿â¡¿OpenGLµ¥Ôª²âÊÔÌ×¼ş";
}

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddRenderersSuite()
{
    auto renderersSuite = GenerateSuite("äÖÈ¾Æ÷");

    // 	ADD_TEST(renderersSuite, PlatformVertexFormatTesting);
    // 	ADD_TEST(renderersSuite, VertexFormatManagementTesting);
    // 	ADD_TEST(renderersSuite, PlatformIndexBufferTesting);
    // 	ADD_TEST(renderersSuite, PlatformVertexBufferTesting);
    // 	ADD_TEST(renderersSuite, BufferLockManageTesting);
    // 	ADD_TEST(renderersSuite, BufferManagementTesting);
    // 	ADD_TEST(renderersSuite, BufferManagementLockEncapsulationTesting);
    // 	ADD_TEST(renderersSuite, PlatformTexture1DTesting);
    // 	ADD_TEST(renderersSuite, PlatformTexture2DTesting);
    // 	ADD_TEST(renderersSuite, PlatformTexture3DTesting);
    // 	ADD_TEST(renderersSuite, PlatformTextureCubeTesting);
    // 	ADD_TEST(renderersSuite, TextureLockManageTesting);
    // 	ADD_TEST(renderersSuite, TextureManagementTesting);
    // 	ADD_TEST(renderersSuite, TextureManagementLockEncapsulationTesting);
    // 	ADD_TEST(renderersSuite, PlatformRenderTargetTesting);
    // 	ADD_TEST(renderersSuite, RenderTargetManagementTesting);

    DoAddSuite(renderersSuite);
}

void Rendering::RenderingOpenGLTestingOpenGLGlutCallBack::AddOpenGLRendererSuite()
{
    auto openGLRendererSuite = GenerateSuite("OpenGLäÖÈ¾Æ÷");

    // 	ADD_TEST(openGLRendererSuite, OpenGLBindTextureTesting);
    // 	ADD_TEST(openGLRendererSuite, OpenGLVertexFormatDataTesting);
    // 	ADD_TEST(openGLRendererSuite, OpenGLVertexFormatArrayDataTesting);
    // 	ADD_TEST(openGLRendererSuite, OpenGLTextureDataTesting);
    // 	ADD_TEST(openGLRendererSuite, OpenGLTextureDataManageTesting);
    // 	ADD_TEST(openGLRendererSuite, OpenGLRenderTargetDataTesting);

    DoAddSuite(openGLRendererSuite);
}
