//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.1 (2020/09/08 23:11)

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
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatTransform& datum)
{
    ;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleTransform& datum)
{
    ;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatTransform& datum)
{
    ;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleTransform& datum)
{
    ;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatBound& datum)
{
    ;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleBound& datum)
{
    ;

    datum.ReadAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatBound& datum)
{
    ;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleBound& datum)
{
    ;

    datum.WriteAggregate(*this);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::FloatColour& datum)
{
    ;

    auto colour = ReadContainer<Rendering::FloatColour::ValueType, Rendering::FloatColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // ͨ��ʹ�þ�̬���ԣ��̶���С����ʹ�ó��������Ǳ�����ġ�
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatColour& datum)
{
    ;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleColour& datum)
{
    ;

    auto colour = ReadContainer<Rendering::DoubleColour::ValueType, Rendering::DoubleColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // ͨ��ʹ�þ�̬���ԣ��̶���С����ʹ�ó��������Ǳ�����ġ�
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleColour& datum)
{
    ;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::ByteColour& datum)
{
    ;

    auto colour = ReadContainer<Rendering::ByteColour::ValueType, Rendering::ByteColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // ͨ��ʹ�þ�̬���ԣ��̶���С����ʹ�ó��������Ǳ�����ġ�
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::ByteColour& datum)
{
    ;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}

template <>
void CoreTools::BufferSource::ReadAggregate(Rendering::IntColour& datum)
{
    ;

    auto colour = ReadContainer<Rendering::IntColour::ValueType, Rendering::IntColour::sm_ArraySize>();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)  // ͨ��ʹ�þ�̬���ԣ��̶���С����ʹ�ó��������Ǳ�����ġ�
    datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
#include STSTEM_WARNING_POP
}

template <>
void CoreTools::BufferTarget::WriteAggregate(const Rendering::IntColour& datum)
{
    ;

    const auto value = datum.GetPoint();
    WriteContainer(value);
}