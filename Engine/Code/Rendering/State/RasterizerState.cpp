///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 19:49)

#include "Rendering/RenderingExport.h"

#include "RasterizerState.h"
#include "Flags/DepthStencilStateComparison.h"
#include "Flags/DepthStencilStateWriteMask.h"
#include "Flags/RasterizerStateCull.h"
#include "Flags/RasterizerStateFill.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/DataTypes/SpecializedIO.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RasterizerState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RasterizerState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RasterizerState);

Rendering::RasterizerState::RasterizerState(const std::string& name)
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

    size += CORE_TOOLS_STREAM_SIZE(fill);
    size += CORE_TOOLS_STREAM_SIZE(cull);
    size += CORE_TOOLS_STREAM_SIZE(frontCCW);
    size += CORE_TOOLS_STREAM_SIZE(depthBias);
    size += CORE_TOOLS_STREAM_SIZE(depthBiasClamp);
    size += CORE_TOOLS_STREAM_SIZE(slopeScaledDepthBias);
    size += RENDERING_STREAM_SIZE(enableDepthClip);
    size += RENDERING_STREAM_SIZE(enableScissor);
    size += CORE_TOOLS_STREAM_SIZE(enableMultisample);
    size += CORE_TOOLS_STREAM_SIZE(enableAntialiasedLine);

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
}

CoreTools::ObjectInterfaceSharedPtr Rendering::RasterizerState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}