///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/21 09:44)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H

#include "CoreTools/CoreToolsDll.h"

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

        NODISCARD int GetIndex() const noexcept;
        NODISCARD std::string GetName() const;

        NODISCARD int GetInteger() const;
        NODISCARD float GetFloat() const;
        NODISCARD double GetDouble() const;
        NODISCARD std::string GetString() const;

        NODISCARD bool IsInteger() const noexcept;
        NODISCARD bool IsFloat() const noexcept;
        NODISCARD bool IsDouble() const noexcept;
        NODISCARD bool IsString() const noexcept;
        NODISCARD bool IsNoValue() const noexcept;

        NODISCARD bool IsUsed() const noexcept;
        void SetUsed();

        void AddEndArgumentValue(const std::string& value);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_H
