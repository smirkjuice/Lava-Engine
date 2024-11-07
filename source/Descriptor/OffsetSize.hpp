#pragma once
#include <cstddef>

namespace Lava
{
    class OffsetSize
    {
      private:
        std::size_t offset;
        std::size_t size;

      public:
        OffsetSize(std::size_t offset_arg, std::size_t size_arg)
          : offset(offset_arg),
            size(size_arg)
        {
        }

        std::size_t GetOffset() const { return offset; }
        std::size_t GetSize() const { return size; }

        bool operator==(const OffsetSize& other) const
        {
            return offset == other.offset && size == other.size;
        }
        bool operator!=(const OffsetSize& other) const
        {
            return !operator==(other);
        }
    };
} // namespace Lava