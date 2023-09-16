///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:02)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H

#include "Rendering/Controllers/ControlledObject.h"

namespace Rendering
{
    class ControlledObjectTest : public ControlledObject
    {
    public:
        using ClassType = ControlledObjectTest;
        using ParentType = ControlledObject;

    public:
        explicit ControlledObjectTest(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControlledObjectTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ControlledObjectTest);

#include SYSTEM_WARNING_POP
}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H