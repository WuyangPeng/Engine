///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 11:19)

#ifndef CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H
#define CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Command/CommandInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandArgumentFactory final
    {
    public:
        using ClassType = CommandArgumentFactory;
        using CommandArgumentSharedPtr = std::shared_ptr<CommandArgumentPackage>;

    public:
        NODISCARD static CommandArgumentSharedPtr Create(int index, const std::string& arguments, const std::string& value);
        NODISCARD static CommandArgumentSharedPtr Create(int index, const std::string& arguments);
    };
}

#endif  // CORE_TOOLS_COMMAND_COMMAND_ARGUMENT_FACTORY_H
