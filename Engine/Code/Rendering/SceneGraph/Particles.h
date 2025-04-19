/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:54)

#ifndef RENDERING_SCENE_GRAPH_PARTICLES_H
#define RENDERING_SCENE_GRAPH_PARTICLES_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Particles, ParticlesImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Particles : public Visual
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Particles);
        using ParentType = Visual;

        using ParticlesSharedPtr = std::shared_ptr<ClassType>;
        using ConstParticlesSharedPtr = std::shared_ptr<ClassType>;
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
        Particles(const Container& positionSize, float sizeAdjust, const VertexFormat& vertexFormat);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Particles);

        NODISCARD int GetNumParticles() const;
        NODISCARD Vector4 GetParticlesPosition(int index) const;
        void SetSizeAdjust(float sizeAdjust);
        NODISCARD float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const Vector4& position);

        // ����Ӧ�ó���ָ��С����������Ķ�����ơ�
        void SetNumActive(int numActive);
        NODISCARD int GetNumActive() const noexcept;

        // �����ǹ���ƣ�������Ծ�ͷ��
        void GenerateParticles(const Camera& camera);

        NODISCARD ControllerSharedPtr Clone() const override;

    private:
        using Vector2 = Mathematics::Vector2F;
        using Vector3 = Mathematics::Vector3F;

    protected:
        void Check(const VertexFormat& vertexFormat) const;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Particles);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Particles);
}

#endif  // RENDERING_SCENE_GRAPH_PARTICLES_H
