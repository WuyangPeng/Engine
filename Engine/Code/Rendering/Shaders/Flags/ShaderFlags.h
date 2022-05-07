///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/11 13:39)

#ifndef RENDERING_SHADERS_SHADER_FLAGS_H
#define RENDERING_SHADERS_SHADER_FLAGS_H

namespace Rendering
{
    namespace ShaderFlags
    {
        // ö��������ɫ���ĸ��������

        // �����ļ�������������������ඥ������ض�ʹ�������Ŀ�������ļ���
        // ���������µ������ļ������Ĵ�ö�ٳ������޸������ࡣ
        enum class Profiles
        {
            MaxProfiles = 5
        };

        // ������ɫ�������ļ���Ϣ��
        enum class VertexShaderProfile
        {
            None,
            VS11,
            VS20,
            VS30,
            ARBVP1,
        };

        // ������ɫ�������ļ���Ϣ��
        enum class PixelShaderProfile
        {
            None,
            PS11,
            PS20,
            PS30,
            ARBFP1,
        };

        // �Ը������Թ��˵����ֵ��
        enum
        {
            MaxAnisotropy = 16
        };

        // ��ɫ������������������������͡�
        enum class VariableType
        {
            None,

            Float,
            Float1,
            Float2,
            Float3,
            Float4,
            Float1X1,
            Float1X2,
            Float1X3,
            Float1X4,
            Float2X1,
            Float2X2,
            Float2X3,
            Float2X4,
            Float3X1,
            Float3X2,
            Float3X3,
            Float3X4,
            Float4X1,
            Float4X2,
            Float4X3,
            Float4X4,

            Half,
            Half1,
            Half2,
            Half3,
            Half4,
            Half1X1,
            Half1X2,
            Half1X3,
            Half1X4,
            Half2X1,
            Half2X2,
            Half2X3,
            Half2X4,
            Half3X1,
            Half3X2,
            Half3X3,
            Half3X4,
            Half4X1,
            Half4X2,
            Half4X3,
            Half4X4,

            Int,
            Int1,
            Int2,
            Int3,
            Int4,
            Int1X1,
            Int1X2,
            Int1X3,
            Int1X4,
            Int2X1,
            Int2X2,
            Int2X3,
            Int2X4,
            Int3X1,
            Int3X2,
            Int3X3,
            Int3X4,
            Int4X1,
            Int4X2,
            Int4X3,
            Int4X4,

            Fixed,
            Fixed1,
            Fixed2,
            Fixed3,
            Fixed4,
            Fixed1X1,
            Fixed1X2,
            Fixed1X3,
            Fixed1X4,
            Fixed2X1,
            Fixed2X2,
            Fixed2X3,
            Fixed2X4,
            Fixed3X1,
            Fixed3X2,
            Fixed3X3,
            Fixed3X4,
            Fixed4X1,
            Fixed4X2,
            Fixed4X3,
            Fixed4X4,

            Bool,
            Bool1,
            Bool2,
            Bool3,
            Bool4,
            Bool1X1,
            Bool1X2,
            Bool1X3,
            Bool1X4,
            Bool2X1,
            Bool2X2,
            Bool2X3,
            Bool2X4,
            Bool3X1,
            Bool3X2,
            Bool3X3,
            Bool3X4,
            Bool4X1,
            Bool4X2,
            Bool4X3,
            Bool4X4,

            Quantity
        };

        // ��ɫ������������������������塣
        enum class VariableSemantic
        {
            None,
            Position,  // ����0
            BlendWeight,  // ����1
            Normal,  // ����2
            Color0,  // ����3 (��������ȾĿ��)
            Color1,  // ����4 (��������ȾĿ��)
            FogCoord,  // ����5
            PSize,  // ����6
            BlendIndices,  // ����7
            TextureCoord0,  // ����8
            TextureCoord1,  // ����9
            TextureCoord2,  // ����10
            TextureCoord3,  // ����11
            TextureCoord4,  // ����12
            TextureCoord5,  // ����13
            TextureCoord6,  // ����14
            TextureCoord7,  // ����15
            Fog,  // �� VS_FOGCOORD һ�� (����5)
            Tangent,  // �� VS_TexCoord6 һ��(����14)
            Binormal,  // �� VS_TexCoord7 һ�� (����15)
            Color2,  // ����ȾĿ��֧��
            Color3,  // ����ȾĿ��֧��
            Depth0,  // ����ȾĿ��֧��
            Quantity
        };

        // �������ͽ��ͷ��䵽��������
        enum class SamplerType
        {
            None,
            Sampler1D,
            Sampler2D,
            Sampler3D,
            SamplerCube,
            Quantity
        };

        // ����ģʽ�Ĳ�������
        enum class SamplerFilter
        {
            None,
            Nearest,  // ���� (Ĭ��)
            Linear,  // �����˲�
            NearestNearest,  // ͼ�������, ����ͼ�����
            NearesLinear,  // ͼ�������, ����ͼ������
            LinearNeares,  // ͼ���е�����, ����ͼ�����
            LinearLinear,  // ͼ���е�����, ����ͼ������
            Quantity
        };

        // ��������Ĳ���ģʽ��
        enum class SamplerCoordinate
        {
            None,
            Clamp,
            Repeat,
            MirroredRepeat,
            ClampBorder,
            ClampEdge,  // Ĭ��
            Quantity
        };
    }
}

#endif  // RENDERING_SHADERS_SHADER_FLAGS_H
