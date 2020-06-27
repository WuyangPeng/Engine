// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:22)

#ifndef RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
#define RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "ControllerInterface.h"

RENDERING_EXPORT_SHARED_PTR(ControlledObjectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ControlledObject : public ControllerInterface 
    {
    public:
        // ����һ��Controller���Ὣ�����ControllerObject��
        // ����һ��Controller���Ὣ���ControllerObjectɾ����
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(ControlledObject);
        using ParentType = ControllerInterface;
        
    public:
        ControlledObject();
        virtual ~ControlledObject();
        
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ControlledObject);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
       
        virtual const ControllerInterface* GetControllerObject () const override;
		virtual ControllerInterface* GetControllerObject () override;
		virtual bool Update (double applicationTime) override;
		virtual void SetObject (ControllerInterface* object) override;
    
        virtual int GetNumControllers () const override;
        ConstControllerInterfaceSmartPointer GetConstController (int index) const;
		ControllerInterfaceSmartPointer GetController (int index);
        virtual void AttachController (ControllerInterfaceSmartPointer& controller) override;
        virtual void DetachController (ControllerInterfaceSmartPointer& controller) override;
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

#endif // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_H
