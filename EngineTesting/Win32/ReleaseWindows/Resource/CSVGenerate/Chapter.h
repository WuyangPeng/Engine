/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
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

        using CSVRow = CoreTools::CSVRow; 

    public:
        explicit Chapter(const CSVRow& csvRow);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD int GetKey() const noexcept override;

        NODISCARD int GetId() const noexcept override;

        NODISCARD int GetNextId() const noexcept override;

        NODISCARD int GetReward() const noexcept override;

        NODISCARD String GetChapterName() const override;

        NODISCARD bool IsMain() const noexcept override;

        NODISCARD CoreTools::Vector2 GetPosition() const noexcept override;

        NODISCARD CoreTools::IntVector4 GetPoint() const noexcept override;

    private:
        void Checking() const;

    private:
        int id;  // Id
        int nextId;  // ��һ��Id
        int reward;  // ���ؽ���
        String chapterName;  // �ؿ�����
        bool isMain;  // �Ƿ�����
        CoreTools::Vector2 position;  // λ��
        CoreTools::IntVector4 point;  // ��
    };
}

#endif  // C_S_V_CONFIGURE_CHAPTER_H
