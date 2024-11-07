#pragma once
#include <memory>
#include <vulkan/vulkan.hpp>

namespace Lava
{
    class WriteDescriptorSet
    {
      private:
        vk::WriteDescriptorSet write_descriptor_set;
        std::unique_ptr<vk::DescriptorImageInfo> image_info;
        std::unique_ptr<vk::DescriptorBufferInfo> buffer_info;

      public:
        WriteDescriptorSet(const vk::WriteDescriptorSet& write_descriptor_set_arg,
                           const vk::DescriptorImageInfo& image_info_arg)
          : write_descriptor_set(write_descriptor_set_arg),
            image_info(std::make_unique<vk::DescriptorImageInfo>(image_info_arg))
        {
            this->write_descriptor_set.pImageInfo = this->image_info.get();
        }

        WriteDescriptorSet(const vk::WriteDescriptorSet write_descriptor_set_arg,
                           const vk::DescriptorBufferInfo& buffer_info_arg)
          : write_descriptor_set(write_descriptor_set_arg),
            buffer_info(std::make_unique<vk::DescriptorBufferInfo>(buffer_info_arg))
        {
        }

        const vk::WriteDescriptorSet& GetWriteDescriptorSet() const { return write_descriptor_set; }
    };

} // namespace Lava