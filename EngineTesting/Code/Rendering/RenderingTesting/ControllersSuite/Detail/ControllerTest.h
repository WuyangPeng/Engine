/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/20 18:15)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H

#include "Rendering/Controllers/Controller.h"

namespace Rendering
{
    class ControllerTest final : public Controller
    {
    public:
        using ClassType = ControllerTest;
        using ParentType = Controller;

        using ControllerTestSharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static ControllerTestSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

        NODISCARD ControllerSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        enum class Constructor
        {
            Default,
        };

    public:
        ControllerTest(const std::string& name, Constructor constructor);
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ControllerTest);

#include SYSTEM_WARNING_POP

}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H