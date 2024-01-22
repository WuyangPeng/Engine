/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:14)

#ifndef CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H
#define CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H

#include "CoreTools/ObjectSystems/InitTermRegisterFactory.h"

#define CORE_TOOLS_INITIALIZE_TERMINATE_DECLARE(isExcept) \
    NODISCARD static bool RegisterFactory();              \
    static void InitializeFactory() noexcept(isExcept);   \
    static void TerminateFactory() noexcept(isExcept)

#define CORE_TOOLS_INITIALIZE_TERMINATE_DEFINE(namespaceName, className)                                                        \
    bool namespaceName::className::RegisterFactory()                                                                            \
    {                                                                                                                           \
        static CoreTools::InitTermRegisterFactory registerFactory{ ClassType::InitializeFactory, ClassType::TerminateFactory }; \
        return true;                                                                                                            \
    }

#define CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(className) \
    static auto SYSTEM_MULTIPLE_CONCATENATOR(g, className, StreamRegistered) = className::RegisterFactory()

#endif  // CORE_TOOLS_HELPER_INITIALIZE_TERMINATE_MACRO_H
