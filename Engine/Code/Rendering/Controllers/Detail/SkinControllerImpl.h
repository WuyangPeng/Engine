// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 10:15)

#ifndef RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Rendering/SceneGraph/Node.h"

#include <vector>

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
    class ObjectLink;
    class ObjectRegister;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SkinControllerImpl
    {
    public:
        using ClassType = SkinControllerImpl;
        using APoint = Mathematics::APointf;

    public:
        // 顶点和骨骼的数目在对象的生存期是固定的。
        SkinControllerImpl(int numVertices, int numBones);
        SkinControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        int GetNumVertices() const noexcept;
        int GetNumBones() const noexcept;

        const ConstNodeSmartPointer GetBones(int bonesIndex) const;
        float GetWeights(int bonesIndex, int verticesIndex) const;
        const APoint GetOffsets(int bonesIndex, int verticesIndex) const;

        // 调用构造函数后，您必须使用这些函数设置数据。
        void SetBones(int bonesIndex, const ConstNodeSmartPointer& node);
        void SetWeights(int bonesIndex, int verticesIndex, float weights);
        void SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets);

        void SetBones(const std::vector<ConstNodeSmartPointer>& bones);
        void SetWeights(int bonesIndex, const std::vector<float>& weights);
        void SetOffsets(int bonesIndex, const std::vector<APoint>& offsets);

        int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

    private:
        int m_NumVertices;  // nv
        int m_NumBones;  // nb
        int m_Size;
        std::vector<ConstNodeSmartPointer> m_Bones;  // bones[nb]
        std::vector<float> m_Weights;  // weight[nb][nv], 索引 v + nv * b
        std::vector<APoint> m_Offsets;  // offset[nb][nv], 索引 v + nv * b
    };
}

#endif  // RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H
