//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/08 23:11)

#include "Rendering/RenderingExport.h"

#include "SpecializedIO.h"
#include "TransformDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

#include <array>

using std::array;

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatTransform& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleTransform& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatTransform& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleTransform& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatBound& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleBound& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatBound& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleBound& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto colour = ReadContainer<Rendering::FloatColour::ValueType, Rendering::FloatColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto colour = ReadContainer<Rendering::DoubleColour::ValueType, Rendering::DoubleColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::ByteColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto colour = ReadContainer<Rendering::ByteColour::ValueType, Rendering::ByteColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::ByteColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::IntColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    auto colour = ReadContainer<Rendering::IntColour::ValueType, Rendering::IntColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // 通过使用静态断言，固定大小数组使用常量索引是被允许的。
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::IntColour& datum)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}