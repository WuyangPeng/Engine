///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:46)

#include "Rendering/RenderingExport.h"

#include "ShaderConstantsDataImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <algorithm>

Rendering::ShaderConstantsDataImpl::ShaderConstantsDataImpl(int number)
    : singleShaderConstantsData{ number, SingleShaderConstantsData{ CoreTools::DisableNotThrow::Disable } }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ShaderConstantsDataImpl::ShaderConstantsDataImpl() noexcept
    : singleShaderConstantsData()
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ShaderConstantsDataImpl)

void Rendering::ShaderConstantsDataImpl::SetConstant(int index, const std::string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(singleShaderConstantsData.size()), "索引错误");

    singleShaderConstantsData.at(index).SetConstant(name, numRegistersUsed);
}

void Rendering::ShaderConstantsDataImpl::InsertData(const std::string& name, int numRegistersUsed)
{
    RENDERING_CLASS_IS_VALID_9;

    singleShaderConstantsData.emplace_back(name, numRegistersUsed);
}

int Rendering::ShaderConstantsDataImpl::GetNumConstants() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(singleShaderConstantsData.size());
}

std::string Rendering::ShaderConstantsDataImpl::GetConstantName(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(singleShaderConstantsData.size()), "索引错误");

    return singleShaderConstantsData.at(index).GetConstantName();
}

int Rendering::ShaderConstantsDataImpl::GetNumRegistersUsed(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(singleShaderConstantsData.size()), "索引错误");

    return singleShaderConstantsData.at(index).GetNumRegistersUsed();
}

void Rendering::ShaderConstantsDataImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    int32_t number{ 0 };
    source.Read(number);
    singleShaderConstantsData.resize(number, SingleShaderConstantsData{ CoreTools::DisableNotThrow::Disable });

    for_each(singleShaderConstantsData.begin(), singleShaderConstantsData.end(), std::bind(&SingleShaderConstantsData::Load, std::placeholders::_1, std::ref(source)));
}

void Rendering::ShaderConstantsDataImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto size = boost::numeric_cast<int32_t>(singleShaderConstantsData.size());
    target.Write(size);

    for_each(singleShaderConstantsData.begin(), singleShaderConstantsData.end(), std::bind(&SingleShaderConstantsData::Save, std::placeholders::_1, std::ref(target)));
}

int Rendering::ShaderConstantsDataImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(int32_t());
    for (const auto& data : singleShaderConstantsData)
    {
        size += data.GetStreamingSize();
    }

    return size;
}

void Rendering::ShaderConstantsDataImpl::Resize(int number)
{
    RENDERING_CLASS_IS_VALID_9;

    singleShaderConstantsData.resize(number, SingleShaderConstantsData{ CoreTools::DisableNotThrow::Disable });
}
