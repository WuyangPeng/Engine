// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 10:31)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H
#define RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"


namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ControllerInterface : public CoreTools::Object
	{
	public:
		using ClassType = ControllerInterface;
        using ParentType = Object;
		using ControllerInterfaceSharedPtr = std::shared_ptr<ClassType>;
	    using ConstControllerInterfaceSharedPtr = std::shared_ptr<const ClassType>;

	public:
		ControllerInterface();
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
                
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerInterface);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;     

		virtual const ControllerInterface* GetControllerObject () const = 0;	 
		virtual ControllerInterface* GetControllerObject () = 0;
		virtual void SetObject (ControllerInterface* object) = 0;

		virtual bool Update (double applicationTime) = 0;

		virtual void AttachController (ControllerInterfaceSharedPtr  controller);
		virtual void DetachController (ControllerInterfaceSharedPtr  controller);

		virtual ControllerInterfaceSharedPtr Clone() const = 0;

		virtual int GetNumControllers () const;
		virtual void SetObjectInCopy(ControllerInterface* object);
	};    
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(ControllerInterface);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE(ControllerInterface); 
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H

