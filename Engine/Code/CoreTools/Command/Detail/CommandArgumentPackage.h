//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:48)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H

#include "CoreTools/CoreToolsDll.h"

#include "CommandArgumentFactory.h"

#include "../CommandArgumentImpl.h"
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

        [[nodiscard]] int GetIndex() const noexcept override;
        [[nodiscard]] const std::string GetName() const override;

        [[nodiscard]] virtual int GetInteger() const = 0;
        [[nodiscard]] virtual float GetFloat() const = 0;
        [[nodiscard]] virtual double GetDouble() const = 0;
        [[nodiscard]] virtual const std::string GetString() const = 0;

        [[nodiscard]] virtual bool IsInteger() const noexcept = 0;
        [[nodiscard]] virtual bool IsFloat() const noexcept = 0;
        [[nodiscard]] virtual bool IsDouble() const noexcept = 0;
        [[nodiscard]] virtual bool IsString() const noexcept = 0;
        [[nodiscard]] virtual bool IsNoValue() const noexcept = 0;

        [[nodiscard]] bool IsUsed() const noexcept override;
        void SetUsed() noexcept override;

        [[nodiscard]] virtual CommandArgumentSharedPtr Clone() const = 0;

        virtual void AddArgumentValue(const std::string& value) = 0;

    private:
        int m_Index;
        std::string m_Name;
        bool m_Used;  // 跟踪已处理的参数
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_PACKAGE_H
