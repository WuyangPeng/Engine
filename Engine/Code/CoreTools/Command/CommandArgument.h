//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:55)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentImpl.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(CommandArgument, CommandArgumentImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CommandArgument final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(CommandArgument);

    public:
        CommandArgument(int index, const std::string& arguments, const std::string& value);
        CommandArgument(int index, const std::string& arguments);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetIndex() const noexcept;
        [[nodiscard]] const std::string GetName() const;

        [[nodiscard]] int GetInteger() const;
        [[nodiscard]] float GetFloat() const;
        [[nodiscard]] double GetDouble() const;
        [[nodiscard]] const std::string GetString() const;

        [[nodiscard]] bool IsInteger() const noexcept;
        [[nodiscard]] bool IsFloat() const noexcept;
        [[nodiscard]] bool IsDouble() const noexcept;
        [[nodiscard]] bool IsString() const noexcept;
        [[nodiscard]] bool IsNoValue() const noexcept;

        [[nodiscard]] bool IsUsed() const noexcept;
        void SetUsed();

        void AddEndArgumentValue(const std::string& value);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H
