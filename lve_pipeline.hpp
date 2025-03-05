#ifndef LVEPIPELINE_HPP
#define LVEPIPELINE_HPP

#include <string>
#include <vector>

namespace lve
{
    class LvePipeline
    {
    public:
        //LvePipeline(const std::string& vertfilepath, const std::string& fragfilepath);
        LvePipeline(const std::string& vertFilePath, const std::string& fragFilePath);

    private:
        static std::vector<char> readFile(const std::string& filepath);
        void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
    };
}


#endif // LVEPIPELINE_HPP
