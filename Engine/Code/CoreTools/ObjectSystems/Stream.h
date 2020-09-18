//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.2 (2020/09/11 16:47)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Stream
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
