// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/17 18:40)

#ifndef RENDERING_DATA_TYPES_SPECIALIZED_IO_H
#define RENDERING_DATA_TYPES_SPECIALIZED_IO_H

#include "Rendering/RenderingDll.h"

#include "Bound.h"
#include "ColourDetail.h"
#include "Transform.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

template <>
struct CoreTools::StreamSize<Rendering::Transform>
{
    static int GetStreamSize(const Rendering::Transform& value)
    {
        return value.GetStreamingSize();
    }
};

template <>
struct CoreTools::StreamSize<Rendering::Bound>
{
    static int GetStreamSize(const Rendering::Bound& value)
    {
        return value.GetStreamingSize();
    }
};

template <typename T>
struct CoreTools::StreamSize<Rendering::Colour<T>>
{
    static int GetStreamSize(const Rendering::Colour<T>& value) noexcept
    {
        SYSTEM_UNUSED_ARG(value);

        return sizeof(T) * 4;
    }
};

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource ::ReadAggregate(Rendering::Transform& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget ::WriteAggregate(const Rendering::Transform& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource ::ReadAggregate(Rendering::Bound& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget ::WriteAggregate(const Rendering::Bound& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource ::ReadAggregate(Rendering::Colour<float>& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget ::WriteAggregate(const Rendering::Colour<float>& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource ::ReadAggregate(Rendering::Colour<unsigned>& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget ::WriteAggregate(const Rendering::Colour<unsigned>& datum);

namespace Rendering
{
    template <typename T>
    int GetStreamSize(T value)
    {
        CoreTools::DoNothing();

        return CoreTools::StreamSize<T>::GetStreamSize(value);
    }
}

// RENDERING_STREAM_SIZE宏被流系统使用。
#define RENDERING_STREAM_SIZE(value) Rendering::GetStreamSize(value)

#endif  // RENDERING_DATA_TYPES_SPECIALIZED_IO_H
