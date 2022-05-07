///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/11 13:39)

#ifndef RENDERING_SHADERS_SHADER_FLAGS_H
#define RENDERING_SHADERS_SHADER_FLAGS_H

namespace Rendering
{
    namespace ShaderFlags
    {
        // 枚举用于着色器的各种组件。

        // 配置文件的最大数量。在派生类顶点和像素都使用这个数目的配置文件。
        // 如果添加了新的配置文件，更改此枚举常数和修改派生类。
        enum class Profiles
        {
            MaxProfiles = 5
        };

        // 顶点着色器配置文件信息。
        enum class VertexShaderProfile
        {
            None,
            VS11,
            VS20,
            VS30,
            ARBVP1,
        };

        // 像素着色器配置文件信息。
        enum class PixelShaderProfile
        {
            None,
            PS11,
            PS20,
            PS30,
            ARBFP1,
        };

        // 对各向异性过滤的最大值。
        enum
        {
            MaxAnisotropy = 16
        };

        // 着色器程序的输入和输出变量的类型。
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

        // 着色器程序的输入和输出变量的语义。
        enum class VariableSemantic
        {
            None,
            Position,  // 属性0
            BlendWeight,  // 属性1
            Normal,  // 属性2
            Color0,  // 属性3 (和用于渲染目标)
            Color1,  // 属性4 (和用于渲染目标)
            FogCoord,  // 属性5
            PSize,  // 属性6
            BlendIndices,  // 属性7
            TextureCoord0,  // 属性8
            TextureCoord1,  // 属性9
            TextureCoord2,  // 属性10
            TextureCoord3,  // 属性11
            TextureCoord4,  // 属性12
            TextureCoord5,  // 属性13
            TextureCoord6,  // 属性14
            TextureCoord7,  // 属性15
            Fog,  // 与 VS_FOGCOORD 一样 (属性5)
            Tangent,  // 与 VS_TexCoord6 一样(属性14)
            Binormal,  // 与 VS_TexCoord7 一样 (属性15)
            Color2,  // 多渲染目标支持
            Color3,  // 多渲染目标支持
            Depth0,  // 多渲染目标支持
            Quantity
        };

        // 采样类型解释分配到采样纹理
        enum class SamplerType
        {
            None,
            Sampler1D,
            Sampler2D,
            Sampler3D,
            SamplerCube,
            Quantity
        };

        // 过滤模式的采样器。
        enum class SamplerFilter
        {
            None,
            Nearest,  // 近邻 (默认)
            Linear,  // 线性滤波
            NearestNearest,  // 图像中最近, 整个图像最近
            NearesLinear,  // 图像中最近, 整个图像线性
            LinearNeares,  // 图像中的线性, 整个图像最近
            LinearLinear,  // 图像中的线性, 整个图像线性
            Quantity
        };

        // 纹理坐标的采样模式。
        enum class SamplerCoordinate
        {
            None,
            Clamp,
            Repeat,
            MirroredRepeat,
            ClampBorder,
            ClampEdge,  // 默认
            Quantity
        };
    }
}

#endif  // RENDERING_SHADERS_SHADER_FLAGS_H
