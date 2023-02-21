///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 11:31)

#ifndef RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
#define RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "ControllerInterface.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ControlledObject, ControlledObjectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ControlledObject : public ControllerInterface
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ControlledObject);
        using ParentType = ControllerInterface;

    public:
        explicit ControlledObject(CoreTools::DisableNotThrow disableNotThrow);
        ~ControlledObject() noexcept = default;
        ControlledObject(const ControlledObject& rhs);
        ControlledObject& operator=(const ControlledObject& rhs);
        ControlledObject(ControlledObject&& rhs) noexcept;
        ControlledObject& operator=(ControlledObject&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ControlledObject);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD const ControllerInterface* GetControllerObject() const noexcept override;
        NODISCARD ControllerInterface* GetControllerObject() noexcept override;
        NODISCARD bool Update(double applicationTime) override;
        void SetObject(ControllerInterface* object) override;

        NODISCARD int GetNumControllers() const override;
        NODISCARD ConstControllerInterfaceSharedPtr GetConstController(int index) const;
        NODISCARD ControllerInterfaceSharedPtr GetController(int index);
        void AttachController(ControllerInterfaceSharedPtr controller) override;
        void DetachController(ControllerInterfaceSharedPtr controller) override;
        void DetachAllControllers();
        NODISCARD bool UpdateControllers(double applicationTime);

    private:
        void AttachControllerInCopy(const ControlledObject& rhs);

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ControlledObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ControlledObject);
}

#endif  // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
