#include "lve_pipeline.hpp"
#include <fstream>
#include <iostream>

namespace lve
{

    LvePipeline::LvePipeline(const std::string& vertFilePath, const std::string& fragFilePath)
    {
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }

    //std::vector<char> -> Return type for readFile function, comming from LvePipeline
    std::vector<char> LvePipeline:: readFile(const std::string& filepath)
    {
        //takes initians input file, with param filepath and bit flags.
        //ate is to seek
        //binary flag it to read it in binary
        std::ifstream file(filepath, std::ios::ate | std::ios::binary);

        if(!file.is_open())
        {
            throw std::runtime_error("Failed to open file " + filepath);
        }

        size_t fileSize = static_cast <size_t> (file.tellg());

        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
    {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << "Vertex Shader Code Size: "<< vertCode.size() << '\n';
        std::cout << "Fragment Shader Code Size: "<< fragCode.size() << '\n';
    }
}
