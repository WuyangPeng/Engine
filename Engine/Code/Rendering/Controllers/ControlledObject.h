/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 09:29)

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
        explicit ControlledObject(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ControlledObject);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD bool Update(double applicationTime) override;

        NODISCARD int GetNumControllers() const override;
        NODISCARD ConstControllerSharedPtr GetConstController(int index) const override;
        NODISCARD ControllerSharedPtr GetController(int index) override;
        void AttachController(const ControllerSharedPtr& controller) override;
        void DetachController(const ControllerSharedPtr& controller) override;
        void DetachAllControllers() override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ControlledObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ControlledObject);
}

#endif  // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
