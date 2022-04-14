// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 16:19)

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
        PointControllerTest();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(PointControllerTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        [[nodiscard]] ObjectInterfaceSharedPtr CloneObject() const override;
        ControllerInterfaceSharedPtr Clone() const override;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(PointControllerTest);

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TEST_H