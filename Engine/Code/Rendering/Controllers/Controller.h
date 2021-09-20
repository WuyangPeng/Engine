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
EXPORT_SHARED_PTR(Rendering, ControllerImpl, RENDERING_DEFAULT_DECLARE);
 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class ControlledObject;
    
    class RENDERING_DEFAULT_DECLARE Controller : public ControllerInterface 
    {
    public:
        // 复制一个Controller不会将其加入ControllerObject。
        // 销毁一个Controller不会将其从ControllerObject删除。
        void Swap(Controller& rhs) noexcept;
   
       public:
           TYPE_DECLARE(Controller);
           using ClassShareType = CoreTools::CopyUnsharedClasses;
           ~Controller() noexcept= default;
           Controller(const Controller& rhs);
           Controller& operator=(const Controller& rhs);
           Controller(Controller&& rhs) noexcept;
           Controller& operator=(Controller&& rhs) noexcept;
        using ParentType = ControllerInterface;
    
    public:
        Controller(); 
    
		CLASS_INVARIANT_OVERRIDE_DECLARE;        
        
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Controller);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
        
          const ControllerInterface* GetControllerObject() const noexcept override;
                ControllerInterface* GetControllerObject() noexcept override;
        
		  bool Update(double applicationTime)   override;
        
        // 这个函数是公有的,因为类ControlledObject需要设置对象在调用AttachController。
        // 派生类管理一组控制器时还需要在调用AttachController设置对象。
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
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
        
        // 控制对象。这是一个常规的指针,而不是一个智能指针,
        // 以避免引用循环在m_Object和'this'之间。
        ControllerInterface* m_Object;
		uint64_t m_ObjectID{ 0 };
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
    CORE_TOOLS_STREAM_REGISTER(Controller);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE(Controller); 
}
#include STSTEM_WARNING_POP
#endif // RENDERING_CONTROLLERS_CONTROLLER_H
