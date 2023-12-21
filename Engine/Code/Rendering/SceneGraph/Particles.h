///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:10)

#ifndef RENDERING_SCENE_GRAPH_PARTICLES_H
#define RENDERING_SCENE_GRAPH_PARTICLES_H

#include "Rendering/RenderingDll.h"

#include "Camera.h"
#include "Culler.h"
#include "TrianglesMesh.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Particles, ParticlesImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Particles : public TrianglesMesh
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Particles);
        using ParentType = TrianglesMesh;
        using ParticlesSharedPtr = std::shared_ptr<ClassType>;
        using ConstParticlesSharedPtr = std::shared_ptr<ClassType>;

    public:
        // VertexFormat����������3Ԫ��λ�á�
        // Ҳ������2Ԫ�������������ͨ���㣬
        // ��Щ��������Ϊ��׼(ÿ���ı���Ϊ��λ������)��
        // vertexbufferԪ�ص�����������4�ı�����
        // Ԫ�ص�������������1/4 vertexbufferԪ�صĸ�����
        // �������������Զ����ɵġ�
        // 'positionSizes'����λ���ڿ�ʼ����Ԫ��ʹ�С�ڵ���Ԫ�顣
        Particles(const VertexFormatSharedPtr& vertexformat,
                  const VertexBufferSharedPtr& vertexbuffer,
                  int indexSize,
                  const std::vector<Mathematics::Vector4F>& positions,
                  const std::vector<float>& sizes,
                  float sizeAdjust);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Particles);

        NODISCARD int GetNumParticles() const;
        NODISCARD Mathematics::Vector4F GetParticlesPosition(int index) const;
        NODISCARD float GetSize(int index) const;
        NODISCARD void SetSizeAdjust(float sizeAdjust);
        NODISCARD float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const Mathematics::Vector4F& position);
        void SetSize(int index, float size);

        // ����Ӧ�ó���ָ��С����������Ķ�����ơ�
        void SetNumActive(int numActive);
        NODISCARD int GetNumActive() const noexcept;

        // �����ǹ���ƣ�������Ծ�ͷ��
        void GenerateParticles(const Camera& camera);

        NODISCARD ControllerSharedPtr Clone() const override;

        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

    private:
        void InitIndexBuffer(int indexSize);
        void InitTextureCoord() noexcept;

        void InitIndexBufferInParticles(IndexBuffer& indexBuffer);

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
