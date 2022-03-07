///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 11:29)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentFactory.h"
#include "CommandArgumentImpl.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentPackage : public CommandArgumentImpl
    {
    public:
        using ClassType = CommandArgumentPackage;
        using FactoryType = CommandArgumentFactory;

    public:
        CommandArgumentPackage(int index, const std::string& name);
        virtual ~CommandArgumentPackage() noexcept = default;
        CommandArgumentPackage(const CommandArgumentPackage& rhs) = default;
        CommandArgumentPackage& operator=(const CommandArgumentPackage& rhs) = default;
        CommandArgumentPackage(CommandArgumentPackage&& rhs) noexcept = default;
        CommandArgumentPackage& operator=(CommandArgumentPackage&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetIndex() const noexcept override;
        NODISCARD std::string GetName() const override;

        NODISCARD virtual int GetInteger() const = 0;
        NODISCARD virtual float GetFloat() const = 0;
        NODISCARD virtual double GetDouble() const = 0;
        NODISCARD virtual const std::string GetString() const = 0;

        NODISCARD virtual bool IsInteger() const noexcept = 0;
        NODISCARD virtual bool IsFloat() const noexcept = 0;
        NODISCARD virtual bool IsDouble() const noexcept = 0;
        NODISCARD virtual bool IsString() const noexcept = 0;
        NODISCARD virtual bool IsNoValue() const noexcept = 0;

        NODISCARD bool IsUsed() const noexcept override;
        void SetUsed() noexcept override;

        NODISCARD virtual CommandArgumentSharedPtr Clone() const = 0;

        virtual void AddArgumentValue(const std::string& value) = 0;

    private:
        int index;
        std::string name;
        bool used;  // 跟踪已处理的参数
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H
