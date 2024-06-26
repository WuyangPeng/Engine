///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:03)

#ifndef RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TEST_H
#define RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TEST_H

#include "Rendering/Controllers/PointController.h"

namespace Rendering
{
    class PointControllerTest : public PointController
    {
    public:
        using ClassType = PointControllerTest;
        using ParentType = PointController;

    public:
        explicit PointControllerTest(const BaseRendererSharedPtr& baseRenderer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(PointControllerTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;
        NODISCARD ControllerSharedPtr Clone() const override;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(PointControllerTest);

#include SYSTEM_WARNING_POP
}

#endif  // RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TEST_H