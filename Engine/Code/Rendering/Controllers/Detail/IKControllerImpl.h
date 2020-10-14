// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 10:12)

#ifndef RENDERING_CONTROLLERS_IK_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_IK_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Controllers/IKGoal.h"
#include "Rendering/Controllers/IKJoint.h"

#include <vector>

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
    class ObjectLink;
    class ObjectRegister;
    class Object;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE IKControllerImpl
    {
    public:
        using ClassType = IKControllerImpl;
        using IKGoalSharedPtrVector = std::vector<IKGoalSharedPtr>;
        using IKJointSharedPtrVector = std::vector<IKJointSharedPtr>;
        using Object = CoreTools::Object;
        using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
        using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

    public:
        IKControllerImpl() noexcept;
        explicit IKControllerImpl(const IKJointSharedPtrVector& joints);

        CLASS_INVARIANT_DECLARE;

        int GetStreamingSize() const;
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        void Load(const CoreTools::BufferSourceSharedPtr& source);
        void Link(const CoreTools::ObjectLinkSharedPtr& source);
        void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

        const ObjectSharedPtr GetObjectByName(const std::string& name);
        const std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name);
        const ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
        const std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

        int GetIterations() const noexcept;
        void SetIterations(int iterations) noexcept;
        bool IsOrderEndToRoot() const noexcept;
        void SetOrderEndToRoot(bool orderEndToRoot) noexcept;

        const IKJointSharedPtr GetJointsSharedPtr(int index);
        int GetJointsNum() const;

    private:
        int m_Iterations;  // ƒ¨»œ = 128
        bool m_OrderEndToRoot;  // ƒ¨»œ = true

        IKJointSharedPtrVector m_Joints;
    };
}

#endif  // RENDERING_CONTROLLERS_IK_CONTROLLER_IMPL_H
