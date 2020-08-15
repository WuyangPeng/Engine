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
          ~Controller();

          Controller(Controller&&) = default;
          Controller& operator=(Controller&&) = default;
    
		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Controller);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
        
          const ControllerInterface* GetControllerObject() const noexcept override;
                ControllerInterface* GetControllerObject() noexcept override;
        
		  bool Update(double applicationTime)   override;
        
        // ��������ǹ��е�,��Ϊ��ControlledObject��Ҫ���ö����ڵ���AttachController��
        // ���������һ�������ʱ����Ҫ�ڵ���AttachController���ö���
                  void SetObject(ControllerInterface* object)   override;
        
        void SetApplicationTime(double applicationTime) noexcept;
                  double GetApplicationTime() const noexcept;

        double GetControlTime (double applicationTime);
        
        ControllerRepeatType GetRepeat() const noexcept;
        double GetMinTime() const noexcept;
        double GetMaxTime() const noexcept;
        double GetPhase() const noexcept;
        double GetFrequency() const noexcept;
        bool IsActive() const noexcept;
        
        void SetRepeat(ControllerRepeatType repeat) noexcept;
        void SetTime(double minTime, double maxTime) noexcept;
        void SetPhase(double phase) noexcept;
        void SetFrequency(double frequency) noexcept;
        void SetActive(bool active) noexcept;
        
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
