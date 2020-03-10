// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:31)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H
#define RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/MemoryTools/SubclassSmartPointer.h"

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE ControllerInterface : public CoreTools::Object
	{
	public:
		using ClassType = ControllerInterface;
        using ParentType = Object;
		using ControllerInterfaceSmartPointer = CoreTools::ThirdSubclassSmartPointer<ClassType>;
	    using ConstControllerInterfaceSmartPointer = CoreTools::ConstThirdSubclassSmartPointer<ClassType>;

	public:
		ControllerInterface();
		virtual ~ControllerInterface();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
                
		CORE_TOOLS_OBJECT_FACTORY_DECLARE(ControllerInterface);
		CORE_TOOLS_RTTI_OVERRIDE_DECLARE;     

		virtual const ControllerInterface* GetControllerObject () const = 0;	 
		virtual ControllerInterface* GetControllerObject () = 0;
		virtual void SetObject (ControllerInterface* object) = 0;

		virtual bool Update (double applicationTime) = 0;

		virtual void AttachController (ControllerInterfaceSmartPointer& controller);
		virtual void DetachController (ControllerInterfaceSmartPointer& controller);

		virtual ControllerInterfaceSmartPointer Clone() const = 0;

		virtual int GetNumControllers () const;
		virtual void SetObjectInCopy(ControllerInterface* object);
	};    
    
    CORE_TOOLS_STREAM_REGISTER(ControllerInterface);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, ControllerInterface); 
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_INTERFACE_H

