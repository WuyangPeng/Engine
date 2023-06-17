///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:07)

#ifndef RENDERING_SCENE_GRAPH_MATERIAL_IMPL_H
#define RENDERING_SCENE_GRAPH_MATERIAL_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Colour.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE MaterialImpl
    {
    public:
        using ClassType = MaterialImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using Colour = Colour<float>;

    public:
        MaterialImpl() noexcept;
        MaterialImpl(const Colour& emissive, const Colour& ambient, const Colour& diffuse, const Colour& specular) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD Colour GetEmissive() const noexcept;
        NODISCARD Colour GetAmbient() const noexcept;
        NODISCARD Colour GetDiffuse() const noexcept;
        NODISCARD Colour GetSpecular() const noexcept;

        void SetEmissive(const Colour& aEmissive) noexcept;
        void SetAmbient(const Colour& aAmbient) noexcept;
        void SetDiffuse(const Colour& aDiffuse) noexcept;
        void SetSpecular(const Colour& aSpecular) noexcept;

        NODISCARD float GetAlpha() const noexcept;
        NODISCARD float GetSpecularExponent() const noexcept;

    private:
        Colour emissive;  // Ĭ��: (0,0,0,1)
        Colour ambient;  // Ĭ��: (0,0,0,1)

        // ���ϵ�alphaʹ��m_Diffuse��alphaͨ��
        Colour diffuse;  // Ĭ��: (0,0,0,1)

        // ���ϵľ���ָ��ʹ��m_Specular��alphaͨ��
        Colour specular;  // Ĭ��: (0,0,0,0)
    };
}

#endif  // RENDERING_SCENE_GRAPH_MATERIAL_IMPL_H
