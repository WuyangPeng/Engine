/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:54)

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
        /// VertexFormat对象必须包含3元组位置。
        /// 也必须有2元组的纹理坐标在通道零，
        /// 这些都是设置为标准(每个四边形为单位正方形)。
        /// vertexBuffer元素的数量必须是4的倍数。
        /// 元素的粒子数量的是1/4 vertexBuffer元素的个数。
        /// 索引缓冲区是自动生成的。
        /// 'positionSizes'包含位置在开始的三元组和大小在第四元组。
        Particles(const Container& positionSize, float sizeAdjust, const VertexFormat& vertexFormat);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Particles);

        NODISCARD int GetNumParticles() const;
        NODISCARD Vector4 GetParticlesPosition(int index) const;
        void SetSizeAdjust(float sizeAdjust);
        NODISCARD float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const Vector4& position);

        // 允许应用程序指定小于最大数量的顶点绘制。
        void SetNumActive(int numActive);
        NODISCARD int GetNumActive() const noexcept;

        // 粒子是广告牌，总是面对镜头。
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
