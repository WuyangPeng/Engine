///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:38)

#ifndef SYSTEM_SECURITY_ACCESS_CHECK_FLAGS_H
#define SYSTEM_SECURITY_ACCESS_CHECK_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class AccessGenericMask
    {
        FileAllAccess = FILE_ALL_ACCESS,
        FileGenericRead = FILE_GENERIC_READ,
        FileGenericWrite = FILE_GENERIC_WRITE,
        FileGenericExecute = FILE_GENERIC_EXECUTE,

        TransactionManagerGenericRead = TRANSACTIONMANAGER_GENERIC_READ,
        TransactionManagerGenericWrite = TRANSACTIONMANAGER_GENERIC_WRITE,
        TransactionManagerGenericExecute = TRANSACTIONMANAGER_GENERIC_EXECUTE,
        TransactionManagerAllAccess = TRANSACTIONMANAGER_ALL_ACCESS,

        TransactionGenericRead = TRANSACTION_GENERIC_READ,
        TransactionGenericWrite = TRANSACTION_GENERIC_WRITE,
        TransactionGenericExecute = TRANSACTION_GENERIC_EXECUTE,
        TransactionAllAccess = TRANSACTION_ALL_ACCESS,

        ResourceManagerGenericRead = RESOURCEMANAGER_GENERIC_READ,
        ResourceManagerGenericWrite = RESOURCEMANAGER_GENERIC_WRITE,
        ResourceManagerGenericExecute = RESOURCEMANAGER_GENERIC_EXECUTE,
        ResourceManagerAllAccess = RESOURCEMANAGER_ALL_ACCESS,

        EnlistmentGenericRead = ENLISTMENT_GENERIC_READ,
        EnlistmentGenericWrite = ENLISTMENT_GENERIC_WRITE,
        EnlistmentGenericExecute = ENLISTMENT_GENERIC_EXECUTE,
        EnlistmentAllAccess = ENLISTMENT_ALL_ACCESS,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class AccessGenericMask
    {
        FileAllAccess = ((0x000F0000L) | (0x00100000L) | 0x1FF),
        FileGenericRead = ((0x00020000L) | (0x0001) | (0x0080) | (0x0008) | (0x00100000L)),
        FileGenericWrite = ((0x00020000L) | (0x0002) | (0x0100) | (0x0010) | (0x0004) | (0x00100000L)),
        FileGenericExecute = ((0x00020000L) | (0x0080) | (0x0020) | (0x00100000L)),

        TransactionManagerGenericRead = ((0x00020000L) | (0x0001)),
        TransactionManagerGenericWrite = ((0x00020000L) | (0x0002) | (0x0004) | (0x0008) | (0x0010)),
        TransactionManagerGenericExecute = ((0x00020000L)),
        TransactionManagerAllAccess = ((0x000F0000L) | TransactionManagerGenericRead | TransactionManagerGenericWrite | TransactionManagerGenericExecute | (0x0020)),

        TransactionGenericRead = ((0x00020000L) | (0x0001) | (0x00100000L)),
        TransactionGenericWrite = ((0x00020000L) | (0x0002) | (0x0008) | (0x0004) | (0x0010) | (0x0020) | (0x00100000L)),
        TransactionGenericExecute = ((0x00020000L) | (0x0008) | (0x0010) | (0x00100000L)),
        TransactionAllAccess = ((0x000F0000L) | TransactionGenericRead | TransactionGenericWrite | TransactionGenericExecute),

        ResourceManagerGenericRead = ((0x00020000L) | (0x0001) | (0x00100000L)),
        ResourceManagerGenericWrite = ((0x00020000L) | (0x0002) | (0x0004) | (0x0008) | (0x0010) | (0x0020) | (0x0040) | (0x00100000L)),
        ResourceManagerGenericExecute = ((0x00020000L) | (0x0004) | (0x0008) | (0x0010) | (0x0040) | (0x00100000L)),
        ResourceManagerAllAccess = ((0x000F0000L) | ResourceManagerGenericRead | ResourceManagerGenericWrite | ResourceManagerGenericExecute),

        EnlistmentGenericRead = ((0x00020000L) | (0x0001)),
        EnlistmentGenericWrite = ((0x00020000L) | (0x0002) | (0x0004) | (0x0008) | (0x0010)),
        EnlistmentGenericExecute = ((0x00020000L) | (0x0004) | (0x0008) | (0x0010)),
        EnlistmentAllAccess = ((0x000F0000L) | EnlistmentGenericRead | EnlistmentGenericWrite | EnlistmentGenericExecute),
    };

#endif  // SYSTEM_PLATFORM_WIN32

    ENUM_ORABLE_OPERATOR_DEFINE(AccessGenericMask);
}

#endif  // SYSTEM_SECURITY_ACCESS_CHECK_FLAGS_H
