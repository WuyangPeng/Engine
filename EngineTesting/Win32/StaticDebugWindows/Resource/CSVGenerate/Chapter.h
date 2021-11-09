/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_CHAPTER_H
#define C_S_V_CONFIGURE_CHAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "CSVConfigureFwd.h"
#include "ChapterBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace CSVConfigure
{
    class Chapter final : public ChapterBase
    {
    public:
        using ClassType = Chapter;
        using ParentType = ChapterBase;

    public:
        explicit Chapter(const CoreTools::CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetID() const noexcept override;

        NODISCARD int GetNextID() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD System::String GetChapterName() const override;

        NODISCARD bool IsMain() const noexcept override;

        NODISCARD CoreTools::Vector2 GetPosition() const noexcept override;

        NODISCARD CoreTools::IntVector4 GetPoint() const noexcept override;

    private:
        void Checking();

    private:
        int id;  // ID
        int nextID;  // ��һ��ID
        int reward;  // ���ؽ���
        System::String chapterName;  // �ؿ�����
        bool isMain;  // �Ƿ�����
        CoreTools::Vector2 position;  // λ��
        CoreTools::IntVector4 point;  // ��
    };
}

#endif  // C_S_V_CONFIGURE_CHAPTER_H
