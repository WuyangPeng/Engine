//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/13 20:17)

#ifndef CORE_TOOLS_FILE_MANAGER_OFSTREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_OFSTREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE OFStreamSeekManager final
    {
    public:
        using ClassType = OFStreamSeekManager;
        using MasterType = System::OFileStream;
        using MasterTypeReference = System::OFileStream&;

    public:
        explicit OFStreamSeekManager(MasterTypeReference master);
        ~OFStreamSeekManager() noexcept;

        OFStreamSeekManager(const OFStreamSeekManager&) = delete;
        OFStreamSeekManager operator=(const OFStreamSeekManager&) = delete;
        OFStreamSeekManager(OFStreamSeekManager&&) noexcept = delete;
        OFStreamSeekManager operator=(OFStreamSeekManager&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        using MasterPosType = MasterType::pos_type;

    private:
        [[nodiscard]] static MasterPosType GetErrorPosition();

    private:
        void SeekBeginPosition();

    private:
        MasterTypeReference m_Master;
        MasterPosType m_CurrentPosition;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_OFSTREAM_SEEK_MANAGER_H
