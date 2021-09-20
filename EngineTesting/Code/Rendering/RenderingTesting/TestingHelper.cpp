// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.3 (2019/09/02 19:10)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Rendering, TestingHelper, "渲染库")

// private
void Rendering::TestingHelper ::AddSuites()
{
    AddMacroSuite();
    AddDataTypesSuite();
    AddResourcesSuite();
    AddSceneGraphSuite();
    AddControllersSuite();
    AddShaderFloatsSuite();
    AddDetailSuite();
    AddShadersSuite();
    AddLocalEffectsSuite();
    AddGlobalEffectsSuite();
    AddCurvesSurfacesSuite();
    AddIlluminationSuite();
    AddImageProcessingSuite();
    AddPictureSuite();
    AddSortingSuite();
    AddTerrainSuite();
    AddVertexSuite();
    AddTextFontsSuite();
    AddConsoleGraphSuite();
    AddOpenGLAPISuite();
    AddDirectAPISuite();
    AddRenderersSuite();
    AddOpenGLRendererSuite();
    AddDx9RendererSuite();
    AddAglRendererSuite();
    AddGlutRendererSuite();
    AddGlxRendererSuite();
    AddWglRendererSuite();
    AddLib3dsSuite();
    AddAbuseSuite();
    AddDemoglSuite();
    AddDevILSuite();
    AddFBXSuite();
    AddJPEGSuite();
    AddTIFFSuite();
    AddOpenvidiaSuite();
    AddNethackSuite();
    AddWingSuite();
    AddWargamerSuite();
    AddNvtoolkitSuite();
}

void Rendering::TestingHelper ::AddMacroSuite()
{
    ADD_TEST_BEGIN(macroSuite, "宏");

    ADD_TEST_END(macroSuite);
}

// private
void Rendering::TestingHelper ::AddDataTypesSuite()
{
    ADD_TEST_BEGIN(dataTypeSuite, "数据类型");

    ADD_TEST(dataTypeSuite, HalfFloatTesting);
    ADD_TEST(dataTypeSuite, ColourDefaultTraitsTesting);
    ADD_TEST(dataTypeSuite, ColourTesting);
    ADD_TEST(dataTypeSuite, TextureColourTesting);
    ADD_TEST(dataTypeSuite, ColourManagerTesting);
    ADD_TEST(dataTypeSuite, ColourConvertFromTesting);
    ADD_TEST(dataTypeSuite, ColourConvertToTesting);
    ADD_TEST(dataTypeSuite, UtilityTesting);
    ADD_TEST(dataTypeSuite, TransformTesting);
    ADD_TEST(dataTypeSuite, BoundTesting);
    ADD_TEST(dataTypeSuite, SpecializedIOTesting);

    ADD_TEST_END(dataTypeSuite);
}

void Rendering::TestingHelper ::AddResourcesSuite()
{
    ADD_TEST_BEGIN(resourcesSuite, "资源");

    ADD_TEST(resourcesSuite, BufferTesting);
    ADD_TEST(resourcesSuite, Texture1DTesting);
    ADD_TEST(resourcesSuite, Texture2DTesting);
    ADD_TEST(resourcesSuite, Texture3DTesting);
    ADD_TEST(resourcesSuite, TextureCubeTesting);
    ADD_TEST(resourcesSuite, RenderTargetTesting);
    ADD_TEST(resourcesSuite, VertexFormatTypeTesting);
    ADD_TEST(resourcesSuite, VertexFormatElementTesting);
    ADD_TEST(resourcesSuite, VertexFormatTesting);
    ADD_TEST(resourcesSuite, VertexBufferAccessorTesting);

    ADD_TEST_END(resourcesSuite);
}

// private
void Rendering::TestingHelper ::AddSceneGraphSuite()
{
    ADD_TEST_BEGIN(sceneGraphSuite, "场景图");

    ADD_TEST(sceneGraphSuite, CameraFrustumDataTesting);
    ADD_TEST(sceneGraphSuite, CameraManageTesting);
    ADD_TEST(sceneGraphSuite, CameraTesting);
    ADD_TEST(sceneGraphSuite, SpatialTesting);
    ADD_TEST(sceneGraphSuite, VisibleSetTesting);
    ADD_TEST(sceneGraphSuite, CullerTesting);
    ADD_TEST(sceneGraphSuite, NodeTesting);
    ADD_TEST(sceneGraphSuite, LightTesting);
    ADD_TEST(sceneGraphSuite, CameraNodeTesting);
    ADD_TEST(sceneGraphSuite, MaterialTesting);
    ADD_TEST(sceneGraphSuite, VisualTesting);
    ADD_TEST(sceneGraphSuite, TriangleIndexTesting);
    ADD_TEST(sceneGraphSuite, TrianglePositionTesting);
    ADD_TEST(sceneGraphSuite, PolypointTesting);
    ADD_TEST(sceneGraphSuite, PolysegmentTesting);
    ADD_TEST(sceneGraphSuite, TrianglesMeshTesting);
    ADD_TEST(sceneGraphSuite, TrianglesStripTesting);
    ADD_TEST(sceneGraphSuite, TrianglesFanTesting);
    ADD_TEST(sceneGraphSuite, ParticlesTesting);
    ADD_TEST(sceneGraphSuite, ProjectorTesting);
    ADD_TEST(sceneGraphSuite, PickRecordTesting);
    ADD_TEST(sceneGraphSuite, PickRecordContainerTesting);
    ADD_TEST(sceneGraphSuite, PickerTesting);
    ADD_TEST(sceneGraphSuite, ScreenTargetTesting);
    ADD_TEST(sceneGraphSuite, StandardMeshTesting);

    ADD_TEST_END(sceneGraphSuite);
}

// private
void Rendering::TestingHelper ::AddControllersSuite()
{
    ADD_TEST_BEGIN(controllersSuite, "控制器");

    ADD_TEST(controllersSuite, ControllerTesting);
    ADD_TEST(controllersSuite, ControlledObjectTesting);
    ADD_TEST(controllersSuite, TransformControllerTesting);
    ADD_TEST(controllersSuite, SkinControllerTesting);
    ADD_TEST(controllersSuite, PointControllerTesting);
    ADD_TEST(controllersSuite, ParticleControllerTesting);
    ADD_TEST(controllersSuite, ControllerKeyInfoTesting);
    ADD_TEST(controllersSuite, MorphControllerTesting);
    ADD_TEST(controllersSuite, KeyframeControllerTesting);
    ADD_TEST(controllersSuite, IKGoalTesting);
    ADD_TEST(controllersSuite, IKJointTesting);
    ADD_TEST(controllersSuite, IKControllerTesting);
    ADD_TEST(controllersSuite, BlendTransformControllerTesting);

    ADD_TEST_END(controllersSuite);
}

void Rendering::TestingHelper ::AddShaderFloatsSuite()
{
    ADD_TEST_BEGIN(shaderFloatsSuite, "浮点着色器");

    ADD_TEST(shaderFloatsSuite, ShaderFloatTesting);
    ADD_TEST(shaderFloatsSuite, CameraModelDirectionVectorConstantTesting);
    ADD_TEST(shaderFloatsSuite, CameraModelPositionConstantTesting);
    ADD_TEST(shaderFloatsSuite, CameraWorldDirectionVectorConstantTesting);
    ADD_TEST(shaderFloatsSuite, CameraWorldPositionConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightAmbientConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightAttenuationConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightDiffuseConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightModelDirectionVectorConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightModelPositionConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightSpecularConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightSpotConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightWorldDirectionVectorConstantTesting);
    ADD_TEST(shaderFloatsSuite, LightWorldPositionConstantTesting);
    ADD_TEST(shaderFloatsSuite, MaterialAmbientConstantTesting);
    ADD_TEST(shaderFloatsSuite, MaterialDiffuseConstantTesting);
    ADD_TEST(shaderFloatsSuite, MaterialEmissiveConstantTesting);
    ADD_TEST(shaderFloatsSuite, MaterialSpecularConstantTesting);
    ADD_TEST(shaderFloatsSuite, ProjectionMatrixConstantTesting);
    ADD_TEST(shaderFloatsSuite, ProjectionViewMatrixConstantTesting);
    ADD_TEST(shaderFloatsSuite, ProjectionViewWorldMatrixConstantTesting);
    ADD_TEST(shaderFloatsSuite, ViewMatrixConstantTesting);
    ADD_TEST(shaderFloatsSuite, ViewWorldMatrixConstantTesting);
    ADD_TEST(shaderFloatsSuite, WorldMatrixConstantTesting);
    ADD_TEST(shaderFloatsSuite, ProjectorWorldPositionConstantTesting);
    ADD_TEST(shaderFloatsSuite, ProjectorMatrixConstantTesting);

    ADD_TEST_END(shaderFloatsSuite);
}

void Rendering::TestingHelper ::AddDetailSuite()
{
    ADD_TEST_BEGIN(detailSuite, "细节");

    ADD_TEST(detailSuite, SwitchNodeTesting);
    ADD_TEST(detailSuite, BillboardNodeTesting);
    ADD_TEST(detailSuite, CollapseRecordTesting);
    ADD_TEST(detailSuite, CollapseRecordArrayTesting);
    ADD_TEST(detailSuite, CreateClodMeshTesting);
    ADD_TEST(detailSuite, ClodMeshTesting);
    ADD_TEST(detailSuite, DlodNodeTesting);

    ADD_TEST_END(detailSuite);
}

void Rendering::TestingHelper ::AddShadersSuite()
{
    ADD_TEST_BEGIN(shadersSuite, "着色器");

    ADD_TEST(shadersSuite, SingleShaderBaseDataTesting);
    ADD_TEST(shadersSuite, ShaderBaseDataTesting);
    ADD_TEST(shadersSuite, SingleShaderConstantsDataTesting);
    ADD_TEST(shadersSuite, ShaderConstantsDataTesting);
    ADD_TEST(shadersSuite, SingleShaderSamplerDataTesting);
    ADD_TEST(shadersSuite, ShaderSamplerDataTesting);
    ADD_TEST(shadersSuite, ShaderManageTesting);
    ADD_TEST(shadersSuite, ShaderParametersTesting);
    ADD_TEST(shadersSuite, VertexShaderTesting);
    ADD_TEST(shadersSuite, PixelShaderTesting);
    ADD_TEST(shadersSuite, SingleShaderProfileDataTesting);
    ADD_TEST(shadersSuite, ShaderProfileDataTesting);
    ADD_TEST(shadersSuite, AlphaStateTesting);
    ADD_TEST(shadersSuite, CullStateTesting);
    ADD_TEST(shadersSuite, DepthStateTesting);
    ADD_TEST(shadersSuite, OffsetStateTesting);
    ADD_TEST(shadersSuite, StencilStateTesting);
    ADD_TEST(shadersSuite, WireStateTesting);
    ADD_TEST(shadersSuite, VisualPassTesting);
    ADD_TEST(shadersSuite, VisualTechniqueTesting);
    ADD_TEST(shadersSuite, VisualEffectTesting);
    ADD_TEST(shadersSuite, SaveVisualEffectTesting);
    ADD_TEST(shadersSuite, LoadVisualEffectTesting);
    ADD_TEST(shadersSuite, VisualEffectInstanceTesting);

    ADD_TEST_END(shadersSuite);
}

void Rendering::TestingHelper ::AddLocalEffectsSuite()
{
    ADD_TEST_BEGIN(localEffectsSuite, "局部特效");

    ADD_TEST_END(localEffectsSuite);
}

void Rendering::TestingHelper ::AddGlobalEffectsSuite()
{
    ADD_TEST_BEGIN(globalEffectsSuite, "全局特效");

    ADD_TEST_END(globalEffectsSuite);
}

void Rendering::TestingHelper ::AddCurvesSurfacesSuite()
{
    ADD_TEST_BEGIN(curvesSurfacesSuite, "曲线曲面");

    ADD_TEST(curvesSurfacesSuite, FloatArrayTesting);
    ADD_TEST(curvesSurfacesSuite, Float2ArrayTesting);
    ADD_TEST(curvesSurfacesSuite, SurfacePatchFrameTesting);
    ADD_TEST(curvesSurfacesSuite, PrincipalCurvatureInfoTesting);
    ADD_TEST(curvesSurfacesSuite, SurfacePatchTesting);

    ADD_TEST_END(curvesSurfacesSuite);
}

void Rendering::TestingHelper ::AddIlluminationSuite()
{
    ADD_TEST_BEGIN(illuminationSuite, "光照");

    ADD_TEST_END(illuminationSuite);
}

void Rendering::TestingHelper ::AddImageProcessingSuite()
{
    ADD_TEST_BEGIN(imageProcessingSuite, "图像处理");

    ADD_TEST_END(imageProcessingSuite);
}

void Rendering::TestingHelper ::AddPictureSuite()
{
    ADD_TEST_BEGIN(pictureSuite, "图像");

    ADD_TEST_END(pictureSuite);
}

void Rendering::TestingHelper ::AddSortingSuite()
{
    ADD_TEST_BEGIN(sortingSuite, "排序");

    ADD_TEST_END(sortingSuite);
}

void Rendering::TestingHelper ::AddTerrainSuite()
{
    ADD_TEST_BEGIN(terrainSuite, "地形处理");

    ADD_TEST_END(terrainSuite);
}

void Rendering::TestingHelper ::AddVertexSuite()
{
    ADD_TEST_BEGIN(vertexSuite, "顶点");

    ADD_TEST_END(vertexSuite);
}

void Rendering::TestingHelper ::AddTextFontsSuite()
{
    ADD_TEST_BEGIN(textFontsSuite, "文本及字体");

    ADD_TEST_END(textFontsSuite);
}

void Rendering::TestingHelper ::AddConsoleGraphSuite()
{
    ADD_TEST_BEGIN(consoleGraphSuite, "控制台图形");

    ADD_TEST_END(consoleGraphSuite);
}

void Rendering::TestingHelper ::AddOpenGLAPISuite()
{
    ADD_TEST_BEGIN(openGLAPISuite, "OpenGLAPI");

    ADD_TEST_END(openGLAPISuite);
}

void Rendering::TestingHelper ::AddDirectAPISuite()
{
    ADD_TEST_BEGIN(directAPISuite, "DirectAPI");

    ADD_TEST_END(directAPISuite);
}

void Rendering::TestingHelper ::AddRenderersSuite()
{
    ADD_TEST_BEGIN(renderersSuite, "渲染器");

    ADD_TEST(renderersSuite, RendererBasisTesting);
    ADD_TEST(renderersSuite, RendererParameterTesting);
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

    ADD_TEST_END(renderersSuite);
}

void Rendering::TestingHelper ::AddOpenGLRendererSuite()
{
    ADD_TEST_BEGIN(openGLRendererSuite, "OpenGL渲染器");

    ADD_TEST(openGLRendererSuite, OpenGLBindTextureTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatArrayDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataManageTesting);
    ADD_TEST(openGLRendererSuite, OpenGLRenderTargetDataTesting);

    ADD_TEST_END(openGLRendererSuite);
}

void Rendering::TestingHelper ::AddDx9RendererSuite()
{
    ADD_TEST_BEGIN(dx9RendererSuite, "Dx9渲染器");

    ADD_TEST_END(dx9RendererSuite);
}

void Rendering::TestingHelper ::AddAglRendererSuite()
{
    ADD_TEST_BEGIN(aglRendererSuite, "Agl渲染器");

    ADD_TEST_END(aglRendererSuite);
}

void Rendering::TestingHelper ::AddGlutRendererSuite()
{
    ADD_TEST_BEGIN(glutRendererSuite, "Glut渲染器");

    ADD_TEST_END(glutRendererSuite);
}

void Rendering::TestingHelper ::AddGlxRendererSuite()
{
    ADD_TEST_BEGIN(glxRendererSuite, "Glx渲染器");

    ADD_TEST_END(glxRendererSuite);
}

void Rendering::TestingHelper ::AddWglRendererSuite()
{
    ADD_TEST_BEGIN(wglRendererSuite, "Wgl渲染器");

    ADD_TEST_END(wglRendererSuite);
}

void Rendering::TestingHelper ::AddLib3dsSuite()
{
    ADD_TEST_BEGIN(lib3dsSuite, "Lib3ds");

    ADD_TEST_END(lib3dsSuite);
}

void Rendering::TestingHelper ::AddAbuseSuite()
{
    ADD_TEST_BEGIN(abuseSuite, "Abuse");

    ADD_TEST_END(abuseSuite);
}

void Rendering::TestingHelper ::AddDemoglSuite()
{
    ADD_TEST_BEGIN(demoglSuite, "Demogl");

    ADD_TEST_END(demoglSuite);
}

void Rendering::TestingHelper ::AddDevILSuite()
{
    ADD_TEST_BEGIN(devILSuite, "DevIL");

    ADD_TEST_END(devILSuite);
}

void Rendering::TestingHelper ::AddFBXSuite()
{
    ADD_TEST_BEGIN(fBXSuite, "FBX");

    ADD_TEST_END(fBXSuite);
}

void Rendering::TestingHelper ::AddJPEGSuite()
{
    ADD_TEST_BEGIN(jPEGSuite, "JPEG");

    ADD_TEST_END(jPEGSuite);
}

void Rendering::TestingHelper ::AddTIFFSuite()
{
    ADD_TEST_BEGIN(tIFFSuite, "TIFF");

    ADD_TEST_END(tIFFSuite);
}

void Rendering::TestingHelper ::AddOpenvidiaSuite()
{
    ADD_TEST_BEGIN(openvidiaSuite, "Openvidia");

    ADD_TEST_END(openvidiaSuite);
}

void Rendering::TestingHelper ::AddNethackSuite()
{
    ADD_TEST_BEGIN(nethackSuite, "Nethack");

    ADD_TEST_END(nethackSuite);
}

void Rendering::TestingHelper ::AddWingSuite()
{
    ADD_TEST_BEGIN(wingSuite, "Wing");

    ADD_TEST_END(wingSuite);
}

void Rendering::TestingHelper ::AddWargamerSuite()
{
    ADD_TEST_BEGIN(wargamerSuite, "Wargamer");

    ADD_TEST_END(wargamerSuite);
}

void Rendering::TestingHelper ::AddNvtoolkitSuite()
{
    ADD_TEST_BEGIN(nvtoolkitSuite, "Nvtoolkit");

    ADD_TEST_END(nvtoolkitSuite);
}
