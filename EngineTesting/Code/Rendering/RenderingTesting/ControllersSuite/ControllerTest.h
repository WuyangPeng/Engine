// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 14:54)

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
        ControllerTest();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        ControllerInterfaceSharedPtr Clone() const override;
        ObjectInterfaceSharedPtr CloneObject() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ControllerTest);
#include STSTEM_WARNING_POP

}

#endif  // RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H