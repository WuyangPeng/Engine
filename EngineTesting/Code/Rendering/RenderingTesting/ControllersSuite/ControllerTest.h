///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 19:55)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H

#include "Rendering/Controllers/Controller.h"

namespace Rendering
{
    class ControllerTest : public Controller
    {
    public:
        using ClassType = ControllerTest;
        using ParentType = Controller;

    public:
        explicit ControllerTest(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(ControllerTest);

#include STSTEM_WARNING_POP

}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H