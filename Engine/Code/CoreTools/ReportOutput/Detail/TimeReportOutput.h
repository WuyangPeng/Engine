// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 17:53)

// ����Ϣ�����ָ����ostream��TimeReportOutputΪ�ڲ��ӿ����ࡣʵ�������ǰʱ���ָ��ʱ��Ĺ��ܡ�

#ifndef CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H

#include "EquilongReportOutputImpl.h" 

namespace boost
{
	namespace timer
	{
		class cpu_timer;
	}
}

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE TimeReportOutput : public EquilongReportOutputImpl
	{
	public:
		using ClassType = TimeReportOutput;
		using ParentType = EquilongReportOutputImpl;
		using CpuTimer = boost::timer::cpu_timer;
		using CpuTimerPtr = std::shared_ptr<CpuTimer>;

	public:
		TimeReportOutput(const std::string& timeDescribe, int borderLineLength, std::ostream* osPtr = &std::cout);
		virtual ~TimeReportOutput();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void PrintCurrentTime();
		void PrintCostTime(const CpuTimerPtr& cpuTime);

	private:
		std::string m_TimeDescribe;
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H