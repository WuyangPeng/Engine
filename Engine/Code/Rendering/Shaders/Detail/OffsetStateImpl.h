///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:29)

#ifndef RENDERING_SHADERS_OFFSET_STATE_IMPL_H
#define RENDERING_SHADERS_OFFSET_STATE_IMPL_H

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OffsetStateImpl
    {
    public:
        using ClassType = OffsetStateImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        OffsetStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsFillEnabled() const noexcept;
        NODISCARD bool IsLineEnabled() const noexcept;
        NODISCARD bool IsPointEnabled() const noexcept;
        NODISCARD float GetScale() const noexcept;
        NODISCARD float GetBias() const noexcept;

        void SetFillEnabled(bool aFillEnabled) noexcept;
        void SetLineEnabled(bool aLineEnabled) noexcept;
        void SetPointEnabled(bool pointEnabled) noexcept;
        void SetScale(float aScale) noexcept;
        void SetBias(float bias) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        // �����Ƿ�Ӧ��Ϊ���ֶ���λ�ͼģʽ����䣬�ߣ��㣩����ƫ�ơ�
        bool fillEnabled;  // Ĭ��: false
        bool lineEnabled;  // Ĭ��: false
        bool pointEnabled;  // Ĭ��: false

        // ƫ������Scale * dZ + Bias * r��
        // ����DZ������ھ���Ļ�ռ�������ȵı仯��
        // r����С�ɷֱ���Ȳ��졣��ֵ��ʾ�ƶ�����νӽ��۾���
        float scale;  // Ĭ��: 0
        float bias;  // Ĭ��: 0
    };
}

#endif  // RENDERING_SHADERS_OFFSET_STATE_IMPL_H
