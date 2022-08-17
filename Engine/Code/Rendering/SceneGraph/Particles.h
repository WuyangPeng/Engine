///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/02 16:05)

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
        // VertexFormat对象必须包含3元组位置。
        // 也必须有2元组的纹理坐标在通道零，
        // 这些都是设置为标准(每个四边形为单位正方形)。
        // vertexbuffer元素的数量必须是4的倍数。
        // 元素的粒子数量的是1/4 vertexbuffer元素的个数。
        // 索引缓冲区是自动生成的。
        // 'positionSizes'包含位置在开始的三元组和大小在第四元组。
        Particles(const VertexFormatSharedPtr& vertexformat,
                  const VertexBufferSharedPtr& vertexbuffer,
                  int indexSize,
                  const std::vector<APoint>& positions,
                  const std::vector<float>& sizes,
                  float sizeAdjust);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Particles);

        NODISCARD int GetNumParticles() const;
        NODISCARD APoint GetParticlesPosition(int index) const;
        NODISCARD float GetSize(int index) const;
        NODISCARD void SetSizeAdjust(float sizeAdjust);
        NODISCARD float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const APoint& position);
        void SetSize(int index, float size);

        // 允许应用程序指定小于最大数量的顶点绘制。
        void SetNumActive(int numActive);
        NODISCARD int GetNumActive() const noexcept;

        // 粒子是广告牌，总是面对镜头。
        void GenerateParticles(const Camera& camera);

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;

        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        void InitIndexBuffer(int indexSize);
        void InitTextureCoord() noexcept;

        void InitIndexBufferInParticles(IndexBuffer& indexBuffer);

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(Particles);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Particles);
}

#endif  // RENDERING_SCENE_GRAPH_PARTICLES_H
