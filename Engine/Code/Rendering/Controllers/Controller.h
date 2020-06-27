// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:23)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_H
#define RENDERING_CONTROLLERS_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "ControllerInterface.h"
#include "Flags/ControllerFlags.h"

RENDERING_EXPORT_SHARED_PTR(ControllerImpl);

namespace Rendering
{
    class ControlledObject;
    
    class RENDERING_DEFAULT_DECLARE Controller : public ControllerInterface 
    {
    public:
        // ����һ��Controller���Ὣ�����ControllerObject��
        // ����һ��Controller���Ὣ���ControllerObjectɾ����
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Controller);
        using ParentType = ControllerInterface;
    
    public:
        Controller();
        virtual ~Controller();
    
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Controller);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
        
        virtual const ControllerInterface* GetControllerObject () const;
		virtual ControllerInterface* GetControllerObject ();
        
		virtual bool Update (double applicationTime);
        
        // ��������ǹ��е�,��Ϊ��ControlledObject��Ҫ���ö����ڵ���AttachController��
        // ���������һ�������ʱ����Ҫ�ڵ���AttachController���ö���
 		virtual void SetObject (ControllerInterface* object);
        
        void SetApplicationTime (double applicationTime);
        double GetApplicationTime () const;

        double GetControlTime (double applicationTime);
        
        ControllerRepeatType GetRepeat() const;
        double GetMinTime() const;
        double GetMaxTime() const;
        double GetPhase() const;
        double GetFrequency() const;
        bool IsActive() const;
        
        void SetRepeat(ControllerRepeatType repeat);
        void SetTime(double minTime,double maxTime);
        void SetPhase(double phase);
        void SetFrequency(double frequency);
        void SetActive(bool active);
        
    private:
		IMPL_TYPE_DECLARE(Controller);
        
        // ���ƶ�������һ�������ָ��,������һ������ָ��,
        // �Ա�������ѭ����m_Object��'this'֮�䡣
        ControllerInterface* m_Object;
		uint64_t m_ObjectID{ 0 };
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(Controller);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, Controller); 
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_H
