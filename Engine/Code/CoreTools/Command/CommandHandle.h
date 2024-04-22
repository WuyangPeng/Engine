/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:21)

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

        /// ���ص�һ��δ������������֡�
        NODISCARD std::string ExcessArguments() const;
        NODISCARD int GetExcessArgumentsCount() const noexcept;

        /// �������ֲ����ķ�Χ��
        /// �����Χ�Ǳ���ģ����Ǳ���Ϊÿ���������á�
        CommandHandle& SetMinValue(double value) noexcept;
        CommandHandle& SetMaxValue(double value) noexcept;
        CommandHandle& SetInfValue(double value) noexcept;
        CommandHandle& SetSupValue(double value) noexcept;

        void ClearBoundary() noexcept;

        /// ���з���ÿ���ķ���ֵ�ǲ��������е�����ѡ���ֵ��

        /// ʹ�ò��������ڲ���ȡ�κβ�����ѡ��������������
        /// MyProgram -debug -x 10 -y 20 -fileName fileName
        /// ѡ�� -debug û�в�����

        /// ���ش��ڵ�ѡ��
        NODISCARD bool GetBoolean(const std::string& name) const;

        NODISCARD int GetInteger(const std::string& name) const;
        NODISCARD float GetFloat(const std::string& name) const;
        NODISCARD double GetDouble(const std::string& name) const;
        NODISCARD std::string GetString(const std::string& name) const;
        NODISCARD std::string GetFileName() const;

        void SetUsed(const std::string& argumentsName);
        void SetFileNameUsed();

    private:
        NODISCARD bool IsArgumentOutOfRange(double value) const noexcept;

    private:
        /// ��������Ϣ��
        CommandLineInformation commandLineInformation;

        /// �����ı߽��顣
        double small;  /// ��ֵ�������½� (min �� inf)
        double large;  /// ��ֵ�������Ͻ� (max �� sup)
        bool minSet;  /// ���Ϊ�棬�Ƚϣ�small <= arg
        bool maxSet;  /// ���Ϊ�棬�Ƚϣ�arg <= large
        bool infSet;  /// ���Ϊ�棬�Ƚϣ�small < arg
        bool supSet;  /// ���Ϊ�棬�Ƚϣ�arg < large
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_H
