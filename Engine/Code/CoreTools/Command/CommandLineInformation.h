//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:56)

// 命令行信息。
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

        // 返回第一个未处理参数的名字。
        [[nodiscard]] const std::string ExcessArguments() const;
        [[nodiscard]] int GetExcessArgumentsCount() const noexcept;

        // 返回存在的选项
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
