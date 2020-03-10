// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:11)

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
        ControllerImpl();
        ~ControllerImpl();
    
        CLASS_INVARIANT_DECLARE;
        
        void SetApplicationTime (double applicationTime);
        double GetApplicationTime () const;

         // �������¡��Ժ���Ϊ��λ��Ӧ�ó���ʱ�䡣
        bool Update (double applicationTime);
        
        // ��Ӧ�ó���λʱ��ת����������λʱ�䡣���������ʹ�ô˸��³���
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
        
        void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
        
    private:
        ControllerRepeatType m_Repeat;  // Ĭ�� = ControllerRepeatType::Clamp
        double m_MinTime;     // Ĭ�� = 0
        double m_MaxTime;     // Ĭ�� = 0
        double m_Phase;       // Ĭ�� = 0
        double m_Frequency;   // Ĭ�� = 1
        bool m_Active;        // Ĭ�� = true
        
        // Ӧ�ó����ʱ��,�Ժ���Ϊ��λ��
        double m_ApplicationTime;
    };
}

#endif // RENDERING_CONTROLLERS_CONTROLLER_IMPL_H
