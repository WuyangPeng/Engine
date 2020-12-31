//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:55)

#ifndef CORE_TOOLS_COMMAND_COMMAND_H
#define CORE_TOOLS_COMMAND_COMMAND_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandLineInformation.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CommandHandle final
    {
    public:
        using ClassType = CommandHandle;

    public:
        CommandHandle(int argumentsNumber, char** arguments);
        explicit CommandHandle(const char* commandLine);

        CLASS_INVARIANT_DECLARE;

        // ���ص�һ��δ������������֡�
        [[nodiscard]] const std::string ExcessArguments() const;
        [[nodiscard]] int GetExcessArgumentsCount() const noexcept;

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
        [[nodiscard]] bool GetBoolean(const std::string& name) const;

        [[nodiscard]] int GetInteger(const std::string& name) const;
        [[nodiscard]] float GetFloat(const std::string& name) const;
        [[nodiscard]] double GetDouble(const std::string& name) const;
        [[nodiscard]] const std::string GetString(const std::string& name) const;
        [[nodiscard]] const std::string GetFileName() const;

        void SetUsed(const std::string& argumentsName);
        void SetFileNmaeUsed();

    private:
        [[nodiscard]] bool IsArgumentOutOfRange(double value) const noexcept;

    private:
        // ��������Ϣ��
        CommandLineInformation m_CommandLineInformation;

        // �����ı߽��顣
        double m_Small;  // ��ֵ�������½� (min �� inf)
        double m_Large;  // ��ֵ�������Ͻ� (max �� sup)
        bool m_MinSet;  // ���Ϊ�棬�Ƚϣ�m_Small <= arg
        bool m_MaxSet;  // ���Ϊ�棬�Ƚϣ�arg <= m_Large
        bool m_InfSet;  // ���Ϊ�棬�Ƚϣ�m_Small < arg
        bool m_SupSet;  // ���Ϊ�棬�Ƚϣ�arg < m_Large
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_H
