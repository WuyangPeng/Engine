///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 16:05)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "BufferOutStream.h"
#include "ObjectSystemsFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    // дobjects��Ӳ���ļ����汾���ַ����ڶ������֮ǰ��������д�롣
    // ������ʧ��ʱ���׳�Error�쳣��

    class CORE_TOOLS_DEFAULT_DECLARE FileOutStream final
    {
    public:
        using ClassType = FileOutStream;
        using ClassShareType = CoreTools::NonCopyClasses;
        using String = System::String;

    public:
        explicit FileOutStream(const OutTopLevel& topLevel);
        ~FileOutStream() noexcept = default;
        FileOutStream(const FileOutStream& rhs) noexcept = delete;
        FileOutStream& operator=(const FileOutStream& rhs) noexcept = delete;
        FileOutStream(FileOutStream&& rhs) noexcept = delete;
        FileOutStream& operator=(FileOutStream&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        void Save(const String& fileName);

    private:
        // ������ͼд�뵽�������С�
        BufferOutStream bufferOutStream;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H
