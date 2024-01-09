/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:21)

#ifndef RENDERING_PICKING_PICK_RECORD_H
#define RENDERING_PICKING_PICK_RECORD_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "Rendering/SceneGraph/Visual.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(PickRecord, PickRecordImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickRecord  
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PickRecord);

        static constexpr auto vertexIndexSize = 3;
        static constexpr int barycentricSize = 3;

        using APoint = Mathematics::APointF;
        using VertexIndexType = std::array<int, vertexIndexSize>;
        using BarycentricType = std::array<float, barycentricSize>;

    public:
        NODISCARD static PickRecord Create();
        PickRecord(const VisualSharedPtr& visual,
                   IndexFormatType primitiveType,
                   int primitiveIndex,
                   const VertexIndexType& vertexIndex,
                   float t,
                   const APoint& linePoint,
                   const BarycentricType& barycentric,
                   const APoint& primitivePoint,
                   float distanceToLinePoint,
                   float distanceToPrimitivePoint,
                   float distanceBetweenLinePrimitive);

    private:
        explicit PickRecord(CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetDistanceToLinePoint() const noexcept;
        NODISCARD float GetT() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_PICKING_PICK_RECORD_H
