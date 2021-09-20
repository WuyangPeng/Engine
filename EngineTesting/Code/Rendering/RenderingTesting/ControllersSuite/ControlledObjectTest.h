// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 14:53)

#ifndef RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H
#define RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H

#include "Rendering/Controllers/ControlledObject.h"

namespace Rendering
{
	class ControlledObjectTest : public ControlledObject 
    {
    public:
        using ClassType = ControlledObjectTest ;
        using ParentType = ControlledObject ;

    public:
        ControlledObjectTest();
        virtual ~ControlledObjectTest();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
        
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControlledObjectTest);     	 
		CORE_TOOLS_RTTI_DECLARE; 

		virtual ControllerInterfaceSharedPtr Clone() const;
                [[nodiscard]] virtual ObjectInterfaceSharedPtr CloneObject() const;
    };

    CORE_TOOLS_STREAM_REGISTER(ControlledObjectTest);
    
	 
}

#endif // RENDERING_CONTROLLERS_SUITE_CONTROLLER_OBJECT_TEST_H