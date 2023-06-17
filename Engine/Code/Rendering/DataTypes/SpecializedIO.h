///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_SPECIALIZED_IO_H
#define RENDERING_DATA_TYPES_SPECIALIZED_IO_H

#include "Rendering/RenderingDll.h"

#include "BoundDetail.h"
#include "ColourDetail.h"
#include "TransformDetail.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Buffers/MemberLayout.h"
#include "Rendering/Shaders/ShaderData.h"
#include "Rendering/State/BlendStateTarget.h"
#include "Rendering/State/DepthStencilStateFace.h"

template <>
struct CoreTools::StreamSize<Rendering::TransformF>
{
    NODISCARD static int GetStreamSize(const Rendering::TransformF& value) noexcept
    {
        return value.GetStreamingSize();
    }
};

template <>
struct CoreTools::StreamSize<Rendering::BoundF>
{
    NODISCARD static int GetStreamSize(const Rendering::BoundF& value) noexcept
    {
        return value.GetStreamingSize();
    }
};

template <typename T>
struct CoreTools::StreamSize<Rendering::Colour<T>>
{
    NODISCARD constexpr static int GetStreamSize(MAYBE_UNUSED const Rendering::Colour<T>& value) noexcept
    {
        return Rendering::Colour<T>::arraySize * CoreTools::GetStreamSize<T>();
    }
};

template <>
struct CoreTools::StreamSize<Rendering::MemberLayout>
{
    NODISCARD static int GetStreamSize(const Rendering::MemberLayout& value)
    {
        return value.GetStreamingSize();
    }
};

template <>
struct CoreTools::StreamSize<Rendering::BlendStateTarget>
{
    NODISCARD static int GetStreamSize(const Rendering::BlendStateTarget& value) noexcept
    {
        return value.GetStreamingSize();
    }
};

template <>
struct CoreTools::StreamSize<Rendering::DepthStencilStateFace>
{
    NODISCARD static int GetStreamSize(const Rendering::DepthStencilStateFace& value) noexcept
    {
        return value.GetStreamingSize();
    }
};

template <>
struct CoreTools::StreamSize<Rendering::ShaderData>
{
    NODISCARD static int GetStreamSize(const Rendering::ShaderData& value)
    {
        return value.GetStreamingSize();
    }
};

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::TransformF& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::TransformF& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::TransformD& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::TransformD& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::BoundF& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::BoundF& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::BoundD& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::BoundD& datum);

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

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::MemberLayout& datum);

template <>
RENDERING_DEFAULT_DECLARE Rendering::MemberLayout CoreTools::BufferSource::ReadAggregate();

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::MemberLayout& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::BlendStateTarget& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::BlendStateTarget& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::DepthStencilStateFace& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::DepthStencilStateFace& datum);

template <>
Rendering::ShaderData CoreTools::BufferSource::ReadAggregate();

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferSource::ReadAggregate(Rendering::ShaderData& datum);

template <>
RENDERING_DEFAULT_DECLARE void CoreTools::BufferTarget::WriteAggregate(const Rendering::ShaderData& datum);

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
