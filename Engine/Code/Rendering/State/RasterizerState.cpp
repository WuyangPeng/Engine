/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:20)

#include "Rendering/RenderingExport.h"

#include "RasterizerState.h"
#include "Flags/DepthStencilStateComparison.h"
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
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RasterizerState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RasterizerState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RasterizerState);

Rendering::RasterizerState::RasterizerStateSharedPtr Rendering::RasterizerState::Create(const std::string& name)
{
    return std::make_shared<RasterizerState>(RasterizerStateCreate::Init, name);
}

Rendering::RasterizerState::RasterizerStateSharedPtr Rendering::RasterizerState::Create(const std::string& name, RasterizerStateFill rasterizerStateFill, RasterizerStateCull rasterizerStateCull)
{
    return std::make_shared<RasterizerState>(RasterizerStateCreate::Init, name, rasterizerStateFill, rasterizerStateCull);
}

Rendering::RasterizerState::RasterizerStateSharedPtr Rendering::RasterizerState::Create(const std::string& name, RasterizerStateCull rasterizerStateCull)
{
    return std::make_shared<RasterizerState>(RasterizerStateCreate::Init, name, rasterizerStateCull);
}

Rendering::RasterizerState::RasterizerState(RasterizerStateCreate rasterizerStateCreate, const std::string& name)
    : ParentType{ name, GraphicsObjectType::RasterizerState },
      fill{ RasterizerStateFill::Solid },
      cull{ RasterizerStateCull::Back },
      frontCcw{ true },
      depthBias{ 0 },
      depthBiasClamp{ 0.0f },
      slopeScaledDepthBias{ 0.0f },
      enableDepthClip{ true },
      enableScissor{ false },
      enableMultiSample{ false },
      enableAntiAliasedLine{ false }
{
    System::UnusedFunction(rasterizerStateCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::RasterizerState::RasterizerState(RasterizerStateCreate rasterizerStateCreate, const std::string& name, RasterizerStateFill rasterizerStateFill, RasterizerStateCull rasterizerStateCull)
    : ParentType{ name, GraphicsObjectType::RasterizerState },
      fill{ rasterizerStateFill },
      cull{ rasterizerStateCull },
      frontCcw{ true },
      depthBias{ 0 },
      depthBiasClamp{ 0.0f },
      slopeScaledDepthBias{ 0.0f },
      enableDepthClip{ true },
      enableScissor{ false },
      enableMultiSample{ false },
      enableAntiAliasedLine{ false }
{
    System::UnusedFunction(rasterizerStateCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::RasterizerState::RasterizerState(RasterizerStateCreate rasterizerStateCreate, const std::string& name, RasterizerStateCull rasterizerStateCull)
    : ParentType{ name, GraphicsObjectType::RasterizerState },
      fill{ RasterizerStateFill::Solid },
      cull{ rasterizerStateCull },
      frontCcw{ true },
      depthBias{ 0 },
      depthBiasClamp{ 0.0f },
      slopeScaledDepthBias{ 0.0f },
      enableDepthClip{ true },
      enableScissor{ false },
      enableMultiSample{ false },
      enableAntiAliasedLine{ false }
{
    System::UnusedFunction(rasterizerStateCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RasterizerState)

Rendering::RasterizerState::RasterizerState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor },
      fill{ RasterizerStateFill::Solid },
      cull{ RasterizerStateCull::Back },
      frontCcw{ true },
      depthBias{ 0 },
      depthBiasClamp{ 0.0f },
      slopeScaledDepthBias{ 0.0f },
      enableDepthClip{ true },
      enableScissor{ false },
      enableMultiSample{ false },
      enableAntiAliasedLine{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::RasterizerState::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += RENDERING_STREAM_SIZE(fill);
    size += RENDERING_STREAM_SIZE(cull);
    size += RENDERING_STREAM_SIZE(frontCcw);
    size += RENDERING_STREAM_SIZE(depthBias);
    size += RENDERING_STREAM_SIZE(depthBiasClamp);
    size += RENDERING_STREAM_SIZE(slopeScaledDepthBias);
    size += RENDERING_STREAM_SIZE(enableDepthClip);
    size += RENDERING_STREAM_SIZE(enableScissor);
    size += RENDERING_STREAM_SIZE(enableMultiSample);
    size += RENDERING_STREAM_SIZE(enableAntiAliasedLine);

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
    target.Write(frontCcw);
    target.Write(depthBias);
    target.Write(depthBiasClamp);
    target.Write(slopeScaledDepthBias);
    target.Write(enableDepthClip);
    target.Write(enableScissor);
    target.Write(enableMultiSample);
    target.Write(enableAntiAliasedLine);

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
    source.Read(frontCcw);
    source.Read(depthBias);
    source.Read(depthBiasClamp);
    source.Read(slopeScaledDepthBias);
    source.Read(enableDepthClip);
    source.Read(enableScissor);
    source.Read(enableMultiSample);
    source.Read(enableAntiAliasedLine);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CheckRasterizerState();
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

bool Rendering::RasterizerState::IsFrontCcw() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontCcw;
}

void Rendering::RasterizerState::SetFrontCcw(bool aFrontCcw) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    frontCcw = aFrontCcw;
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

bool Rendering::RasterizerState::IsEnableMultiSample() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableMultiSample;
}

void Rendering::RasterizerState::SetEnableMultiSample(bool aEnableMultiSample) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableMultiSample = aEnableMultiSample;
}

bool Rendering::RasterizerState::IsEnableAntiAliasedLine() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableAntiAliasedLine;
}

void Rendering::RasterizerState::SetEnableAntiAliasedLine(bool aEnableAntiAliasedLine) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableAntiAliasedLine = aEnableAntiAliasedLine;
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

void Rendering::RasterizerState::CheckRasterizerState()
{
    if (GetType() != GraphicsObjectType::RasterizerState)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GraphicsObject类型错误。"s));
    }
}
