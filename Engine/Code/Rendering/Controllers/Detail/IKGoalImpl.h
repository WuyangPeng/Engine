///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_IKGOAL_IMPL_H
#define RENDERING_CONTROLLERS_IKGOAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/SceneGraph/Spatial.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE IKGoalImpl
    {
    public:
        using ClassType = IKGoalImpl;
        using APoint = Mathematics::APointF;
        using Object = CoreTools::Object;
        using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
        using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

    public:
        IKGoalImpl() noexcept;
        IKGoalImpl(const SpatialSharedPtr& target, const SpatialSharedPtr& effector, float weight = 1.0f) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        NODISCARD ObjectSharedPtr GetObjectByName(const std::string& name);
        NODISCARD std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name);
        NODISCARD ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
        NODISCARD std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

        NODISCARD ConstSpatialSharedPtr GetTarget() const noexcept;
        NODISCARD ConstSpatialSharedPtr GetEffector() const noexcept;
        NODISCARD APoint GetTargetPosition() const noexcept;
        NODISCARD APoint GetEffectorPosition() const noexcept;

        void SetWeight(float aWeight) noexcept;
        NODISCARD float GetWeight() const noexcept;

    private:
        float weight;  // Ĭ�� = 1
        CoreTools::ObjectAssociated<Spatial> goalTarget;
        CoreTools::ObjectAssociated<Spatial> effector;
    };
}

#endif  // RENDERING_CONTROLLERS_IKGOAL_IMPL_H
