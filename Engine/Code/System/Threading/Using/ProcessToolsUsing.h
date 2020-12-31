//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 14:35)

#ifndef SYSTEM_THREADING_PROCESS_TOOLS_USING_H
#define SYSTEM_THREADING_PROCESS_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using AsynchronousProcedureCallFunction = PAPCFUNC;
    using ProcessorNumber = PROCESSOR_NUMBER;
    using ProcessorNumberPtr = PPROCESSOR_NUMBER;

#else  // !SYSTEM_PLATFORM_WIN32

    using AsynchronousProcedureCallFunction = void (*)(WindowPtrULongPtr parameter);

    struct ProcessorNumber
    {
        uint16_t Group;
        uint8_t Number;
        uint8_t Reserved;
    };
    using ProcessorNumberPtr = ProcessorNumber*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_PROCESS_TOOLS_USING_H