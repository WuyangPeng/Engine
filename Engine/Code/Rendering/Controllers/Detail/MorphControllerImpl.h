// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 10:14)

#ifndef RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"

#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MorphControllerImpl
    {
    public:
        using ClassType = MorphControllerImpl;
        using AVector = Mathematics::FloatAVector;
        using APoint = Mathematics::FloatAPoint;

    public:
        // 顶点的数目，变形的目标，被固定对象的生存期的键。
        // 构造函数做一些创建控制器的工作。
        // 每个目标顶点，时间，和权重都必须由相应的成员访问分配。

        // numVertices: 每个目标的顶点的数量。所有的目标具有相同数量的顶点。

        // numTargets:  变形的目标数

        // numKeys:  键的数目，每个键发生在一个特定的时间。

        MorphControllerImpl(int numVertices, int numTargets, int numKeys);
        MorphControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 调用构造函数后，您必须使用这些函数设置顶点数组，时间和权重。
        int GetNumVertices() const noexcept;
        int GetNumTargets() const noexcept;
        int GetNumKeys() const noexcept;
        const APoint GetVertices(int target, int vertices) const;
        float GetTimes(int key) const;
        float GetWeights(int key, int target) const;

        void SetVertices(int target, int vertices, const APoint& point);
        void SetTimes(int key, float times);
        void SetWeights(int key, int target, float weights);

        // 查找边界上的键。
        const ControllerKeyInfo GetKeyInfo(float ctrlTime) noexcept;

        int GetStreamingSize() const;
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        void Load(const CoreTools::BufferSourceSharedPtr& source);

    private:
        // 目标几何体。每个目标的顶点的数量必须和被管理的几何对象的顶点数量相匹配。
        // 顶点数组在位置0是那些目标之一。
        // 基于关于“变形密钥”（下）的意见，
        // 在位置 i >= 1数组被计算为第i个目标和第0个之间的差异。
        int m_NumVertices;
        int m_NumTargets;
        std::vector<APoint> m_Vertices;  // [numTargets][numVertices]

        // 变形的键。该仿型对象的目的是通过权重w[0]到w[N-1]使目标的组合w[i]到[0,1]和w[i]的sum_i是1。
        // 每个组合是sum_{i=0}^{N-1} w[i] * X[i]，其中X[i]为第i个目标的一个顶点。
        // 这可以被改写为组合X[0] + sum_{i=0}^{N-2} w'[i] Y[i] ，其中w'[i] = w[i+1]，
        // 和Y[i] = X[i+1] - X[0]。
        // 存储在这个类的权重是w'[i] （减少存储）。
        // 这也有少量减少了计算时间（X[0]的系数为1，所以必须没有倍增发生）。
        int m_NumKeys;
        std::vector<float> m_Times;  // [numKeys]
        std::vector<float> m_Weights;  // [numKeys][numTargets-1]

        // O(1)边界查找键。
        int m_LastIndex;
    };
}

#endif  // RENDERING_CONTROLLERS_MORPH_CONTROLLER_IMPL_H
