///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

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
        explicit ControllerInterface(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerInterface);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD virtual const ControllerInterface* GetControllerObject() const = 0;
        NODISCARD virtual ControllerInterface* GetControllerObject() = 0;
        virtual void SetObject(ControllerInterface* object) = 0;

        NODISCARD virtual bool Update(double applicationTime) = 0;

        virtual void AttachController(ControllerInterfaceSharedPtr controller);
        virtual void DetachController(ControllerInterfaceSharedPtr controller);

        NODISCARD virtual ControllerInterfaceSharedPtr Clone() const = 0;

        NODISCARD virtual int GetNumControllers() const;
        virtual void SetObjectInCopy(ControllerInterface* object);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ControllerInterface);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ControllerInterface);
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H
