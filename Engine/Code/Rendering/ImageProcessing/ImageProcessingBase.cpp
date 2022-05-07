///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/18 16:51)

#include "Rendering/RenderingExport.h"

#include "ImageProcessingBase.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/Float.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "Rendering/Shaders/ShaderManager.h"

Rendering::ImageProcessingBase::ImageProcessingBase(int numCols, int numRows, int numTargets)
    : numCols{ numCols },
      numRows{ numRows },
      numColsM1{ numCols - 1 },
      numRowsM1{ numRows - 1 },
      numTargets{ numTargets },
      colSpacing{ 1.0f / numColsM1 },
      rowSpacing{ 1.0f / numRowsM1 },
      camera{ std::make_shared<Camera>(false) },
      rectangle{},
      vertexShader{},
      pvwMatrixConstant{},
      renderTargets{},
      mainTexture{},
      mainEffect{},
      mainEffectInstance{},
      boundaryEffect{},
      boundaryEffectInstance{},
      drawEffect{},
      drawEffectInstance{},
      drawInput{},
      drawInputInstance{}
{
    RENDERING_ASSERTION_0(numCols > 1 && numRows > 0, "无效bound.\n");
    RENDERING_ASSERTION_0(numTargets > 0, "目标数量无效。\n");

    camera->SetFrustum(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    camera->SetFrame(Mathematics::APointF{}, Mathematics::AVectorF::GetUnitZ(), Mathematics::AVectorF::GetUnitY(), Mathematics::AVectorF::GetUnitX());

    std::vector<VertexFormatType> triple{};

    triple.emplace_back(VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0);
    triple.emplace_back(VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 1);

    auto vformat = VertexFormat::Create(triple);

    vformat->SetAttribute(0, 0, 0, VertexFormatFlags::AttributeType::Float3, VertexFormatFlags::AttributeUsage::Position, 0);
    vformat->SetAttribute(1, 0, 3 * sizeof(float), VertexFormatFlags::AttributeType::Float2, VertexFormatFlags::AttributeUsage::TextureCoord, 0);
    vformat->SetStride(5 * sizeof(float));

    const auto vstride = vformat->GetStride();
    auto vbuffer = VertexBuffer::Create(4, vstride);
    VertexBufferAccessor vba{ vformat, vbuffer };

    auto xmin = 0.0f;
    auto xmax = 0.0f;
    auto ymin = 0.0f;
    auto ymax = 0.0f;
    Mathematics::Float2 tc0{};
    Mathematics::Float2 tc1{};
    Mathematics::Float2 tc2{};
    Mathematics::Float2 tc3{};
    if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
    {
        xmin = 0.0f;
        xmax = 1.0f;
        ymin = 0.0f;
        ymax = 1.0f;
        tc0 = Mathematics::Float2(0.0f, 0.0f);
        tc1 = Mathematics::Float2(1.0f, 0.0f);
        tc2 = Mathematics::Float2(1.0f, 1.0f);
        tc3 = Mathematics::Float2(0.0f, 1.0f);
    }
    else
    {
        xmin = -0.5f * colSpacing;
        xmax = 1.0f - 0.5f * colSpacing;
        ymin = +0.5f * rowSpacing;
        ymax = 1.0f + 0.5f * rowSpacing;
        tc0 = Mathematics::Float2(0.0f, 1.0f);
        tc1 = Mathematics::Float2(1.0f, 1.0f);
        tc2 = Mathematics::Float2(1.0f, 0.0f);
        tc3 = Mathematics::Float2(0.0f, 0.0f);
    }

    vbuffer->SetPosition(vba, 0, Mathematics::APoint(xmin, ymin, 0.0f));
    vbuffer->SetPosition(vba, 1, Mathematics::APoint(xmax, ymin, 0.0f));
    vbuffer->SetPosition(vba, 2, Mathematics::APoint(xmax, ymax, 0.0f));
    vbuffer->SetPosition(vba, 3, Mathematics::APoint(xmin, ymax, 0.0f));

    vbuffer->SetTextureCoord(vba, 0, Mathematics::Vector2F(tc0[0], tc0[1]), 0);
    vbuffer->SetTextureCoord(vba, 0, Mathematics::Vector2F(tc1[0], tc1[1]), 1);
    vbuffer->SetTextureCoord(vba, 0, Mathematics::Vector2F(tc2[0], tc2[1]), 2);
    vbuffer->SetTextureCoord(vba, 0, Mathematics::Vector2F(tc3[0], tc3[1]), 3);

    auto ibuffer = IndexBuffer::Create(6, boost::numeric_cast<int>(sizeof(int)));

    auto indices = ibuffer->GetWriteSpanIterator();
    indices.Increase<int32_t>(0);
    indices.Increase<int32_t>(1);
    indices.Increase<int32_t>(2);
    indices.Increase<int32_t>(0);
    indices.Increase<int32_t>(2);
    indices.Increase<int32_t>(3);

    rectangle = std::make_shared<TrianglesMesh>(vformat, vbuffer, ibuffer);

    CreateVertexShader();

    for (auto i = 0; i < numTargets; ++i)
    {
        renderTargets.emplace_back(std::make_shared<RenderTarget>(1, System::EnumCastUnderlying<TextureFormat>(System::TextureInternalFormat::A32B32G32R32F), numCols, numRows, false, false));
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ImageProcessingBase)

void Rendering::ImageProcessingBase::CreateEffect(const PixelShaderSharedPtr& pshader, VisualEffectSharedPtr& effect, VisualEffectInstanceSharedPtr& instance)
{
    RENDERING_CLASS_IS_VALID_9;

    auto pass = std::make_shared<VisualPass>(CoreTools::DisableNotThrow::Disable);
    pass->SetPixelShader(pshader);

    pass->SetVertexShader(vertexShader);

    pass->SetAlphaState(std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable));
    pass->SetOffsetState(std::make_shared<OffsetState>(CoreTools::DisableNotThrow::Disable));
    pass->SetStencilState(std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable));
    pass->SetWireState(std::make_shared<WireState>(CoreTools::DisableNotThrow::Disable));

    auto cstate = std::make_shared<CullState>(CoreTools::DisableNotThrow::Disable);
    cstate->SetEnabled(false);
    pass->SetCullState(cstate);

    auto dstate = std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable);
    dstate->SetEnabled(false);
    dstate->SetWritable(false);
    pass->SetDepthState(dstate);

    auto technique = std::make_shared<VisualTechnique>(CoreTools::DisableNotThrow::Disable);
    technique->InsertPass(pass);
    effect = std::make_shared<VisualEffect>(CoreTools::DisableNotThrow::Disable);
    effect->InsertTechnique(technique);

    instance = std::make_shared<VisualEffectInstance>(effect, 0);

    instance->SetVertexConstant(0, "PVWMatrix", pvwMatrixConstant);
}

void Rendering::ImageProcessingBase::PreDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
    {
        camera->SetPostProjectionMatrix(Mathematics::MatrixF{ 1.0f, -1.0f, 1.0f });
    }
}

void Rendering::ImageProcessingBase::PostDraw()
{
    RENDERING_CLASS_IS_VALID_9;

    if (SHADER_MANAGE_SINGLETON.GetVertexProfile() == ShaderFlags::VertexShaderProfile::ARBVP1)
    {
        camera->SetPostProjectionMatrix(Mathematics::MatrixF::GetIdentityMatrix());
    }
}

void Rendering::ImageProcessingBase::Initialize(Renderer& renderer, bool openglHack)
{
    RENDERING_CLASS_IS_VALID_9;

    renderer.Bind(renderTargets.at(0));
    renderer.Bind(renderTargets.at(1));
    renderer.Bind(GetMainTexture());
    if (renderer.PreDraw())
    {
        renderer.SetCamera(camera);

        if (openglHack)
        {
            mainEffectInstance->SetPixelTexture(0, "StateSampler", mainTexture);
            rectangle->SetEffectInstance(mainEffectInstance);
        }
        else
        {
            drawEffectInstance->SetPixelTexture(0, "StateSampler", mainTexture);
            rectangle->SetEffectInstance(drawEffectInstance);
        }

        renderer.Enable(renderTargets.at(0));
        renderer.ClearColorBuffer();
        renderer.Draw(rectangle);
        renderer.Disable(renderTargets.at(0));
        if (openglHack)
        {
            mainEffectInstance->SetPixelTexture(0, "StateSampler", boost::dynamic_pointer_cast<Texture>(renderTargets.at(1)->GetColorTexture(0)->CloneObject()));
        }
        else
        {
            drawEffectInstance->SetPixelTexture(0, "StateSampler", boost::dynamic_pointer_cast<Texture>(renderTargets.at(1)->GetColorTexture(0)->CloneObject()));
        }

        rectangle->SetEffectInstance(boundaryEffectInstance);
        renderer.Enable(renderTargets.at(1));
        renderer.Draw(rectangle);
        renderer.Disable(renderTargets.at(1));

        renderer.PostDraw();
    }
}

void Rendering::ImageProcessingBase::ExecuteStep(Renderer& renderer, bool draw)
{
    RENDERING_CLASS_IS_VALID_9;

    if (draw)
    {
        PreDraw();
        rectangle->SetEffectInstance(drawEffectInstance);
        renderer.Draw(rectangle);
        PostDraw();
    }

    rectangle->SetEffectInstance(mainEffectInstance);
    renderer.Enable(renderTargets.at(0));
    renderer.Draw(rectangle);
    renderer.Disable(renderTargets.at(0));

    rectangle->SetEffectInstance(boundaryEffectInstance);
    renderer.Enable(renderTargets.at(1));
    renderer.Draw(rectangle);
    renderer.Disable(renderTargets.at(1));
}

void Rendering::ImageProcessingBase::CreateVertexShader()
{
    RENDERING_CLASS_IS_VALID_9;

    vertexShader = std::make_shared<VertexShader>("Wm5.ScreenShader", 1, 2, 1, 0);
    vertexShader->SetInput(0, "modelPosition", ShaderFlags::VariableType::Float3, ShaderFlags::VariableSemantic::Position);
    vertexShader->SetOutput(0, "clipPosition", ShaderFlags::VariableType::Float4, ShaderFlags::VariableSemantic::Position);
    vertexShader->SetOutput(1, "vertexTCoord", ShaderFlags::VariableType::Float2, ShaderFlags::VariableSemantic::TextureCoord0);
    vertexShader->SetConstant(0, "PVWMatrix", 4);

    auto profile = vertexShader->GetProfile();

    for (auto i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (auto j = 0; j < 1; ++j)
        {
            profile->SetBaseRegister(i, j, *vRegisters.at(i));
        }

        profile->SetProgram(i, vPrograms.at(i));
    }

    pvwMatrixConstant = std::make_shared<ProjectionViewWorldMatrixConstant>(CoreTools::DisableNotThrow::Disable);
}

void Rendering::ImageProcessingBase::SetMainTexture(const Texture2DSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    mainTexture = val;
}

void Rendering::ImageProcessingBase::SetMainEffect(const VisualEffectSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    mainEffect = val;
}

void Rendering::ImageProcessingBase::SetMainEffectInstance(const VisualEffectInstanceSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    mainEffectInstance = val;
}

void Rendering::ImageProcessingBase::SetBoundaryEffect(const VisualEffectSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    boundaryEffect = val;
}

void Rendering::ImageProcessingBase::SetBoundaryEffectInstance(const VisualEffectInstanceSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    boundaryEffectInstance = val;
}

void Rendering::ImageProcessingBase::SetDrawEffect(const VisualEffectSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    drawEffect = val;
}

void Rendering::ImageProcessingBase::SetDrawEffectInstance(const VisualEffectInstanceSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    drawEffectInstance = val;
}

Rendering::TextureSharedPtr Rendering::ImageProcessingBase::GetColorTexture(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return boost::dynamic_pointer_cast<Texture>(renderTargets.at(index)->GetColorTexture(0)->CloneObject());
}

std::array<const int*, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessingBase::vRegisters{
    nullptr,
    &dx9VRegisters,
    &dx9VRegisters,
    &dx9VRegisters,
    &oglVRegisters
};

std::array<std::string, System::EnumCastUnderlying(Rendering::ShaderFlags::Profiles::MaxProfiles)> Rendering::ImageProcessingBase::vPrograms{
    // VP_NONE
    "",

    // VP_VS_1_1
    "",

    // VP_VS_2_0
    "vs_2_0\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 oPos.w, r0, c3\n"
    "dp4 oPos.z, r0, c2\n"
    "dp4 oPos.y, r0, c1\n"
    "dp4 oPos.x, r0, c0\n"
    "mov oT0.xy, v1\n",

    // VP_VS_3_0
    "vs_3_0\n"
    "dcl_position o0\n"
    "dcl_texcoord0 o1\n"
    "def c4, 1.00000000, 0, 0, 0\n"
    "dcl_position0 v0\n"
    "dcl_texcoord0 v1\n"
    "mov r0.w, c4.x\n"
    "mov r0.xyz, v0\n"
    "dp4 o0.w, r0, c3\n"
    "dp4 o0.z, r0, c2\n"
    "dp4 o0.y, r0, c1\n"
    "dp4 o0.x, r0, c0\n"
    "mov o1.xy, v1\n",

    // VP_ARBVP1
    "!!ARBvp1.0\n"
    "PARAM c[5] = { { 1 },\n"
    "		program.local[1..4] };\n"
    "TEMP R0;\n"
    "MOV R0.w, c[0].x;\n"
    "MOV R0.xyz, vertex.position;\n"
    "DP4 result.position.w, R0, c[4];\n"
    "DP4 result.position.z, R0, c[3];\n"
    "DP4 result.position.y, R0, c[2];\n"
    "DP4 result.position.x, R0, c[1];\n"
    "MOV result.texcoord[0].xy, vertex.texcoord[0];\n"
    "END\n"
};

int Rendering::ImageProcessingBase::GetNumCols() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numCols;
}

int Rendering::ImageProcessingBase::GetNumRows() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numRows;
}

int Rendering::ImageProcessingBase::GetNumTargets() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numTargets;
}

float Rendering::ImageProcessingBase::GetColSpacing() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return colSpacing;
}

float Rendering::ImageProcessingBase::GetRowSpacing() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rowSpacing;
}

Rendering::ConstCameraSharedPtr Rendering::ImageProcessingBase::GetCamera() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return camera;
}

Rendering::ConstTrianglesMeshSharedPtr Rendering::ImageProcessingBase::GetRectangle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rectangle;
}

Rendering::ConstRenderTargetSharedPtr Rendering::ImageProcessingBase::GetTarget(int i) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderTargets.at(i);
}

int Rendering::ImageProcessingBase::Index(int col, int row) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return col + numCols * row;
}

Rendering::ConstTexture2DSharedPtr Rendering::ImageProcessingBase::GetMainTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return mainTexture;
}

Rendering::ConstVisualEffectInstanceSharedPtr Rendering::ImageProcessingBase::GetMainEffectInstance() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return mainEffectInstance;
}
