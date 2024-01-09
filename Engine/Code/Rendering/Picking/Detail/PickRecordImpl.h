/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 09:59)

#ifndef RENDERING_PICKING_PICK_RECORD_IMPL_H
#define RENDERING_PICKING_PICK_RECORD_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Visual.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickRecordImpl
    {
    public:
        using ClassType = PickRecordImpl;

        static constexpr auto vertexIndexSize = 3;
        static constexpr int barycentricSize = 3;

        using APoint = Mathematics::APointF;
        using VertexIndexType = std::array<int, vertexIndexSize>;
        using BarycentricType = std::array<float, barycentricSize>;

    public:
        PickRecordImpl() noexcept;
        PickRecordImpl(VisualSharedPtr visual,
                       IndexFormatType primitiveType,
                       int primitiveIndex,
                       const VertexIndexType& vertexIndex,
                       float t,
                       const APoint& linePoint,
                       const BarycentricType& barycentric,
                       const APoint& primitivePoint,
                       float distanceToLinePoint,
                       float distanceToPrimitivePoint,
                       float distanceBetweenLinePrimitive) noexcept;

        ~PickRecordImpl() noexcept = default;
        PickRecordImpl(const PickRecordImpl& rhs);
        PickRecordImpl& operator=(const PickRecordImpl& rhs);
        PickRecordImpl(PickRecordImpl&& rhs) noexcept;
        PickRecordImpl& operator=(PickRecordImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetDistanceToLinePoint() const noexcept;

        NODISCARD float GetT() const noexcept;

    private:
    private:
        ConstVisualSharedPtr visual;

        IndexFormatType primitiveType;
        int primitiveIndex;
        VertexIndexType vertexIndex;

        float t;
        APoint linePoint;

        BarycentricType barycentric;
        APoint primitivePoint;

        float distanceToLinePoint;
        float distanceToPrimitivePoint;
        float distanceBetweenLinePrimitive;
    };
}

#endif  // RENDERING_PICKING_PICK_RECORD_IMPL_H
