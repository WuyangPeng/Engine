///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 16:31)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H

#include "System/Helper/PragmaWarning/Operators.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickRecordImpl : private boost::totally_ordered<PickRecordImpl>
    {
    public:
        using ClassType = PickRecordImpl;

    public:
        // 它存在支持const static PickRecord在Picker构造。
        PickRecordImpl() noexcept;
        ~PickRecordImpl() noexcept = default;
        PickRecordImpl(const PickRecordImpl& rhs);
        PickRecordImpl& operator=(const PickRecordImpl& rhs);
        PickRecordImpl(PickRecordImpl&& rhs) noexcept;
        PickRecordImpl& operator=(PickRecordImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSpatialSharedPtr GetIntersected() const noexcept;
        NODISCARD float GetParameter() const noexcept;
        NODISCARD int GetTriangle() const noexcept;
        NODISCARD float GetBary(int index) const;

        void SetIntersected(const ConstSpatialSharedPtr& aIntersected) noexcept;
        void SetParameter(float aParameter) noexcept;
        void SetTriangle(int aTriangle) noexcept;
        void SetBary(float firstBary, float secondBary);

    private:
        // 分割的对象
        ConstSpatialSharedPtr intersected;

        // 线性组件是由P + t * D参数化。成员m_Parameter是参数t在交点的值。
        float parameter;

        // 射线相交的三角形的索引。
        int triangle;

        static const int barySize = 3;

        // 交点的重心坐标。所有的坐标是在[0,1]和b0 + b1 + b2 = 1。
        std::array<float, barySize> bary;
    };

    NODISCARD bool operator==(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
    NODISCARD bool operator<(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
