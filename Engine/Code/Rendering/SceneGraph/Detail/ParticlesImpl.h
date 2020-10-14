// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/19 19:22)

#ifndef RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H
#define RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

namespace Rendering
{
    class Culler;

    class RENDERING_HIDDEN_DECLARE ParticlesImpl
    {
    public:
        using ClassType = ParticlesImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using APoint = Mathematics::FloatAPoint;

    public:
        // VertexFormat����������3Ԫ��λ�á�
        // Ҳ������2Ԫ�������������ͨ���㣬
        // ��Щ��������Ϊ��׼(ÿ���ı���Ϊ��λ������)��
        // vertexbufferԪ�ص�����������4�ı�����
        // Ԫ�ص�������������1/4 vertexbufferԪ�صĸ�����
        // �������������Զ����ɵġ�
        // 'positionSizes'����λ���ڿ�ʼ����Ԫ��ʹ�С�ڵ���Ԫ�顣
        ParticlesImpl(const std::vector<APoint>& positions, const std::vector<float>& sizes, float sizeAdjust);
        ParticlesImpl();

        CLASS_INVARIANT_DECLARE;

        int GetNumParticles() const;
        const APoint GetPosition(int index) const;
        float GetSize(int index) const;
        void SetSizeAdjust(float sizeAdjust);
        float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const APoint& position);
        void SetSize(int index, float size);

        float GetTrueSize(int index) const;

        // ����Ӧ�ó���ָ��С����������Ķ�����ơ�
        void SetNumActive(int numActive);
        int GetNumActive() const noexcept;

        void Load(const CoreTools::BufferSourceSharedPtr& source);
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        int GetStreamingSize() const;

    private:
        std::vector<APoint> m_Positions;
        std::vector<float> m_Sizes;
        float m_SizeAdjust;
        int m_NumActive;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H
