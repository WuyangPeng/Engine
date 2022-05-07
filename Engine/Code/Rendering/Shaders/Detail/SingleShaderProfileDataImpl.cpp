///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 14:48)

#include "Rendering/RenderingExport.h"

#include "SingleShaderProfileDataImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;

Rendering::SingleShaderProfileDataImpl::SingleShaderProfileDataImpl(int numConstants, int numSamplers)
    : baseRegisters(numConstants), textureUnits(numSamplers), programs{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SingleShaderProfileDataImpl)

void Rendering::SingleShaderProfileDataImpl::SetBaseRegister(int index, int baseRegister)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(baseRegisters.size()), "索引错误");

    baseRegisters.at(index) = baseRegister;
}

void Rendering::SingleShaderProfileDataImpl::SetTextureUnit(int index, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(textureUnits.size()), "索引错误");

    textureUnits.at(index) = textureUnit;
}

void Rendering::SingleShaderProfileDataImpl::SetProgram(const string& program)
{
    RENDERING_CLASS_IS_VALID_9;

    programs = program;
}

int Rendering::SingleShaderProfileDataImpl::GetBaseRegister(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(baseRegisters.size()), "索引错误");

    return baseRegisters.at(index);
}

int Rendering::SingleShaderProfileDataImpl::GetTextureUnit(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(textureUnits.size()), "索引错误");

    return textureUnits.at(index);
}

std::string Rendering::SingleShaderProfileDataImpl::GetProgram() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return programs;
}

int Rendering::SingleShaderProfileDataImpl::GetBaseRegisterSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(baseRegisters.size());
}

int Rendering::SingleShaderProfileDataImpl::GetTextureUnitSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(textureUnits.size());
}

void Rendering::SingleShaderProfileDataImpl::ResetData(int numConstants, int numSamplers)
{
    RENDERING_CLASS_IS_VALID_9;

    baseRegisters.resize(numConstants);
    textureUnits.resize(numSamplers);
}

void Rendering::SingleShaderProfileDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    source.ReadContainer(baseRegisters);
    source.ReadContainer(textureUnits);
    programs = source.ReadString();
}

void Rendering::SingleShaderProfileDataImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteContainerWithNumber(baseRegisters);
    target.WriteContainerWithNumber(textureUnits);
    target.Write(programs);
}

int Rendering::SingleShaderProfileDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(baseRegisters);

    size += CORE_TOOLS_STREAM_SIZE(textureUnits);
    size += CORE_TOOLS_STREAM_SIZE(programs);

    return size;
}
