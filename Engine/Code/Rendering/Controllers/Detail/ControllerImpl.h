// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:11)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/Flags/ControllerFlags.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
    class ControllerInterface;
    
    class RENDERING_HIDDEN_DECLARE ControllerImpl  
    {
    public:
        using ClassType = ControllerImpl;
        using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
        using Math = Mathematics::Math<double>;
        
    public:
        ControllerImpl() noexcept;
 
    
        CLASS_INVARIANT_DECLARE;
        
        void SetApplicationTime(double applicationTime) noexcept;
        double GetApplicationTime() const noexcept;

         // 动画更新。以毫秒为单位的应用程序时间。
        bool Update(double applicationTime) noexcept;
        
        // 从应用程序单位时间转换控制器单位时间。派生类可以使用此更新程序。
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
        
        void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
        
    private:
        ControllerRepeatType m_Repeat;  // 默认 = ControllerRepeatType::Clamp
        double m_MinTime;     // 默认 = 0
        double m_MaxTime;     // 默认 = 0
        double m_Phase;       // 默认 = 0
        double m_Frequency;   // 默认 = 1
        bool m_Active;        // 默认 = true
        
        // 应用程序的时间,以毫秒为单位。
        double m_ApplicationTime;
    };
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
