/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:27)

#ifndef SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_H
#define SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_H

#include "System/Helper/Platform.h"

///  MessageBox() 标志
namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class MessageBoxType
    {
        Ok = MB_OK,
        OkCancel = MB_OKCANCEL,
        AbortRetryIgnore = MB_ABORTRETRYIGNORE,
        YesNoCancel = MB_YESNOCANCEL,
        YesNo = MB_YESNO,
        RetryCancel = MB_RETRYCANCEL,
        CancelTryContinue = MB_CANCELTRYCONTINUE,
    };

    enum class MessageBoxIcon
    {
        NoIcon = 0x00000000L,
        Hand = MB_ICONHAND,
        Question = MB_ICONQUESTION,
        Exclamation = MB_ICONEXCLAMATION,
        Asterisk = MB_ICONASTERISK,
        UserIcon = MB_USERICON,
        Waning = MB_ICONWARNING,
        Error = MB_ICONERROR,
        Information = MB_ICONINFORMATION,
        Stop = MB_ICONSTOP,
    };

    enum class MessageBoxDefault
    {
        Button1 = MB_DEFBUTTON1,
        Button2 = MB_DEFBUTTON2,
        Button3 = MB_DEFBUTTON3,
        Button4 = MB_DEFBUTTON4,
    };

    enum class MessageBoxMode
    {
        ApplicationModal = MB_APPLMODAL,
        SystemModal = MB_SYSTEMMODAL,
        TaskModal = MB_TASKMODAL,
    };

    enum class MessageBoxMisc
    {
        NoMisc = 0x00000000L,

        Help = MB_HELP,
        NoFocus = MB_NOFOCUS,
        SetForeground = MB_SETFOREGROUND,
        DefaultDesktopOnly = MB_DEFAULT_DESKTOP_ONLY,
        TopMost = MB_TOPMOST,
        Right = MB_RIGHT,
        RightToLeftReading = MB_RTLREADING,
        ServiceNotification = MB_SERVICE_NOTIFICATION,  // 如果设置了此参数，则hWnd参数一定为nullptr。
        ServiceNotificationNt3X = MB_SERVICE_NOTIFICATION_NT3X,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class MessageBoxType
    {
        Ok = 0x00000000L,
        OkCancel = 0x00000001L,
        AbortRetryIgnore = 0x00000002L,
        YesNoCancel = 0x00000003L,
        YesNo = 0x00000004L,
        RetryCancel = 0x00000005L,
        CancelTryContinue = 0x00000006L,
    };

    enum class MessageBoxIcon
    {
        NoIcon = 0x00000000L,
        Hand = 0x00000010L,
        Question = 0x00000020L,
        Exclamation = 0x00000030L,
        Asterisk = 0x00000040L,
        UserIcon = 0x00000080L,
        Waning = Exclamation,
        Error = Hand,
        Information = Asterisk,
        Stop = Hand,
    };

    enum class MessageBoxDefault
    {
        Button1 = 0x00000000L,
        Button2 = 0x00000100L,
        Button3 = 0x00000200L,
        Button4 = 0x00000300L,
    };

    enum class MessageBoxMode
    {
        ApplicationModal = 0x00000000L,
        SystemModal = 0x00001000L,
        TaskModal = 0x00002000L,
    };

    enum class MessageBoxMisc
    {
        NoMisc = 0x00000000L,
        Help = 0x00004000L,
        NoFocus = 0x00008000L,
        SetForeground = 0x00010000L,
        DefaultDesktopOnly = 0x00020000L,
        TopMost = 0x00040000L,
        Right = 0x00080000L,
        RightToLeftReading = 0x00100000L,
        ServiceNotification = 0x00200000L,
        ServiceNotificationNt3X = 0x00040000L,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SYSTEM_OUTPUT_MESSAGE_BOX_FLAGS_H