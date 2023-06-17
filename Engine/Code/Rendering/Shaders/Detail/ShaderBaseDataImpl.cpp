///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:45)

#include "Rendering/RenderingExport.h"

#include "ShaderBaseDataImpl.h"
#include "SingleShaderBaseDataImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <algorithm>

Rendering::ShaderBaseDataImpl::ShaderBaseDataImpl(int number)
    : singleShaderBaseData(number, SingleShaderBaseData{ CoreTools::DisableNotThrow::Disable })
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderBaseDataImpl::ShaderBaseDataImpl() noexcept
    : singleShaderBaseData()
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderBaseDataImpl)

void Rendering::ShaderBaseDataImpl::SetData(int index, const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(singleShaderBaseData.size()), "索引错误");

    singleShaderBaseData.at(index).SetData(name, type, semantic);
}

void Rendering::ShaderBaseDataImpl::InsertData(const std::string& name, ShaderFlags::VariableType type, ShaderFlags::VariableSemantic semantic)
{
    RENDERING_CLASS_IS_VALID_9;

    singleShaderBaseData.emplace_back(name, type, semantic);
}

int Rendering::ShaderBaseDataImpl::GetNumber() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(singleShaderBaseData.size());
}

std::string Rendering::ShaderBaseDataImpl::GetName(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(singleShaderBaseData.size()), "索引错误");

    return singleShaderBaseData.at(index).GetName();
}

Rendering::ShaderFlags::VariableType Rendering::ShaderBaseDataImpl::GetType(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(singleShaderBaseData.size()), "索引错误");

    return singleShaderBaseData.at(index).GetType();
}

Rendering::ShaderFlags::VariableSemantic Rendering::ShaderBaseDataImpl::GetSemantic(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(singleShaderBaseData.size()), "索引错误");

    return singleShaderBaseData.at(index).GetSemantic();
}

void Rendering::ShaderBaseDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    int32_t number{ 0 };
    source.Read(number);
    singleShaderBaseData.resize(number, SingleShaderBaseData{ CoreTools::DisableNotThrow::Disable });

    for_each(singleShaderBaseData.begin(), singleShaderBaseData.end(), std::bind(&SingleShaderBaseData::Load, std::placeholders::_1, std::ref(source)));
}

void Rendering::ShaderBaseDataImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto size = boost::numeric_cast<int32_t>(singleShaderBaseData.size());
    target.Write(size);

    for_each(singleShaderBaseData.begin(), singleShaderBaseData.end(), std::bind(&SingleShaderBaseData::Save, std::placeholders::_1, std::ref(target)));
}

int Rendering::ShaderBaseDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(int32_t{});
    for (const auto& data : singleShaderBaseData)
    {
        size += data.GetStreamingSize();
    }

    return size;
}

void Rendering::ShaderBaseDataImpl::Resize(int number)
{
    RENDERING_CLASS_IS_VALID_9;

    singleShaderBaseData.resize(number, SingleShaderBaseData{ CoreTools::DisableNotThrow::Disable });
}
