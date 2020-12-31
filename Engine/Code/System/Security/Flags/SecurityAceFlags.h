//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 14:09)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_FLAGS_H
#define SYSTEM_SECURITY_SECURITY_ACE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class ControlACEInheritance
    {
        ObjectInheritAce = OBJECT_INHERIT_ACE,
        ContainerInheritAce = CONTAINER_INHERIT_ACE,
        NoPropagateInheritAce = NO_PROPAGATE_INHERIT_ACE,
        InheritOnlyAce = INHERIT_ONLY_ACE,
        InheritedAce = INHERITED_ACE,
        ValidInheritFlags = VALID_INHERIT_FLAGS,
    };

    enum class MandatoryPolicy
    {
        LabelNoWriteUp = SYSTEM_MANDATORY_LABEL_NO_WRITE_UP,
        LabelNoReadUp = SYSTEM_MANDATORY_LABEL_NO_READ_UP,
        LabelNoExecuteUp = SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class ControlACEInheritance
    {
        ObjectInheritAce = (0x1),
        ContainerInheritAce = (0x2),
        NoPropagateInheritAce = (0x4),
        InheritOnlyAce = (0x8),
        InheritedAce = (0x10),
        ValidInheritFlags = (0x1F),
    };

    enum class MandatoryPolicy
    {
        LabelNoWriteUp = 0x1,
        LabelNoReadUp = 0x2,
        LabelNoExecuteUp = 0x4,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_ACE_FLAGS_H
