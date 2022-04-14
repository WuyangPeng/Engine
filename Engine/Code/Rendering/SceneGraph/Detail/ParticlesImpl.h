///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 16:06)

#ifndef RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H
#define RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/SceneGraph/SceneGraphFwd.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ParticlesImpl
    {
    public:
        using ClassType = ParticlesImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::APointF;

    public:
        // VertexFormat����������3Ԫ��λ�á�
        // Ҳ������2Ԫ�������������ͨ���㣬
        // ��Щ��������Ϊ��׼(ÿ���ı���Ϊ��λ������)��
        // vertexbufferԪ�ص�����������4�ı�����
        // Ԫ�ص�������������1/4 vertexbufferԪ�صĸ�����
        // �������������Զ����ɵġ�
        // 'positionSizes'����λ���ڿ�ʼ����Ԫ��ʹ�С�ڵ���Ԫ�顣
        ParticlesImpl(const std::vector<APoint>& positions, const std::vector<float>& sizes, float sizeAdjust);
        ParticlesImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumParticles() const;
        NODISCARD APoint GetParticlesPosition(int index) const;
        NODISCARD float GetSize(int index) const;
        void SetSizeAdjust(float aSizeAdjust);
        NODISCARD float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const APoint& position);
        void SetSize(int index, float size);

        NODISCARD float GetTrueSize(int index) const;

        // ����Ӧ�ó���ָ��С����������Ķ�����ơ�
        void SetNumActive(int aNumActive);
        NODISCARD int GetNumActive() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        std::vector<APoint> positions;
        std::vector<float> sizes;
        float sizeAdjust;
        int numActive;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H
