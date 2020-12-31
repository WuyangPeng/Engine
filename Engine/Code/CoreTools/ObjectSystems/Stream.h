//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/22 11:36)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Stream final
    {
    public:
        using ClassType = Stream;

    public:
        // ����������ش洢�ַ���������ֽ������ַ�������������Ϊһ��int32���洢��������������ַ���
        // ���ַ���������䣬ʹ�ܴ洢��ʹ���ĸ��ֽڵı�����
        [[nodiscard]] static int GetStreamingSize(const std::string& input);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
