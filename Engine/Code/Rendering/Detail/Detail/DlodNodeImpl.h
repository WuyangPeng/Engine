///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/10 16:26)

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

        // ��������(LOD)ϸ�ڵȼ���
        NODISCARD APoint GetModelCenter() const noexcept;
        NODISCARD APoint GetWorldCenter() const noexcept;

        void SetModelCenter(const APoint& modelCenter) noexcept;
        void SetWorldCenter(const TransformF& transform) noexcept;

        // ����ӽڵ�ľ�������
        NODISCARD int GetNumLevelsOfDetail() const noexcept;
        NODISCARD float GetModelMinDistance(int index) const;
        NODISCARD float GetModelMaxDistance(int index) const;
        NODISCARD float GetWorldMinDistance(int index) const;
        NODISCARD float GetWorldMaxDistance(int index) const;
        void SetModelDistance(int index, float minDistance, float maxDistance);
        void SetWorldDistance(float uniformScale) noexcept;

    private:
        // �õ�ľ��룬���������ȷ�ļ����ӽڵ㡣
        APoint modelLodCenter;
        APoint worldLodCenter;

        // ����ÿ��LOD�����ƽ�����롣

        // �ӽڵ������
        int numLevelsOfDetail;
        std::vector<float> modelMinDistance;
        std::vector<float> modelMaxDistance;
        std::vector<float> worldMinDistance;
        std::vector<float> worldMaxDistance;
    };
}

#endif  // RENDERING_DETAIL_DLOD_NODE_IMPL_H
