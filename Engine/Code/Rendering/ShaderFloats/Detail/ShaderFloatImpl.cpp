///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 18:17)

#include "Rendering/RenderingExport.h"

#include "ShaderFloatImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"

Rendering::ShaderFloatImpl::ShaderFloatImpl() noexcept
    : data{}, allowUpdater{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloatImpl::ShaderFloatImpl(int numRegisters)
    : data{}, allowUpdater{ true }
{
    SetNumRegisters(numRegisters);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ShaderFloatImpl::ShaderFloatImpl(const FloatVector& data)
    : data{ data }, allowUpdater{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::ShaderFloatImpl::IsValid() const noexcept
{
    if (data.size() % floatingPointSize == 0)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::ShaderFloatImpl::GetNumRegisters() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(data.size() / floatingPointSize);
}

void Rendering::ShaderFloatImpl::SetNumRegisters(int numRegisters)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(0 < numRegisters, "寄存器的数量必须为正数。\n");

    const auto size = numRegisters * floatingPointSize;
    data.resize(size);
}

const float* Rendering::ShaderFloatImpl::GetData() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(!data.empty(), "寄存器的数量为零。\n");

    return data.data();
}

float* Rendering::ShaderFloatImpl::GetData()
{
    RENDERING_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(float*, GetData);
}

void Rendering::ShaderFloatImpl::SetRegister(int index, const FloatVector& aData)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");
    RENDERING_ASSERTION_0(aData.size() == 4, "传入的值大小错误！\n");

    for (auto targetIndex = 0; targetIndex < floatingPointSize; ++targetIndex)
    {
        const auto dataIndex = floatingPointSize * index + targetIndex;
        data.at(dataIndex) = aData.at(targetIndex);
    }
}

void Rendering::ShaderFloatImpl::SetRegister(int index, const AVector& vector)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

    for (auto targetIndex = 0; targetIndex < floatingPointSize - 1; ++targetIndex)
    {
        const auto dataIndex = floatingPointSize * index + targetIndex;
        data.at(dataIndex) = vector[targetIndex];
    }

    const auto dataIndex = floatingPointSize * index + floatingPointSize - 1;
    data.at(dataIndex) = 0.0f;
}

void Rendering::ShaderFloatImpl::SetRegister(int index, const APoint& point)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

    for (auto targetIndex = 0; targetIndex < floatingPointSize - 1; ++targetIndex)
    {
        const auto dataIndex = floatingPointSize * index + targetIndex;
        data.at(dataIndex) = point[targetIndex];
    }

    const auto dataIndex = floatingPointSize * index + floatingPointSize - 1;
    data.at(dataIndex) = 1.0f;
}

void Rendering::ShaderFloatImpl::SetRegister(int index, const Colour& colour)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

    data.at(floatingPointSize * boost::numeric_cast<size_t>(index)) = colour.GetRed();
    data.at(floatingPointSize * boost::numeric_cast<size_t>(index) + 1) = colour.GetGreen();
    data.at(floatingPointSize * boost::numeric_cast<size_t>(index) + 2) = colour.GetBlue();
    data.at(floatingPointSize * boost::numeric_cast<size_t>(index) + 3) = colour.GetAlpha();
}

void Rendering::ShaderFloatImpl::SetRegisters(const Matrix& matrix)
{
    RENDERING_CLASS_IS_VALID_1;

    RENDERING_ASSERTION_0(floatingPointSize == GetNumRegisters(), "无效寄存器！\n");

    for (auto outer = 0; outer < floatingPointSize; ++outer)
    {
        for (auto inner = 0; inner < floatingPointSize; ++inner)
        {
            const auto dataIndex = floatingPointSize * outer + inner;
            data.at(dataIndex) = matrix(outer, inner);
        }
    }
}

void Rendering::ShaderFloatImpl::SetRegisters(const FloatVector& aData)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_2(data.size() == aData.size(), "传入的值大小错误！\n");

    data = aData;
}

Rendering::ShaderFloatImpl::FloatVector Rendering::ShaderFloatImpl::GetRegister(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumRegisters(), "无效寄存器！\n");

    const auto beginIndex = floatingPointSize * index;
    const auto endIndex = floatingPointSize * index + floatingPointSize;
    FloatVector result{ data.begin() + beginIndex, data.begin() + endIndex };

    return result;
}

Rendering::ShaderFloatImpl::FloatVector Rendering::ShaderFloatImpl::GetRegisters() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return data;
}

const float& Rendering::ShaderFloatImpl::operator[](int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(data.size()), "无效索引！\n");

    return data.at(index);
}

float& Rendering::ShaderFloatImpl::operator[](int index)
{
    RENDERING_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(float, index);
}

void Rendering::ShaderFloatImpl::EnableUpdater() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    allowUpdater = true;
}

void Rendering::ShaderFloatImpl::DisableUpdater() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    allowUpdater = false;
}

bool Rendering::ShaderFloatImpl::AllowUpdater() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return allowUpdater;
}

void Rendering::ShaderFloatImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadContainer(data);
    allowUpdater = source.ReadBool();
}

void Rendering::ShaderFloatImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteContainerWithNumber(data);
    target.Write(allowUpdater);
}

int Rendering::ShaderFloatImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(data);
    size += CoreTools::GetStreamSize(allowUpdater);

    return size;
}
