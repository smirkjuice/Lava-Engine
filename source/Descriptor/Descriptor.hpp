#pragma once
#include "OffsetSize.hpp"
#include "WriteDescriptorSet.hpp"

namespace Lava
{
    struct Descriptor
    {
        Descriptor()          = default;
        virtual ~Descriptor() = default;

        virtual WriteDescriptorSet GetWriteDescriptor(
          std::size_t binding,
          vk::DescriptorType descriptor_type,
          const std::optional<OffsetSize>& offset_size) const = 0;
    };
} // namespace Lava