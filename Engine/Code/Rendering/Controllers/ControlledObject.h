// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:22)

#ifndef RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
#define RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "ControllerInterface.h"

RENDERING_EXPORT_SHARED_PTR(ControlledObjectImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ControlledObject : public ControllerInterface 
    {
    public:
        // 复制一个Controller不会将其加入ControllerObject。
        // 销毁一个Controller不会将其从ControllerObject删除。
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ControlledObject);
        using ParentType = ControllerInterface;
        
    public:
        ControlledObject();
         ~ControlledObject();

         ControlledObject(ControlledObject&&) = default;
         ControlledObject& operator=(ControlledObject&&) = default;
        
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ControlledObject);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
       
         const ControllerInterface* GetControllerObject () const noexcept override;
                ControllerInterface* GetControllerObject() noexcept override;
		 bool Update (double applicationTime) override;
                void SetObject(ControllerInterface* object) noexcept override;
    
          int GetNumControllers () const override;
        ConstControllerInterfaceSmartPointer GetConstController (int index) const;
		ControllerInterfaceSmartPointer GetController (int index);
         void AttachController (ControllerInterfaceSmartPointer  controller) override;
         void DetachController (ControllerInterfaceSmartPointer  controller) override;
        void DetachAllControllers ();
        bool UpdateControllers (double applicationTime);

	private:
		void AttachControllerInCopy(const ControlledObject& rhs);

    private:
		IMPL_TYPE_DECLARE(ControlledObject);
        ControllerInterface* m_Object;
		uint64_t m_ObjectID{ 0 };
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(ControlledObject);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, ControlledObject); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
