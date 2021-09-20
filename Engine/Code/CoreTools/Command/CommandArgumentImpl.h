//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:48)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CommandArgumentFactory;

    class CORE_TOOLS_DEFAULT_DECLARE CommandArgumentImpl
    {
    public:
        using ClassType = CommandArgumentImpl;
        using CommandArgumentSharedPtr = std::shared_ptr<CommandArgumentImpl>;
        using FactoryType = CommandArgumentFactory;

    public:
        CommandArgumentImpl() noexcept = default;
        virtual ~CommandArgumentImpl() noexcept = default;
        CommandArgumentImpl(const CommandArgumentImpl& rhs) = default;
        CommandArgumentImpl& operator=(const CommandArgumentImpl& rhs) = default;
        CommandArgumentImpl(CommandArgumentImpl&& rhs) noexcept = default;
        CommandArgumentImpl& operator=(CommandArgumentImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_PURE_VIRTUAL_DECLARE;

        [[nodiscard]] virtual int GetIndex() const noexcept = 0;
        [[nodiscard]] virtual const std::string GetName() const = 0;

        [[nodiscard]] virtual int GetInteger() const = 0;
        [[nodiscard]] virtual float GetFloat() const = 0;
        [[nodiscard]] virtual double GetDouble() const = 0;
        [[nodiscard]] virtual const std::string GetString() const = 0;

        [[nodiscard]] virtual bool IsInteger() const noexcept = 0;
        [[nodiscard]] virtual bool IsFloat() const noexcept = 0;
        [[nodiscard]] virtual bool IsDouble() const noexcept = 0;
        [[nodiscard]] virtual bool IsString() const noexcept = 0;
        [[nodiscard]] virtual bool IsNoValue() const noexcept = 0;

        [[nodiscard]] virtual bool IsUsed() const noexcept = 0;
        virtual void SetUsed() noexcept = 0;

        [[nodiscard]] virtual CommandArgumentSharedPtr Clone() const = 0;

        virtual void AddArgumentValue(const std::string& value) = 0;
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_IMPL_H
