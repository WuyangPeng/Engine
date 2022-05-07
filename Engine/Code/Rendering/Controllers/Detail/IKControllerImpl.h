///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/06 11:23)

#ifndef RENDERING_CONTROLLERS_IK_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_IK_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Controllers/IKGoal.h"
#include "Rendering/Controllers/IKJoint.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE IKControllerImpl
    {
    public:
        using ClassType = IKControllerImpl;
        using IKGoalSharedPtrVector = std::vector<CoreTools::ObjectAssociated<IKGoal>>;
        using IKJointSharedPtrVector = std::vector<CoreTools::ObjectAssociated<IKJoint>>;
        using Object = CoreTools::Object;
        using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
        using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

    public:
        IKControllerImpl() noexcept;
        explicit IKControllerImpl(const IKJointSharedPtrVector& joints);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        NODISCARD ObjectSharedPtr GetObjectByName(const std::string& name);
        NODISCARD std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name);
        NODISCARD ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
        NODISCARD std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

        NODISCARD int GetIterations() const noexcept;
        void SetIterations(int aIterations) noexcept;
        NODISCARD bool IsOrderEndToRoot() const noexcept;
        void SetOrderEndToRoot(bool aOrderEndToRoot) noexcept;

        NODISCARD IKJointSharedPtr GetJointsSharedPtr(int index);
        NODISCARD int GetJointsNum() const;

    private:
        int iterations;  // 默认 = 128
        bool orderEndToRoot;  // 默认 = true

        IKJointSharedPtrVector joints;
    };
}

#endif  // RENDERING_CONTROLLERS_IK_CONTROLLER_IMPL_H
