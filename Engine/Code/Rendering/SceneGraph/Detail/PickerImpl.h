///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 16:16)

#ifndef RENDERING_SCENE_GRAPH_PICKER_IMPL_H
#define RENDERING_SCENE_GRAPH_PICKER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/SceneGraph/PickRecordContainer.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickerImpl
    {
    public:
        using ClassType = PickerImpl;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;

    public:
        // 线性参数化的成分是P + t * D，
        // P是一个点的成分(P是原点),D是一个单位长度方向,
        // t是一个在区间[tmin,tmax]的标量，其中 tmin < tmax。
        // P和D值必须在世界坐标。tmin和tmax的选择如下
        // 直线:  tmin = -Mathf::maxReal, tmax = Mathf::maxReal
        // 射线:  tmin = 0, tmax = Mathematics::Mathf::maxReal
        // 线段:  tmin = 0, tmax > 0;
        PickerImpl(const Spatial& scene, const APoint& origin, const AVector& direction, float tMin, float tMax);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsRecordsExist() const noexcept;

        // 以下三个函数返回满足约束的记录。
        // 他们应该在0 < m_Records.GetSize()时调用。

        // 定位记录中最小绝对值的T值。
        NODISCARD PickRecord GetClosestToZero() const;

        // 定位记录最接近零的与非负值的T值。
        NODISCARD PickRecord GetClosestNonnegative() const;

        // 定位记录最接近零的与非正值的T值。
        NODISCARD PickRecord GetClosestNonpositive() const;

    private:
        // 选择发生递归遍历的输入场景。
        void ExecuteRecursive(const Spatial& object);

    private:
        APoint origin;
        AVector direction;
        float tMin;
        float tMax;

        // 访问所有的记录在选择操作。
        PickRecordContainer records;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PICKER_IMPL_H
