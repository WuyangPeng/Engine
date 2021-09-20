//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 16:43)

#include "CoreTools/CoreToolsExport.h"

#include "Stream.h"
#include "StreamSize.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

int CoreTools::Stream::GetStreamingSize(const string& input)
{
    // ���ַ�����д�뵽���̣������ǳ��ȣ��������ַ�����û�а�������ֹ�ַ����������Ϊ�ĸ��ֽڵı�����

    auto length = boost::numeric_cast<int>(input.size());
    const auto padding = GetPadding(length);

    return GetStreamSize<int>() + length * GetStreamSize<char>() + padding;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26497)
int CoreTools::Stream::GetPadding(int length) noexcept
{
    auto padding = 0;
    if (0 < length)
    {
        padding = (length % g_DefaultSize);
        if (0 < padding)
        {
            padding = g_DefaultSize - padding;
        }
    }

    return padding;
}
#include STSTEM_WARNING_POP