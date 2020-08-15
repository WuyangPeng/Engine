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
        using IKGoalSmartPointerVector = std::vector<IKGoalSmartPointer>;
        using IKJointSmartPointerVector = std::vector<IKJointSmartPointer>;
        using Object = CoreTools::Object;
        using ObjectSmartPointer = CoreTools::ObjectSmartPointer;
        using ConstObjectSmartPointer = CoreTools::ConstObjectSmartPointer;

    public:
        IKControllerImpl() noexcept;
        explicit IKControllerImpl(const IKJointSmartPointerVector& joints);

        CLASS_INVARIANT_DECLARE;

        int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        const ObjectSmartPointer GetObjectByName(const std::string& name);
        const std::vector<ObjectSmartPointer> GetAllObjectsByName(const std::string& name);
        const ConstObjectSmartPointer GetConstObjectByName(const std::string& name) const;
        const std::vector<ConstObjectSmartPointer> GetAllConstObjectsByName(const std::string& name) const;

        int GetIterations() const noexcept;
        void SetIterations(int iterations) noexcept;
        bool IsOrderEndToRoot() const noexcept;
        void SetOrderEndToRoot(bool orderEndToRoot) noexcept;

        const IKJointSmartPointer GetJointsSmartPointer(int index);
        int GetJointsNum() const;

    private:
        int m_Iterations;  // ƒ¨»œ = 128
        bool m_OrderEndToRoot;  // ƒ¨»œ = true

        IKJointSmartPointerVector m_Joints;
    };
}

#endif  // RENDERING_CONTROLLERS_IK_CONTROLLER_IMPL_H
