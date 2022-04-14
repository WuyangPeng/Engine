// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/05 16:19)

#ifndef RENDERING_CONTROLLERS_SUITE_PARTICLE_CONTROLLER_TEST_H
#define RENDERING_CONTROLLERS_SUITE_PARTICLE_CONTROLLER_TEST_H

#include "Rendering/Controllers/ParticleController.h"

namespace Rendering
{
    class ParticleControllerTest : public ParticleController
    {
    public:
        using ClassType = ParticleControllerTest;
        using ParentType = ParticleController;

    public:
        ParticleControllerTest();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_OBJECT_FACTORY_DECLARE(ParticleControllerTest);
        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        [[nodiscard]] ObjectInterfaceSharedPtr CloneObject() const override;
        ControllerInterfaceSharedPtr Clone() const override;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(ParticleControllerTest);
#include STSTEM_WARNING_POP

}

#endif  // RENDERING_CONTROLLERS_SUITE_PARTICLE_CONTROLLER_TEST_H