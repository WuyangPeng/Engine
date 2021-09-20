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
        using ClassType = ControllerTest ;
        using ParentType = Controller ;

    public:
        ControllerTest();
        virtual ~ControllerTest();
 
        CLASS_INVARIANT_OVERRIDE_DECLARE;
 
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerTest);     	 
		CORE_TOOLS_RTTI_DECLARE; 
         	virtual ControllerInterfaceSharedPtr Clone() const;
                 ObjectInterfaceSharedPtr CloneObject() const override;
    };

    CORE_TOOLS_STREAM_REGISTER(ControllerTest);
    
	 
}

#endif // RENDERING_CONTROLLERS_SUITE_CONTROLLER_TEST_H