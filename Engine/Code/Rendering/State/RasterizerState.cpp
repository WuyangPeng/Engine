///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:27)

#include "Rendering/RenderingExport.h"

#include "RasterizerState.h"
#include "Flags/DepthStencilStateComparison.h"
#include "Flags/DepthStencilStateWriteMask.h"
#include "Flags/RasterizerStateCull.h"
#include "Flags/RasterizerStateFill.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/OpenGLRenderer/State/OpenGLRasterizerState.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RasterizerState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RasterizerState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RasterizerState);

Rendering::RasterizerState::RasterizerStateSharedPtr Rendering::RasterizerState::Create(const std::string& name)
{
    return std::make_shared<RasterizerState>(RasterizerStateCreate::Init, name);
}

Rendering::RasterizerState::RasterizerState(RasterizerStateCreate rasterizerStateCreate, const std::string& name)
    : ParentType{ name, GraphicsObjectType::RasterizerState },
      fill{ RasterizerStateFill::Solid },
      cull{ RasterizerStateCull::Back },
      frontCCW{ true },
      depthBias{ 0 },
      depthBiasClamp{ 0.0f },
      slopeScaledDepthBias{ 0.0f },
      enableDepthClip{ true },
      enableScissor{ false },
      enableMultisample{ false },
      enableAntialiasedLine{ false }
{
    System::UnusedFunction(rasterizerStateCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RasterizerState)

Rendering::RasterizerState::RasterizerState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor },
      fill{ RasterizerStateFill::Solid },
      cull{ RasterizerStateCull::Back },
      frontCCW{ true },
      depthBias{ 0 },
      depthBiasClamp{ 0.0f },
      slopeScaledDepthBias{ 0.0f },
      enableDepthClip{ true },
      enableScissor{ false },
      enableMultisample{ false },
      enableAntialiasedLine{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::RasterizerState::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += RENDERING_STREAM_SIZE(fill);
    size += RENDERING_STREAM_SIZE(cull);
    size += RENDERING_STREAM_SIZE(frontCCW);
    size += RENDERING_STREAM_SIZE(depthBias);
    size += RENDERING_STREAM_SIZE(depthBiasClamp);
    size += RENDERING_STREAM_SIZE(slopeScaledDepthBias);
    size += RENDERING_STREAM_SIZE(enableDepthClip);
    size += RENDERING_STREAM_SIZE(enableScissor);
    size += RENDERING_STREAM_SIZE(enableMultisample);
    size += RENDERING_STREAM_SIZE(enableAntialiasedLine);

    return size;
}

int64_t Rendering::RasterizerState::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::RasterizerState::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteEnum(fill);
    target.WriteEnum(cull);
    target.Write(frontCCW);
    target.Write(depthBias);
    target.Write(depthBiasClamp);
    target.Write(slopeScaledDepthBias);
    target.Write(enableDepthClip);
    target.Write(enableScissor);
    target.Write(enableMultisample);
    target.Write(enableAntialiasedLine);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::RasterizerState::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::RasterizerState::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::RasterizerState::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.ReadEnum(fill);
    source.ReadEnum(cull);
    source.Read(frontCCW);
    source.Read(depthBias);
    source.Read(depthBiasClamp);
    source.Read(slopeScaledDepthBias);
    source.Read(enableDepthClip);
    source.Read(enableScissor);
    source.Read(enableMultisample);
    source.Read(enableAntialiasedLine);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CheckDrawingState();
}

CoreTools::ObjectInterfaceSharedPtr Rendering::RasterizerState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::RasterizerStateFill Rendering::RasterizerState::GetFill() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fill;
}

void Rendering::RasterizerState::SetFill(RasterizerStateFill rasterizerStateFill) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    fill = rasterizerStateFill;
}

Rendering::RasterizerStateCull Rendering::RasterizerState::GetCull() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cull;
}

void Rendering::RasterizerState::SetCull(RasterizerStateCull rasterizerStateCull) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    cull = rasterizerStateCull;
}

bool Rendering::RasterizerState::IsFrontCCW() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontCCW;
}

void Rendering::RasterizerState::SetFrontCCW(bool aFrontCCW) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frontCCW = aFrontCCW;
}

int Rendering::RasterizerState::GetDepthBias() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthBias;
}

void Rendering::RasterizerState::SetDepthBias(int aDepthBias) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    depthBias = aDepthBias;
}

float Rendering::RasterizerState::GetDepthBiasClamp() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthBiasClamp;
}

void Rendering::RasterizerState::SetDepthBiasClamp(float aDepthBiasClamp) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    depthBiasClamp = aDepthBiasClamp;
}

float Rendering::RasterizerState::GetSlopeScaledDepthBias() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return slopeScaledDepthBias;
}

void Rendering::RasterizerState::SetSlopeScaledDepthBias(float aSlopeScaledDepthBias) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    slopeScaledDepthBias = aSlopeScaledDepthBias;
}

bool Rendering::RasterizerState::IsEnableDepthClip() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableDepthClip;
}

void Rendering::RasterizerState::SetEnableDepthClip(bool aEnableDepthClip) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableDepthClip = aEnableDepthClip;
}

bool Rendering::RasterizerState::IsEnableScissor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableScissor;
}

void Rendering::RasterizerState::SetEnableScissor(bool aEnableScissor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableScissor = aEnableScissor;
}

bool Rendering::RasterizerState::IsEnableMultisample() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableMultisample;
}

void Rendering::RasterizerState::SetEnableMultisample(bool aEnableMultisample) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableMultisample = aEnableMultisample;
}

bool Rendering::RasterizerState::IsEnableAntialiasedLine() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableAntialiasedLine;
}

void Rendering::RasterizerState::SetEnableAntialiasedLine(bool aEnableAntialiasedLine) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableAntialiasedLine = aEnableAntialiasedLine;
}

Rendering::RasterizerState::RendererObjectSharedPtr Rendering::RasterizerState::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLRasterizerState>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}

void Rendering::RasterizerState::CheckDrawingState()
{
    if (GetType() != GraphicsObjectType::RasterizerState)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject类型错误。"s));
    }
}
