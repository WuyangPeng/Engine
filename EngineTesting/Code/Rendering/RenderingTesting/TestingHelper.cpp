/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 15:13)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

Rendering::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "渲染库" }
{
    InitSuite();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TestingHelper)

void Rendering::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddBaseSuite();
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
    AddRendererEngineSuite();
    AddOpenGLRendererSuite();
    AddDx9RendererSuite();
    AddAglRendererSuite();
    AddGlutRendererSuite();
    AddGlxRendererSuite();
    AddWglRendererSuite();
    AddStateSuite();
}

void Rendering::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    AddSuite(helperSuite);
}

void Rendering::TestingHelper::AddBaseSuite()
{
    auto baseSuite = GenerateSuite("基础");

    ADD_TEST(baseSuite, GraphicsObjectTesting);

    AddSuite(baseSuite);
}

void Rendering::TestingHelper::AddDataTypesSuite()
{
    auto dataTypeSuite = GenerateSuite("数据类型");

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

    AddSuite(dataTypeSuite);
}

void Rendering::TestingHelper::AddResourcesSuite()
{
    auto resourcesSuite = GenerateSuite("资源");

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

    AddSuite(resourcesSuite);
}

void Rendering::TestingHelper::AddSceneGraphSuite()
{
    auto sceneGraphSuite = GenerateSuite("场景图");

    sceneGraphSuite.AddSuite(GetViewVolumeSuite());
    sceneGraphSuite.AddSuite(GetCameraSuite());
    ADD_TEST(sceneGraphSuite, CameraManageTesting);
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

    AddSuite(sceneGraphSuite);
}

CoreTools::Suite Rendering::TestingHelper::GetViewVolumeSuite()
{
    auto viewVolumeSuite = GenerateSuite("视景体");

    ADD_TEST(viewVolumeSuite, WorldCoordinateFrameTesting);
    ADD_TEST(viewVolumeSuite, ProjectionMatrixTesting);
    ADD_TEST(viewVolumeSuite, CameraFrustumTesting);
    ADD_TEST(viewVolumeSuite, ViewVolumeTesting);

    return viewVolumeSuite;
}

Rendering::TestingHelper::Suite Rendering::TestingHelper::GetCameraSuite()
{
    auto cameraSuite = GenerateSuite("摄像机");

    ADD_TEST(cameraSuite, CameraFrustumDataTesting);
    ADD_TEST(cameraSuite, PickLineTesting);
    ADD_TEST(cameraSuite, CameraTesting);

    return cameraSuite;
}

void Rendering::TestingHelper::AddControllersSuite()
{
    auto controllersSuite = GenerateSuite("控制器");

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

    AddSuite(controllersSuite);
}

void Rendering::TestingHelper::AddShaderFloatsSuite()
{
    auto shaderFloatsSuite = GenerateSuite("浮点着色器");

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

    AddSuite(shaderFloatsSuite);
}

void Rendering::TestingHelper::AddDetailSuite()
{
    auto detailSuite = GenerateSuite("细节");

    ADD_TEST(detailSuite, SwitchNodeTesting);
    ADD_TEST(detailSuite, BillboardNodeTesting);
    ADD_TEST(detailSuite, CollapseRecordTesting);
    ADD_TEST(detailSuite, CollapseRecordArrayTesting);
    ADD_TEST(detailSuite, CreateClodMeshTesting);
    ADD_TEST(detailSuite, ClodMeshTesting);
    ADD_TEST(detailSuite, DlodNodeTesting);

    AddSuite(detailSuite);
}

void Rendering::TestingHelper::AddShadersSuite()
{
    auto shadersSuite = GenerateSuite("着色器");

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

    AddSuite(shadersSuite);
}

void Rendering::TestingHelper::AddLocalEffectsSuite()
{
    auto localEffectsSuite = GenerateSuite("局部特效");

    AddSuite(localEffectsSuite);
}

void Rendering::TestingHelper::AddGlobalEffectsSuite()
{
    auto globalEffectsSuite = GenerateSuite("全局特效");

    AddSuite(globalEffectsSuite);
}

void Rendering::TestingHelper::AddCurvesSurfacesSuite()
{
    auto curvesSurfacesSuite = GenerateSuite("曲线曲面");

    ADD_TEST(curvesSurfacesSuite, FloatArrayTesting);
    ADD_TEST(curvesSurfacesSuite, Float2ArrayTesting);
    ADD_TEST(curvesSurfacesSuite, SurfacePatchFrameTesting);
    ADD_TEST(curvesSurfacesSuite, PrincipalCurvatureInfoTesting);
    ADD_TEST(curvesSurfacesSuite, SurfacePatchTesting);

    AddSuite(curvesSurfacesSuite);
}

void Rendering::TestingHelper::AddIlluminationSuite()
{
    auto illuminationSuite = GenerateSuite("光照");

    AddSuite(illuminationSuite);
}

void Rendering::TestingHelper::AddImageProcessingSuite()
{
    auto imageProcessingSuite = GenerateSuite("图像处理");

    AddSuite(imageProcessingSuite);
}

void Rendering::TestingHelper::AddPictureSuite()
{
    auto pictureSuite = GenerateSuite("图像");

    AddSuite(pictureSuite);
}

void Rendering::TestingHelper::AddSortingSuite()
{
    auto sortingSuite = GenerateSuite("排序");

    AddSuite(sortingSuite);
}

void Rendering::TestingHelper::AddTerrainSuite()
{
    auto terrainSuite = GenerateSuite("地形处理");

    AddSuite(terrainSuite);
}

void Rendering::TestingHelper::AddVertexSuite()
{
    auto vertexSuite = GenerateSuite("顶点");

    AddSuite(vertexSuite);
}

void Rendering::TestingHelper::AddTextFontsSuite()
{
    auto textFontsSuite = GenerateSuite("文本及字体");

    AddSuite(textFontsSuite);
}

void Rendering::TestingHelper::AddConsoleGraphSuite()
{
    auto consoleGraphSuite = GenerateSuite("控制台图形");

    AddSuite(consoleGraphSuite);
}

void Rendering::TestingHelper::AddOpenGLAPISuite()
{
    auto openGLAPISuite = GenerateSuite("OpenGLAPI");

    AddSuite(openGLAPISuite);
}

void Rendering::TestingHelper::AddDirectAPISuite()
{
    auto directAPISuite = GenerateSuite("DirectAPI");

    AddSuite(directAPISuite);
}

void Rendering::TestingHelper::AddRendererEngineSuite()
{
    auto rendererEngineSuite = GenerateSuite("渲染器");

    ADD_TEST(rendererEngineSuite, ViewportTesting);
    ADD_TEST(rendererEngineSuite, DepthRangeTesting);
    ADD_TEST(rendererEngineSuite, RendererBasisTesting);
    ADD_TEST(rendererEngineSuite, WindowsParameterTesting);
    ADD_TEST(rendererEngineSuite, RendererParameterTesting);
    ADD_TEST(rendererEngineSuite, EnvironmentParameterTesting);
    ADD_TEST(rendererEngineSuite, RenderingEnvironmentTesting);
    ADD_TEST(rendererEngineSuite, RenderingDeviceTesting);
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

    AddSuite(rendererEngineSuite);
}

void Rendering::TestingHelper::AddOpenGLRendererSuite()
{
    auto openGLRendererSuite = GenerateSuite("OpenGL渲染器");

    ADD_TEST(openGLRendererSuite, OpenGLBindTextureTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLVertexFormatArrayDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataTesting);
    ADD_TEST(openGLRendererSuite, OpenGLTextureDataManageTesting);
    ADD_TEST(openGLRendererSuite, OpenGLRenderTargetDataTesting);

    AddSuite(openGLRendererSuite);
}

void Rendering::TestingHelper::AddDx9RendererSuite()
{
    auto dx9RendererSuite = GenerateSuite("Dx9渲染器");

    AddSuite(dx9RendererSuite);
}

void Rendering::TestingHelper::AddAglRendererSuite()
{
    auto aglRendererSuite = GenerateSuite("Agl渲染器");

    AddSuite(aglRendererSuite);
}

void Rendering::TestingHelper::AddGlutRendererSuite()
{
    auto glutRendererSuite = GenerateSuite("Glut渲染器");

    AddSuite(glutRendererSuite);
}

void Rendering::TestingHelper::AddGlxRendererSuite()
{
    auto glxRendererSuite = GenerateSuite("Glx渲染器");

    AddSuite(glxRendererSuite);
}

void Rendering::TestingHelper::AddWglRendererSuite()
{
    auto wglRendererSuite = GenerateSuite("Wgl渲染器");

    AddSuite(wglRendererSuite);
}

void Rendering::TestingHelper::AddStateSuite()
{
    auto stateSuite = GenerateSuite("状态");

    ADD_TEST(stateSuite, DrawingStateTesting);
    ADD_TEST(stateSuite, BlendStateTargetTesting);
    ADD_TEST(stateSuite, BlendStateTesting);
    ADD_TEST(stateSuite, DepthStencilStateFaceTesting);
    ADD_TEST(stateSuite, DepthStencilStateTesting);
    ADD_TEST(stateSuite, RasterizerStateTesting);

    AddSuite(stateSuite);
}
