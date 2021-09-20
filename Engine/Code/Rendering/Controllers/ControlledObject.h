// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:22)

#ifndef RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
#define RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "ControllerInterface.h"
EXPORT_SHARED_PTR(Rendering, ControlledObjectImpl, RENDERING_DEFAULT_DECLARE); 
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
        void Swap(ControlledObject& rhs) noexcept;
     
         public:
             TYPE_DECLARE(ControlledObject);
             using ClassShareType = CoreTools::CopyUnsharedClasses;
             ~ControlledObject() noexcept= default;
             ControlledObject(const ControlledObject& rhs);
             ControlledObject& operator=(const ControlledObject& rhs);
             ControlledObject(ControlledObject&& rhs) noexcept;
             ControlledObject& operator=(ControlledObject&& rhs) noexcept;
        using ParentType = ControllerInterface;
        
    public:
        ControlledObject();
        
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ControlledObject);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
       
         const ControllerInterface* GetControllerObject () const noexcept override;
                ControllerInterface* GetControllerObject() noexcept override;
		 bool Update (double applicationTime) override;
                void SetObject(ControllerInterface* object) noexcept override;
    
          int GetNumControllers () const override;
        ConstControllerInterfaceSharedPtr GetConstController (int index) const;
		ControllerInterfaceSharedPtr GetController (int index);
         void AttachController (ControllerInterfaceSharedPtr  controller) override;
         void DetachController (ControllerInterfaceSharedPtr  controller) override;
        void DetachAllControllers ();
        bool UpdateControllers (double applicationTime);

	private:
		void AttachControllerInCopy(const ControlledObject& rhs);

    private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
        ControllerInterface* m_Object;
		uint64_t m_ObjectID{ 0 };
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(ControlledObject);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( ControlledObject); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
