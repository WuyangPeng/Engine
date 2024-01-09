/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:48)

#ifndef RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H
#define RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Vector4.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ParticlesImpl
    {
    public:
        using ClassType = ParticlesImpl;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using Vector4 = Mathematics::Vector4F;
        using Container = std::vector<Vector4>;

    public:
        /// VertexFormat����������3Ԫ��λ�á�
        /// Ҳ������2Ԫ�������������ͨ���㣬
        /// ��Щ��������Ϊ��׼(ÿ���ı���Ϊ��λ������)��
        /// vertexBufferԪ�ص�����������4�ı�����
        /// Ԫ�ص�������������1/4 vertexBufferԪ�صĸ�����
        /// �������������Զ����ɵġ�
        /// 'positionSizes'����λ���ڿ�ʼ����Ԫ��ʹ�С�ڵ���Ԫ�顣
        ParticlesImpl(const Container& positionSize, float sizeAdjust);
        ParticlesImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumParticles() const;
        NODISCARD Vector4 GetParticlesPosition(int index) const;
        void SetSizeAdjust(float aSizeAdjust);
        NODISCARD float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const Vector4& position);

        // ����Ӧ�ó���ָ��С����������Ķ�����ơ�
        void SetNumActive(int aNumActive);
        NODISCARD int GetNumActive() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;

    private:
        Container positionSize;
        float sizeAdjust;
        int numActive;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PARTICLES_IMPL_H
