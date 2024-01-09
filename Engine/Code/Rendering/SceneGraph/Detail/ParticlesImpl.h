/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:48)

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
        /// VertexFormat对象必须包含3元组位置。
        /// 也必须有2元组的纹理坐标在通道零，
        /// 这些都是设置为标准(每个四边形为单位正方形)。
        /// vertexBuffer元素的数量必须是4的倍数。
        /// 元素的粒子数量的是1/4 vertexBuffer元素的个数。
        /// 索引缓冲区是自动生成的。
        /// 'positionSizes'包含位置在开始的三元组和大小在第四元组。
        ParticlesImpl(const Container& positionSize, float sizeAdjust);
        ParticlesImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumParticles() const;
        NODISCARD Vector4 GetParticlesPosition(int index) const;
        void SetSizeAdjust(float aSizeAdjust);
        NODISCARD float GetSizeAdjust() const noexcept;

        void SetPosition(int index, const Vector4& position);

        // 允许应用程序指定小于最大数量的顶点绘制。
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
