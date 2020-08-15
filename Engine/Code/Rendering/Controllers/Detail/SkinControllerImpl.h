// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/23 10:15)

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
        // ����͹�������Ŀ�ڶ�����������ǹ̶��ġ�
        SkinControllerImpl(int numVertices, int numBones);
        SkinControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        int GetNumVertices() const noexcept;
        int GetNumBones() const noexcept;

        const ConstNodeSmartPointer GetBones(int bonesIndex) const;
        float GetWeights(int bonesIndex, int verticesIndex) const;
        const APoint GetOffsets(int bonesIndex, int verticesIndex) const;

        // ���ù��캯����������ʹ����Щ�����������ݡ�
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
        std::vector<float> m_Weights;  // weight[nb][nv], ���� v + nv * b
        std::vector<APoint> m_Offsets;  // offset[nb][nv], ���� v + nv * b
    };
}

#endif  // RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H
