///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:45)

#include "Rendering/RenderingExport.h"

#include "../Resources/Flags/DataFormatType.h"
#include "ImageProcessingBase.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/Float.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

Rendering::ImageProcessingBase::ImageProcessingBase(int numCols, int numRows, int numTargets)
    : numCols{ numCols },
      numRows{ numRows },
      numColsM1{ numCols - 1 },
      numRowsM1{ numRows - 1 },
      numTargets{ numTargets },
      colSpacing{ 1.0f / numColsM1 },
      rowSpacing{ 1.0f / numRowsM1 },
      camera{ std::make_shared<Camera>(false, true) },
      rectangle{},
      pvwMatrixConstant{},
      renderTargets{},
      mainTexture{},
      mainEffect{},
      boundaryEffect{},
      drawEffect{},
      drawInput{}
{
    RENDERING_ASSERTION_0(numCols > 1 && numRows > 0, "无效bound.\n");
    RENDERING_ASSERTION_0(numTargets > 0, "目标数量无效。\n");

    camera->SetFrustum(0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    camera->SetFrame(Mathematics::APointF{}, Mathematics::AVectorF::GetUnitZ(), Mathematics::AVectorF::GetUnitY(), Mathematics::AVectorF::GetUnitX());

    std::vector<VertexFormatAttribute> triple{};

    triple.emplace_back(DataFormatType::R32G32B32Float, VertexFormatFlags::Semantic::Position, 0, 0);
    triple.emplace_back(DataFormatType::R32G32Float, VertexFormatFlags::Semantic::TextureCoord, 1, boost::numeric_cast<int>(3 * sizeof(float)));

    auto vformat = VertexFormat::Create(triple);

    vformat->SetAttribute(0, DataFormatType::R32G32B32Float, VertexFormatFlags::Semantic::Position, 0, 0);
    vformat->SetAttribute(1, DataFormatType::R32G32Float, VertexFormatFlags::Semantic::TextureCoord, 0, 3 * sizeof(float));
    vformat->SetStride(5 * sizeof(float));

    const auto vstride = vformat->GetStride();
    auto vbuffer = VertexBuffer::Create(*vformat, vstride);
    VertexBuffer vba = *vbuffer;

    const Mathematics::Float2 tc0{};
    const Mathematics::Float2 tc1{};
    const Mathematics::Float2 tc2{};
    const Mathematics::Float2 tc3{};

    auto ibuffer = IndexBuffer::Create(IndexFormatType::PolyPoint, 6, boost::numeric_cast<int>(sizeof(int)));

    auto indices = ibuffer->GetData();
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
        renderTargets.emplace_back(std::make_shared<DrawTarget>(1, System::EnumCastUnderlying<DataFormatType>(System::TextureInternalFormat::RGBA32F), numCols, numRows));
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ImageProcessingBase)

void Rendering::ImageProcessingBase::CreateEffect(MAYBE_UNUSED VisualEffectSharedPtr& effect) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::ImageProcessingBase::PreDraw() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::ImageProcessingBase::PostDraw() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::ImageProcessingBase::Initialize(BaseRenderer& renderer, bool openglHack) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
    renderer;
    openglHack;
    /*  renderer.Bind(renderTargets.at(0));
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
              mainEffectInstance->SetPixelTexture(0, "StateSampler", boost::dynamic_pointer_cast<Texture>(renderTargets.at(1)->GetRenderTargetTexture(0)->CloneObject()));
          }
          else
          {
              drawEffectInstance->SetPixelTexture(0, "StateSampler", boost::dynamic_pointer_cast<Texture>(renderTargets.at(1)->GetRenderTargetTexture(0)->CloneObject()));
          }

          rectangle->SetEffectInstance(boundaryEffectInstance);
          renderer.Enable(renderTargets.at(1));
          renderer.Draw(rectangle);
          renderer.Disable(renderTargets.at(1));

          renderer.PostDraw();
      }*/
}

void Rendering::ImageProcessingBase::ExecuteStep(BaseRenderer& renderer, bool draw) noexcept
{
    RENDERING_CLASS_IS_VALID_9;
    renderer;
    draw;
    /*  if (draw)
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
      renderer.Disable(renderTargets.at(1));*/
}

void Rendering::ImageProcessingBase::CreateVertexShader()
{
    RENDERING_CLASS_IS_VALID_9;

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

void Rendering::ImageProcessingBase::SetBoundaryEffect(const VisualEffectSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    boundaryEffect = val;
}

void Rendering::ImageProcessingBase::SetDrawEffect(const VisualEffectSharedPtr& val) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    drawEffect = val;
}

Rendering::TextureSharedPtr Rendering::ImageProcessingBase::GetColorTexture(int index)
{
    RENDERING_CLASS_IS_VALID_9;

    return boost::dynamic_pointer_cast<Texture>(renderTargets.at(index)->GetRenderTargetTexture(0)->CloneObject());
}

std::array<const int*, 5> Rendering::ImageProcessingBase::vRegisters{
    nullptr,
    &dx9VRegisters,
    &dx9VRegisters,
    &dx9VRegisters,
    &oglVRegisters
};

std::array<std::string, 5> Rendering::ImageProcessingBase::vPrograms{
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

Rendering::ConstDrawTargetSharedPtr Rendering::ImageProcessingBase::GetTarget(int i) const
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
