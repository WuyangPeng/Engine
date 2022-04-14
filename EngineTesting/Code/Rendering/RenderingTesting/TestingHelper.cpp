// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/02 19:10)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

Rendering::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "��Ⱦ��"s }
{
    InitSuite();

    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TestingHelper)

void Rendering::TestingHelper::InitSuite()
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

void Rendering::TestingHelper::AddMacroSuite()
{
    auto macroSuite = GenerateSuite("��");

    AddSuite(macroSuite);
}

// private
void Rendering::TestingHelper::AddDataTypesSuite()
{
    auto dataTypeSuite = GenerateSuite("��������");

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
    auto resourcesSuite = GenerateSuite("��Դ");

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

// private
void Rendering::TestingHelper::AddSceneGraphSuite()
{
    auto sceneGraphSuite = GenerateSuite("����ͼ");

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

    AddSuite(sceneGraphSuite);
}

// private
void Rendering::TestingHelper::AddControllersSuite()
{
    auto controllersSuite = GenerateSuite("������");

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
    auto shaderFloatsSuite = GenerateSuite("������ɫ��");

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
    auto detailSuite = GenerateSuite("ϸ��");

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
    auto shadersSuite = GenerateSuite("��ɫ��");

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
    auto localEffectsSuite = GenerateSuite("�ֲ���Ч");

    AddSuite(localEffectsSuite);
}

void Rendering::TestingHelper::AddGlobalEffectsSuite()
{
    auto globalEffectsSuite = GenerateSuite("ȫ����Ч");

    AddSuite(globalEffectsSuite);
}

void Rendering::TestingHelper::AddCurvesSurfacesSuite()
{
    auto curvesSurfacesSuite = GenerateSuite("��������");

    ADD_TEST(curvesSurfacesSuite, FloatArrayTesting);
    ADD_TEST(curvesSurfacesSuite, Float2ArrayTesting);
    ADD_TEST(curvesSurfacesSuite, SurfacePatchFrameTesting);
    ADD_TEST(curvesSurfacesSuite, PrincipalCurvatureInfoTesting);
    ADD_TEST(curvesSurfacesSuite, SurfacePatchTesting);

    AddSuite(curvesSurfacesSuite);
}

void Rendering::TestingHelper::AddIlluminationSuite()
{
    auto illuminationSuite = GenerateSuite("����");

    AddSuite(illuminationSuite);
}

void Rendering::TestingHelper::AddImageProcessingSuite()
{
    auto imageProcessingSuite = GenerateSuite("ͼ����");

    AddSuite(imageProcessingSuite);
}

void Rendering::TestingHelper::AddPictureSuite()
{
    auto pictureSuite = GenerateSuite("ͼ��");

    AddSuite(pictureSuite);
}

void Rendering::TestingHelper::AddSortingSuite()
{
    auto sortingSuite = GenerateSuite("����");

    AddSuite(sortingSuite);
}

void Rendering::TestingHelper::AddTerrainSuite()
{
    auto terrainSuite = GenerateSuite("���δ���");

    AddSuite(terrainSuite);
}

void Rendering::TestingHelper::AddVertexSuite()
{
    auto vertexSuite = GenerateSuite("����");

    AddSuite(vertexSuite);
}

void Rendering::TestingHelper::AddTextFontsSuite()
{
    auto textFontsSuite = GenerateSuite("�ı�������");

    AddSuite(textFontsSuite);
}

void Rendering::TestingHelper::AddConsoleGraphSuite()
{
    auto consoleGraphSuite = GenerateSuite("����̨ͼ��");

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

void Rendering::TestingHelper::AddRenderersSuite()
{
    auto renderersSuite = GenerateSuite("��Ⱦ��");

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

    AddSuite(renderersSuite);
}

void Rendering::TestingHelper::AddOpenGLRendererSuite()
{
    auto openGLRendererSuite = GenerateSuite("OpenGL��Ⱦ��");

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
    auto dx9RendererSuite = GenerateSuite("Dx9��Ⱦ��");

    AddSuite(dx9RendererSuite);
}

void Rendering::TestingHelper::AddAglRendererSuite()
{
    auto aglRendererSuite = GenerateSuite("Agl��Ⱦ��");

    AddSuite(aglRendererSuite);
}

void Rendering::TestingHelper::AddGlutRendererSuite()
{
    auto glutRendererSuite = GenerateSuite("Glut��Ⱦ��");

    AddSuite(glutRendererSuite);
}

void Rendering::TestingHelper::AddGlxRendererSuite()
{
    auto glxRendererSuite = GenerateSuite("Glx��Ⱦ��");

    AddSuite(glxRendererSuite);
}

void Rendering::TestingHelper::AddWglRendererSuite()
{
    auto wglRendererSuite = GenerateSuite("Wgl��Ⱦ��");

    AddSuite(wglRendererSuite);
}

void Rendering::TestingHelper::AddLib3dsSuite()
{
    auto lib3dsSuite = GenerateSuite("Lib3ds");

    AddSuite(lib3dsSuite);
}

void Rendering::TestingHelper::AddAbuseSuite()
{
    auto abuseSuite = GenerateSuite("Abuse");

    AddSuite(abuseSuite);
}

void Rendering::TestingHelper::AddDemoglSuite()
{
    auto demoglSuite = GenerateSuite("Demogl");

    AddSuite(demoglSuite);
}

void Rendering::TestingHelper::AddDevILSuite()
{
    auto devILSuite = GenerateSuite("DevIL");

    AddSuite(devILSuite);
}

void Rendering::TestingHelper::AddFBXSuite()
{
    auto fBXSuite = GenerateSuite("FBX");

    AddSuite(fBXSuite);
}

void Rendering::TestingHelper::AddJPEGSuite()
{
    auto jPEGSuite = GenerateSuite("JPEG");

    AddSuite(jPEGSuite);
}

void Rendering::TestingHelper::AddTIFFSuite()
{
    auto tIFFSuite = GenerateSuite("TIFF");

    AddSuite(tIFFSuite);
}

void Rendering::TestingHelper::AddOpenvidiaSuite()
{
    auto openvidiaSuite = GenerateSuite("Openvidia");

    AddSuite(openvidiaSuite);
}

void Rendering::TestingHelper::AddNethackSuite()
{
    auto nethackSuite = GenerateSuite("Nethack");

    AddSuite(nethackSuite);
}

void Rendering::TestingHelper::AddWingSuite()
{
    auto wingSuite = GenerateSuite("Wing"); 

    AddSuite(wingSuite);
}

void Rendering::TestingHelper::AddWargamerSuite()
{
    auto wargamerSuite = GenerateSuite("Wargamer");  

    AddSuite(wargamerSuite);
}

void Rendering::TestingHelper::AddNvtoolkitSuite()
{
    auto nvtoolkitSuite = GenerateSuite("Nvtoolkit");   

    AddSuite(nvtoolkitSuite);
}
