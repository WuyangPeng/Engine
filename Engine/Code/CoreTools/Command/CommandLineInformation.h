///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/21 09:44)

#ifndef CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H
#define CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(CommandLineInformation, CommandLineInformationImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CommandLineInformation final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(CommandLineInformation);

    public:
        CommandLineInformation(int argumentsNumber, char** arguments);
        explicit CommandLineInformation(const char* commandLine);

        CLASS_INVARIANT_DECLARE;

        // 返回第一个未处理参数的名字。
        NODISCARD std::string ExcessArguments() const;
        NODISCARD int GetExcessArgumentsCount() const noexcept;

        // 返回存在的选项
        NODISCARD bool GetBoolean(const std::string& name) const;

        NODISCARD int GetInteger(const std::string& name) const;
        NODISCARD float GetFloat(const std::string& name) const;
        NODISCARD double GetDouble(const std::string& name) const;
        NODISCARD std::string GetString(const std::string& name) const;
        NODISCARD std::string GetFileName() const;

        void SetUsed(const std::string& argumentsName);
        void SetFileNameUsed();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_LINE_INFORMATION_H
