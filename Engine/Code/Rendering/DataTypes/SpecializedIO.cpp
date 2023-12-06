///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:56)

#include "Rendering/RenderingExport.h"

#include "SpecializedIO.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"

#include <array>

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    auto colour = ReadContainer<Rendering::FloatColour::ValueType, Rendering::FloatColour::arraySize>();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include SYSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    auto colour = ReadContainer<Rendering::DoubleColour::ValueType, Rendering::DoubleColour::arraySize>();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include SYSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::ByteColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    auto colour = ReadContainer<Rendering::ByteColour::ValueType, Rendering::ByteColour::arraySize>();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include SYSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::ByteColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::IntColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    auto colour = ReadContainer<Rendering::IntColour::ValueType, Rendering::IntColour::arraySize>();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include SYSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::IntColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::MemberLayout& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum = ReadAggregate<Rendering::MemberLayout>();
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::MemberLayout& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    Write(datum.GetName());
    Write<int32_t>(datum.GetOffset());
    Write<int32_t>(datum.GetNumElements());
}

template <>
Rendering::MemberLayout CoreTools::BufferSource::ReadAggregate()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::string name = ReadString();
    auto offset = Read<int32_t>();
    auto numElements = Read<int32_t>();

    return Rendering::MemberLayout{ name, offset, numElements };
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::BlendStateTarget& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.Load(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::BlendStateTarget& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.Save(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DepthStencilStateFace& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.Load(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DepthStencilStateFace& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.Save(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::ShaderData& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.Load(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::ShaderData& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.Save(*this);
}

template <>
Rendering::ShaderData CoreTools::BufferSource::ReadAggregate()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto inType = Rendering::GraphicsObjectType::None;
    ReadEnum(inType);

    const auto inName = ReadString();
    const auto inBindPoint = Read<int>();
    const auto inNumBytes = Read<int>();
    const auto inExtra = Read<int>();
    const auto inIsGpuWritable = ReadBool();

    return Rendering::ShaderData{ inType, inName, inBindPoint, inNumBytes, inExtra, inIsGpuWritable };
}