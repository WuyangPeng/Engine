/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:32)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Command/CommandInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentImpl
    {
    public:
        using ClassType = CommandArgumentImpl;

        using CommandArgumentSharedPtr = std::shared_ptr<CommandArgumentImpl>;
        using FactoryType = CommandArgumentFactory;

    public:
        CommandArgumentImpl() noexcept = default;
        virtual ~CommandArgumentImpl() noexcept = default;
        CommandArgumentImpl(const CommandArgumentImpl& rhs) noexcept = default;
        CommandArgumentImpl& operator=(const CommandArgumentImpl& rhs) noexcept = default;
        CommandArgumentImpl(CommandArgumentImpl&& rhs) noexcept = default;
        CommandArgumentImpl& operator=(CommandArgumentImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_PURE_VIRTUAL_DECLARE;

        NODISCARD virtual int GetIndex() const noexcept = 0;
        NODISCARD virtual std::string GetName() const = 0;

        NODISCARD virtual int GetInteger() const = 0;
        NODISCARD virtual float GetFloat() const = 0;
        NODISCARD virtual double GetDouble() const = 0;
        NODISCARD virtual std::string GetString() const = 0;

        NODISCARD virtual bool IsInteger() const noexcept = 0;
        NODISCARD virtual bool IsFloat() const noexcept = 0;
        NODISCARD virtual bool IsDouble() const noexcept = 0;
        NODISCARD virtual bool IsString() const noexcept = 0;
        NODISCARD virtual bool IsNoValue() const noexcept = 0;

        NODISCARD virtual bool IsUsed() const noexcept = 0;
        virtual void SetUsed() noexcept = 0;

        NODISCARD virtual CommandArgumentSharedPtr Clone() const = 0;

        virtual void AddArgumentValue(const std::string& value) = 0;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H
