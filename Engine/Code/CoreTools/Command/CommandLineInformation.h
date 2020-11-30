//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:56)

// ��������Ϣ��
#ifndef CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H
#define CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CommandLineInformationImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CommandLineInformation final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(CommandLineInformation);

    public:
        CommandLineInformation(int argumentsNumber, char** arguments);
        explicit CommandLineInformation(const char* commandLine);

        CLASS_INVARIANT_DECLARE;

        // ���ص�һ��δ������������֡�
        [[nodiscard]] const std::string ExcessArguments() const;
        [[nodiscard]] int GetExcessArgumentsCount() const noexcept;

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
        IMPL_TYPE_DECLARE(CommandLineInformation);
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H
