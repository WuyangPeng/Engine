/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/30 22:34)

#ifndef CORE_TOOLS_FILE_MANAGER_I_FILE_STREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_I_FILE_STREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <fstream>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE IFileStreamSeekManager final
    {
    public:
        using ClassType = IFileStreamSeekManager;

        using MasterType = System::IFileStream;
        using MasterTypeReference = System::IFileStream&;

    public:
        explicit IFileStreamSeekManager(MasterTypeReference master);
        ~IFileStreamSeekManager() noexcept;

        IFileStreamSeekManager(const IFileStreamSeekManager& rhs) = delete;
        IFileStreamSeekManager operator=(const IFileStreamSeekManager& rhs) = delete;
        IFileStreamSeekManager(IFileStreamSeekManager&& rhs) noexcept = delete;
        IFileStreamSeekManager operator=(IFileStreamSeekManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        using MasterPosType = MasterType::pos_type;

    private:
        void ResetPosition() noexcept;
        void SeekBeginPosition();

        NODISCARD static MasterPosType GetErrorPosition();

    private:
        MasterTypeReference master;
        MasterPosType currentPosition;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_I_FILE_STREAM_SEEK_MANAGER_H
