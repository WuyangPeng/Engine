///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 19:49)

#include "Rendering/RenderingExport.h"

#include "DepthStencilState.h"
#include "Flags/DepthStencilStateComparison.h"
#include "Flags/DepthStencilStateWriteMask.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/DataTypes/SpecializedIO.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, DepthStencilState);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, DepthStencilState);
CORE_TOOLS_FACTORY_DEFINE(Rendering, DepthStencilState);

Rendering::DepthStencilState::DepthStencilState(const std::string& name)
    : ParentType{ name, GraphicsObjectType::DepthStencilState },
      depthEnable{ true },
      writeMask{ DepthStencilStateWriteMask::All },
      comparison{ DepthStencilStateComparison::LessEqual },
      stencilEnable{ false },
      stencilReadMask{ 0xFF },
      stencilWriteMask{ 0xFF },
      frontFace{},
      backFace{},
      reference{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, DepthStencilState)

Rendering::DepthStencilState::DepthStencilState(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor },
      depthEnable{ true },
      writeMask{ DepthStencilStateWriteMask::All },
      comparison{ DepthStencilStateComparison::LessEqual },
      stencilEnable{ false },
      stencilReadMask{ 0xFF },
      stencilWriteMask{ 0xFF },
      frontFace{},
      backFace{},
      reference{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::DepthStencilState::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(depthEnable);
    size += CORE_TOOLS_STREAM_SIZE(writeMask);
    size += CORE_TOOLS_STREAM_SIZE(comparison);
    size += CORE_TOOLS_STREAM_SIZE(stencilEnable);
    size += CORE_TOOLS_STREAM_SIZE(stencilReadMask);
    size += CORE_TOOLS_STREAM_SIZE(stencilWriteMask);
    size += RENDERING_STREAM_SIZE(frontFace);
    size += RENDERING_STREAM_SIZE(backFace);
    size += CORE_TOOLS_STREAM_SIZE(reference);

    return size;
}

int64_t Rendering::DepthStencilState::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::DepthStencilState::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(depthEnable);
    target.WriteEnum(writeMask);
    target.WriteEnum(comparison);
    target.Write(stencilEnable);
    target.Write(stencilReadMask);
    target.Write(stencilWriteMask);

    target.WriteAggregate(frontFace);
    target.WriteAggregate(backFace);

    target.Write(reference);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::DepthStencilState::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::DepthStencilState::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::DepthStencilState::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    depthEnable = source.ReadBool();
    source.ReadEnum(writeMask);
    source.ReadEnum(comparison);
    stencilEnable = source.ReadBool();
    source.Read(stencilReadMask);
    source.Read(stencilWriteMask);

    source.ReadAggregate(frontFace);
    source.ReadAggregate(backFace);

    source.Read(reference);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::DepthStencilState::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}