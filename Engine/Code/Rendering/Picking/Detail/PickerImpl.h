/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:27)

#ifndef RENDERING_PICKING_PICKER_IMPL_H
#define RENDERING_PICKING_PICKER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Rendering/Picking/PickRecordContainer.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickerImpl
    {
    public:
        using ClassType = PickerImpl;

        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Line3 = Mathematics::Line3<float>;

    public:
        explicit PickerImpl(int numThreads);

        CLASS_INVARIANT_DECLARE;

        void SetMaxDistance(float aMaxDistance) noexcept;
        NODISCARD float GetMaxDistance() const noexcept;

        void operator()(Spatial& scene,
                        const APoint& aOrigin,
                        const AVector& aDirection,
                        float aTMin,
                        float aTMax);

        NODISCARD bool IsRecordsExist() const noexcept;

        /// 以下三个函数返回满足约束的记录。
        /// 他们应该在0 < records.GetSize()时调用。

        /// 定位记录中最小绝对值的T值。
        NODISCARD PickRecord GetClosestToZero() const;

        /// 定位记录最接近零的与非负值的T值。
        NODISCARD PickRecord GetClosestNonnegative() const;

        /// 定位记录最接近零的与非正值的T值。
        NODISCARD PickRecord GetClosestNonpositive() const;

    private:
        // 选择发生递归遍历的输入场景。
        void ExecuteRecursive(Spatial& object);

    private:
        int numThreads;

        float maxDistance;

        APoint origin;
        AVector direction;
        float tMin;
        float tMax;

        // 访问所有的记录在选择操作。
        PickRecordContainer records;
    };
}

#endif  // RENDERING_PICKING_PICKER_IMPL_H
