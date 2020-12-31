//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/09/29 15:25)

#ifndef CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H
#define CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H

#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"

#define CORE_TOOLS_INIT_TERM_DECLARE             \
    [[nodiscard]] static bool RegisterFactory(); \
    static void InitializeFactory();             \
    static void TerminateFactory();

#define CORE_TOOLS_INIT_TERM_DEFINE(namespaceName, className)                                                        \
    bool namespaceName::className::RegisterFactory()                                                                 \
    {                                                                                                                \
        static InitTermRegisterFactory registerFactory{ ClassType::InitializeFactory, ClassType::TerminateFactory }; \
        return true;                                                                                                 \
    }

#define CORE_TOOLS_INIT_TERM_REGISTER(namespaceName, className)                                          \
    namespace namespaceName                                                                              \
    {                                                                                                    \
        const auto SYSTEM_MULTIPLE_CONCATENATOR(g_Registered, className) = className::RegisterFactory(); \
    }

#endif  // CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H
