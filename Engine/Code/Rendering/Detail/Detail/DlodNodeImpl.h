///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/10 16:26)

#ifndef RENDERING_DETAIL_DLOD_NODE_IMPL_H
#define RENDERING_DETAIL_DLOD_NODE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/DataTypes/DataTypesFwd.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE DlodNodeImpl
    {
        using ClassType = DlodNodeImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APointF;

    public:
        DlodNodeImpl() noexcept;
        explicit DlodNodeImpl(int numLevelsOfDetail);

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        // 访问中心(LOD)细节等级。
        NODISCARD APoint GetModelCenter() const noexcept;
        NODISCARD APoint GetWorldCenter() const noexcept;

        void SetModelCenter(const APoint& modelCenter) noexcept;
        void SetWorldCenter(const TransformF& transform) noexcept;

        // 获得子节点的距离间隔。
        NODISCARD int GetNumLevelsOfDetail() const noexcept;
        NODISCARD float GetModelMinDistance(int index) const;
        NODISCARD float GetModelMaxDistance(int index) const;
        NODISCARD float GetWorldMinDistance(int index) const;
        NODISCARD float GetWorldMaxDistance(int index) const;
        void SetModelDistance(int index, float minDistance, float maxDistance);
        void SetWorldDistance(float uniformScale) noexcept;

    private:
        // 该点的距离，相机决定正确的激活子节点。
        APoint modelLodCenter;
        APoint worldLodCenter;

        // 对于每个LOD区间的平方距离。

        // 子节点的数量
        int numLevelsOfDetail;
        std::vector<float> modelMinDistance;
        std::vector<float> modelMaxDistance;
        std::vector<float> worldMinDistance;
        std::vector<float> worldMaxDistance;
    };
}

#endif  // RENDERING_DETAIL_DLOD_NODE_IMPL_H
