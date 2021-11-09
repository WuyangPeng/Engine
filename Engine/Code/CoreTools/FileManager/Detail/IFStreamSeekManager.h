///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 14:14)

#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE IFStreamSeekManager final
    {
    public:
        using ClassType = IFStreamSeekManager;
        using MasterType = System::IFileStream;
        using MasterTypeReference = System::IFileStream&;

    public:
        explicit IFStreamSeekManager(MasterTypeReference master);
        ~IFStreamSeekManager() noexcept;

        IFStreamSeekManager(const IFStreamSeekManager& rhs) = delete;
        IFStreamSeekManager operator=(const IFStreamSeekManager& rhs) = delete;
        IFStreamSeekManager(IFStreamSeekManager&& rhs) noexcept = delete;
        IFStreamSeekManager operator=(IFStreamSeekManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        void ResetPosition() noexcept;
        void SeekBeginPosition();

    private:
        using MasterPosType = MasterType::pos_type;

    private:
        NODISCARD static MasterPosType GetErrorPosition();

    private:
        MasterTypeReference master;
        MasterPosType currentPosition;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H
