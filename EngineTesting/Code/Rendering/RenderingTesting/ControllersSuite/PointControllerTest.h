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
		using ClassType = PointControllerTest ;
		using ParentType = PointController ;

    public:
		PointControllerTest();
		virtual ~PointControllerTest();

 
        CLASS_INVARIANT_OVERRIDE_DECLARE;
 
        
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(PointControllerTest);     	 
		CORE_TOOLS_RTTI_DECLARE; 
		    [[nodiscard]] virtual ObjectInterfaceSharedPtr CloneObject() const ;
		virtual ControllerInterfaceSharedPtr Clone() const;
    };

	CORE_TOOLS_STREAM_REGISTER(PointControllerTest);
    
	 
}

#endif // RENDERING_CONTROLLERS_SUITE_POINT_CONTROLLER_TEST_H