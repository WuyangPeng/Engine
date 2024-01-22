/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:01)

#include "CoreTools/CoreToolsExport.h"

#include "Stream.h"
#include "StreamSize.h"
#include "System/CharacterString/FormatString.h"

int CoreTools::Stream::GetStreamingSize(const char* input)
{
    const auto length = boost::numeric_cast<int>(System::StrLen(input));

    return GetStreamingSize(length);
}

int CoreTools::Stream::GetStreamingSize(int length) noexcept
{
    // ���ַ�����д�뵽���̣������ǳ��ȣ��������ַ�����û�а�������ֹ�ַ����������Ϊ�ĸ��ֽڵı�����
    const auto padding = GetPadding(length);

    return GetStreamSize<int32_t>() + length * GetStreamSize<char>() + padding;
}
