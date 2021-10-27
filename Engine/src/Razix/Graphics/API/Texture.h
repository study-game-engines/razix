#pragma once

#include "Razix/Core/Log.h"

namespace Razix {
    namespace Graphics {

        /**
         * A class that manages Textures/Image resources for the Engine
         * @brief It manages creation and conversion of Image resources, also stores in a custom Engine Format depending on how it's being used
         */
        // TODO: Derive Texture from a RazixResource/Asset class this way it gets a resource/asset UUID + serialization by default
        class RAZIX_API RZTexture
        {
            // Texture internal Types
        public:
            /* The type of the texture */
            enum class Type
            {
                COLOR, DEPTH, CUBE
            };

            /* The format of the Texture resource */
            enum class Format
            {
                R8, R16, R32, RG8, RG16, RG32, RGB8, RGB16, RGB32, RGBA8, RGBA16, RGBA32,
                R8F, R16F, R32F, RG8F, RG16F, RG32F, RGB8F, RGB16F, RGB32F, RGBA8F, RGBA16F, RGBA32F
            };

            /* Wrap mode for the texture texels */
            enum class Wrapping
            {
                NONE, REPEAT, CLAMP, MIRRORED_REPEAT,
                CLAMP_TO_EDGE, CLAMP_TO_BORDER
            };

            /* Filtering for the Texture */
            struct Filtering
            {
                enum class FilterMode{NONE, LINEAR, NEAREST};
                FilterMode minFilter;
                FilterMode magFilter;
            };

        public:
            /* Default constructor, texture resource is done on demand */
            RZTexture() = default;
            /* Virtual destructor enables the API implementation to delete it's resources */
            virtual ~RZTexture() {}

            /**
             * Calculates the Mip Map count based on the Width and Height of the texture
             *
             * @param width     The width of the Texture
             * @param height    The height of the texture
             */
            static uint32_t calculateMipMapCount(uint32_t width, uint32_t height);
            static Format bitsToTextureFormat(uint32_t bits);

            /* Returns the name of the texture resource */
            std::string getName() const { return m_Name; }
            /* returns the width of the texture */
            uint32_t getWidth() const { return m_Width; }
            /* returns the height of the texture */
            uint32_t getHeight() const { return m_Height; }
            /* Gets the size of the texture resource */
            uint32_t getSize() const { return m_Size; }
            /* Returns the internal format of the texture */
            Format getFormat() const { return m_Format; }
        protected:
            /* Binds the Texture resource to the Pipeline */
            virtual void Bind(uint32_t slot) = 0;
            /* Unbinds the Texture resource from the pipeline */
            virtual void Unbind(uint32_t slot) = 0;

            /* Gets the handle to the underlying API texture instance */
            virtual void* GetHandle() const = 0;

        protected:
            std::string     m_Name;             /* The name of the texture resource         */
            std::string     m_VirtualPath;      /* The virtual path of the texture          */
            uint32_t        m_Width;            /* The width of the texture                 */
            uint32_t        m_Height;           /* The height of the texture                */
            uint32_t        m_Size;             /* The size of the texture resource         */
            Type            m_TextureType;      /* The type of this texture                 */
            Format          m_Format;   /* The internal format of the texture data  */
            Wrapping        m_WrapMode;         /* Wrap mode of the texture                 */
            Filtering       m_FilterMode;       /* Filtering mode of the texture data       */
            bool            m_FlipX;            /* Flip the texture on X-axis during load   */
            bool            m_FlipY;            /* Flip the texture on Y-axis during load   */
        };

        //-----------------------------------------------------------------------------------
        // Texture 2D
        //-----------------------------------------------------------------------------------

        class RAZIX_API RZTexture2D : public RZTexture
        {
        public:
            /**
             * Create a 2D texture resource from the given data
             * 
             * @param name          The name of the texture resource 
             * @param width         The Width of the texture
             * @param height        The height of the texture
             * @param data          The pixel data to fill the texture with
             * @param format        The internal format of the texture
             * @param wrapMode      The wrapping mode of the texture
             * @param filterMode    The filtering mode of the texture
             * @returns Pointer to Texture object of the underlying API
             */
            static RZTexture2D* Create(const std::string& name, uint32_t width, uint32_t height, void* data, Format format, Wrapping wrapMode, Filtering filterMode);
            /**
             * Create a 2D texture resource from the given file
             * 
             * @param filePath      The filepath to load the texture resource from
             * @param name          The name of the texture resource 
             * @param format        The internal format of the texture
             * @param wrapMode      The wrapping mode of the texture
             * @param filterMode    The filtering mode of the texture
             * @returns Pointer to Texture object of the underlying API
             */
            static RZTexture2D* CreateFromFile(const std::string& filePath, const std::string& name, Wrapping wrapMode, Filtering filterMode);

            virtual void SetData(const void* pixels) = 0;
        };
        
    }
}