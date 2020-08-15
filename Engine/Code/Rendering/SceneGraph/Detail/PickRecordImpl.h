// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 19:23)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H

#include "Rendering/SceneGraph/Spatial.h"

#include "System/Helper/PragmaWarning/Operators.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickRecordImpl : private boost::totally_ordered<PickRecordImpl>
    {
    public:
        using ClassType = PickRecordImpl;

    public:
        // 它存在支持const static PickRecord在Picker构造。
        PickRecordImpl() noexcept;
        PickRecordImpl(const PickRecordImpl& rhs);
        PickRecordImpl& operator=(const PickRecordImpl& rhs);
        PickRecordImpl(PickRecordImpl&& rhs) = default;
        PickRecordImpl& operator=(PickRecordImpl&& rhs) = default;
        ~PickRecordImpl() = default;

        CLASS_INVARIANT_DECLARE;

        ConstSpatialSmartPointer GetIntersected() const noexcept;
        float GetParameter() const noexcept;
        int GetTriangle() const noexcept;
        float GetBary(int index) const;

        void SetIntersected(const ConstSpatialSmartPointer& intersected) noexcept;
        void SetParameter(float parameter) noexcept;
        void SetTriangle(int triangle) noexcept;
        void SetBary(float firstBary, float secondBary);

    private:
        // 分割的对象
        ConstSpatialSmartPointer m_Intersected;

        // 线性组件是由P + t * D参数化。成员m_Parameter是参数t在交点的值。
        float m_Parameter;

        // 射线相交的三角形的索引。
        int m_Triangle;

        static const int sm_BarySize = 3;

        // 交点的重心坐标。所有的坐标是在[0,1]和b0 + b1 + b2 = 1。
        float m_Bary[sm_BarySize];
    };

    bool operator==(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
    bool operator<(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
