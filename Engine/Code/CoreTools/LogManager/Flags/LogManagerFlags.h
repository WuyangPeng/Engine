/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 13:52)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H

#include "System/Helper/EnumOperator.h"

namespace CoreTools
{
    enum class LogFilter
    {
        System = 0,  // ϵͳ
        CoreTools,  // ���Ĺ���
        Network,  // ����
        Database,  // ���ݿ�
        Script,  // �ű�
        Mathematics,  // ��ѧ
        SoundEffect,  // ��Ч
        InputOutput,  // �������
    	ResourceManager,  // ��Դ����
        Rendering,  // ��Ⱦ
        Physics,  // ����
        Imagics,  // ͼ�����
        Animation,  // ����
        ArtificialIntelligence,  // �˹�����
        UserInterface,  // ����
        AssistTools,  // ��������
        Framework,  // ���
        User,  // �û��Զ���
        MaxLogFilter
    };

    enum class LogLevel
    {
        Disabled = 0,  // ����
        Trace,  // ������Ϣ
        Debug,  // ������Ϣ
        Info,  // һ����Ϣ
        Warn,  // ������Ϣ
        Error,  // ������Ϣ
        Fatal,  // ����������Ϣ
        MaxLogLevels
    };

    enum class AppenderType
    {
        None = 0,
        Console,
        File,
        FileConfiguration,
    };

    enum class AppenderPrint
    {
        None = 0x00,
        PrefixTimestamp = 0x01,
        PrefixLogLevel = 0x02,
        PrefixLogFilterType = 0x04,
        PostfixFunctionDescribed = 0x08,

        All = PrefixTimestamp | PrefixLogLevel | PrefixLogFilterType | PostfixFunctionDescribed,
    };

    enum class LogAppenderIOManageSign
    {
        TriggerAssert,  // ��������
        AlwaysConsole,  // �������������̨
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MANAGER_FLAGS_H
