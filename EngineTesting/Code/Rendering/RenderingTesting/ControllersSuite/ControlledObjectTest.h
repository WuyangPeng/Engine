// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/05 14:53)

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
        ControlledObjectTest();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControlledObjectTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        ControllerInterfaceSharedPtr Clone() const noexcept override;
        [[nodiscard]] ObjectInterfaceSharedPtr CloneObject() const noexcept override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ControlledObjectTest);

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H