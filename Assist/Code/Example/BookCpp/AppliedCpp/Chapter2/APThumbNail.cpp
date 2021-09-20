///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/26 23:54)

#include "Example/BookCpp/AppliedCpp/AppliedCppExport.h"

#include "APThumbNail.h"
#include "Example/BookCpp/AppliedCpp/Helper/AppliedCppClassInvariantMacro.h"

#include <gsl/gsl_util>
#include <cstdio>
#include <memory>

// setw()操纵器
#include <iomanip>
#include <iostream>

///  简单的独立缩略图生成器程序

/// 标尺
///       1         2         3         4         5         6    6
///345678901234567890123456789012345678901234567890123456789012345

BookIntermediate::AppliedCpp::APThumbNail::APThumbNail() noexcept
{
    APPLIED_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookIntermediate::AppliedCpp, APThumbNail)

void BookIntermediate::AppliedCpp::APThumbNail::CreateThumbNail(const char* inputFile, const char* outputFile, int factor)
{
    APPLIED_CPP_CLASS_IS_VALID_9;

    // 验证参数
    if (inputFile == nullptr || outputFile == nullptr || factor <= 1)
    {
        throw Invalid();
    }

    // 读取原始图片
    ReadImage(inputFile);
    if (!image.IsImageValid())
    {
        throw Invalid();
    }

    // 创建我们的内部缩略图
    thumbNail = APImage(image.Width() / factor, image.Height() / factor);

    // 将apImage中的所有rangeErrors转换为我们的无效错误
    try
    {
        for (int y = 0; y < thumbNail.Height(); y++)
        {
            for (int x = 0; x < thumbNail.Width(); x++)
            {
                // 转换为图像坐标以找到平均值
                const unsigned char pixel = AveragePixels(x * factor, y * factor, factor);
                thumbNail.SetPixel(x, y, pixel);
            }
        }
    }
    catch (const APImage::RangeError&)
    {
        throw Invalid();
    }

    WriteImage(outputFile);
}

unsigned char BookIntermediate::AppliedCpp::APThumbNail::AveragePixels(int x0, int y0, int factor)
{
    int sum = 0;

    // 输入图像中的平均因数像素
    try
    {
        for (int y = 0; y < factor; y++)
        {
            for (int x = 0; x < factor; x++)
            {
                sum += image.GetPixel(x + x0, y + y0);
            }
        }
    }
    catch (const APImage::RangeError&)
    {
        throw Invalid();
    }

    // 这种转换是非常安全的

    return gsl::narrow_cast<unsigned char>(sum / (factor * factor));
}

void BookIntermediate::AppliedCpp::APThumbNail::ReadImage([[maybe_unused]] const char* inputFile)
{
    // 我们将在稍后讨论此步骤。 现在，仅假定从文件中读取图像并将其作为二维数据数组放置在图像中。
    // 以下代码将创建一个合成的64x64图像。

    image = APImage(64, 64);

    try
    {
        for (int y = 0; y < image.Height(); y++)
        {
            for (int x = 0; x < image.Width(); x++)
            {
                image.SetPixel(x, y, gsl::narrow_cast<unsigned char>(y % 255));
            }
        }
    }
    catch (const APImage::RangeError&)
    {
        throw Invalid();
    }
}

void BookIntermediate::AppliedCpp::APThumbNail::WriteImage([[maybe_unused]] const char* outputFile) const
{
    // 我们将在稍后讨论此步骤。 现在，仅假设缩略图图像已写入文件。
    // 以下代码将图像显示为十六进制值。
    APImage output = thumbNail;

    // 保存流的格式化状态
    const std::ios_base::fmtflags flags = std::cout.flags(std::cout.hex);
    const auto width = std::cout.width(2);

    for (int y = 0; y < output.Height(); y++)
    {
        for (int x = 0; x < output.Width(); x++)
        {
            // (int)确保我们显示为数字，而不是字符。
            std::cout << static_cast<int>(output.GetPixel(x, y)) << " ";
        }

        std::cout << std::endl;
    }

    std::cout.flags(flags);
    std::cout.width(width);
}
