#pragma once
#include <coroutine>
#include <csignal>
#include <cstdint>
#include <string>
#include <vector>
#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_enums.hpp>


namespace Lava
{
    class Shader
    {
      public:

        using define = std::pair<std::string, std::string>;


        class VertexInput
        {
          private:
            std::vector<vk::VertexInputBindingDescription> binding_descriptions;
            std::vector<vk::VertexInputAttributeDescription> attribute_descriptions;

          public:
            VertexInput(std::vector<vk::VertexInputBindingDescription> binding_descriptions_arg     = {},
                        std::vector<vk::VertexInputAttributeDescription> attribute_descriptions_arg = {})
              : binding_descriptions(std::move(binding_descriptions_arg)),
                attribute_descriptions(std::move(attribute_descriptions_arg))
            {
            }

            std::vector<vk::VertexInputBindingDescription> GetBindingDescriptions() const
            {
                return binding_descriptions;
            }

            std::vector<vk::VertexInputAttributeDescription> GetAttributeDescriptions() const
            {
                return attribute_descriptions;
            }

            bool operator<(const VertexInput& other) const
            {
                return binding_descriptions.front().binding < other.binding_descriptions.front().binding;
            }
            bool operator>(const VertexInput& other) const
            {
                return binding_descriptions.front().binding > other.binding_descriptions.front().binding;
            }
        }; // End of Vertex Input


        class Uniform
        {
          private:
            friend class Shader;

            vk::ShaderStageFlags stage_flags;
            std::int32_t binding{};
            std::int32_t offset{};
            std::int32_t size{};
            std::int32_t gl_type{};
            bool is_read_only{};
            bool is_write_only{};

          public:
            Uniform(std::int32_t binding_arg             = -1,
                    std::int32_t offset_arg              = -1,
                    std::int32_t size_arg                = -1,
                    std::int32_t gl_type_arg             = -1,
                    vk::ShaderStageFlags stage_flags_arg = {},
                    bool is_read_only_arg                = false,
                    bool is_write_only_arg               = false)
              : stage_flags(stage_flags_arg),
                binding(binding_arg),
                offset(offset_arg),
                size(size_arg),
                gl_type(gl_type_arg),
                is_read_only(is_read_only_arg),
                is_write_only(is_write_only_arg)
            {
                //! TODO: Find a better naming convention for initialiser lists.
                // I don't like the "m_" prefix for members, and the "_arg" suffix looks messy
            }

            vk::ShaderStageFlags GetStageFlags() const { return stage_flags; }
            std::int32_t GetBinding() const { return binding; }
            std::int32_t GetOffset() const { return offset; }
            std::int32_t GetSize() const { return size; }
            std::int32_t GetGlType() const { return gl_type; }
            bool IsReadOnly() const { return is_read_only; }
            bool IsWriteOnly() const { return is_write_only; }


            bool operator==(const Uniform& other) const
            {
                //! TODO: Fix .clang-format to make this neat
                return binding == other.binding && offset == other.offset && size == other.size
                       && gl_type == other.gl_type && is_read_only == other.is_read_only
                       && is_write_only == other.is_write_only && stage_flags == other.stage_flags;
            }

            bool operator!=(const Uniform& other) const { return !operator==(other); }

            
        }; // End of Uniform


    }; // End of Shader
} // namespace Lava