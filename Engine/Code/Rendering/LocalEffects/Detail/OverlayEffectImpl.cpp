///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 14:29)

#include "Rendering/RenderingExport.h"

#include "OverlayEffectImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/ProgramFactory.h"
#include "Rendering/Shaders/ShaderDetail.h"
#include "Rendering/Shaders/VisualProgram.h"
#include "Rendering/State/SamplerState.h"

Rendering::OverlayEffectImpl::OverlayEffectImpl() noexcept
    : windowWidth{ 0.0f },
      windowHeight{ 0.0f },
      invTextureWidth{ 0.0f },
      invTextureHeight{ 0.0f },
      overlayRectangle{},
      textureRectangle{},
      vertexBuffer{},
      indexBuffer{},
      program{},
      effect{},
      shaderAPIType{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OverlayEffectImpl::OverlayEffectImpl(int windowWidth, int windowHeight)
    : windowWidth{ boost::numeric_cast<float>(windowWidth) },
      windowHeight{ boost::numeric_cast<float>(windowHeight) },
      invTextureWidth{ 0.0f },
      invTextureHeight{ 0.0f },
      overlayRectangle{},
      textureRectangle{},
      vertexBuffer{},
      indexBuffer{},
      program{},
      effect{},
      shaderAPIType{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OverlayEffectImpl::OverlayEffectImpl(ProgramFactory& factory,
                                                int windowWidth,
                                                int windowHeight,
                                                int textureWidth,
                                                int textureHeight,
                                                SamplerStateFilter filter,
                                                SamplerStateMode mode0,
                                                SamplerStateMode mode1,
                                                bool useColorPShader)
    : windowWidth{ boost::numeric_cast<float>(windowWidth) },
      windowHeight{ boost::numeric_cast<float>(windowHeight) },
      invTextureWidth{ 1.0f / boost::numeric_cast<float>(textureWidth) },
      invTextureHeight{ 1.0f / boost::numeric_cast<float>(textureHeight) },
      overlayRectangle{ 0, 0, windowWidth, windowHeight },
      textureRectangle{ 0, 0, textureWidth, textureHeight },
      vertexBuffer{ VertexBuffer::Create(GetVertexFormat(), 4) },
      indexBuffer{ IndexBuffer::Create(IndexFormatType::TriMesh, 2, sizeof(int32_t)) },
      program{ factory.CreateFromFiles("Resource/Shader/OverlayEffect.vs", useColorPShader ? "Resource/Shader/OverlayEffectColor.ps" : "Resource/Shader/OverlayEffectGray.ps", "") },
      effect{ std::make_shared<VisualEffect>(program) },
      shaderAPIType{ factory.GetAPI() }
{
    Initialize();

    SetNormalizedZ(0.0f);

    const auto sampler = std::make_shared<SamplerState>(filter, mode0, mode1);
    program->GetPixelShader()->Set("imageSampler", sampler);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OverlayEffectImpl::OverlayEffectImpl(ProgramFactory& factory, int windowWidth, int windowHeight, int textureWidth, int textureHeight, const std::string& pixelShaderFile)
    : windowWidth{ boost::numeric_cast<float>(windowWidth) },
      windowHeight{ boost::numeric_cast<float>(windowHeight) },
      invTextureWidth{ 1.0f / boost::numeric_cast<float>(textureWidth) },
      invTextureHeight{ 1.0f / boost::numeric_cast<float>(textureHeight) },
      overlayRectangle{ 0, 0, windowWidth, windowHeight },
      textureRectangle{ 0, 0, textureWidth, textureHeight },
      vertexBuffer{ VertexBuffer::Create(GetVertexFormat(), 4) },
      indexBuffer{ IndexBuffer::Create(IndexFormatType::TriMesh, 2, sizeof(int32_t)) },
      program{ factory.CreateFromFiles("Resource/Shader/OverlayEffect.vs", pixelShaderFile, "") },
      effect{ std::make_shared<VisualEffect>(program) },
      shaderAPIType{ factory.GetAPI() }
{
    Initialize();

    SetNormalizedZ(0.0f);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormat Rendering::OverlayEffectImpl::GetVertexFormat()
{
    const auto vertexFormat = VertexFormat::Create();
    vertexFormat->Bind(VertexFormatFlags::Semantic::Position, DataFormatType::R32G32Float, 0);
    vertexFormat->Bind(VertexFormatFlags::Semantic::TextureCoord, DataFormatType::R32G32Float, 0);

    return *vertexFormat;
}

void Rendering::OverlayEffectImpl::Initialize()
{
    vertexBuffer->SetUsage(UsageType::DynamicUpdate);
    UpdateVertexBuffer();

    auto indices = indexBuffer->GetData();
    indices.Increase<int32_t>(0);
    indices.Increase<int32_t>(2);
    indices.Increase<int32_t>(3);
    indices.Increase<int32_t>(0);
    indices.Increase<int32_t>(3);
    indices.Increase<int32_t>(1);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OverlayEffectImpl)

Rendering::OverlayEffectImpl::ConstVertexBufferSharedPtr Rendering::OverlayEffectImpl::GetVertexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexBuffer;
}

Rendering::OverlayEffectImpl::ConstIndexBufferSharedPtr Rendering::OverlayEffectImpl::GetIndexBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return indexBuffer;
}

Rendering::OverlayEffectImpl::ConstVisualProgramSharedPtr Rendering::OverlayEffectImpl::GetProgram() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return program;
}

Rendering::OverlayEffectImpl::ConstVisualEffectSharedPtr Rendering::OverlayEffectImpl::GetEffect() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return effect;
}

void Rendering::OverlayEffectImpl::SetOverlayRectangle(const RectangleType& rectangle)
{
    RENDERING_CLASS_IS_VALID_9;

    overlayRectangle = rectangle;

    UpdateVertexBuffer();
}

Rendering::OverlayEffectImpl::RectangleType Rendering::OverlayEffectImpl::GetOverlayRectangle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return overlayRectangle;
}

void Rendering::OverlayEffectImpl::SetTextureRectangle(const RectangleType& rectangle)
{
    RENDERING_CLASS_IS_VALID_9;

    textureRectangle = rectangle;

    UpdateVertexBuffer();
}

Rendering::OverlayEffectImpl::RectangleType Rendering::OverlayEffectImpl::GetTextureRectangle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureRectangle;
}

void Rendering::OverlayEffectImpl::SetRectangles(const RectangleType& aOverlayRectangle, const RectangleType& aTextureRectangle)
{
    RENDERING_CLASS_IS_VALID_9;

    overlayRectangle = aOverlayRectangle;
    textureRectangle = aTextureRectangle;

    UpdateVertexBuffer();
}

bool Rendering::OverlayEffectImpl::Contains(int x, int y) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return overlayRectangle.at(0) <= x && x < overlayRectangle.at(0) + overlayRectangle.at(2) && overlayRectangle.at(1) <= y && y < overlayRectangle.at(1) + overlayRectangle.at(3);
}

void Rendering::OverlayEffectImpl::SetTexture(const Texture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto pixelShader = effect->GetPixelShader();
    const auto sampler = pixelShader->Get<SamplerState>("imageSampler");
    pixelShader->Set("imageTexture", texture, "imageSampler", sampler);
}

void Rendering::OverlayEffectImpl::SetTexture(std::string const& textureName, const Texture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto pixelShader = effect->GetPixelShader();
    const auto sampler = pixelShader->Get<SamplerState>("imageSampler");
    pixelShader->Set(textureName, texture, "imageSampler", sampler);
}

void Rendering::OverlayEffectImpl::UpdateVertexBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto invWindowWidth = 1.0f / windowWidth;
    const auto invWindowHeight = 1.0f / windowHeight;
    const auto px = static_cast<float>(overlayRectangle.at(0)) * invWindowWidth;
    const auto py = static_cast<float>(overlayRectangle.at(1)) * invWindowHeight;
    const auto pw = static_cast<float>(overlayRectangle.at(2)) * invWindowWidth;
    const auto ph = static_cast<float>(overlayRectangle.at(3)) * invWindowHeight;

    const auto tx = static_cast<float>(textureRectangle.at(0)) * invTextureWidth;
    const auto ty = static_cast<float>(textureRectangle.at(1)) * invTextureHeight;
    const auto tw = static_cast<float>(textureRectangle.at(2)) * invTextureWidth;
    const auto th = static_cast<float>(textureRectangle.at(3)) * invTextureHeight;

    auto vertex = vertexBuffer->GetData();

    vertex.Increase<float>(px);
    vertex.Increase<float>(py);

    vertex.Increase<float>(tx);
    vertex.Increase<float>(ty);

    vertex.Increase<float>(px + pw);
    vertex.Increase<float>(py);

    vertex.Increase<float>(tx + tw);
    vertex.Increase<float>(ty);

    vertex.Increase<float>(px);
    vertex.Increase<float>(py + ph);

    vertex.Increase<float>(tx);
    vertex.Increase<float>(ty + th);

    vertex.Increase<float>(px + pw);
    vertex.Increase<float>(py + ph);

    vertex.Increase<float>(tx + tw);
    vertex.Increase<float>(ty + th);
}

void Rendering::OverlayEffectImpl::SetNormalizedZ(float z)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto constantBuffer = std::make_shared<ConstantBuffer>(CoreTools::GetStreamSize<float>(), true);

    auto data = constantBuffer->GetData();
    if (shaderAPIType == ShaderAPIType::GLSL)
    {
        data.Increase<float>(z);
    }
    else
    {
        data.Increase<float>(2.0f * z - 1.0f);
    }
    program->GetVertexShader()->Set("ZNDC", constantBuffer);
}