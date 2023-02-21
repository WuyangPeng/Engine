///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.2 (2023/02/12 16:07)

#ifndef CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H
#define CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H

#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"

#define CORE_TOOLS_INITIALIZE_TERMINATE_DECLARE(isExcept) \
    NODISCARD static bool RegisterFactory();              \
    static void InitializeFactory() noexcept(isExcept);   \
    static void TerminateFactory() noexcept(isExcept);

#define CORE_TOOLS_INITIALIZE_TERMINATE_DEFINE(namespaceName, className)                                                        \
    bool namespaceName::className::RegisterFactory()                                                                            \
    {                                                                                                                           \
        static CoreTools::InitTermRegisterFactory registerFactory{ ClassType::InitializeFactory, ClassType::TerminateFactory }; \
        return true;                                                                                                            \
    }

#define CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(className) \
    static auto SYSTEM_MULTIPLE_CONCATENATOR(g, className, StreamRegistered) = className::RegisterFactory()

#endif  // CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H
