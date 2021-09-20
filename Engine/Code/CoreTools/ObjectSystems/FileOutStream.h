//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/21 20:58)

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
        BufferOutStream m_BufferOutStream;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FILE_OUT_STREAM_H
