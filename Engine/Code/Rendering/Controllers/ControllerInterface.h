///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 09:31)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H
#define RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ControllerInterface : public CoreTools::Object
    {
    public:
        using ClassType = ControllerInterface;
        using ParentType = Object;

        using ControllerInterfaceSharedPtr = std::shared_ptr<ClassType>;
        using ConstControllerInterfaceSharedPtr = std::shared_ptr<const ClassType>;

    public:
        explicit ControllerInterface(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerInterface);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD virtual ConstControllerInterfaceSharedPtr GetControllerObject() const = 0;
        NODISCARD virtual ControllerInterfaceSharedPtr GetControllerObject() = 0;
        virtual void SetControllerObject(const ControllerInterfaceSharedPtr& object) = 0;

        NODISCARD virtual bool Update(double applicationTime) = 0;

        virtual void AttachController(const ControllerInterfaceSharedPtr& controller);
        virtual void DetachController(const ControllerInterfaceSharedPtr& controller);

        NODISCARD virtual ControllerInterfaceSharedPtr Clone() const = 0;

        NODISCARD virtual int GetNumControllers() const;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ControllerInterface);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ControllerInterface);
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H
