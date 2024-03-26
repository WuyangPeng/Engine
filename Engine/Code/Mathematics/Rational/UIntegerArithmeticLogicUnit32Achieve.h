/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 19:36)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_ACHIEVE_H
#define MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_ACHIEVE_H

#include "UIntegerArithmeticLogicUnit32.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/BitHacks.h"

template <typename UInteger>
Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::UIntegerArithmeticLogicUnit32() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename UInteger>
bool Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename UInteger>
bool Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::operator==(const UInteger& number) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto& self = GetSelf();
    const auto numBits = self.GetNumBits();
    if (numBits != number.GetNumBits())
    {
        return false;
    }

    if (0 < numBits)
    {
        const auto& bits = self.GetBits();
        const auto& numberBits = number.GetBits();
        const auto last = self.GetSize() - 1;
        for (auto i = last; 0 <= i; --i)
        {
            if (bits.at(i) != numberBits.at(i))
            {
                return false;
            }
        }
    }
    return true;
}

template <typename UInteger>
bool Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::operator!=(const UInteger& number) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !operator==(number);
}

template <typename UInteger>
bool Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::operator<(const UInteger& number) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto& self = GetSelf();
    const auto numberNumBits = number.GetNumBits();
    const auto& numberBits = number.GetBits();

    const auto numBits = self.GetNumBits();
    if (0 < numBits && 0 < numberNumBits)
    {
        /// 必须将这些数字进行比较，就好像它们彼此左对齐一样。
        /// 我们之所以来到这里，是因为我们的self = 1.u * 2^p 和 number = 1.v * 2^p。
        /// 尽管它们具有相同的指数，但有可能'self < number'但'numBits(1u) > numBits(1v)'。
        /// 一次比较一个32位块的位。
        const auto& bits = self.GetBits();
        const auto bitIndex0 = numBits - 1;
        const auto bitIndex1 = numberNumBits - 1;
        auto block0 = bitIndex0 / 32;
        auto block1 = bitIndex1 / 32;
        const auto numBlockBits0 = 1 + (bitIndex0 % 32);
        const auto numBlockBits1 = 1 + (bitIndex1 % 32);
        auto n0Shift = bits.at(block0);
        auto n1Shift = numberBits.at(block1);
        while (0 <= block0 && 0 <= block1)
        {
            /// 将前导块中的位移位到高阶位。
            auto value0 = boost::numeric_cast<uint32_t>((static_cast<uint64_t>(n0Shift) << (32 - numBlockBits0)) & 0x00000000FFFFFFFFull);
            auto value1 = boost::numeric_cast<uint32_t>((static_cast<uint64_t>(n1Shift) << (32 - numBlockBits1)) & 0x00000000FFFFFFFFull);

            /// 移位下一个块中的位（如果有）以填充当前块。
            if (0 <= --block0)
            {
                n0Shift = bits.at(block0);
                value0 |= boost::numeric_cast<uint32_t>((n0Shift >> numBlockBits0) & 0x00000000FFFFFFFFull);
            }
            if (0 <= --block1)
            {
                n1Shift = numberBits.at(block1);
                value1 |= boost::numeric_cast<uint32_t>((n1Shift >> numBlockBits1) & 0x00000000FFFFFFFFull);
            }
            if (value0 < value1)
            {
                return true;
            }
            if (value1 < value0)
            {
                return false;
            }
        }
        return block0 < block1;
    }
    else
    {
        /// 一个或两个数字都为零。
        /// 只有当'number'为正数时，'less than'才是“true”。
        return numberNumBits > 0;
    }
}

template <typename UInteger>
bool Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::operator<=(const UInteger& number) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return operator<(number) || operator==(number);
}

template <typename UInteger>
bool Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::operator>(const UInteger& number) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !operator<=(number);
}

template <typename UInteger>
bool Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::operator>=(const UInteger& number) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return !operator<(number);
}

template <typename UInteger>
void Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::Add(const UInteger& n0, const UInteger& n1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto& self = GetSelf();
    const auto n0NumBits = n0.GetNumBits();
    const auto n1NumBits = n1.GetNumBits();

    /// 将被视为正整数的数字相加。
    /// 如果没有执行，则将最后一个块设置为零。
    auto numBits = std::max(n0NumBits, n1NumBits) + 1;
    self.SetNumBits(numBits);
    self.SetBack(0);

    /// 获取输入数组的大小。
    const auto numElements0 = n0.GetSize();
    const auto numElements1 = n1.GetSize();

    /// 对输入进行排序，使第一个具有最多的块。
    const auto& u0 = (numElements1 <= numElements0 ? n0.GetBits() : n1.GetBits());
    const auto& u1 = (numElements1 <= numElements0 ? n1.GetBits() : n0.GetBits());
    const auto numElements = std::minmax(numElements0, numElements1);

    /// 将u1块添加到u0块。
    auto& bits = self.GetBits();
    auto carry = 0ull;

    auto i = 0;
    for (; i < numElements.first; ++i)
    {
        const auto sum = u0.at(i) + (u1.at(i) + carry);
        bits.at(i) = boost::numeric_cast<uint32_t>(sum & 0x00000000FFFFFFFFull);
        carry = (sum >> 32);
    }

    /// 我们没有更多的u1块。
    /// 传播执行（如果有），或复制剩余块（如果没有）。
    if (0 < carry)
    {
        for (; i < numElements.second; ++i)
        {
            const auto sum = u0.at(i) + carry;
            bits.at(i) = boost::numeric_cast<uint32_t>(sum & 0x00000000FFFFFFFFull);
            carry = (sum >> 32);
        }
        if (0 < carry)
        {
            bits.at(i) = boost::numeric_cast<uint32_t>(carry & 0x00000000FFFFFFFFull);
        }
    }
    else
    {
        for (; i < numElements.second; ++i)
        {
            bits.at(i) = u0.at(i);
        }
    }

    /// 如果没有进位，请减少位数。
    const auto firstBitIndex = (numBits - 1) % 32;
    const auto mask = (1 << firstBitIndex);
    if ((mask & self.GetBack()) == 0)
    {
        self.SetNumBits(--numBits);
    }
}

template <typename UInteger>
void Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::Sub(const UInteger& n0, const UInteger& n1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto& self = GetSelf();
    const auto n0NumBits = n0.GetNumBits();
    const auto& n0Bits = n0.GetBits();
    const auto& n1Bits = n1.GetBits();

    /// 减去被认为是正整数的数字。
    /// 我们知道n0 > n1，所以创建一个与n0具有相同位数的数字n2，
    /// 并使用二补生成-n2，然后将n0和-n2相加。
    /// 结果是非负的，
    /// 所以我们不需要对负结果应用二的补码来提取符号和绝对值。

    /// 获取输入数组的大小。我们知道
    /// numElements0 >= numElements1.
    const auto numElements0 = n0.GetSize();
    const auto numElements1 = n1.GetSize();

    /// 创建二补数n2。我们知道
    /// n2.GetNumElements() 与 numElements0相同。
    auto n2 = UInteger::CreateZero();
    n2.SetNumBits(n0NumBits);
    auto& n2Bits = n2.GetBits();
    auto i = 0;
    for (; i < numElements1; ++i)
    {
        n2Bits.at(i) = ~n1Bits.at(i);
    }
    for (; i < numElements0; ++i)
    {
        n2Bits.at(i) = ~0u;
    }

    /// 现在将1加到位否定的结果上，得到 -n1。
    auto carry = 1ull;
    for (i = 0; i < numElements0; ++i)
    {
        const auto sum = n2Bits.at(i) + carry;
        n2Bits.at(i) = boost::numeric_cast<uint32_t>(sum & 0x00000000FFFFFFFFull);
        carry = (sum >> 32);
    }

    /// 把这些数字加成正整数。
    /// 如果没有执行，则将最后一个块设置为零。
    self.SetNumBits(n0NumBits + 1);
    self.SetBack(0);

    /// 将n0个块添加到n2个块。
    auto& bits = self.GetBits();
    for (i = 0, carry = 0; i < numElements0; ++i)
    {
        const auto sum = n2Bits.at(i) + (n0Bits.at(i) + carry);
        bits.at(i) = boost::numeric_cast<uint32_t>(sum & 0x00000000FFFFFFFFull);
        carry = (sum >> 32);
    }

    /// 去掉二进制补码引入的位。
    auto block = numElements0 - 1;
    for (; block >= 0; --block)
    {
        if (bits.at(block) > 0)
        {
            break;
        }
    }

    if (block >= 0)
    {
        self.SetNumBits(32 * block + BitHacks::GetLeadingBit(bits.at(block)) + 1);
    }
    else
    {
        /// 此块最初不存在，只有if块存在。
        /// 在RAEGC书籍的一些测试过程中，似乎需要块的地方发生了崩溃。
        /// 我添加了这个块来解决问题，但忘记了n0 > n1的前提条件。
        /// 因此，我没有仔细查看输入和调用堆栈来确定这是如何发生的。
        /// 捕获此问题，并在再次发生这种情况时分析导致此情况的调用堆栈和输入。
        /// 调用堆栈由BSNumber::SubIgnoreSign(...)启动。
        self.SetNumBits(0);
        THROW_EXCEPTION(SYSTEM_TEXT("该数字的差值为零，这违反了前提条件 n0 > n1。"))
    }
}

template <typename UInteger>
void Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::Mul(const UInteger& n0, const UInteger& n1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto& self = GetSelf();
    const auto n0NumBits = n0.GetNumBits();
    const auto n1NumBits = n1.GetNumBits();
    const auto& n0Bits = n0.GetBits();
    const auto& n1Bits = n1.GetBits();

    /// 比特的数量最多是这个，可能小一点。
    auto numBits = n0NumBits + n1NumBits;
    self.SetNumBits(numBits);
    auto& bits = self.GetBits();

    /// 单个块号与多个块号的乘积。
    auto product = UInteger::CreateZero();
    product.SetNumBits(numBits);
    auto& pBits = product.GetBits();

    /// 获取数组大小。
    const auto numElements0 = n0.GetSize();
    const auto numElements1 = n1.GetSize();
    const auto numElements = self.GetSize();

    // 计算乘积 v = u0*u1。
    auto i1 = 0;
    auto i2 = 0;

    /// i0 == 0 的情况是单独处理的，以使用 u0[0]*v初始化累加器。
    /// 这避免了必须在双循环之外用零填充“位”的字节，
    /// 当 'numBits'很大时，这可能是一个性能问题。
    auto block0 = static_cast<uint64_t>(n0Bits.at(0));
    auto carry = 0ull;
    for (; i1 < numElements1; ++i1)
    {
        const auto term = block0 * n1Bits.at(i1) + carry;
        bits.at(i1) = boost::numeric_cast<uint32_t>(term & 0x00000000FFFFFFFFull);
        carry = (term >> 32);
    }
    if (i1 < numElements)
    {
        bits.at(i1) = boost::numeric_cast<uint32_t>(carry & 0x00000000FFFFFFFFull);
    }

    for (auto i0 = 1; i0 < numElements0; ++i0)
    {
        /// 计算乘积 p = u0[i0]*u1.
        block0 = n0Bits.at(i0);
        carry = 0;
        for (i1 = 0, i2 = i0; i1 < numElements1; ++i1, ++i2)
        {
            const auto term = block0 * n1Bits.at(i1) + carry;
            pBits.at(i2) = boost::numeric_cast<uint32_t>(term & 0x00000000FFFFFFFFull);
            carry = (term >> 32);
        }
        if (i2 < numElements)
        {
            pBits.at(i2) = boost::numeric_cast<uint32_t>(carry & 0x00000000FFFFFFFFull);
        }

        /// 将p加到累加器v上。
        carry = 0;
        for (i1 = 0, i2 = i0; i1 < numElements1; ++i1, ++i2)
        {
            const auto sum = pBits.at(i2) + (bits.at(i2) + carry);
            bits.at(i2) = boost::numeric_cast<uint32_t>(sum & 0x00000000FFFFFFFFull);
            carry = (sum >> 32);
        }
        if (i2 < numElements)
        {
            const auto sum = pBits.at(i2) + carry;
            bits.at(i2) = boost::numeric_cast<uint32_t>(sum & 0x00000000FFFFFFFFull);
        }
    }

    // 如果没有进位，请减少位数。
    const auto firstBitIndex = (numBits - 1) % 32;
    const auto mask = (1 << firstBitIndex);
    if ((mask & self.GetBack()) == 0)
    {
        self.SetNumBits(--numBits);
    }
}

template <typename UInteger>
void Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::ShiftLeft(const UInteger& number, int shift)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto& self = GetSelf();
    const auto numberNumBits = number.GetNumBits();
    const auto& nBits = number.GetBits();

    /// 移位被视为奇数正整数的'number。
    self.SetNumBits(numberNumBits + shift);

    /// 将低位设置为零。
    auto& bits = self.GetBits();
    const auto shiftBlock = shift / 32;
    for (auto i = 0; i < shiftBlock; ++i)
    {
        bits.at(i) = 0;
    }

    /// 获取结果中低位1位的位置。
    const auto numInElements = number.GetSize();
    const auto lShift = shift % 32;

    if (0 < lShift)
    {
        /// 源和目标的尾随1位处于不同的相对索引。
        /// 每个移位的源块跨越两个目标块之间的边界，
        /// 因此我们必须提取子块并相应地进行复制。
        const auto rShift = 32 - lShift;
        auto prev = 0;
        auto i = shiftBlock;
        for (auto j = 0; j < numInElements; ++i, ++j)
        {
            auto curr = nBits.at(j);
            bits.at(i) = (curr << lShift) | (prev >> rShift);
            prev = curr;
        }
        if (i < self.GetSize())
        {
            /// 源的前导1位位于相对索引处，
            /// 因此当您添加移位量时，该位将出现在新块中。
            bits.at(i) = (prev >> rShift);
        }
    }
    else
    {
        /// 源和目标的尾随1位处于相同的相对索引。
        /// 偏移减少为块拷贝。
        for (auto i = shiftBlock, j = 0; j < numInElements; ++i, ++j)
        {
            bits.at(i) = nBits.at(j);
        }
    }
}

template <typename UInteger>
int32_t Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::ShiftRightToOdd(const UInteger& number)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    auto& self = GetSelf();
    const auto& nBits = number.GetBits();

    /// 获得领先的1位。
    const auto numElements = number.GetSize();
    const auto numM1 = numElements - 1;
    const auto firstBitIndex = 32 * numM1 + BitHacks::GetLeadingBit(nBits.at(numM1));

    /// 获取后面的1位。
    auto lastBitIndex = -1;
    for (auto block = 0; block < numElements; ++block)
    {
        auto value = nBits.at(block);
        if (value > 0)
        {
            lastBitIndex = 32 * block + BitHacks::GetTrailingBit(value);
            break;
        }
    }

    /// 右移的结果。
    self.SetNumBits(firstBitIndex - lastBitIndex + 1);
    auto& bits = self.GetBits();
    const auto numBlocks = self.GetSize();

    /// 获取结果中低位1位的位置。
    const auto shiftBlock = lastBitIndex / 32;
    const auto rShift = lastBitIndex % 32;
    if (0 < rShift)
    {
        const auto lShift = 32 - rShift;
        auto i = 0;
        auto j = shiftBlock;
        auto curr = nBits.at(j++);
        for (; j < numElements; ++i, ++j)
        {
            auto next = nBits.at(j);
            bits.at(i) = (curr >> rShift) | (next << lShift);
            curr = next;
        }
        if (i < numBlocks)
        {
            bits.at(i) = (curr >> rShift);
        }
    }
    else
    {
        for (auto i = 0, j = shiftBlock; i < numBlocks; ++i, ++j)
        {
            bits.at(i) = nBits.at(j);
        }
    }

    return rShift + 32 * shiftBlock;
}

template <typename UInteger>
int32_t Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::RoundUp()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto& self = GetSelf();
    auto rounded = UInteger::CreateZero();
    rounded.Add(self, UInteger{ 1u });

    return ShiftRightToOdd(rounded);
}

template <typename UInteger>
uint64_t Mathematics::UIntegerArithmeticLogicUnit32<UInteger>::GetPrefix(int numRequested) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto& self = GetSelf();
    const auto& bits = self.GetBits();

    /// 复制到非零的前导32位块的“前缀”。
    const auto bitIndex = self.GetNumBits() - 1;
    auto blockIndex = bitIndex / 32;
    auto prefix = static_cast<uint64_t>(bits.at(blockIndex));

    /// 获取块中以前导1位开始的位数。
    const auto firstBitIndex = bitIndex % 32;
    const auto numBlockBits = firstBitIndex + 1;

    /// 将前缀的前导1位移位到63位。
    /// 我们已经消耗了numBlockBits，这可能不是全部预算。
    auto targetIndex = 63;
    auto shift = targetIndex - firstBitIndex;
    prefix <<= boost::numeric_cast<uint32_t>(shift);
    numRequested -= numBlockBits;
    targetIndex -= numBlockBits;

    if (0 < numRequested && 0 <= --blockIndex)
    {
        /// 更多的位可用。
        /// 复制并移动整个32位下一个块，然后将其“或”到“前缀”中。
        /// 对于'float'，我们将消耗掉整个预算。
        /// 对于'double'，我们可能必须从第三个块中获取位。
        auto nextBlock = static_cast<uint64_t>(bits.at(blockIndex));
        /// 偏移量为正。
        shift = targetIndex - 31;
        nextBlock <<= boost::numeric_cast<uint32_t>(shift);
        prefix |= nextBlock;
        numRequested -= 32;
        targetIndex -= 32;

        if (0 < numRequested && 0 <= --blockIndex)
        {
            /// 我们知道targetIndex>0；
            /// 只有 'double'允许我们到达这里，所以numRequested最多为53。
            /// 我们还知道 targetIndex < 32，因为我们从63开始，并从中减去至少32。
            /// 因此，偏移量是正的。
            nextBlock = bits.at(blockIndex);
            shift = 31 - targetIndex;
            nextBlock >>= boost::numeric_cast<uint32_t>(shift);
            prefix |= nextBlock;
        }
    }

    return prefix;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_ARITHMETIC_LOGIC_UNIT_32_ACHIEVE_H
