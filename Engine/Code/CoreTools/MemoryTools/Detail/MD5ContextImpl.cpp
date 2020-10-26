//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/19 19:30)

#include "CoreTools/CoreToolsExport.h"

#include "MD5ContextImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/FileManager/Endian.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/Flags/MD5ContextStatus.h"

constexpr auto g_Buffer0 = 0x67452301;
constexpr auto g_Buffer1 = 0xefcdab89;
constexpr auto g_Buffer2 = 0x98badcfe;
constexpr auto g_Buffer3 = 0x10325476;

CoreTools::MD5ContextImpl::MD5ContextImpl() noexcept
    : m_Buffer{ g_Buffer0, g_Buffer1, g_Buffer2, g_Buffer3 }, m_LowBits{ 0 }, m_HighBits{ 0 }, m_In{}, m_Source{ nullptr }, m_Length{ 0 }, m_Status{ MD5ContextStatus::Init }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MD5ContextImpl::IsValid() const noexcept
{
    if (m_Source == nullptr && m_Length == 0)
        return true;
    else if (m_Source != nullptr && m_Length != 0)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

// 开始MD5累积器。设置计数为0和缓冲区初始化为神秘的常量。
void CoreTools::MD5ContextImpl::MD5Init()
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_2(m_Status != MD5ContextStatus::Update, "MD5计算未完成！");

    m_Buffer = BufferType{ g_Buffer0, g_Buffer1, g_Buffer2, g_Buffer3 };

    m_LowBits = 0;
    m_HighBits = 0;

    m_In.fill(0);

    m_Source = nullptr;
    m_Length = 0;
    m_Status = MD5ContextStatus::Init;
}

// 更新环境体现另一个缓冲区满字节的拼接。
void CoreTools::MD5ContextImpl::MD5Update(uint8_t const* buffer, uint32_t length) noexcept(g_Assert < 2 || g_CoreToolsAssert < 2)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_2(m_Status == MD5ContextStatus::Update || m_Status == MD5ContextStatus::Init, "MD5状态错误！");

    m_Status = MD5ContextStatus::Update;

    m_Source = buffer;
    m_Length = length;

    // 更新位计数
    const auto originalLength = UpdateBitCount();

    // 处理任何导致奇数大小的块
    if (HandleOddSizedChunks(originalLength))
    {
        // 在64字节的块里处理数据
        ProcessDataIn64Byte();

        // 处理数据的任何剩余字节
        System::MemoryCopy(m_In.data(), m_Source, m_Length);
    }
}

// private
uint32_t CoreTools::MD5ContextImpl::UpdateBitCount() noexcept
{
    // 计算出信息位长，结果存储在m_LowBits和m_HighBits中。
    const auto originalLowBits = m_LowBits;
    m_LowBits += (m_Length << 3);
    if (m_LowBits < (static_cast<uint64_t>(m_Length) << 3))
    {
        // 进位
        ++m_HighBits;
    }

    m_HighBits += m_Length >> 29;

    // 返回上一个未处理完的缓冲区的长度。
    // 计算长度模64
    return (originalLowBits >> 3) & 0x3f;
}

// private
bool CoreTools::MD5ContextImpl::HandleOddSizedChunks(uint32_t originalLength) noexcept
{
    if (originalLength != 0)
    {
        // 上一个缓冲区还有未处理完的数据
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
        auto original = reinterpret_cast<uint8_t*>(m_In.data()) + originalLength;
#include STSTEM_WARNING_POP

        const auto remainLength = sm_DealBufferByte - originalLength;
        if (m_Length < remainLength)
        {
            // 这个缓冲区还是没有填满数据，直接返回。
            System::MemoryCopy(original, m_Source, m_Length);
            return false;
        }

        // 这个缓冲区填充完毕。
        System::MemoryCopy(original, m_Source, remainLength);

        InByteReverse();
        MD5Transform();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        m_Source += remainLength;
#include STSTEM_WARNING_POP

        m_Length -= remainLength;
    }

    return true;
}

// private
void CoreTools::MD5ContextImpl::ProcessDataIn64Byte() noexcept
{
    while (sm_DealBufferByte <= m_Length)
    {
        System::MemoryCopy(m_In.data(), m_Source, sm_DealBufferByte);

        InByteReverse();
        MD5Transform();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
        m_Source += sm_DealBufferByte;
#include STSTEM_WARNING_POP

        m_Length -= sm_DealBufferByte;
    }
}

// private
void CoreTools::MD5ContextImpl::InByteReverse() noexcept
{
#ifdef SYSTEM_BIG_ENDIAN
    Endian::SwapByteOrder(4, sm_DealBufferByte / 4, m_In.data());
#endif  // SYSTEM_BIG_ENDIAN
}

// private
void CoreTools::MD5ContextImpl::BufferByteReverse() noexcept
{
#ifdef SYSTEM_BIG_ENDIAN
    Endian::SwapByteOrder(4, 1, m_Buffer.data());
#endif  // SYSTEM_BIG_ENDIAN
}

// private
void CoreTools::MD5ContextImpl::MD5Transform() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto a = m_Buffer[0];
    auto b = m_Buffer[1];
    auto c = m_Buffer[2];
    auto d = m_Buffer[3];

    MD5Step(CoreFunction1, a, b, c, d, m_In[0] + 0xd76aa478, 7);
    MD5Step(CoreFunction1, d, a, b, c, m_In[1] + 0xe8c7b756, 12);
    MD5Step(CoreFunction1, c, d, a, b, m_In[2] + 0x242070db, 17);
    MD5Step(CoreFunction1, b, c, d, a, m_In[3] + 0xc1bdceee, 22);
    MD5Step(CoreFunction1, a, b, c, d, m_In[4] + 0xf57c0faf, 7);
    MD5Step(CoreFunction1, d, a, b, c, m_In[5] + 0x4787c62a, 12);
    MD5Step(CoreFunction1, c, d, a, b, m_In[6] + 0xa8304613, 17);
    MD5Step(CoreFunction1, b, c, d, a, m_In[7] + 0xfd469501, 22);
    MD5Step(CoreFunction1, a, b, c, d, m_In[8] + 0x698098d8, 7);
    MD5Step(CoreFunction1, d, a, b, c, m_In[9] + 0x8b44f7af, 12);
    MD5Step(CoreFunction1, c, d, a, b, m_In[10] + 0xffff5bb1, 17);
    MD5Step(CoreFunction1, b, c, d, a, m_In[11] + 0x895cd7be, 22);
    MD5Step(CoreFunction1, a, b, c, d, m_In[12] + 0x6b901122, 7);
    MD5Step(CoreFunction1, d, a, b, c, m_In[13] + 0xfd987193, 12);
    MD5Step(CoreFunction1, c, d, a, b, m_In[14] + 0xa679438e, 17);
    MD5Step(CoreFunction1, b, c, d, a, m_In[15] + 0x49b40821, 22);

    MD5Step(CoreFunction2, a, b, c, d, m_In[1] + 0xf61e2562, 5);
    MD5Step(CoreFunction2, d, a, b, c, m_In[6] + 0xc040b340, 9);
    MD5Step(CoreFunction2, c, d, a, b, m_In[11] + 0x265e5a51, 14);
    MD5Step(CoreFunction2, b, c, d, a, m_In[0] + 0xe9b6c7aa, 20);
    MD5Step(CoreFunction2, a, b, c, d, m_In[5] + 0xd62f105d, 5);
    MD5Step(CoreFunction2, d, a, b, c, m_In[10] + 0x02441453, 9);
    MD5Step(CoreFunction2, c, d, a, b, m_In[15] + 0xd8a1e681, 14);
    MD5Step(CoreFunction2, b, c, d, a, m_In[4] + 0xe7d3fbc8, 20);
    MD5Step(CoreFunction2, a, b, c, d, m_In[9] + 0x21e1cde6, 5);
    MD5Step(CoreFunction2, d, a, b, c, m_In[14] + 0xc33707d6, 9);
    MD5Step(CoreFunction2, c, d, a, b, m_In[3] + 0xf4d50d87, 14);
    MD5Step(CoreFunction2, b, c, d, a, m_In[8] + 0x455a14ed, 20);
    MD5Step(CoreFunction2, a, b, c, d, m_In[13] + 0xa9e3e905, 5);
    MD5Step(CoreFunction2, d, a, b, c, m_In[2] + 0xfcefa3f8, 9);
    MD5Step(CoreFunction2, c, d, a, b, m_In[7] + 0x676f02d9, 14);
    MD5Step(CoreFunction2, b, c, d, a, m_In[12] + 0x8d2a4c8a, 20);

    MD5Step(CoreFunction3, a, b, c, d, m_In[5] + 0xfffa3942, 4);
    MD5Step(CoreFunction3, d, a, b, c, m_In[8] + 0x8771f681, 11);
    MD5Step(CoreFunction3, c, d, a, b, m_In[11] + 0x6d9d6122, 16);
    MD5Step(CoreFunction3, b, c, d, a, m_In[14] + 0xfde5380c, 23);
    MD5Step(CoreFunction3, a, b, c, d, m_In[1] + 0xa4beea44, 4);
    MD5Step(CoreFunction3, d, a, b, c, m_In[4] + 0x4bdecfa9, 11);
    MD5Step(CoreFunction3, c, d, a, b, m_In[7] + 0xf6bb4b60, 16);
    MD5Step(CoreFunction3, b, c, d, a, m_In[10] + 0xbebfbc70, 23);
    MD5Step(CoreFunction3, a, b, c, d, m_In[13] + 0x289b7ec6, 4);
    MD5Step(CoreFunction3, d, a, b, c, m_In[0] + 0xeaa127fa, 11);
    MD5Step(CoreFunction3, c, d, a, b, m_In[3] + 0xd4ef3085, 16);
    MD5Step(CoreFunction3, b, c, d, a, m_In[6] + 0x04881d05, 23);
    MD5Step(CoreFunction3, a, b, c, d, m_In[9] + 0xd9d4d039, 4);
    MD5Step(CoreFunction3, d, a, b, c, m_In[12] + 0xe6db99e5, 11);
    MD5Step(CoreFunction3, c, d, a, b, m_In[15] + 0x1fa27cf8, 16);
    MD5Step(CoreFunction3, b, c, d, a, m_In[2] + 0xc4ac5665, 23);

    MD5Step(CoreFunction4, a, b, c, d, m_In[0] + 0xf4292244, 6);
    MD5Step(CoreFunction4, d, a, b, c, m_In[7] + 0x432aff97, 10);
    MD5Step(CoreFunction4, c, d, a, b, m_In[14] + 0xab9423a7, 15);
    MD5Step(CoreFunction4, b, c, d, a, m_In[5] + 0xfc93a039, 21);
    MD5Step(CoreFunction4, a, b, c, d, m_In[12] + 0x655b59c3, 6);
    MD5Step(CoreFunction4, d, a, b, c, m_In[3] + 0x8f0ccc92, 10);
    MD5Step(CoreFunction4, c, d, a, b, m_In[10] + 0xffeff47d, 15);
    MD5Step(CoreFunction4, b, c, d, a, m_In[1] + 0x85845dd1, 21);
    MD5Step(CoreFunction4, a, b, c, d, m_In[8] + 0x6fa87e4f, 6);
    MD5Step(CoreFunction4, d, a, b, c, m_In[15] + 0xfe2ce6e0, 10);
    MD5Step(CoreFunction4, c, d, a, b, m_In[6] + 0xa3014314, 15);
    MD5Step(CoreFunction4, b, c, d, a, m_In[13] + 0x4e0811a1, 21);
    MD5Step(CoreFunction4, a, b, c, d, m_In[4] + 0xf7537e82, 6);
    MD5Step(CoreFunction4, d, a, b, c, m_In[11] + 0xbd3af235, 10);
    MD5Step(CoreFunction4, c, d, a, b, m_In[2] + 0x2ad7d2bb, 15);
    MD5Step(CoreFunction4, b, c, d, a, m_In[9] + 0xeb86d391, 21);

    m_Buffer[0] += a;
    m_Buffer[1] += b;
    m_Buffer[2] += c;
    m_Buffer[3] += d;
#include STSTEM_WARNING_POP
}

// private
void CoreTools::MD5ContextImpl::MD5Step(CoreFunction function, uint32_t& w, uint32_t x, uint32_t y, uint32_t z, uint32_t data, uint32_t s) noexcept
{
    if (function != nullptr)
    {
        w += function(x, y, z) + data;
        w = (w << s) | (w >> (32 - s));
        w += x;
    }
}

void CoreTools::MD5ContextImpl::MD5Final(uint8_t* digest)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
    CORE_TOOLS_ASSERTION_0(digest != nullptr, "传入的缓冲区为空！");
    CORE_TOOLS_ASSERTION_2(m_Status == MD5ContextStatus::Update, "MD5计算状态错误！");

    // 计算字节数模64
    auto count = (m_LowBits >> 3) & 0x3F;

    // 第一个字符填充设置为0x80。这是安全的,因为至少有一个字节是可用的。
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
    auto ptr = reinterpret_cast<uint8_t*>(m_In.data()) + count;
    *ptr++ = 0x80;
#include STSTEM_WARNING_POP

    // 以64字节计算需要填充的字节。
    count = sm_DealBufferByte - 1 - count;

    if (count < 8)
    {
        // 填充必须进行
        System::MemorySet(ptr, 0, count);

        InByteReverse();
        MD5Transform();

        System::MemorySet(m_In.data(), 0, 56);
    }
    else
    {
        System::MemorySet(ptr, 0, count - 8);
    }

    InByteReverse();

    // 附加长度在最后两个位
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_In[14] = m_LowBits;
    m_In[15] = m_HighBits;
#include STSTEM_WARNING_POP

    MD5Transform();
    BufferByteReverse();

    System::MemoryCopy(digest, m_Buffer.data(), 16);

    m_Status = MD5ContextStatus::Final;

    MD5Init();
}
