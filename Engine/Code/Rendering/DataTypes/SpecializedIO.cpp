///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 17:12)

#include "Rendering/RenderingExport.h"

#include "SpecializedIO.h"
#include "TransformDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"

#include <array>

using std::array;

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::TransformF& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::TransformD& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::TransformF& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::TransformD& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::BoundF& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::BoundD& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::BoundF& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::BoundD& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    auto colour = ReadContainer<Rendering::FloatColour::ValueType, Rendering::FloatColour::arraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include STSTEM_WARNING_POP
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include STSTEM_WARNING_POP
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include STSTEM_WARNING_POP
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。

    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);

#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::IntColour& datum)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}