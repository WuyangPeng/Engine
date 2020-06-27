// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:23)

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
        // 复制一个Controller不会将其加入ControllerObject。
        // 销毁一个Controller不会将其从ControllerObject删除。
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
        
        // 这个函数是公有的,因为类ControlledObject需要设置对象在调用AttachController。
        // 派生类管理一组控制器时还需要在调用AttachController设置对象。
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
        
        // 控制对象。这是一个常规的指针,而不是一个智能指针,
        // 以避免引用循环在m_Object和'this'之间。
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
