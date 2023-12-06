/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/20 16:25)

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

        using ControllerSharedPtr = std::shared_ptr<ClassType>;
        using ConstControllerSharedPtr = std::shared_ptr<const ClassType>;

    public:
        explicit ControllerInterface(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerInterface);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD virtual ConstControllerSharedPtr GetController() const;
        NODISCARD virtual ControllerSharedPtr GetController();
        virtual void SetController(const ControllerSharedPtr& controller);

        NODISCARD virtual bool Update(double applicationTime) = 0;

        NODISCARD virtual ConstControllerSharedPtr GetConstController(int index) const;
        NODISCARD virtual ControllerSharedPtr GetController(int index);
        virtual void AttachController(const ControllerSharedPtr& controller);
        virtual void DetachController(const ControllerSharedPtr& controller);
        virtual void DetachAllControllers();

        NODISCARD virtual ControllerSharedPtr Clone() const = 0;

        NODISCARD virtual int GetNumControllers() const;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ControllerInterface);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ControllerInterface);
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H
