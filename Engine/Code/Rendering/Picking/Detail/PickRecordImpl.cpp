/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:07)

#include "Rendering/RenderingExport.h"

#include "PickRecordImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PickRecordImpl::PickRecordImpl() noexcept
    : visual{},

      primitiveType{ IndexFormatType::None },
      primitiveIndex{},
      vertexIndex{},

      t{ 0.0f },
      linePoint{ 0.0f, 0.0f, 0.0f },

      barycentric{ 0.0f, 0.0f, 1.0f },
      primitivePoint{ 0.0f, 0.0f, 0.0f },

      distanceToLinePoint{},
      distanceToPrimitivePoint{},
      distanceBetweenLinePrimitive{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecordImpl::PickRecordImpl(VisualSharedPtr visual, IndexFormatType primitiveType, int primitiveIndex, const VertexIndexType& vertexIndex, float t, const APoint& linePoint, const BarycentricType& barycentric, const APoint& primitivePoint, float distanceToLinePoint, float distanceToPrimitivePoint, float distanceBetweenLinePrimitive) noexcept
    : visual{ std::move(visual) },

      primitiveType{ primitiveType },
      primitiveIndex{ primitiveIndex },
      vertexIndex{ vertexIndex },

      t{ t },
      linePoint{ linePoint },

      barycentric{ barycentric },
      primitivePoint{ primitivePoint },

      distanceToLinePoint{ distanceToLinePoint },
      distanceToPrimitivePoint{ distanceToPrimitivePoint },
      distanceBetweenLinePrimitive{ distanceBetweenLinePrimitive }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecordImpl::PickRecordImpl(const PickRecordImpl& rhs)
    : visual{ rhs.visual != nullptr ? boost::polymorphic_pointer_cast<Visual>(rhs.visual->Clone()) : nullptr },

      primitiveType{ rhs.primitiveType },
      primitiveIndex{ rhs.primitiveIndex },
      vertexIndex{ rhs.vertexIndex },

      t{ rhs.t },
      linePoint{ rhs.linePoint },

      barycentric{ rhs.barycentric },
      primitivePoint{ rhs.primitivePoint },

      distanceToLinePoint{ rhs.distanceToLinePoint },
      distanceToPrimitivePoint{ rhs.distanceToPrimitivePoint },
      distanceBetweenLinePrimitive{ rhs.distanceBetweenLinePrimitive }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PickRecordImpl& Rendering::PickRecordImpl::operator=(const PickRecordImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    if (this == &rhs)
    {
        return *this;
    }

    if (!rhs.visual)
    {
        visual.reset();
    }
    else
    {
        visual = boost::polymorphic_pointer_cast<Visual>(rhs.visual->Clone());
    }

    primitiveType = rhs.primitiveType;
    primitiveIndex = rhs.primitiveIndex;
    vertexIndex = rhs.vertexIndex;

    t = rhs.t;
    linePoint = rhs.linePoint;

    barycentric = rhs.barycentric;
    primitivePoint = rhs.primitivePoint;

    distanceToLinePoint = rhs.distanceToLinePoint;
    distanceToPrimitivePoint = rhs.distanceToPrimitivePoint;
    distanceBetweenLinePrimitive = rhs.distanceBetweenLinePrimitive;

    return *this;
}

Rendering::PickRecordImpl& Rendering::PickRecordImpl::operator=(PickRecordImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (this == &rhs)
    {
        return *this;
    }

    visual = std::move(rhs.visual);

    primitiveType = rhs.primitiveType;
    primitiveIndex = rhs.primitiveIndex;
    vertexIndex = rhs.vertexIndex;

    t = rhs.t;
    linePoint = rhs.linePoint;

    barycentric = rhs.barycentric;
    primitivePoint = rhs.primitivePoint;

    distanceToLinePoint = rhs.distanceToLinePoint;
    distanceToPrimitivePoint = rhs.distanceToPrimitivePoint;
    distanceBetweenLinePrimitive = rhs.distanceBetweenLinePrimitive;

    return *this;
}

Rendering::PickRecordImpl::PickRecordImpl(PickRecordImpl&& rhs) noexcept
    : visual{ std::move(rhs.visual) },

      primitiveType{ rhs.primitiveType },
      primitiveIndex{ rhs.primitiveIndex },
      vertexIndex{ rhs.vertexIndex },

      t{ rhs.t },
      linePoint{ rhs.linePoint },

      barycentric{ rhs.barycentric },
      primitivePoint{ rhs.primitivePoint },

      distanceToLinePoint{ rhs.distanceToLinePoint },
      distanceToPrimitivePoint{ rhs.distanceToPrimitivePoint },
      distanceBetweenLinePrimitive{ rhs.distanceBetweenLinePrimitive }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::PickRecordImpl::IsValid() const noexcept
{
    try
    {
        if (-1 <= t &&
            0.0f <= barycentric.at(0) &&
            barycentric.at(0) <= 1.0f &&
            0.0f <= barycentric.at(1) &&
            barycentric.at(1) <= 1.0f &&
            0.0f <= barycentric.at(2) &&
            barycentric.at(2) <= 1.0f &&
            Mathematics::MathF::Approximate(1.0f, barycentric.at(0) + barycentric.at(1) + barycentric.at(2)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

float Rendering::PickRecordImpl::GetDistanceToLinePoint() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return distanceToLinePoint;
}

float Rendering::PickRecordImpl::GetT() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return t;
}
