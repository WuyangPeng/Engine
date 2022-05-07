///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/06 16:31)

#ifndef RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/SceneGraph/Node.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SkinControllerImpl
    {
    public:
        using ClassType = SkinControllerImpl;
        using APoint = Mathematics::APointF;

    public:
        // ����͹�������Ŀ�ڶ�����������ǹ̶��ġ�
        SkinControllerImpl(int numVertices, int numBones);
        SkinControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumBones() const noexcept;

        NODISCARD ConstNodeSharedPtr GetBones(int bonesIndex) const;
        NODISCARD float GetWeights(int bonesIndex, int verticesIndex) const;
        NODISCARD APoint GetOffsets(int bonesIndex, int verticesIndex) const;

        // ���ù��캯����������ʹ����Щ�����������ݡ�
        void SetBones(int bonesIndex, const ConstNodeSharedPtr& node);
        void SetWeights(int bonesIndex, int verticesIndex, float weight);
        void SetOffsets(int bonesIndex, int verticesIndex, const APoint& offset);

        void SetBones(const std::vector<CoreTools::ConstObjectAssociated<Node>>& aBones);
        void SetWeights(int bonesIndex, const std::vector<float>& weight);
        void SetOffsets(int bonesIndex, const std::vector<APoint>& offset);

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

    private:
        int numVertices;  // nv
        int numBones;  // nb
        int size;
        std::vector<CoreTools::ConstObjectAssociated<Node>> bones;  // bones[nb]
        std::vector<float> weights;  // weight[nb][nv], ���� v + nv * b
        std::vector<APoint> offsets;  // offset[nb][nv], ���� v + nv * b
    };
}

#endif  // RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H
