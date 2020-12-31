//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/08 22:33)

#ifndef RENDERING_DATA_TYPES_SPECIALIZED_IO_H
#define RENDERING_DATA_TYPES_SPECIALIZED_IO_H

#include "Rendering/RenderingDll.h"

#include "BoundDetail.h"
#include "ColourDetail.h"
#include "TransformDetail.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <>
struct CoreTools::StreamSize<Rendering::FloatTransform>
{
    static int GetStreamSize(const Rendering::FloatTransform& value) noexcept
    {
        return value.GetStreamingSize();
    }
};

template <>
struct CoreTools::StreamSize<Rendering::FloatBound>
{
    static int GetStreamSize(const Rendering::FloatBound& value) noexcept
    {
        return value.GetStreamingSize();
    }
};

template <typename T>
struct CoreTools::StreamSize<Rendering::Colour<T>>
{
    constexpr static int GetStreamSize([[maybe_unused]] const Rendering::Colour<T>& value) noexcept
    {
        return Rendering::Colour<T>::sm_ArraySize * CoreTools::GetStreamSize<T>();
    }
};

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::FloatTransform& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatTransform& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleTransform& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleTransform& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::FloatBound& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatBound& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleBound& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleBound& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::FloatColour& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::FloatColour& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::DoubleColour& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::DoubleColour& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::ByteColour& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::ByteColour& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::IntColour& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::IntColour& datum);

namespace Rendering
{
    template <typename T>
    int GetStreamSize(T value) noexcept(noexcept(CoreTools::StreamSize<T>::GetStreamSize(value)))
    {
        return CoreTools::StreamSize<T>::GetStreamSize(value);
    }
}

// RENDERING_STREAM_SIZE宏被流系统使用。
#define RENDERING_STREAM_SIZE(value) Rendering::GetStreamSize(value)

#endif  // RENDERING_DATA_TYPES_SPECIALIZED_IO_H
