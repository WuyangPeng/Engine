// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:55)

#ifndef CORE_TOOLS_COMMAND_COMMAND_H
#define CORE_TOOLS_COMMAND_COMMAND_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandLineInformation.h"

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE CommandHandle
	{
	public:
		using ClassType = CommandHandle;

	public:
		CommandHandle(int argumentsNumber, char** arguments);
		explicit CommandHandle(const char* commandLine);

		CLASS_INVARIANT_DECLARE;

		// ���ص�һ��δ������������֡�			
		const std::string ExcessArguments() const;
		int GetExcessArgumentsCount() const;

		// �������ֲ����ķ�Χ��
		// �����Χ�Ǳ���ģ����Ǳ���Ϊÿ���������á�
		CommandHandle& SetMinValue(double value) noexcept;
		CommandHandle& SetMaxValue(double value) noexcept;
		CommandHandle& SetInfValue(double value) noexcept;
		CommandHandle& SetSupValue(double value) noexcept;

		void ClearBoundary() noexcept;

		// ���з���ÿ���ķ���ֵ�ǲ��������е�����ѡ���ֵ��

		// ʹ�ò��������ڲ���ȡ�κβ�����ѡ��������������
		// MyProgram -debug -x 10 -y 20 -fileName fileName
		// ѡ�� -debug û�в�����

		// ���ش��ڵ�ѡ��
		bool GetBoolean(const std::string& name) const;

		int GetInteger(const std::string& name) const;
		float GetFloat(const std::string& name) const;
		double GetDouble(const std::string& name) const;
		const std::string GetString(const std::string& name) const;
		const std::string GetFileName() const;

		void SetUsed(const std::string& argumentsName);
		void SetFileNmaeUsed();

	private:
		bool IsArgumentOutOfRange(double value) const noexcept;

	private:
		// ��������Ϣ��
		CommandLineInformation m_CommandLineInformation;

		// �����ı߽��顣
		double m_Small; // ��ֵ�������½� (min �� inf)
		double m_Large; // ��ֵ�������Ͻ� (max �� sup)
		bool m_MinSet; // ���Ϊ�棬�Ƚϣ�m_Small <= arg
		bool m_MaxSet; // ���Ϊ�棬�Ƚϣ�arg <= m_Large
		bool m_InfSet; // ���Ϊ�棬�Ƚϣ�m_Small < arg
		bool m_SupSet; // ���Ϊ�棬�Ƚϣ�arg < m_Large		
	};
}

#endif // CORE_TOOLS_COMMAND_COMMAND_H
