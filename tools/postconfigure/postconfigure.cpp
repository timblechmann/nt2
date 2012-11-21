#include <filesystem/filesystem.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

namespace fs = filesystem;
using std::string;

int main(int argc, char* argv[])
{
    try
    {
        std::string root;
        std::string args;
        std::vector<std::string> modules;

        for(int i=1; i!=argc; ++i)
        {
            if(!strcmp(argv[i], "--root") && i!=argc-1)
            {
                root = argv[++i];
                continue;
            }

            if(!strcmp(argv[i], "--modules") && i!=argc-1)
            {
                boost::split(modules, argv[++i], boost::is_any_of(";|&"));
                continue;
            }

            if(root.empty() && argv[i][0] != '-')
            {
                root = argv[i];
                root = fs::parent_path(root);
            }
            std::string arg = argv[i];
            boost::replace_all(arg, "\\", "\\\\");
            boost::replace_all(arg, "\"", "\\\"");
            args += " \"" + arg + '"';
        }
        if(root.empty())
        {
            root = argv[0];
            if(!fs::is_absolute(root))
                root = fs::current_path() + '/' + root;
            root = fs::parent_path(fs::parent_path(fs::parent_path(root)));
        }

        if(modules.empty())
        {
            for(fs::directory_iterator it((root + "/modules").c_str()); *it; ++it)
            {
                std::string f = *it;
                if(f.substr(f.size()-9) == ".manifest")
                    modules.push_back(f.substr(0, f.size()-9));
            }
        }

        for(std::vector<std::string>::const_iterator it = modules.begin(); it != modules.end(); ++it)
        {
            string path = root + "/modules/" + *it + ".manifest";
            std::ifstream fp(path.c_str());
            string line;

            if(!fp)
                continue;

            while(std::getline(fp, line, '\n'))
            {
                size_t pos = line.find(' ');
                if(pos == (size_t)-1 || pos == line.size())
                {
                    std::cerr << "error: invalid syntax in " << *it << std::endl;
                    continue;
                }

                string tool_name = line.substr(0, pos);
                string tool_path = root + "/tools/"  + tool_name + '/' + tool_name;
                string command = '"' + tool_path + '"' + args + line.substr(pos);
#ifdef WIN32
                command = '"' + command + '"'; // yes, the Windows shell is nonsense
#endif
                if(std::system(command.c_str()) < 0)
                    std::cerr << "error: command in " << *it << " could not be executed" << std::endl;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "error: " << e.what() << std::endl;
        return 1;
    }
    catch(...)
    {
        std::cerr << "error: uncaught exception" << std::endl;
        return 1;
    }
}
