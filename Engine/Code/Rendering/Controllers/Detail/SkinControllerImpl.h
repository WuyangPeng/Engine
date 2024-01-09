///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 13:46)

#ifndef RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ConstWeakObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/BoundingSphere.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/SceneGraph/Node.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SkinControllerImpl
    {
    public:
        using ClassType = SkinControllerImpl;

        using APoint = Mathematics::APointF;
        using BaseRendererWeakPtr = std::weak_ptr<BaseRenderer>;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using ConstObjectAssociated = CoreTools::ConstObjectAssociated<Node>;
        using ConstObjectAssociatedContainer = std::vector<ConstObjectAssociated>;

    public:
        // 顶点和骨骼的数目在对象的生存期是固定的。
        SkinControllerImpl(int numVertices, int numBones, const BaseRendererSharedPtr& baseRenderer);
        SkinControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumBones() const noexcept;

        NODISCARD ConstNodeSharedPtr GetBones(int bonesIndex) const;
        NODISCARD float GetWeights(int bonesIndex, int verticesIndex) const;
        NODISCARD APoint GetOffsets(int bonesIndex, int verticesIndex) const;

        // 调用构造函数后，您必须使用这些函数设置数据。
        void SetBones(int bonesIndex, const ConstNodeSharedPtr& node);
        void SetWeights(int bonesIndex, int verticesIndex, float weight);
        void SetOffsets(int bonesIndex, int verticesIndex, const APoint& offset);

        void SetBones(const ConstObjectAssociatedContainer& aBones);
        void SetWeights(int bonesIndex, const std::vector<float>& weight);
        void SetOffsets(int bonesIndex, const std::vector<APoint>& offset);

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        NODISCARD bool Update(const VisualSharedPtr& visual);

    private:
        using ConstWeakObjectAssociated = CoreTools::ConstWeakObjectAssociated<Node>;

    private:
        void OnFirstUpdate(Visual& visual);

    private:
        int numVertices;
        int numBones;
        int size;
        std::vector<ConstWeakObjectAssociated> bones;  // bones[numBones]
        std::vector<float> weights;  // weight[numBones][numVertices], 索引 vertex + numVertices * bone
        std::vector<APoint> offsets;  // offset[numBones][numVertices], 索引 vertex + numVertices * bone

        BaseRendererWeakPtr baseRenderer;
        int position;
        int stride;
        bool firstUpdate;
        bool canUpdate;
    };
}

#endif  // RENDERING_CONTROLLERS_SKIN_CONTROLLER_IMPL_H
