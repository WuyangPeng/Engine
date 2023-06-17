///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:48)

#include "Rendering/RenderingExport.h"

#include "SingleShaderBaseDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::SingleShaderBaseDataImpl::SingleShaderBaseDataImpl(const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
    : name{ name }, variableType{ type }, semantic{ semantic }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::SingleShaderBaseDataImpl::SingleShaderBaseDataImpl() noexcept
    : name{}, variableType{ ShaderFlags::VariableType::None }, semantic{ ShaderFlags::VariableSemantic::None }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderBaseDataImpl)

void Rendering::SingleShaderBaseDataImpl::SetData(const std::string& aName, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic aSemantic)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
    variableType = type;
    semantic = aSemantic;
}

std::string Rendering::SingleShaderBaseDataImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

Rendering::ShaderFlags::VariableType Rendering::SingleShaderBaseDataImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return variableType;
}

Rendering::ShaderFlags::VariableSemantic Rendering::SingleShaderBaseDataImpl::GetSemantic() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return semantic;
}

void Rendering::SingleShaderBaseDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    name = source.ReadString();
    source.ReadEnum(variableType);
    source.ReadEnum(semantic);
}

void Rendering::SingleShaderBaseDataImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(name);
    target.WriteEnum(variableType);
    target.WriteEnum(semantic);
}

int Rendering::SingleShaderBaseDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(name);
    size += CoreTools::GetStreamSize(variableType);
    size += CoreTools::GetStreamSize(semantic);

    return size;
}
