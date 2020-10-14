// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/19 19:22)

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
        // VertexFormat对象必须包含3元组位置。
        // 也必须有2元组的纹理坐标在通道零，
        // 这些都是设置为标准(每个四边形为单位正方形)。
        // vertexbuffer元素的数量必须是4的倍数。
        // 元素的粒子数量的是1/4 vertexbuffer元素的个数。
        // 索引缓冲区是自动生成的。
        // 'positionSizes'包含位置在开始的三元组和大小在第四元组。
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

        // 允许应用程序指定小于最大数量的顶点绘制。
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
